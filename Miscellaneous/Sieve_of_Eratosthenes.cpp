#include <iostream>
using namespace std;

int* sieve(int n,int arr[1000])
{
    for(int j=2; j*j<=n; j++)
        {
            if(arr[j-1]==0)
            {
                for(int k=j*j;k<=n;k=k+j)
                {
                    arr[k-1]=1;
                }
            }
        }
        return arr;
}

int main()
{
    int n,c;
    c=0;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        arr[i]=0;
    int* p=sieve(n, arr);
    for(int a=1;a<n;a++)
    {
        if(*(p+a)==0)
           {
            cout << a+1 << "\n";
            c=c+1;
            }
    }
    cout << c;
    return 0;
}
