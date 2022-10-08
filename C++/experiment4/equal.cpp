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