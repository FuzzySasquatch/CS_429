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
  int count = 0;
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
  return count;
}

int main () {
	// printf("0x%X\n", bitMask(5,3));
	// printf("fitsBits = %d\n",fitsBits(1,1));
	// printf("%d\n", conditional(1, 4, 5));
	// printf("0x%X\n", reverseBytes(0x01020304));
	printf("%d\n", bitCount(5));
}