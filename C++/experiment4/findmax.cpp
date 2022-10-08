#include<iostream>

using namespace std;

template<typename T>              
T findmax(T* arr,T n)                       
{
   int j=0;
   for(int i=1;i<n;i++)
   {
       if(arr[i]>arr[j])
           j=i;
   }
       cout<<arr[j]<<endl;
       return  arr[j];
};

int main()
{
   int a[]={1,2,8,3,5,9,4};                           
   double b[]={1.23,2.24,3.21,6.1,2.3};    

   cout<<"amax:";
   findmax(a,7);

   cout<<"bmax:";
   findmax(b,5.0);
   return 0;
}



