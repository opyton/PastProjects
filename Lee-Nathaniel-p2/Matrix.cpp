#include "Matrix.h"
#include <iostream>

using namespace std;
typedef unsigned int uint;
/**
 * Matrix initializing constructor. This will create a matrix with the specified
 * size initialized at 0 for all values;
 * 
 * @param rows  
 * @param cols
 */
Matrix::Matrix(uint rows, uint cols){
   //** that will hold reference to ptr to 1d matrix
    rowLength = rows; colLength = cols;
    values = new double * [rowLength];
    for (uint rowAmt = 0; rowAmt < rows; rowAmt++){
        values[rowAmt] = new double[colLength];
    }
}

/**
 * Creates a copy of the matrix
 * 
 * @param   m   matrix to be copied
 */

Matrix::Matrix(const Matrix & m){
    rowLength = m.rowLength;
    colLength = m.colLength;
    values = new double * [rowLength];
    for (uint rowAmt = 0; rowAmt < rowLength; rowAmt++){
        values[rowAmt] = new double[colLength];
    }
    for (uint y =0; y < m.numRows(); y++){
        for(uint x = 0; x < m.numCols(); x++){
            values[y][x]=m.at(y,x);
        }
    
    }
} 


/**
 * Matrix deconstructor 
 * UPDATE: 4/2/18
 * fixed memory leak using for loop deleting *[] stored in **[]
 */
Matrix::~Matrix(){
    for(uint i = 0; i< rowLength;i++){
        delete[] values[i];
    }
     delete [] values;
 }

Matrix Matrix::add(double s) const{
    Matrix temp(rowLength,colLength);
    for (uint y =0; y < Matrix::numRows(); y++){
        for(uint x = 0; x < Matrix::numCols(); x++){
            temp.at(y,x)=(Matrix::at(y,x)+s);
        }
    
    }
    return temp;
}

Matrix Matrix::add(const Matrix & m) const{
    Matrix temp(rowLength,colLength);
    for (uint y =0; y < Matrix::numRows(); y++){
        for(uint x = 0; x < Matrix::numCols(); x++){
            temp.at(y,x)=(Matrix::at(y,x)+m.at(y,x));
        }
    
    }
    return temp;
}

Matrix Matrix::subtract(double s) const{
    Matrix temp(rowLength,colLength);
    for (uint y =0; y < Matrix::numRows(); y++){
        for(uint x = 0; x < Matrix::numCols(); x++){
            temp.at(y,x)=(Matrix::at(y,x)-s);
        }
    
    }
    return temp;
}

Matrix Matrix::subtract(const Matrix & m) const{
    Matrix temp(rowLength,colLength);
    for (uint y =0; y < Matrix::numRows(); y++){
        for(uint x = 0; x < Matrix::numCols(); x++){
            temp.at(y,x)=(Matrix::at(y,x)-m.at(y,x));
        }
    
    }
    return temp;
}

Matrix Matrix::multiply(double s) const{
    Matrix temp(rowLength,colLength);
    for (uint y =0; y < Matrix::numRows(); y++){
        for(uint x = 0; x < Matrix::numCols(); x++){
            temp.at(y,x)=(Matrix::at(y,x)*s);
        }
    
    }
    return temp;
}

Matrix Matrix::multiply(const Matrix & m) const{
    Matrix temp(rowLength,m.rowLength);
    for (uint y =0; y < temp.numRows(); y++){
        for(uint x = 0; x < temp.numCols(); x++){
            uint sum = 0;
            for(uint rowVals = 0; rowVals<Matrix::colLength;rowVals++){
                sum+=Matrix::at(y,rowVals)*m.at(rowVals,x);
            }
            temp.at(y,x)=sum;
        }
    
    }
    return temp;
}

Matrix Matrix::t() const{
    Matrix temp(colLength,rowLength);
    for (uint y =0; y < Matrix::numRows(); y++){
        for(uint x = 0; x < Matrix::numCols(); x++){
            temp.at(x,y)=Matrix::at(y,x);
        }
    }
    return temp;
}   

Matrix Matrix::divide(double s) const{
    Matrix temp(rowLength,colLength);
    for (uint y =0; y < Matrix::numRows(); y++){
        for(uint x = 0; x < Matrix::numCols(); x++){
            temp.at(y,x)=(Matrix::at(y,x)/s);
        }
    
    }
    return temp;
}

Matrix Matrix::operator+(const double s) const{
   return Matrix::add(s);
}
Matrix Matrix::operator+(const Matrix & m)const {
    return Matrix::add(m);
}
Matrix Matrix::operator-(const double s) const{
   return Matrix::subtract(s);  
}
Matrix Matrix::operator-(const Matrix & m)const {
    return Matrix::subtract(m);
}
Matrix Matrix::operator*(const double s) const{
   return Matrix::multiply(s);  
}
Matrix Matrix::operator*(const Matrix & m)const {
    return Matrix::multiply(m);
}
Matrix Matrix::operator/(const double s) const{
   return Matrix::divide(s);  
}
Matrix Matrix::operator=(const Matrix & m){
    return Matrix(m);
}

Matrix operator+(double s, Matrix m){
    return m.add(s);
}
Matrix operator-(double s, Matrix m){
    return m.subtract(s);
}
Matrix operator*(double s, Matrix m){
    return m.multiply(s);
}
Matrix operator/(double s, Matrix m){
   Matrix temp(m.numRows(),m.numCols());
    for (uint y =0; y < m.numRows(); y++){
        for(uint x = 0; x < m.numCols(); x++){
            temp.at(y,x)=(s/m.at(y,x));
        }
    
    }
    return temp;
}


ostream & operator << (ostream & out, const Matrix & matrix){
    for(uint y =0; y < matrix.numRows();y++){
        out << "[";
        for(uint x = 0; x < matrix.numCols(); x++){
            out<<" ";
            out<<matrix.values[y][x];
        }
        out <<" ]";
        cout<<endl;
    }
return out;
}


const uint Matrix::numRows() const{
    return rowLength;
}              
const uint Matrix::numCols() const{
    return colLength;
}                

double & Matrix::at(uint row, uint col){
    return values[row][col];
}             
const double & Matrix::at (uint row, uint col) const{
    return values[row][col];
}

