#ifndef COMP_PI_HPP
#define COMP_PI_HPP
  
  /*
     * Computation of the n'th decimal digit of \pi with very little memory.
     * Written by Fabrice Bellard on January 8, 1997.
     * 
     * We use a slightly modified version of the method described by Simon
     * Plouffe in "On the Computation of the n'th decimal digit of various
     * transcendental numbers" (November 1996). We have modified the algorithm
     * to get a running time of O(n^2) instead of O(n^3log(n)^3).
     * 
     * This program uses mostly integer arithmetic. It may be slow on some
     * hardwares where integer multiplications and divisons must be done
     * by software. We have supposed that 'int' has a size of 32 bits. If
     * your compiler supports 'long long' integers of 64 bits, you may use
     * the integer version of 'mul_mod' (see HAS_LONG_LONG).  
     */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* uncomment the following line to use 'long long' integers */
/* #define HAS_LONG_LONG */

struct CompPi
{
	int inv_mod(int x, int y);
	int pow_mod(int a, int b, int m);
	int is_prime(int n);
	int next_prime(int n);
	int computePi(int n);
};

#endif
