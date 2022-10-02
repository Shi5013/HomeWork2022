#ifndef TEACHERCADRE_H_
#define TEACHERCADRE_H_

#include <string>
//Teacher class
class Teacher
{
private:
    std::string name;
    int age;
    std::string title;
public:
    Teacher(/* args */);
    Teacher(const std::string name_,const int age_,const std::string title_);
    void display();
    ~Teacher();
};
//Cadre class
class Cadre
{
private:
    std::string name;
    int age;
    std::string post;
public:
    Cadre();
    Cadre(const std::string name_,const int age_,const std::string post_);
    void display();
    ~Cadre();
};
// Teacher_Cadre class
class Teacher_Cadre:public Teacher,public Cadre
{
private:
    float wages;
public:
    Teacher_Cadre();
    Teacher_Cadre(const std::string name_,
                    const int age_,
                    const std::string title_,
                    const std::string post_,
                    const float wages_);
    void show();
    ~Teacher_Cadre();
};

#endif