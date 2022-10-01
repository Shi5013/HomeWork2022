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

    Block B1(1.0,2.0,3.0);//parameter constructer function
    B1.volume();
    cout << "The B1's volume is:" << endl;
    B1.output();

    Block B2(B1);//"copy" constructer function
    B2.volume();
    cout << "The B2's volume is:" << endl;
    B2.output();
    return 0;
}
