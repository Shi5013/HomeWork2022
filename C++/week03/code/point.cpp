#include <iostream>

using namespace std;
// Base class:point
class point
{
private:
    float x;
    float y;
public:
    point();
    point(float a, float b);
    void get_point();
    ~point();
};

void point::get_point()
{
    cout << "(" << x << "," << y << ")"<< endl;
}
point::point()
{
    this->x = 0.0;
    this->y = 0.0;
}
point::point(const float a, const float b) : x(a) , y(b) {}
point::~point()
{
}

//Derived class circle
class circle : public point
{
private:
    float r;
public:
    circle(float a1,float b1,float c1);
    void get_circle();
    ~circle();
};

circle::circle(float a1 = 0.0 ,float b1 = 0.0 ,float c1 = 0.0) : point(b1,c1)
{
    r = a1;
}
void circle::get_circle()
{
    cout << r << endl;
}
circle::~circle()
{
}

int main()
{
    float rr = 0.0;
    float xx = 0.0;
    float yy = 0.0;
    cout <<"Please input the point of circle:" << endl;
    cin >> xx >> yy;
    cout <<"Please input the r of circle:" << endl;
    cin >> rr;
    circle c(rr,xx,yy);
    cout << "The point of circle is:" << endl;
    c.get_point();
    cout <<"The r of circle is:" << endl;
    c.get_circle();
    return 0;
}
