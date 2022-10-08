#include <iostream>

using namespace std;

class Shape
{
private:
    /* data */
public:
    Shape(/* args */);
    ~Shape();
};

Shape::Shape(/* args */)
{
}

Shape::~Shape()
{
}

class Circle : public Shape
{
private:
    float r;
public:
    Circle(/* args */);
    Circle(float r_);
    virtual float area();
    ~Circle();
};
Circle::Circle(/* args */)
{
}
Circle::Circle(float r_)
{
    this->r = r_;
}
float Circle::area()
{
    return 3.14*r*r;
}
Circle::~Circle()
{
}

class Rectangle :public Shape
{
private:
    float length;
    float width;
public:
    Rectangle(/* args */);
    Rectangle(float l , float w);
    virtual float area();
    ~Rectangle();
};

Rectangle::Rectangle(/* args */)
{
}
Rectangle::Rectangle(float l , float w)
{
    this->length = l;
    this->width = w;
}
float Rectangle::area()
{
    return length*width;
}
Rectangle::~Rectangle()
{
}

class Triangle : public Shape
{
private:
    float height;
    float bottom;
public:
    Triangle(/* args */);
    Triangle(float h,float b);
    virtual float area(){return 0.5*height*bottom;}
    ~Triangle();
};

Triangle::Triangle(/* args */)
{
}
Triangle::Triangle(float h,float b)
{
    this->height = h;
    this->bottom = b;
}
Triangle::~Triangle()
{
}


int main()
{
    Circle cir(2.5);
    float cir1 = cir.area();
    cout << cir1 << endl;

    Rectangle rec(3.0,4.0);
    float rec1 = rec.area();
    cout << rec1 << endl;

    Triangle tri(2.0,1.0);
    float tri1 = tri.area();
    cout << tri1 << endl;
    
    cout << "The sum:" << cir1+rec1+tri1 << endl;
    return 0;
}