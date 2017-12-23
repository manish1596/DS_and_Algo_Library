#include <iostream>
using namespace std;

void binary_s(int a[], int p, int q, int key)
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
            if(a[p]==key)
            {
                cout << "The key found at index " << p;
                check=true;
            }
            if(check==false)
            {
                cout << "Key not found";
                cout << "\nElement just greater than the key = " << a[p];
            }
        }

}

int main()
{
    int n, key;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cout << "Enter the key: ";
    cin >> key;
    binary_s(arr, 0, n-1, key);
    return 0;
}
