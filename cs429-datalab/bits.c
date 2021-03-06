/*
 * CS:APP Data Lab
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the "dlc"
 * checker. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#include "btest.h"
#include <limits.h>

/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

// You will provide your solution to the Data Lab by
// editing the collection of functions in this source file.
// 
// CODING RULES:
// 
  // Replace the "return" statement in each function with one
//   or more lines of C code that implements the function. Your code
//   must conform to the following style:
// 
//   int Funct(arg1, arg2, ...) {
//       /* brief description of how your implementation works */
//       int var1 = Expr1;
//       ...
//       int varM = ExprM;
// 
//       varJ = ExprJ;
//       ...
//       varN = ExprN;
//       return ExprR;
//   }
// 
//   Each "Expr" is an expression using ONLY the following:
//   1. Integer constants 0 through 255 (0xFF), inclusive. You are
//       not allowed to use big constants such as 0xffffffff.
//   2. Function arguments and local variables (no global variables).
//   3. Unary integer operations ! ~
//   4. Binary integer operations & ^ | + << >>
// 
//   Some of the problems restrict the set of allowed operators even further.
//   Each "Expr" may consist of multiple operators. You are not restricted to
//   one operator per line.
// 
//   You are expressly forbidden to:
//   1. Use any control constructs such as if, do, while, for, switch, etc.
//   2. Define or use any macros.
//   3. Define any additional functions in this file.
//   4. Call any functions.
//   5. Use any other operations, such as &&, ||, -, or ?:
//   6. Use any form of casting.
// 
//   You may assume that your machine:
//   1. Uses 2s complement, 32-bit representations of integers.
//   2. Performs right shifts arithmetically.
//   3. Has unpredictable behavior when shifting an integer by more
//      than the word size.
// 
// EXAMPLES OF ACCEPTABLE CODING STYLE:
//   /*
//    * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
//    */
//   int pow2plus1(int x) {
//      /* exploit ability of shifts to compute powers of 2 */
//      return (1 << x) + 1;
//   }
// 
//   /*
//    * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
//    */
//   int pow2plus4(int x) {
//      /* exploit ability of shifts to compute powers of 2 */
//      int result = (1 << x);
//      result += 4;
//      return result;
//   }
// 
// 
// NOTES:
//   1. Use the dlc (data lab checker) compiler (described in the handout) to
//      check the legality of your solutions.
//   2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
//      that you are allowed to use for your implementation of the function.
//      The max operator count is checked by dlc. Note that '=' is not
//      counted; you may use as many of these as you want without penalty.
//   3. Use the btest test harness to check your functions for correctness.
//   4. The maximum number of ops for each function is given in the
//      header comment for each function. If there are any inconsistencies
//      between the maximum ops in the writeup and in this file, consider
//      this file the authoritative source.

/*
 * STEP 2: Modify the following functions according to the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest test harness to check that your solutions produce
 *      the correct answers. Watch out for corner cases around Tmin and Tmax.
 *   3. If you have Perl installed, you can use driver.pl to calculate
 *      your final score.
 */

/*
 * bitAnd - x&y using only ~ and |
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  /* definition of Demorgan's using ~'s & |'s */
  int result = ~x | ~y;
  return ~result;
}
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 2
 */
int bitXor(int x, int y) {
  /* definiton of XOR */
  int result = ~(x & y) & ~(~x & ~y);
  return result;
}
/*
 * isEqual - return 1 if x == y, and 0 otherwise
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {
  /* If the XOR'd bits are the same they will produce 0x0.
     !ing this leaves 0x1 */
  int result = x^y;
  return !result;
}
/*
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int evenBits(void) {
  /* Creates an even byte mask, 0x55, checking each byte in 32 bits */
  int even_bits = 0x55;
  int result = 0x00 | even_bits;
  even_bits <<= 8;
  result |= even_bits;
  even_bits <<= 8;
  result |= even_bits;
  even_bits <<= 8;
  result |= even_bits;
  return result;
}
/*
 * fitsBits - return 1 if x can be represented as an
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  /* Masks the signed bit to get the most significant bit, then shifts right n - 1 and ! the solution */
  int mask = x >> 31;

  return !(((~x & mask) + (x & ~mask)) >> (n + ~0));
}
/*
 * bitMask - Generate a mask consisting of all 1's
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {
  /* high masks above highbit, low masks below lowbit and the complement of the | of the two leaves the answer */
  int high_mask = ~0x01 << highbit;
  int low_mask = ~(~0x00 << lowbit);
  int mask = ~(high_mask | low_mask);   // complement of high and low
  return mask;
}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  /*If x is not_zero, or true, y is returned, else z is returned */
  int not_zero = !!(x^0x00);

  int is_true = ((not_zero << 31) >> 31) & y;
  int is_false = ((!not_zero << 31) >> 31) & z;


  int result = is_true | is_false;

  return result;
}
/*
 * reverseBytes - reverse the bytes of x
 *   Example: reverseBytes(0x01020304) = 0x04030201
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int reverseBytes(int x) {
  /* Stores each byte and |'s them back together in reverse order */
  int mask = 0xFF;

  int byte_4 = (x << 24) & mask << 24;
  int byte_3 = (x << 8) & mask << 16;
  int byte_2 = (x >> 8) & mask << 8;
  int byte_1 = (x >> 24) & mask;

  int result = byte_4 | byte_3 | byte_2 | byte_1;
  return result;
}
/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int bang(int x) {
  /* Uses a technique known as 'bitsmearing' to create 1's to the right of the leftmost bit.
     ~ing x and &ing 1 produces the result */
  x |= x >> 16;
  x |= x >> 8;
  x |= x >> 4;
  x |= x >> 2;
  x |= x >> 1;

  return ~x & 0x01;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  /* Uses a technique known as 'hamming weight' to count bits simultaneously */
  int m1 = 0x55;  
  int m2 = 0x33;
  int m4 = 0x0F;
  int m8 = 0xFF;  
  int m16 = 0xFF;

  m1 = (m1 <<  8) | m1;     
  m1 = (m1 << 16) | m1;
  
  m2 = (m2 <<  8) | m2;     
  m2 = (m2 << 16) | m2;
  
  m4 = (m4 <<  8) | m4;     
  m4 = (m4 << 16) | m4;
  
  m8 = (0xFF << 16) | m8;

  m16 = (m16 << 8) | m16;
  
  x = (x & m1 ) + ((x >>  1) & m1 ); // put count of each  2 bits into those  2 bits 
  x = (x & m2 ) + ((x >>  2) & m2 ); // put count of each  4 bits into those  4 bits 
  x = (x & m4 ) + ((x >>  4) & m4 ); // put count of each  8 bits into those  8 bits 
  x = (x & m8 ) + ((x >>  8) & m8 ); // put count of each 16 bits into those 16 bits 
  x = (x & m16) + ((x >> 16) & m16); // put count of each 32 bits into those 32 bits

  return x;
}
/*
 * isZero - returns 1 if x == 0, and 0 otherwise
 *   Examples: isZero(5) = 0, isZero(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int isZero(int x) {
  /* Uses the isEqual method to test x for equality with 0 */
  return !(x^0x00);
}
/*
 * isNegative - return 1 if x < 0, return 0 otherwise
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNegative(int x) {
  /* Obtains the leftmost bit, or the sign bit */
  return (x >> 31) & 1;
}
/*
 * multFiveEights - multiplies by 5/8 rounding toward 0.
 *   Examples: multFiveEights(77) = 48
 *             multFiveEights(-22) = -13
 *   You can assume |x| < (1 << 29)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int multFiveEights(int x) {
  /* Grab the signed bit. XOR it with x and add the opposite of the signed bit.
     Divide the result by 8 by capitalizing on shift operators. & the result with
     0111. Multiply by 5 using shift operators plus the prestanding results. Put
     it all together */
  int sign = ~((x >> 31) & 1) + 1;
  int op_sign = ~sign + 1;
  int n = (x ^ sign) + op_sign;
  int z = n >> 3; 
  int y = n & 7;  
  z = (z << 2) + z;
  y = (y << 2) + y;
  return (sign ^ (z + (y >> 3))) + op_sign;
}
/*
 * sum3 - x+y+z using only a single '+'
 *   Example: sum3(3, 4, 5) = 12
 *   Legal ops: ! ~ & ^ | << >>
 *   Max ops: 16
 *   Rating: 3
 */
/* A helper routine to perform the addition.  Don't change this code */
static int sum(int x, int y) {
  return x+y;
}
int sum3(int x, int y, int z) {
/* XORs x and y then z to obtain one part of the equation and stores the carry bit in word2 */ 
  int word1;
  int word2;
  /**************************************************************
     Fill in code below that computes values for word1 and word2
     (note that the + operation is not allowed here!)
  ***************************************************************/
  int foo = (x ^ y) ^ z;
  int bar = ((x & y) | (x & z) | (y & z)) << 1;
  word1 = foo;
  word2 = bar;
  /**************************************************************
     Don't change anything below here
  ***************************************************************/
  return sum(word1,word2);
}
/*
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
  /* Accounts for several cases overflow cases using the sign bit */
  int sum = x + y;
  int x_less_zero = ((x >> 31) & 1);
  int y_less_zero = ((y >> 31) & 1);
  int sum_less_zero = ((sum >> 31) & 1);
  int neg_overflow = x_less_zero & y_less_zero & !sum_less_zero;
  int pos_overflow = !x_less_zero & !y_less_zero & sum_less_zero;
  return !neg_overflow & !pos_overflow;
}
/*
 * isLess - if x < y  then return 1, else return 0
 *   Example: isLess(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLess(int x, int y) {
  /* Accounts for several cases in which x is less than y through use of the sign bit */
  int x_neg = (x >> 31) & 1;
  int y_neg = (y >> 31) & 1;
  
  int x_pos = !x_neg;
  int y_pos = !y_neg;
  
  int not_equal = !!(x^y);
  int difference = ((x + (~y + 1)) >> 31) & 1;

  int x_less_pos = x_pos & y_pos & difference;
  int x_less_neg = x_neg & y_neg & difference;
  int x_neg_y_pos = x_neg & y_pos;

  return (x_less_pos | x_less_neg | x_neg_y_pos) & not_equal;
}
/*
 * abs - absolute value of x (except returns TMin for TMin)
 *   Example: abs(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int abs(int x) {
  /* Retrieves the sign bit, XORs it with x and adds the opposite.
     This will have no effect on a nonnegative number */
  int mask = x >> 31;
  int result = (x ^ mask) + (~mask + 1);
  return result;
}
/*
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int isNonZero(int x) {
  /* Tests to see if x is positive or negative. If so it is nonzero else it is zero */
  int is_pos = ((~x + 1) >> 31);
  int is_neg = (x >> 31);
  return (is_pos | is_neg) & 1;
}
/*
 * tc2sm - Convert from two's complement to sign-magnitude
 *   where the MSB is the sign bit
 *   You can assume that x > TMin
 *   Example: tc2sm(-5) = 0x80000005.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int tc2sm(int x) {
  /* Takes the abs value of x and applies the sign bit back */
  int mask = x >> 31;
  int result = (x ^ mask) + (~mask + 1);
  return result | (mask << 31);
}
