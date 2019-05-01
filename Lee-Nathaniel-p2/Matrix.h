#ifndef Matrix_h
#define Matrix_h

#include <iostream>


using namespace std;
typedef unsigned int uint;

class Matrix {

 public:

  Matrix(uint rows, uint cols);                 // constructor (all elements initialized to 0)
  Matrix(const Matrix & m);                     // copy constructor
  ~Matrix();                                    // destructor

  Matrix add(double s) const;                   // add scalar to this matrix
  Matrix add(const Matrix & m) const;           // add this matrix and another matrix

  Matrix subtract(double s) const;              // subtract scalar from this matrix
  Matrix subtract(const Matrix & m) const;      // subtract another matrix from this matrix

  Matrix multiply(double s) const;              // multiply this matrix by a scaler
  Matrix multiply(const Matrix & m) const;      // multiply this matrix by another matrix

  Matrix divide(double s) const;                // divide this matrix by a scaler
  Matrix t() const;                             // transpose of this matrix
  
   /**
   *Project 2 operator overloading code portion. ex. this is meant to replace "/" with the divide function
   *specified in the Matrix class
   */
  Matrix operator+(double s) const;
  Matrix operator+(const Matrix & m) const;
  Matrix operator-(double s) const;
  Matrix operator-(const Matrix & m) const;
  Matrix operator*(double s) const;
  Matrix operator*(const Matrix & m) const;
  Matrix operator/(double s) const;
  Matrix operator=(const Matrix & m) const;
  Matrix operator=(const Matrix & m);
  
  


  const uint numRows() const;                   // returns the number of rows
  const uint numCols() const;                   // returns the number of cols

  double & at(uint row, uint col);              // get/set element at row,col
  const double & at (uint row, uint col) const; // get element at row,col (when using a const object)
  


public:
    double ** values;  
private:
    uint rowLength, colLength;
      
}; // Matrix
ostream & operator << (ostream & out, const Matrix & matrix);
Matrix operator+(double s, Matrix m);
Matrix operator-(double s, Matrix m);
Matrix operator*(double s, Matrix m);
Matrix operator/(double s, Matrix m);
#endif

