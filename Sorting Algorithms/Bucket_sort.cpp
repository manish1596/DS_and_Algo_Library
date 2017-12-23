#include <iostream>
using namespace std;

int main()
{
    int n,i,j;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array: ";
    for (i=0; i<n; i++)
        cin >> a[i];
    int max=0;
    for(i=0; i<n; i++)
    {
        if(a[i]>max)
            max=a[i];
    }
    int b[max+1];
    for(i=0; i<max+1; i++)
        b[i]=0;
    for(i=0; i<n; i++)
        b[a[i]]++;
    cout << "Sorted array:" << "\n";
    for(i=0; i<max+1; i++)
    {
        for(j=0; j<b[i]; j++)
            cout << i << " ";
    }
    return 0;
}
