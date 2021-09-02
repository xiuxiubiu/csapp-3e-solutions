/**
 * A. 0; x = INT_MIN
 * B. 0; x = INT_MAX, y = INT_MAX
 * C. 1; ~x + ~y + 1 = (-x - 1) + (-y) = -(x + y) - 1 = ~(x + y + 1)
 * D. 0; y = INT_MAX, x = INT_MIN
 * E. 1; x >> 2
*/

/*
 * 2.82.c
 */
#include <stdio.h>
#include <assert.h>
#include <limits.h>

/* broken when x is INT_MIN */
int A(int x, int y) {
    return (x < y) == (-x > -y);
}

/*
 * right
 *
 * ((x + y) << 4) + y - x
 *   =>
 * x << 4 - x + y << 4 + y
 *   =>
 * x*16 - x + y*16 + y
 *   whether overflow or not, =>
 * x*15 + y*17
 */
int B(int x, int y) {
    return ((x + y) << 4) + y - x == 17 * y + 15 * x;
}

/*
 * right
 *
 * ~x + ~y + 1
 *   =>
 * ~x + 1 + ~y + 1 - 1
 *   =>
 * -x + -y - 1
 *   =>
 * -(x + y) - 1
 *   =>
 * ~(x + y) + 1 - 1
 *   =>
 * ~(x + y)
 */
int C(int x, int y) {
    return ~x + ~y + 1 == ~(x + y);
}

/*
 * right
 *
 * (ux - uy) == -(unsigned) (y - x)
 *   =>
 * -(ux - uy) == (unsigned) (y - x)
 *   =>
 * (ux - uy) == (unsigned) (x - y)
 */
int D(int x, int y) {
  unsigned ux = (unsigned) x;
  unsigned uy = (unsigned) y;

  return (ux - uy) == -(unsigned) (y - x);
}

/*
 * right
 *
 * (x >> 2) << 2 => x & ~0x3
 * 最后两位置为0
 */
int E(int x, int y) {
    return ((x >> 2) << 2) <= x;
}