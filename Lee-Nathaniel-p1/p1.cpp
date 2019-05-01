
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
}
