#include <iostream>
using namespace std;
//insertion sort involving recursive approach
void ins(int a[],int n,int key)
{
    int i=n-1;
    while(i>=0&&a[i]>key)
    {
        a[i+1]=a[i];
        i--;
    }
    a[i+1]=key;
}

void sor_t(int a[], int n)
{
    if(n>1)
    {
        sor_t(a, n-1);
        ins(a, n-1, a[n-1]);
    }
    else
        {
        }
}

int main()
{
    int n,a;
    cout << "Enter the number of terms in the array: ";
    cin >> n;
    int arr[n];
    for(a=0; a<n; a++)
        cin >> arr[a];
    sor_t(arr, n);
    for(a=0; a<n; a++)
        cout << arr[a] << " ";
}
