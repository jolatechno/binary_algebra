#pragma once

#include "../binary_arithmetic/reference_arithmetic/reference_arithmetic.hpp"
#include "../binary_arithmetic/binary_arithmetic.hpp"

#include <cassert>

/*
transposition
*/


void test_transpose(const reference_arithmetic ref, Matrice const& mat) {
  Matrice stupid_transposed = ref.transpose(mat);

  assert(ref.equal(mat.T(), stupid_transposed));
}


/*
multiplications
*/


void test_multiplication(const reference_arithmetic ref, Matrice const& mat1, Matrice const& mat2) {
  Matrice stupid_product = ref.multiplication(mat1, mat2);

  assert(ref.equal(mat1 * mat2, stupid_product));
}

void test_multiplication(const reference_arithmetic ref, Matrice const& mat, Vector const& vect) {
  Vector stupid_product = ref.multiplication(mat, vect);

  assert(ref.equal(mat * vect, stupid_product));
}

void test_multiplication(const reference_arithmetic ref, Vector const& vect1, Vector const& vect2) {
  Matrice stupid_product = ref.multiplication(vect1, vect2);

  assert(ref.equal(vect1 * vect2, stupid_product));
}


/*
additions
*/


void test_addition(const reference_arithmetic ref, Matrice const& mat1, Matrice const& mat2) {
  Matrice stupid_add = ref.addition(mat1, mat2);

  assert(ref.equal(mat1 ^ mat2, stupid_add));
}

void test_addition(const reference_arithmetic ref, Matrice const& mat, bool bit) {
  Matrice stupid_add = ref.addition(mat, bit);

  assert(ref.equal(mat ^ bit, stupid_add));
}

void test_addition(const reference_arithmetic ref, Vector const& vect1, Vector const& vect2) {
  Vector stupid_add = ref.addition(vect1, vect2);

  assert(ref.equal(vect1 ^ vect2, stupid_add));
}
void test_addition(const reference_arithmetic ref, Vector const& vect, bool bit) {
  Vector stupid_add = ref.addition(vect, bit);

  assert(ref.equal(vect ^ bit, stupid_add));
}


/*
bitwise multiplication
*/


void test_bitwise_multiplication(const reference_arithmetic ref, Matrice const& mat1, Matrice const& mat2) {
  Matrice stupid_mul = ref.bitwise_multiplication(mat1, mat2);

  assert(ref.equal(mat1 & mat2, stupid_mul));
}

void test_bitwise_multiplication(const reference_arithmetic ref, Matrice const& mat, bool bit) {
  Matrice stupid_mul = ref.bitwise_multiplication(mat, bit);

  assert(ref.equal(mat & bit, stupid_mul));
}

void test_bitwise_multiplication(const reference_arithmetic ref, Vector const& vect1, Vector const& vect2) {
  Vector stupid_mul = ref.bitwise_multiplication(vect1, vect2);

  assert(ref.equal(vect1 & vect2, stupid_mul));
}
void test_bitwise_multiplication(const reference_arithmetic ref, Vector const& vect, bool bit) {
  Vector stupid_mul = ref.bitwise_multiplication(vect, bit);

  assert(ref.equal(vect & bit, stupid_mul));
}


/*
negation
*/


void test_negation(const reference_arithmetic ref, Matrice const& mat) {
  Matrice stupid_negated = ref.negate(mat);

  assert(ref.equal(~mat, stupid_negated));
}

void test_negation(const reference_arithmetic ref, Vector const& vect) {
  Vector stupid_negated = ref.negate(vect);

  assert(ref.equal(~vect, stupid_negated));
}


/*
scalar product
*/


void test_scalar_product(const reference_arithmetic ref, Matrice const& mat1, Matrice const& mat2) {
  bool stupid_scalar = ref.scalar_product(mat1, mat2);

  assert((mat1 % mat2) == stupid_scalar);
}

void test_scalar_product(const reference_arithmetic ref, Vector const& vect1, Vector const& vect2) {
  bool stupid_scalar = ref.scalar_product(vect1, vect2);

  assert((vect1 % vect2) == stupid_scalar);
}
