# C++上机实验2
## 一、实验目的

- 掌握类构成和对象的建立
- 掌握构造函数的建立
- 掌握多文件程序编写

## 二、实验内容
1.创建类Block用来描述长方体，私有数据成员length、width、heigth记录长方体的长、宽、高。要求用成员函数实现以下功能：(1)成员函数input用来从键盘分别输入长方体的长宽高； (2)成员函数volume计算长方体的体积； (3)成员函数output输出长方体的体积。
2.在题目一的基础上，为Block类建立构造函数用于初始化，其中包括无参构造函数，有参构造函数，拷贝构造函数。

**代码：**
```c++
//Problem 1 and 2.
#include <iostream>
using namespace std;
class Block
{
    private:
        float length;
        float width;
        float height;
    public:
        float V;
        void input()
        {
            cin >> length >> width >> height;
        }
        void volume()
        {
            V = length*width*height;
        }
        void output()
        {
            cout << V << endl ;
        }
        Block()//No parameter
        {
            length = 0.0;
            width = 0.0;
            height = 0.0;
        }
        Block(float l_,float w_,float h_)//parameter
        {
            length = l_;
            width = w_;
            height = h_;
        }
};

int main()
{
    Block B;
    B.input();
    B.volume();
    cout << "Volume output" << endl;
    B.output();  

    Block B1(1.0,2.0,3.0);
    //parameter constructer function
    B1.volume();
    cout << "The B1's volume is:" << endl;
    B1.output();  

    Block B2(B1);//"copy" constructer function
    B2.volume();
    cout << "The B2's volume is:" << endl;
    B2.output();
    return 0;
}
```
**运行结果：**
![[Pasted image 20220924113709.png]]
3.创建一个复数类complex，私有成员包括实部real和虚部imag，初始化使用init成员函数，计算幅值使用amplitude成员函数，计算相角用phase成员函数，同时为complex定义加减乘除四则运算add，subtract，multiply，divide四个成员函数。
**代码：**
```c++
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
    void add();
    void subtract();
    void multiply();
    void divide(); 
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
```
**运行结果：**
![[Pasted image 20220924121957.png]]
4.编写一个包含：(1)类定义的头文件student.h；(2)成员函数定义的源文件student.cpp；(3)主函数的源文件main.cpp。student类的私有数据成员包括：学号num，姓名name，性别sex。定义其普通构造函数、拷贝构造函数。并定义成员函数display完成学号，姓名和性别信息的输出。
**代码：**
```c++
//student.h
#ifndef STUDENT_H_
#define STUDENT_H_
#include <string>
class Student
{
private:
   std::string num;
   std::string name;
   bool sex;
public:
    Student();//default constructor
    Student(const std::string &num_,const std::string &name_,bool sex_);
    ~Student();
    void display();
};
#endif
```
```c++
//student.cpp
#include <iostream>
#include "student.h"
Student::Student()
{
    num = "0";
    name = "No one";
    sex = 0;
}
Student::Student(const std::string &num_,const std::string &name_,bool sex_)
{
    num = num_;
    name = name_;
    sex = sex_;
}  
Student::~Student()
{
}  
void Student::display()
{
    using std::cout;
    //cout.precision(0);//keep n decimal,in the mean time avoid Scientific Counting Method
    cout <<
    "Student Number:\n" << num <<
    "\nName:\n" << name <<
    "\nSex:\n" << sex ;
}
```
```c++
//main.cpp
#include <iostream>
#include "student.h"
#include <string>
using namespace std;
int main()
{
    const char * num1 = "20159100018";
    const char * name1 = "shiwenwei" ;
    bool sex = 1;
    Student student1(num1,name1,sex);
    student1.display();
    return 0;
}
```
**运行结果：**
![[Pasted image 20220924170257.png]]
## 三、心得体会
通过本次上机实验，我熟悉了C++类的基本操作以及多文件链接、编译的基本原理。同时，在编写程序的过程中，解决了一系列的小问题，比如输入学号时，刚开始定义num为double型，需要对输出的结果禁止科学计数法表示。最后综合考虑，选择使用字符串表示学号。
