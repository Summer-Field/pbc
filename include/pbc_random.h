//requires
// * gmp.h
#ifndef __PBC_RANDOM_H__
#define __PBC_RANDOM_H__

/*@manual pbcrandom
Uses 'filename' as a source of random bytes. For example,
on Linux one might use `/dev/random`.
*/
void random_set_file(char *filename);

/*@manual pbcrandom
Use a determinstic random number generator.
*/
void random_set_deterministic(void);

/*@manual pbcrandom
Use previously chosen random number generator to select
a random 'z' that is less than 'limit'.
*/
void pbc_mpz_random(mpz_t z, mpz_t limit);

/*@manual pbcrandom
Use previously chosen random number generator to select
a random 'bits'-bit integer 'z'.
*/
void pbc_mpz_randomb(mpz_t z, unsigned int bits);

void set_random_function(void (*fun)(mpz_t, mpz_t, void *), void *data);

#endif //__PBC_RANDOM_H__
