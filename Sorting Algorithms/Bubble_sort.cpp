#include <iostream>
#include <algorithm>
using namespace std;

void bubblesort(int a[], int n)
{
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=n-1; j>i; j--)
        {
            if(a[j]<a[j-1])
                swap(a[j], a[j-1]);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    bubblesort(arr, n);
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    return 0;
}
