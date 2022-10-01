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