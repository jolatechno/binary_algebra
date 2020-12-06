#include <stdint.h>
#include <stdio.h>

#include "../binary_arithmetic/binary_arithmetic.hpp"

#include "utils.hpp"
#include "functions.hpp"

int main(int argc, char** argv){
  const int n_iter = 50;
  const int sizes[] = {
    20, 50, 100, 200,
  };
  const int n_sizes = sizeof(sizes)/sizeof(sizes[0]);

  /*
  transposition
  */


  printf("\n");
  timeit(transposition, "Matrice transposition: %f µsec/op for size=%d\n", n_iter, sizes, n_sizes);


  /*
  equality
  */


  printf("\n\n\n");
  timeit(equal_mat, "Matrice equality: %f µsec/op for size=%d\n", n_iter, sizes, n_sizes);

  printf("\n");
  timeit(equal_vect, "Vector equality: %f µsec/op for size=%d\n", n_iter, sizes, n_sizes);


  /*
  comparaison
  */


  printf("\n\n\n");
  timeit(comparaisons_mat, "Matrice Comparaison: %f µsec/op for size=%d\n", n_iter, sizes, n_sizes);

  printf("\n");
  timeit(comparaisons_vect, "Vector Comparaison: %f µsec/op for size=%d\n", n_iter, sizes, n_sizes);


  /*
  addition
  */


  printf("\n\n\n");
  timeit(additions_mat, "Matrice addition: %f µsec/op for size=%d\n", n_iter, sizes, n_sizes);

  printf("\n");
  timeit(additions_vect, "Vector addition: %f µsec/op for size=%d\n", n_iter, sizes, n_sizes);


  /*
  scalar products
  */


  printf("\n\n\n");
  timeit(scalar_product_mat, "Matrice scalar product: %f µsec/op for size=%d\n", n_iter, sizes, n_sizes);

  printf("\n");
  timeit(scalar_product_vect, "Vector scalar product: %f µsec/op for size=%d\n", n_iter, sizes, n_sizes);

  printf("\n");
  timeit(integer_scalar_product_mat, "Matrice integer scalar product: %f µsec/op for size=%d\n", n_iter, sizes, n_sizes);

  printf("\n");
  timeit(integer_scalar_product_vect, "Vector integer scalar product: %f µsec/op for size=%d\n", n_iter, sizes, n_sizes);


  /*
  multiplciations
  */


  printf("\n\n\n");
  timeit(multiplication_mat, "Matrice multiplication with matrice: %f µsec/op for size=%d\n", n_iter, sizes, n_sizes);

  printf("\n");
  timeit(multiplication_mat_vect, "Matrice multiplication with vector: %f µsec/op for size=%d\n", n_iter, sizes, n_sizes);

  printf("\n");
  timeit(multiplication_vect, "Vector multiplication with vector: %f µsec/op for size=%d\n", n_iter, sizes, n_sizes);
}