#include <iostream>
#include "Matrix.h"

using namespace std;

/*
 * 
 */
int main() {
    Matrix a(2,2);
    a.at(0,0)=1;
    a.at(0,1)=2;
    a.at(1,0)=1;
    a.at(1,1)=3;
    cout<<"Matrix a"<<endl;
    for (uint y =0; y < a.numRows(); y++){
        for(uint x = 0; x < a.numCols(); x++){
            cout << a.values[y][x]<< " ";
        }
        cout << endl;
    }
    
    cout<<endl;
    cout<<"Matrix b"<<endl;
    Matrix b(2,1);
    b.at(0,0)=3;
    b.at(1,0)=2;
    for (uint y =0; y < b.numRows(); y++){
        for(uint x = 0; x < b.numCols(); x++){
            cout << b.values[y][x]<< " ";
        }
        cout << endl;
    }
    cout<<endl;
    cout<<"Matrix c = Matrix a + 2"<<endl;
    Matrix c(a.add(2));
    for (uint y =0; y < c.numRows(); y++){
        for(uint x = 0; x < c.numCols(); x++){
            cout << c.values[y][x]<< " ";
        }
        cout << endl;
    }
    
    cout<<endl;
    cout<<"Matrix d = Matrix a + Matrix c"<<endl;
    Matrix d(a.add(c));
    for (uint y =0; y < d.numRows(); y++){
        for(uint x = 0; x < d.numCols(); x++){
            cout << d.values[y][x]<< " ";
        }
        cout << endl;
    }
    
    cout<<endl;
    cout<<"Matrix e = Matrix a - 2"<<endl;
    Matrix e (a.subtract(2));
    for (uint y =0; y <  e.numRows(); y++){
        for(uint x = 0; x <  e.numCols(); x++){
            cout <<  e.values[y][x]<< " ";
        }
        cout << endl;
    }
    
    cout<<endl;
    cout<<"Matrix f = Matrix a - c"<<endl;
    Matrix  f(a.subtract(c));
    for (uint y =0; y <  f.numRows(); y++){
        for(uint x = 0; x <  f.numCols(); x++){
            cout <<  f.values[y][x]<< " ";
        }
        cout << endl;
    }
    
    cout<<endl;
    cout<<"Matrix g = Matrix f * 2"<<endl;
    Matrix g( f.multiply(2));
    for (uint y =0; y <  f.numRows(); y++){
        for(uint x = 0; x <  f.numCols(); x++){
            cout <<  g.values[y][x]<< " ";
        }
        cout << endl;
    }
    
    cout<<endl;
    cout<<"Transverse of d"<<endl;
    Matrix  h(d.t());
    for (uint y =0; y < d.numRows(); y++){
        for(uint x = 0; x < d.numCols(); x++){
            cout <<  h.values[y][x]<< " ";
        }
        cout << endl;
    }
    
    cout<<endl;
    cout<<"Matrix i = Matrix c * d"<<endl;
    Matrix  i(c.multiply(d));
    for (uint y =0; y <  i.numRows(); y++){
        for(uint x = 0; x <  i.numCols(); x++){
            cout <<  i.values[y][x]<< " ";
        }
        cout << endl;
    }
    
    cout<<endl;
    cout<<"Matrix j = Matrix c / 2"<<endl;
    Matrix  j(c.divide(2));
    for (uint y =0; y < c.numRows(); y++){
        for(uint x = 0; x < c.numCols(); x++){
            cout <<  j.values[y][x]<< " ";
        }
        cout << endl;
    }
    Matrix a1 = j + 2;
    cout<<endl;
    cout<<"Matrix a1 = Matrix j + 2"<<endl;
    for (uint y =0; y < a1.numRows(); y++){
        for(uint x = 0; x < a1.numCols(); x++){
            cout <<  a1.values[y][x]<< " ";
        }
        cout << endl;
    }
    
    Matrix a2 = a1 + a1;
    cout<<endl;
    cout<<"Matrix a2 = Matrix a1 + a1"<<endl;
    cout<<a2;
    
    Matrix a3 = a2 - 1;
    cout<<endl;
    cout<<"Matrix a3 = Matrix a2 - 1"<<endl;
    cout<<a3;
    
    Matrix a4 = a2-a1;
    cout<<endl;
    cout<<"Matrix a4 = Matrix a2 - a1"<<endl;
    cout<<a4;
    
    Matrix a5 = a4*2;
    cout<<endl;
    cout<<"Matrix a5 = Matrix a4 * 2"<<endl;
    cout<<a5;
    
    Matrix a6 = a5*a5;
    cout<<endl;
    cout<<"Matrix a5 = Matrix a5 * a5"<<endl;
    cout<<a6;
    
    Matrix a7 = a6/2;
    cout<<endl;
    cout<<"Matrix a7 = Matrix a6 / 2"<<endl;
    cout<<a7;
    
    Matrix a8 = a7;
    cout<<endl;
    cout<<"Matrix a8"<<endl;
    cout<<a8;
    
    Matrix z(2,2);
    z.at(0,0) = 1;
    z.at(0,1) = 2;
    z.at(1,0) = 3;
    z.at(1,1) = 4;
    cout<<endl;
    cout<<"Matrix z"<<endl;
    cout<<z;
    
    Matrix z0 = 4.0 + z;
    cout<<endl;
    cout<<"z0 = 4 + z"<<endl;
    cout<<z0;
    
    Matrix z1 = 4.0 - z;
    cout<<endl;
    cout<<"z1 = 4 - z"<<endl;
    cout<<z1;
    
    Matrix z2 = 2.0 * z;
    cout<<endl;
    cout<<"z2 = 2 * z"<<endl;
    cout<<z2;
    
    Matrix z3 = 12.0 / z;
    cout<<endl;
    cout<<"z3 = 12 / z"<<endl;
    cout<<z3;
}

