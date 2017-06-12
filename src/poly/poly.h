/*
 * poly_gen.h
 *
 *  Created on: Jun 5, 2017
 *      Author: zhenfei
 */

#ifndef POLY_POLY_H_
#define POLY_POLY_H_


/*
 * generate a degree N-1 trinary polynomial with
 * d number of +1s and -1s each
 */
void
pol_gen_flat(
          int64_t  *ai,
    const uint16_t  N,
    const uint16_t  d);

/*
 * generate a degree N-1 polynomial whose coefficients
 * follow discrete Gaussian with deviation stdev
 */

void DGS (
          int64_t   *v,
    const uint16_t  N,
    const uint8_t   stdev);

/* Uniform random element of pZ^n, v, such that
 * v_i + (p-1)/2 <= (q-1)/2
 * v_i - (p-1)/2 >= -(q-1)/2
 */
void
pol_unidrnd_pZ(
          int64_t   *v,
    const uint16_t   N,
    const int64_t    q,
    const int8_t     p);


void NTT(
    const int64_t     *f,
          int64_t     *f_ntt);

void Inv_NTT(
          int64_t     *f,
    const int64_t     *f_ntt);


int64_t max_norm(const int64_t *f, const int16_t N);


void
pol_mul_coefficients(
     int64_t         *c,       /* out - address for polynomial c */
     const int64_t   *a,       /*  in - pointer to polynomial a */
     const int64_t   *b,       /*  in - pointer to polynomial b */
     const uint16_t  N,        /*  in - ring degree */
     const uint16_t  padN,     /*  in - padded polynomial degree */
     const int64_t   q,        /*  in - large modulus */
     int64_t         *tmp);

int
pol_inv_mod2(
    int64_t        *a_inv,
    const int64_t  *a,
    const uint16_t N);


int64_t InvMod(int64_t a, int64_t n);

/* Center 'a' modulo p (an odd prime).
 * (a_i -> [-(p-1)/2, (p-1)/2]
 */
int64_t
cmod(const int64_t a, const int64_t p);
#endif /* POLY_POLY_H_ */