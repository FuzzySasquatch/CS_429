#include "btest.h"
#include <limits.h>
#include <stdio.h>

int isEqual(int x, int y) {
  int result = ~(x^y);
  result <<= 30;
  printf("0x%X\n", result);
  return result;
}

int evenBits(void) {
  int even_bits = 0x11;
  int result = 0x00 | even_bits;

  even_bits <<= 8;
  result |= even_bits;
  even_bits <<= 8;
  result |= even_bits;
  even_bits <<= 8;
  result |= even_bits;

  return result;
}

int fitsBits(int x, int n) {
  int left_shift = n + ~0;
  
  // int mask = 0x01 << left_shift << 1;
  // printf("mask = 0x%X\n", mask);

  // int result = x | mask;
  // printf("result | mask = 0x%X\n", result);
  // result = result >> left_shift >> 1;
  // printf("result = 0x%X\n", result);
  int mask = ~0x00 << left_shift << 1;
  printf("mask = 0x%X\n", mask);

  printf("0x%X\n", x);
  int result = x & mask;
  printf("result & mask = 0x%X\n", result);

  return !(result^0x00);
}

int bitMask(int highbit, int lowbit) {
  
  int highMask = ~0x01 << (highbit);
  int lowMask = ~(~0x00 << lowbit);
  int mask = ~(highMask ^ lowMask);
  return mask;
}

int conditional(int x, int y, int z) {
  int not_zero = !!(x^0x00);

  // (((test1 << 31) >> 31) & a) | ((((!test1 & test2) << 31) >> 31) & b)
  int is_true = ((not_zero << 31) >> 31) & y;
  int is_false = ((!not_zero << 31) >> 31) & z;
  // condition <<= 31;
  // condition >>= 31;
  printf("0x%X\n", not_zero);
  int result = is_true | is_false;

  return result;
}

int reverseBytes(int x) {
  int mask = 0xFF << 24;
  printf("0x%X\n", mask);

  int byte_4 = (x << 24) & mask;
  int byte_3 = (x << 16) & mask;
  int byte_2 = (x << 8) & mask;
  int byte_1 = x & mask;

  int result = byte_4 | byte_3 | byte_2 | byte_1;
  return result;
}

int bang(int x) {
  return ;
}

int bitCount(int x) {
  // int count = 0;
  // count+= x & 1;
  // count+= x >> 1 & 1;
  // count+= x >> 2 & 1;
  // count+= x >> 3 & 1;
  // count+= x >> 4 & 1;
  // count+= x >> 5 & 1;
  // count+= x >> 6 & 1;
  // count+= x >> 7 & 1;
  // count+= x >> 8 & 1;
  // count+= x >> 9 & 1;
  // count+= x >> 10 & 1;
  // count+= x >> 11 & 1;
  // count+= x >> 12 & 1;
  // count+= x >> 13 & 1;
  // count+= x >> 14 & 1;
  // count+= x >> 15 & 1;
  // count+= x >> 16 & 1;
  // count+= x >> 17 & 1;
  // count+= x >> 18 & 1;
  // count+= x >> 19 & 1;
  // count+= x >> 20 & 1;
  // count+= x >> 21 & 1;
  // count+= x >> 22 & 1;
  // count+= x >> 23 & 1;
  // count+= x >> 24 & 1;
  // count+= x >> 25 & 1;
  // count+= x >> 26 & 1;
  // count+= x >> 27 & 1;
  // count+= x >> 28 & 1;
  // count+= x >> 29 & 1;
  // count+= x >> 30 & 1;
  // count+= x >> 31 & 1;

  int m1 = 0x55;                
  m1 = (m1 <<  8) | m1;     
  m1 = (m1 << 16) | m1;

  int m2 = 0x33;
  m2 = (m2 <<  8) | m2;     
  m2 = (m2 << 16) | m2;

  int m4 = 0x0F;
  m4 = (m4 <<  8) | m4;     
  m4 = (m4 << 16) | m4;

  int m8 = 0xFF | 0xFF << 16;

  int m16 = 0xFF;
  m16 = (m16 << 8) | m16;

  x = (x & m1 ) + ((x >>  1) & m1 ); //put count of each  2 bits into those  2 bits 
  x = (x & m2 ) + ((x >>  2) & m2 ); //put count of each  4 bits into those  4 bits 
  x = (x & m4 ) + ((x >>  4) & m4 ); //put count of each  8 bits into those  8 bits 
  x = (x & m8 ) + ((x >>  8) & m8 ); //put count of each 16 bits into those 16 bits 
  x = (x & m16) + ((x >> 16) & m16); //put count of each 32 bits into those 32 bits


  // int fives = 0x55;                
  // fives = (fives <<  8) | fives;     
  // fives = (fives << 16) | fives;
  // int threes = 0x33;
  // threes = (threes <<  8) | threes;     
  // threes = (threes << 16) | threes;
  // int zero_f = 0x0F;
  // zero_f = (zero_f <<  8) | zero_f;     
  // zero_f = (zero_f << 16) | zero_f;
  // int front_f = 0xFF;
  // int mid_f = front_f << 16;
  // front_f = (front_f << 4) | front_f;


  // count = (x & fives) + ((x >> 1) & fives);
  // count = (count & threes) + ((count >> 2) & threes);
  // count = (count & zero_f) + ((count >> 4) & zero_f);
  // count = (count & mid_f) + ((count >> 8) & mid_f);
  // count = (count & front_f) + ((count >> 16) & front_f);

  return x;
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
  int sum = x + y;
  int neg_overflow = ((x >> 31) & 1) & ((y >> 31) & 1) & !((sum >> 31) & 1);
  int pos_overflow = !((x >> 31) & 1) & !((y >> 31) & 1) & ((sum >> 31) & 1);
  return !neg_overflow & !pos_overflow;
}

int isLess(int x, int y) {
  // int difference = x + (~y + 1);


  // int is_less = (difference >> 31) & 1;
  // printf("%d\n", difference);
  // printf("%X\n", is_less);

  int x_neg = (x >> 31) & 1;
  int y_neg = (y >> 31) & 1;
  
  int x_pos = !x_neg;
  int y_pos = !y_neg;
  
  int not_equal = !!(x^y);



  int difference = ((x + (~y + 1)) >> 31) & 1;



  int x_less_pos = x_pos & y_pos & difference;
  int x_less_neg = x_neg & y_neg & difference;
  int x_neg_y_pos = x_neg & y_pos;


  // int difference = x + (~y + 1);
  // int is_less = (difference >> 31) & 1;
  return x_less_pos | x_less_neg | x_neg_y_pos & not_equal;
  
}

/*
 * abs - absolute value of x (except returns TMin for TMin)
 *   Example: abs(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int ab(int x) {
  int x_neg = (x >> 31) & 1;
   printf("%d\n", x_neg);
  return x_neg & (~x + 1);
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
int multFiveEights(int num) {
  int s = -((num >> 31) & 1); // sign bit as -1 or 0

  int n = (num ^ s) - s; // twos complement if negative

  int x = n >> 3; // divide by 8

  x = (x << 2) + x;   // multiply by 5; no overflow yet since 5/8 is less than one

  int y = n & 7;  // the bits we shifted out

  y = (y << 2) + y;   // multiply by 5; no overflow

  return (s ^ (x + (y >> 3))) - s; // the two pieces and complemented back
}

int main () {
  // printf("%d\n", ~5 + 1);
	// printf("0x%X\n", bitMask(5,3));
	// printf("fitsBits = %d\n",fitsBits(1,1));
	// printf("%d\n", conditional(1, 4, 5));
	// printf("0x%X\n", reverseBytes(0x01020304));
  printf("%d\n", multFiveEights(77));
  printf("%d\n", ~0);
  // printf("%d\n", ab(-3));
	// printf("%X\n", addOK(0x80000000, 0x80000000));
  return 0;
}