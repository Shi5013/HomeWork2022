#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    vector<string> msg {"Hello","C++","World","!"};
    for (const string& word :msg)
    {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}
