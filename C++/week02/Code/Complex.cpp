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
    void amplitude();
    void phase();
};

void Complex::init()
{
    cin >> real >> imag;
}
void Complex::amplitude()
{
    float amplitude;
    amplitude = sqrt(real*real + imag*imag);
    cout << "The amplitude of complex is:" << amplitude << endl;
}
void Complex::phase()
{
    float phase;
    phase = atan(imag/real);
    cout << "The phase of complex is:" << phase <<endl;
}


int main()
{
    Complex c;
    c.init();
    c.amplitude();
    c.phase();
    return 0;
}