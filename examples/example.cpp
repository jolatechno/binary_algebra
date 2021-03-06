#include <iostream>
#include <stdint.h>
#include <stdio.h>

#include "../src/binary_arithmetic.hpp"

#ifdef MPIENABLED
  #include <mpi.h>
#endif

int main(int argc, char** argv){
  #ifdef MPIENABLED
    // Initialisation
    int err = MPI_Init(&argc, &argv); if (err != 0) return err;
  #endif

  Matrix mat(2, 2);

  mat.randomize();

  Matrix mat_t = mat.T();

  std::cout << mat << "\n" << mat_t << "\n";
  std:: cout << mat * mat_t << "\n";

  mat *= mat_t;
  std:: cout << mat << "\n";

  Vector vect(2);
  vect.randomize();

  std::cout << vect << "\n";

  mat.diag(vect);
  std::cout << mat << "\n";

  std::cout << mat * vect << "\n";

  vect *= mat;
  std::cout << vect << "\n";


  printf("%s %s\n", mat == mat_t ? "true" : "false", mat == mat ? "true" : "false");
  printf("%s %s\n", mat != mat_t ? "true" : "false", mat != mat ? "true" : "false");
  printf("%s %s\n", mat == 1 ? "true" : "false", vect == 1 ? "true" : "false");

  #ifdef MPIENABLED
    // Finalisation
    return MPI_Finalize();
  #endif
}
