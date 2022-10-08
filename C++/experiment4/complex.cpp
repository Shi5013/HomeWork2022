#include <iostream>
#include <math.h>
using namespace std;

class Complex
{
private:
    float real;
    float imag;
public:
    void init();
    friend Complex operator+(Complex other1,Complex other2);
    Complex operator*(Complex other);
    void show();
};

void Complex::init()
{
    cin >> real >> imag;
}
Complex operator+(Complex other1,Complex other2)
{
    Complex result;
    result.real = other2.real + other1.real;
    result.imag = other2.imag + other1.imag;
    return result;  
}
Complex Complex::operator*(Complex other)
{
    Complex result;
    result.real = (real*(other.real))-(imag*(other.imag));
    result.imag = (real*(other.imag))+(imag*(other.real));
    return result;
}
void Complex::show()
{
    if(imag < 0)
    {
        cout << real << imag << "i" <<endl;
    }
    else
    {
        cout << real << "+" << imag << "i" <<endl;
    }
}

int main()
{
    Complex c1;
    c1.init();
    Complex c2;
    c2.init();
    Complex c3;
    c3 = c1+c2;
    cout << "The add's result: " ;
    c3.show();
    Complex c4;
    c4 = c1*c2;
    cout << "The mul's result: " ;
    c4.show();
    return 0;
}