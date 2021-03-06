#define ARITHMETIC_VARIABLE_HEADER \
  auto *res_blocks = res.blocks; \
  auto *other_blocks = other.blocks; \
  auto *this_blocks = blocks;

#define ARITHMETIC_MATRIX_BITWISE_HEADER \
  assert(height == other.height); \
  assert(width == other.width); \
  Matrix res(height, width); \
  auto _width = width; \
  auto _height = height; \
  auto _size = _height * _width;

#define ARITHMETIC_VECTOR_BITWISE_HEADER \
  assert(height == other.height); \
  Vector res(height); \
  auto _height = height;


/*
transposition
*/


Matrix Matrix::T() const {
  Matrix res(width, height);

  uint64_t *this_blocks = blocks;
  uint64_t *res_blocks = res.blocks;

  int _width = width;
  int _height = height;

  int16_t i, j;
  #if defined(_OPENMP) && defined(TARGET)
    if(_width*_height > GPU_LIMIT) {
      #pragma omp target teams distribute parallel for collapse(2)
      for (i = 0; i < _height; i++)
        for (j = 0; j < _width; j++)
          res_blocks[i + j*_height] = transpose_block(this_blocks[j + i*_width]);
      res.from();
    } else {
  #endif

  _OPENMP_PRAGMA("omp parallel for collapse(2) schedule(static) if(_width*_height > CPU_LIMIT)")
  for (i = 0; i < _height; i++)
    for (j = 0; j < _width; j++)
      res_blocks[i + j*_height] = transpose_block(this_blocks[j + i*_width]);

  #if defined(_OPENMP) && defined(TARGET)
      res.to();
    }
  #endif

  return res;
}


/*
negation
*/


Matrix Matrix::operator~() const {
  Matrix res(height, width);

  uint64_t *this_blocks = blocks;
  uint64_t *res_blocks = res.blocks;

  int _size = width * height;

  int16_t n;
  #if defined(_OPENMP) && defined(TARGET)
    if(_size > GPU_LIMIT) {
      #pragma omp target teams distribute parallel for
      for (n = 0; n < _size; n++)
        res_blocks[n] = ~this_blocks[n];
        res.from();
    } else {
  #endif

  _OPENMP_PRAGMA("omp parallel for schedule(static) if(_size > CPU_LIMIT)")
  for (n = 0; n < _size; n++)
    res_blocks[n] = ~this_blocks[n];

  #if defined(_OPENMP) && defined(TARGET)
      res.to();
    }
  #endif

  return res;
}

Vector Vector::operator~() const {
  Vector res(height);

  uint8_t *this_blocks = blocks;
  uint8_t *res_blocks = res.blocks;

  int _height = height;

  int16_t i;
  #if defined(_OPENMP) && defined(TARGET)
    if(_height > GPU_LIMIT) {
      #pragma omp target teams distribute parallel for
      for (i = 0; i < _height; i++)
        res_blocks[i] = ~this_blocks[i];
      res.from();
    } else {
  #endif

  _OPENMP_PRAGMA("omp parallel for schedule(static) if(_height > CPU_LIMIT)")
  for (i = 0; i < _height; i++)
    res_blocks[i] = ~this_blocks[i];

  #if defined(_OPENMP) && defined(TARGET)
      res.to();
    }
  #endif

  return res;
}


/*
additions
*/


Matrix Matrix::operator^(Matrix const& other) const {
  ARITHMETIC_MATRIX_BITWISE_HEADER;
  ARITHMETIC_VARIABLE_HEADER;

  int16_t n;
  #if defined(_OPENMP) && defined(TARGET)
    if(_size > GPU_LIMIT) {
      #pragma omp target teams distribute parallel for
      for (n = 0; n < _size; n++)
        res_blocks[n] = this_blocks[n] ^ other_blocks[n];
      res.from();
    } else {
  #endif

  _OPENMP_PRAGMA("omp parallel for schedule(static) if(_size > CPU_LIMIT)")
  for (n = 0; n < _size; n++)
    res_blocks[n] = this_blocks[n] ^ other_blocks[n];

  #if defined(_OPENMP) && defined(TARGET)
      res.to();
    }
  #endif

  return res;
}

Matrix Matrix::operator+(Matrix const& other) const {
  return *this ^ other;
}

Matrix Matrix::operator-(Matrix const& other) const {
  return *this ^ other;
}

Matrix Matrix::operator^(const bool bit) const {
  return bit ? ~(*this) : *this ;
}

Matrix Matrix::operator+(const bool bit) const {
  return *this ^ bit;
}

Matrix Matrix::operator-(const bool bit) const {
  return *this ^ bit;
}

Vector Vector::operator^(Vector const& other) const {
  ARITHMETIC_VECTOR_BITWISE_HEADER;
  ARITHMETIC_VARIABLE_HEADER;

  int16_t i;
  #if defined(_OPENMP) && defined(TARGET)
    if(_height > GPU_LIMIT) {
      #pragma omp target teams distribute parallel for
      for (i = 0; i < _height; i++)
        res_blocks[i] = this_blocks[i] ^ other_blocks[i];
      res.from();
    } else {
  #endif

  _OPENMP_PRAGMA("omp parallel for schedule(static) if(_height > CPU_LIMIT)")
  for (i = 0; i < _height; i++)
    res_blocks[i] = this_blocks[i] ^ other_blocks[i];

  #if defined(_OPENMP) && defined(TARGET)
      res.to();
    }
  #endif

  return res;
}

Vector Vector::operator+(Vector const& other) const {
  return *this ^ other;
}

Vector Vector::operator-(Vector const& other) const {
  return *this ^ other;
}

Vector Vector::operator^(const bool bit) const {
  return bit ? ~(*this) : *this ;
}

Vector Vector::operator+(const bool bit) const {
  return *this ^ bit;
}

Vector Vector::operator-(const bool bit) const {
  return *this ^ bit;
}


/*
bitwise multiplications
*/


Matrix Matrix::operator&(Matrix const& other) const {
  ARITHMETIC_MATRIX_BITWISE_HEADER;
  ARITHMETIC_VARIABLE_HEADER;

  int16_t n;
  #if defined(_OPENMP) && defined(TARGET)
    if(_size > GPU_LIMIT) {
      #pragma omp target teams distribute parallel for
      for (n = 0; n < _size; n++)
        res_blocks[n] = this_blocks[n] & other_blocks[n];
      res.from();
    } else {
  #endif

  _OPENMP_PRAGMA("omp parallel for schedule(static) if(_size > CPU_LIMIT)")
  for (n = 0; n < _size; n++)
    res_blocks[n] = this_blocks[n] & other_blocks[n];

  #if defined(_OPENMP) && defined(TARGET)
      res.to();
    }
  #endif

  return res;
}

Matrix Matrix::operator&(const bool bit) const {
  return bit ? *this : Matrix(height, width);
}

Vector Vector::operator&(Vector const& other) const {
  ARITHMETIC_VECTOR_BITWISE_HEADER;
  ARITHMETIC_VARIABLE_HEADER;

  int16_t i;
  #if defined(_OPENMP) && defined(TARGET)
    if(_height > GPU_LIMIT) {
      #pragma omp target teams distribute parallel for
      for (i = 0; i < _height; i++)
        res_blocks[i] = this_blocks[i] & other_blocks[i];
      res.from();
    } else {
  #endif

  _OPENMP_PRAGMA("omp parallel for schedule(static) if(_height > CPU_LIMIT)")
  for (i = 0; i < _height; i++)
    res_blocks[i] = this_blocks[i] & other_blocks[i];

  #if defined(_OPENMP) && defined(TARGET)
      res.to();
    }
  #endif

  return res;
}

Vector Vector::operator&(const bool bit) const {
  return bit ? *this : Vector(height);
}


/*
multiplications
*/


Matrix Matrix::operator*(Matrix const& other) const {
  assert(width == other.height); //check if dimensions are compatible

  Matrix res(height, other.width);

  int16_t _width = width;
  int16_t _height = height;
  int16_t _size = other.width;

  long unsigned int *res_blocks = res.blocks;
  long unsigned int *other_blocks = other.blocks;
  long unsigned int *this_blocks = blocks;

  int16_t i, j, k;
  #if defined(_OPENMP) && defined(TARGET)
    if(_width*_height*_size > GPU_LIMIT) {
      #pragma omp target teams distribute parallel for collapse(3)
      for (j = 0; j < _size; j++)
        for (i = 0; i < _height; i++)
          for (k = 0; k < _width; k++) {
            #pragma omp atomic
            res_blocks[i + j*_height] ^= multiply_block_block(this_blocks[k + j*_width], other_blocks[i + k*_size]);
          }
      res.from();
    } else {
  #endif

  _OPENMP_PRAGMA("omp parallel for collapse(3) schedule(static) if(_width*_height*_size > CPU_LIMIT)")
  for (j = 0; j < _size; j++)
    for (k = 0; k < _width; k++)
      for (i = 0; i < _height; i++) {
        _OPENMP_PRAGMA("omp atomic")
        res_blocks[i + j*_height] ^= multiply_block_block(this_blocks[k + j*_width], other_blocks[i + k*_size]);
      }

  #if defined(_OPENMP) && defined(TARGET)
      res.to();
    }
  #endif

  return res;
}

Vector Matrix::operator*(Vector const& other) const {
  assert(width == other.height); //check if dimensions are compatible

  Vector res(height);

  auto _width = width;
  auto _height = height;

  uint8_t *res_blocks = res.blocks;
  uint8_t *other_blocks = other.blocks;
  uint64_t *this_blocks = blocks;

  int16_t i, k;
  #if defined(_OPENMP) && defined(TARGET)
    if(_height*_width > GPU_LIMIT) {
      long unsigned int *res_blocks_long = (long unsigned int*)&res.blocks[0];

      #pragma omp target teams distribute parallel for collapse(2)
      for (i = 0; i < _height/8 - 1; i++)
        for (k = 0; k < _width; k++) {
          #pragma omp atomic
          res_blocks_long[i] ^= multiply_block_word(this_blocks[k + 8*i*_width], this_blocks[k + (8*i + 1)*_width], this_blocks[k + (8*i + 2)*_width], this_blocks[k + (8*i + 3)*_width], \
            this_blocks[k + (8*i + 4)*_width], this_blocks[k + (8*i + 5)*_width], this_blocks[k + (8*i + 6)*_width], this_blocks[k + (8*i + 7)*_width], \
            other_blocks[k]);
        }
      res.from();

      auto start = std::max(0, _height - _height%8 - 8);
      auto length = _height - start;
      #pragma omp parallel for collapse(2) schedule(static) if(8*_width > CPU_LIMIT)
      for (k = 0; k < _width; k++)
        for (i = start; i < _height; i++) {
          #pragma omp atomic
          res_blocks[i] ^= multiply_block_byte(this_blocks[k + i*_width], other_blocks[k]);
        }
      res.to(start, length);

    } else {
  #endif

  _OPENMP_PRAGMA("omp parallel for collapse(2) schedule(static) if(_height*_width > CPU_LIMIT)")
  for (k = 0; k < _width; k++)
    for (i = 0; i < _height; i++) {
      _OPENMP_PRAGMA("omp atomic")
      res_blocks[i] ^= multiply_block_byte(this_blocks[k + i*_width], other_blocks[k]);
    }

  #if defined(_OPENMP) && defined(TARGET)
      res.to();
    }
  #endif

  return res;
}

Matrix Vector::operator*(Vector const& other) const {
  Matrix res(other.height, height);

  int16_t _height = other.height;
  int16_t _width = height;

  long unsigned int *res_blocks = res.blocks;
  uint8_t *other_blocks = other.blocks;
  uint8_t *this_blocks = blocks;

  int16_t i, j;
  #if defined(_OPENMP) && defined(TARGET)
    if(_width *_height > GPU_LIMIT) {
      #pragma omp target teams distribute parallel for collapse(2)
      for (j = 0; j < _width; j++)
        for (i = 0; i < _height; i++)
          res_blocks[j + i*_width] = multiply_byte_byte(this_blocks[j], other_blocks[i]);
      res.from();
    } else {
  #endif

  _OPENMP_PRAGMA("omp parallel for collapse(2) schedule(static) if(_height*_width > CPU_LIMIT)")
  for (j = 0; j < _width; j++)
    for (i = 0; i < _height; i++)
      res_blocks[j + i*_width] = multiply_byte_byte(this_blocks[j], other_blocks[i]);

  #if defined(_OPENMP) && defined(TARGET)
      res.to();
    }
  #endif

  return res;
}


/*
scalar products
*/


bool Matrix::operator%(Matrix const& other) const {
  COMPARAISON_MATRIX_BITWISE_HEADER;
  COMPARAISON_VARIABLE_HEADER;

  long unsigned int sum = 0;

  int16_t n;
  #if defined(_OPENMP) && defined(TARGET)
    if(_size > GPU_LIMIT) {
      #pragma omp target teams distribute parallel for reduction(^ : sum) map(tofrom:sum)
      for (n = 0; n < _size; n++)
        sum ^= this_blocks[n] & other_blocks[n];
    } else {
  #endif

  _OPENMP_PRAGMA("omp parallel for reduction(^ : sum) schedule(static) if(_size > CPU_LIMIT)")
  for (n = 0; n < _size; n++)
    sum ^= this_blocks[n] & other_blocks[n];

  #if defined(_OPENMP) && defined(TARGET)
    }
  #endif

  return utils->count_ones_64(sum) % 2;
}

bool Vector::operator%(Vector const& other) const {
  COMPARAISON_VECTOR_BITWISE_HEADER;
  COMPARAISON_VARIABLE_HEADER;

  unsigned int sum = 0;

  int16_t i;
  #if defined(_OPENMP) && defined(TARGET)
    if(_height > GPU_LIMIT) {
      #pragma omp target teams distribute parallel for reduction(^ : sum) map(tofrom:sum)
      for (i = 0; i < _height; i++)
        sum ^= this_blocks[i] & other_blocks[i];
    } else {
  #endif

  _OPENMP_PRAGMA("omp parallel for reduction(^ : sum) schedule(static) if(_height > CPU_LIMIT)")
  for (i = 0; i < _height; i++)
    sum ^= this_blocks[i] & other_blocks[i];

  #if defined(_OPENMP) && defined(TARGET)
    }
  #endif

  return utils->count_ones_8(sum) % 2;
}

int Matrix::operator/(Matrix const& other) const {
  COMPARAISON_MATRIX_BITWISE_HEADER;
  COMPARAISON_VARIABLE_HEADER;

  int sum = 0;

  int16_t n;
  #if defined(_OPENMP) && defined(TARGET)
    if(_size > GPU_LIMIT) {
      #pragma omp target teams distribute parallel for reduction(+ : sum) map(tofrom:sum)
      for (n = 0; n < _size; n++)
        sum += utils->count_ones_64(this_blocks[n] & other_blocks[n]);
    } else {
  #endif

  _OPENMP_PRAGMA("omp parallel for reduction(+ : sum) schedule(static) if(_size > CPU_LIMIT)")
  for (n = 0; n < _size; n++)
    sum += utils->count_ones_64(this_blocks[n] & other_blocks[n]);

  #if defined(_OPENMP) && defined(TARGET)
    }
  #endif

  return sum;
}

int Vector::operator/(Vector const& other) const {
  COMPARAISON_VECTOR_BITWISE_HEADER;
  COMPARAISON_VARIABLE_HEADER;

  int sum = 0;

  int16_t i;
  #if defined(_OPENMP) && defined(TARGET)
    if(_height > GPU_LIMIT) {
      #pragma omp target teams distribute parallel for reduction(+ : sum) map(tofrom:sum)
      for (i = 0; i < _height; i++)
        sum += utils->count_ones_8(this_blocks[i] & other_blocks[i]);
    } else {
  #endif

  _OPENMP_PRAGMA("omp parallel for reduction(+ : sum) schedule(static) if(_height > CPU_LIMIT)")
  for (i = 0; i < _height; i++)
    sum += utils->count_ones_8(this_blocks[i] & other_blocks[i]);

  #if defined(_OPENMP) && defined(TARGET)
    }
  #endif

  return sum;
}
