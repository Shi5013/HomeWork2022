#include <iostream>
#include "teachercadre.h"

//Teacher class
Teacher::Teacher(/* args */)
{
}
Teacher::Teacher(const std::string name_,const int age_,const std::string title_)
{
    name = name_;
    age = age_;
    title = title_;
}
void Teacher::display()
{
    std::cout << "The name is: " << name << std::endl;
    std::cout << "The age is: " << age << std::endl;
    std::cout << "The title is: " << title << std::endl;
}
Teacher::~Teacher()
{
}

//Cadre class
Cadre::Cadre()
{
}
Cadre::Cadre(const std::string name_,const int age_,const std::string post_)
{
    name = name_;
    age = age_;
    post = post_;
}
void Cadre::display()
{
    std::cout << "The post is: " << post << std::endl;
}
Cadre::~Cadre()
{
}
//Teacher_Cadre class
Teacher_Cadre::Teacher_Cadre()
{
}
Teacher_Cadre::Teacher_Cadre(const std::string name_,
                    const int age_,
                    const std::string title_,
                    const std::string post_,
                    const float wages_) : 
                    Teacher(name_,age_,title_),
                    Cadre(name_,age_,post_)
{
    wages = wages_;
}
void Teacher_Cadre::show()
{
    Teacher::display();//这里应该会重复输出吧
    Cadre::display();
    std::cout << "The wages is: " << wages << std::endl;
}
Teacher_Cadre::~Teacher_Cadre()
{
}
