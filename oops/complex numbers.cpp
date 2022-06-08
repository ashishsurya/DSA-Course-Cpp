#include <iostream>
using namespace std;

class ComplexNumbers {
    // Complete this class
    
    public:
    	int real;
    	int imaginary;
    
    public : 
    
    	ComplexNumbers(int x, int y) {
            this->real = x;
            this->imaginary = y;
        }
    
    	
    	void add(ComplexNumbers c) {
         	 real += c.real;
            imaginary += c.imaginary;
        }


      void multiply(ComplexNumbers c) {
        real = real * c.real - imaginary * c.imaginary;
        imaginary = real * c.imaginary + imaginary * c.real;
      }

      void print() {
        cout << real << " + i" << imaginary;
      }
};


int main() {
    int real1, imaginary1, real2, imaginary2;
    
    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;
    
    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    c1.add(c2);

    cout << c1.real << " " << c1.imaginary << endl;

    c1.multiply(c2);
    cout << c1.real << " " << c1.imaginary << endl;

    c1.print();
    return 0;
}