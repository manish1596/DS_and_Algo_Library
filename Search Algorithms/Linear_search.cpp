#include <iostream>
using namespace std;

int main()
{
    int i,n, key;
    bool check=false;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the key.";
    cin>>key;
    for(i=0; i<n; i++)
    {
        if(key==arr[i])
        {
            cout << "Key found at index " << i;
            check=true;

        }
    }
    if(check==false)
        cout << "Key not found.";
    return 0;
}
