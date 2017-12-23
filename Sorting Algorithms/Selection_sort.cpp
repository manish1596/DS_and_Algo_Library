#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
    int temp=a;
    a=b;
    b=temp;
}
void selection_sort(int n, int arr[])
{
    int i, temp, smallest_index;
    for(i=0; i<n; i++)
    {
        smallest_index=i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[smallest_index]>arr[j])
            {
               smallest_index=j;
            }
        }
        swap(arr[smallest_index],arr[i]);
    }
    cout << "\n";
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    selection_sort(n,arr);
    for(int i=0; i<n; i++)
        cout << arr[i]<<" ";
    return 0;
}


