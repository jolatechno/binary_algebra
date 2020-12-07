#include <chrono>
#include <stdio.h>

#include "../binary_arithmetic/binary_arithmetic.hpp"

using namespace std::chrono;

void timeit(void (*f)(Matrice, Vector), const char* message, int iterations, const int sizes[], int n_sizes) {
  for (int size = 0; size < n_sizes; size++) {
    //initializing matrices
    Matrice mat(sizes[size], sizes[size]); Vector vect(sizes[size]);
    mat.randomize(); vect.randomize();

    //reading initial time
    auto start = high_resolution_clock::now();

    for (int i = 0; i < iterations; i++)
      (*f)(mat, vect);

    //reading end time
    auto stop = high_resolution_clock::now();
    double duration = duration_cast<microseconds>(stop - start).count()/iterations;

    //printing message
    if (duration < 1000) {
      printf(message, duration, "µs/op", sizes[size]);
    } else if (duration < 1000000) {
      duration /= 1000;
      printf(message, duration, "ms/op", sizes[size]);
    } else {
      duration /= 1000000;
      printf(message, duration / 1000,000, "s/op", sizes[size]);
    }
  }
}

void timeit(void (*f)(Matrice, Matrice), const char* message, int iterations, const int sizes[], int n_sizes) {
  for (int size = 0; size < n_sizes; size++) {
    //initializing matrices
    Matrice mat1(sizes[size], sizes[size]); Matrice mat2(sizes[size], sizes[size]);
    mat1.randomize(); mat2.randomize();

    //reading initial time
    auto start = high_resolution_clock::now();

    for (int i = 0; i < iterations; i++)
      (*f)(mat1, mat2);

    //reading end time
    auto stop = high_resolution_clock::now();
    double duration = duration_cast<microseconds>(stop - start).count()/iterations;

    //printing message
    if (duration < 1000) {
      printf(message, duration, "µs/op", sizes[size]);
    } else if (duration < 1000000) {
      duration /= 1000;
      printf(message, duration, "ms/op", sizes[size]);
    } else {
      duration /= 1000000;
      printf(message, duration, "s/op", sizes[size]);
    }

  }
}

void timeit(void (*f)(Matrice), const char* message, int iterations, const int sizes[], int n_sizes) {
  for (int size = 0; size < n_sizes; size++) {
    //initializing matrices
    Matrice mat(sizes[size], sizes[size]);
    mat.randomize();

    //reading initial time
    auto start = high_resolution_clock::now();

    for (int i = 0; i < iterations; i++)
      (*f)(mat);

    //reading end time
    auto stop = high_resolution_clock::now();
    double duration = duration_cast<microseconds>(stop - start).count()/iterations;

    //printing message
    if (duration < 1000) {
      printf(message, duration, "µs/op", sizes[size]);
    } else if (duration < 1000000) {
      duration /= 1000;
      printf(message, duration, "ms/op", sizes[size]);
    } else {
      duration /= 1000000;
      printf(message, duration, "s/op", sizes[size]);
    }
  }
}

void timeit(void (*f)(Vector, Vector), const char* message, int iterations, const int sizes[], int n_sizes) {
  for (int size = 0; size < n_sizes; size++) {
    //initializing matrices
    Vector vect1(sizes[size]); Vector vect2(sizes[size]);
    vect1.randomize(); vect2.randomize();

    //reading initial time
    auto start = high_resolution_clock::now();

    for (int i = 0; i < iterations; i++)
      (*f)(vect1, vect2);

    //reading end time
    auto stop = high_resolution_clock::now();
    double duration = duration_cast<microseconds>(stop - start).count()/iterations;

    //printing message
    if (duration < 1000) {
      printf(message, duration, "µs/op", sizes[size]);
    } else if (duration < 1000000) {
      duration /= 1000;
      printf(message, duration, "ms/op", sizes[size]);
    } else {
      duration /= 1000000;
      printf(message, duration, "s/op", sizes[size]);
    }
  }
}

void timeit(void (*f)(Vector), const char* message, int iterations, const int sizes[], int n_sizes) {
  for (int size = 0; size < n_sizes; size++) {
    //initializing matrices
    Vector vect(sizes[size]);
    vect.randomize();

    //reading initial time
    auto start = high_resolution_clock::now();

    for (int i = 0; i < iterations; i++)
      (*f)(vect);

    //reading end time
    auto stop = high_resolution_clock::now();
    double duration = duration_cast<microseconds>(stop - start).count()/iterations;

    //printing message
    if (duration < 1000) {
      printf(message, duration, "µs/op", sizes[size]);
    } else if (duration < 1000000) {
      duration /= 1000;
      printf(message, duration, "ms/op", sizes[size]);
    } else {
      duration /= 1000000;
      printf(message, duration, "s/op", sizes[size]);
    }
  }
}
