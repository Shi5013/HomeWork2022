# C++上机实验4
## 一、实验目的
1.了解多态性的概念
2.了解虚函数的作用以及使用方法
3.了解静态关联和动态关联的概念和用法
4.掌握纯虚函数和抽象类的概念和用法
5.掌握运算符重载的概念和用法
6.掌握函数模板和类模板的概念及使用方法
## 二、实验内容
1.设计一个函数模板FindMax,实现对参数类型T定义的数组`a[n]` 查找最大值。

**代码：**
```c++
#include<iostream>

using namespace std;

template<typename T>              
T findmax(T* arr,T n)                      
{
   int j=0;
   for(int i=1;i<n;i++)
   {
       if(arr[i]>arr[j])
           j=i;
   }
       cout<<arr[j]<<endl;
       return  arr[j];
};  
int main()
{
   int a[]={1,2,8,3,5,9,4};                   
   double b[]={1.23,2.24,3.21,6.1,2.3};    
   cout<<"amax:";
   findmax(a,7);  
   cout<<"bmax:";
   findmax(b,5.0);
   return 0;
}
```

**结果：**

![Result 1](https://github.com/Shi5013/HomeWork2022/blob/main/C%2B%2B/experiment4/Pasted%20image%2020221008222204.png)

2.编写一个程序，重载运算符"`==`",用于判断两个N维向量是否相等。

**代码:**

```c++
#include <iostream>
class vector
{
private:
    int length; 
    int *a;
public:
    vector();
    vector(const int n,int *arr);
    bool operator==(const vector & other);
    ~vector();
};
vector::vector()
{
}
vector::vector(const int n, int *arr)
{
    this->length = n;
    this->a = arr;
}
bool vector::operator==(const vector & other)
{
    for(int i = 0;i < length;i++)
    {
       if (this->a[i] == other.a[i])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}
vector::~vector()
{
}
int main()
{
	int ex1[5] = {1,3,3,4,5};
    int ex2[5] = {1,2,3,4,5};
    std::cout << "The first array: " ;
    for (int i = 0; i < 5; i++)
    {
        std::cout << ex1[i] <<" ";
    }
    std::cout << std::endl;
    std::cout << "The second array: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << ex2[i] << " ";
    }
    std::cout << std::endl;
    vector example1(5,ex1);
    vector example2(5,ex2);
    if(example1 == example2){
        std::cout << "equal" << std::endl;
    }
    else
    {
        std::cout << "not equal" << std::endl;
    }
    return 0;
}
```

**运行结果：**

![Result 2](https://github.com/Shi5013/HomeWork2022/blob/main/C%2B%2B/experiment4/Pasted%20image%2020221008222811.png)

3.编写一个复数类complex用友元函数重载运算符"+",对两个复数进行加法操作。
4.编写一个复数类complex，用成员函数重载复合运算符"`*`",对两个复数进行乘法运算。

**代码：**
```c++
//problem3 and 4 in the same file
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
```

**结果：**

![Result 34](https://github.com/Shi5013/HomeWork2022/blob/main/C%2B%2B/experiment4/Pasted%20image%2020221008223247.png)

5.已知有类的定义如下：
```c++
class Base
{public:
 virtual void print(){cout << "Base" << endl;l}
};
```
从Base中派生出两个新的类BaseA 、BaseB，每个类用成员函数Print()来打印自己的类名。在main()函数中创建这些类的对象及指针，通过该指针来调用Print()函数。

**代码：**
```c++
#include <iostream>
using namespace std;
class Base
{
private:
    /* data */
public:
    Base(/* args */);
    virtual void print() {cout << "Base" << endl;}    
    ~Base();
};
Base::Base(/* args */)
{
}
Base::~Base()
{
}  
class BaseA : public Base
{
private:
    /* data */
public:
    BaseA(/* args */);
    virtual void print() {cout << "BaseA" << endl;}
    ~BaseA();
}; 
BaseA::BaseA(/* args */)
{
}
BaseA::~BaseA()
{
}
class BaseB : public Base
{
private:
    /* data */
public:
    BaseB(/* args */);
    virtual void print() {cout << "BaseB" << endl;}
    ~BaseB();
};
BaseB::BaseB(/* args */)
{
}
BaseB::~BaseB()
{
}
int main()
{
    Base base;
    Base * basept =  & base;
    basept->print();
    
    BaseA basea;
    Base *baseapt = & basea;
    baseapt->print();
    
    BaseB baseb;
    Base *basebpt = & baseb;
    basebpt->print();
    return 0;

}
```

**结果：**

![Result 5](https://github.com/Shi5013/HomeWork2022/blob/main/C%2B%2B/experiment4/Pasted%20image%2020221008224824.png)

6.写一个程序，定义抽象基类Shape,它有三个公有派生类：类Circle来描述圆形，类Rectangle来描述矩形，类Triangle来描述三角形。用虚函数area()分别来计算几种图形的面积，并求他们的和。

**代码：**

```c++
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
```

**结果：**

![Result 6](https://github.com/Shi5013/HomeWork2022/blob/main/C%2B%2B/experiment4/Pasted%20image%2020221008224606.png)

## 三、心得体会
通过本次的上机实验，我熟悉了类的继承与虚函数和友元函数，编写了简单的程序进行实践。加深了对C++类的使用的理解。
