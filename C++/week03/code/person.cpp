#include <iostream>
#include <string>
using namespace std;

//Base class : person 
class person
{
private:
    string name;
    bool sex;
    int age;
public:
    person();
    person(const string name_,bool sex_,int age_);
    void display();
    ~person();
};

person::person()
{
}
person::person(const string name_,bool sex_,int age_)
{
    name = name_;
    sex = sex_;
    age = age_;
}
void person::display()
{
    cout << "name: " << name << endl;
    if(sex == 1)
    {
        cout << "sex: " << "male" << endl;
    }
    else
    {
        cout << "sex: " << "femal" << endl;
    }
    cout << "age: " << age << endl;

}
person::~person()
{
}

// Derived class : student
class student : public person
{
private:
    string num;
public:
    student();
    student(const string name_,bool sex_,int age_,const string num_);
    void display();
    ~student();
};

student::student()
{
}
student::student(const string name_,bool sex_,int age_,const string num_) : person(name_,sex_,age_)
{
    num = num_;
}
void student::display()
{
    person::display();
    cout << "num: " << num << endl;
}
student::~student()
{
}

int main()
{
    student stu("shiwenwei",1,20,"20159100018");
    stu.display();
    return 0;
}