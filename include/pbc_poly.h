// Polynomial rings R[x], and polynomial rings modulo polynomials,
// i.e. R[x]_{f(x)}.

// Requires:
// * gmp.h
// * field.h
#ifndef __PBC_POLY_H__
#define __PBC_POLY_H__

// Initializes a polynomial ring.
void field_init_poly(field_ptr f, field_ptr base_field);

// Initializes a polynomial modulo ring.
// Requires poly to be monic.
void field_init_polymod(field_ptr f, element_ptr poly);

#pragma GCC visibility push(hidden)
// Internal library functions:

// Returns deg f + 1.
int poly_coeff_count(element_ptr f);

// Returns coefficient of x^n in f.
// Requires deg f >= n.
// The element the return value points to may be modified. Take care never
// to zero the leading coefficient, e.g. never write:
//   element_set0(poly_coeff(f, poly_degree(f)));
// Use poly_set_coeff0() to zero the leading coefficient.
element_ptr poly_coeff(element_ptr f, int n);

// Returns deg f.
static inline int poly_degree(element_ptr f) {
  return poly_coeff_count(f) - 1;
}

// Returns base field of f (where the coefficients live).
field_ptr poly_base_field(element_t f);

// Sets the coefficient of x^n to 0.
void poly_set_coeff0(element_ptr f, int n);

// Sets the coefficient of x^n to 1.
void poly_set_coeff1(element_ptr f, int n);

// Sets the coefficient of x^n to a.
void poly_set_coeff(element_ptr f, element_ptr a, int n);

// Sets f = x.
void poly_setx(element_ptr f);
void poly_const_mul(element_ptr res, element_ptr a, element_ptr poly);

// Returns 0 when a root exists and sets root to one of the roots.
int poly_findroot(element_ptr root, element_ptr poly);

// Returns 1 if polynomial is irreducible, 0 otherwise.
// Requires the polynomial to be monic.
int poly_is_irred(element_ptr f);
void poly_random_monic(element_ptr f, int deg);

void element_field_to_poly(element_t poly, element_t constant);
void element_field_to_polymod(element_ptr f, element_ptr a);
element_ptr polymod_coeff(element_ptr e, int i);

void polymod_const_mul(element_ptr res, element_ptr a, element_ptr e);
int polymod_field_degree(field_t f);

#pragma GCC visibility pop

#endif //__PBC_POLY_H__
