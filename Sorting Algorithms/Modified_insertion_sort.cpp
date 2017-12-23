#include <iostream>
using namespace std;


int binary_s(int a[], int p, int q, int key)
{
    int mid;
    bool check=false;
    if(p<q)
        {
            mid=(p+q)/2;
            if(key<=a[mid])
                binary_s(a, p, mid, key);
            else
                binary_s(a, mid+1, q, key);
        }
    else
        {
            return p;
        }
}

void ins(int a[],int n,int key)
{
    int i=n-1;
    if(key<a[n-1])
    {while(i>=binary_s(a, 0, n-1, key))
    {
        a[i+1]=a[i];
        i--;
    }
    a[i+1]=key;}
    else{}
}

void sor_t(int a[], int n)
{
    if(n>1)
    {
        sor_t(a, n-1);
        ins(a, n-1, a[n-1]);
        /*for(int i=0; i<n; i++)
        {
        cout << a[i] << " ";
        }
        cout << "\n";*/
    }
    else
        {
        }

}

int main()
{
    int n, key;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    sor_t(arr, n);
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
