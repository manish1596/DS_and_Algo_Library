#include <iostream>
using namespace std;

void sor_t(int a[], int n)
{
    int i,j;
    int temp;
    for(j=1; j<n; j++)
    {
        temp=a[j];
        i=j-1;
        while(i>=0&&a[i]>temp)
        {
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=temp;
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
    return 0;
}
