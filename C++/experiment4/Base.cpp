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
    Base * basept =  & base;
    basept->print();

    BaseA basea;
    Base *baseapt = & basea;
    baseapt->print();

    BaseB baseb;
    Base *basebpt = & baseb;
    basebpt->print();
    return 0;
}