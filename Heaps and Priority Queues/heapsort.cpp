#include <iostream>
#include <algorithm>
using namespace std;

int arr_max(int arr[], int a, int r, int l)
{
    if(arr[a]>arr[r]&&arr[a]>arr[l])
        return a;
    else if(arr[r]>arr[l])
        return r;
    else
        return l;
}

void max_heapify(int arr[], int heapsize, int a)
{
    int r, l, largest;
    l=2*a+1;
    r=2*a+2;
    if(r<=heapsize-1)
    {
        largest=arr_max(arr, a, r, l);
        if(largest!=a)
        {
            if(largest==r)
            {
                swap(arr[a], arr[r]);
                max_heapify(arr, heapsize, r);
            }
            else
            {
                swap(arr[a], arr[l]);
                max_heapify(arr, heapsize, l);
            }
        }
    }
    else if(l==heapsize-1)
    {
        if(arr[a]<arr[l])
            swap(arr[a], arr[l]);
    }
}

void build_max_heap(int arr[], int n, int heapsize)       //Here, n is the immediate larger power of 2(just greater than size of the array) minus 1 and heapsize is the size of the array
{
    int i;
    for(i=(n/2)-1; i>=0; i--)
    {
        max_heapify(arr, heapsize, i);
    }
}

void heapsort(int arr[], int n)
{
    int j, p;
    p=1;
    while(p<=n)
        p=p*2;
    //cout << "Value of p=" << p << "\n";
    build_max_heap(arr, p-1, n);
    /*for(int x=0; x<n; x++)
    {
        cout << arr[x] << " ";
    }*/
    for(j=n-1; j>=0; j--)
    {
        swap(arr[0], arr[j]);
        max_heapify(arr, j, 0);
    }
}




int main()
{
    int n, x;
    cin >> n;
    int arr[n];
    cout << "Enter the elements : ";
    for(x=0; x<n; x++)
    {
        cin >> arr[x];
    }
    heapsort(arr, n);
    for(x=0; x<n; x++)
    {
        cout << arr[x] << " ";
    }
}
