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