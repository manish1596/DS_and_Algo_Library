#include <iostream>
using namespace std;

void merg_e(int a[], int p, int q, int r)
{
    int i,j,k;
    j=0;
    k=0;
    int l[q-p+1];
    int m[r-q];
    for(i=0; i<q-p+1; i++)
        l[i]=a[p+i];

    for(i=0; i<r-q; i++)
        m[i]=a[q+1+i];
if(r>p)
    {
        for(i=0;i<r-p+1;i++)
        {
        if(j>=q-p+1)
        {
            a[p+i]=m[k];
            k++;
            continue;
        }
        if(k>=r-q)
        {
            a[p+i]=l[j];
            j++;
            continue;
        }
        if(l[j]<=m[k])
        {
            a[p+i]=l[j];
            j++;
        }
        else
        {
            a[p+i]=m[k];
            k++;
        }
        }
    }
}

void iter_merge_sort(int* arr, int n)
{
    int mid, left_start, right_end;
    int curr_size;
    for(curr_size=1; curr_size<=n-1; curr_size*=2)
    {
        for(left_start=0; left_start+curr_size-1<n-1; left_start+=2*curr_size)
        {
            mid=left_start+curr_size-1;
            right_end=min(left_start+2*curr_size-1, n-1);
            merg_e(arr, left_start, mid, right_end);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    iter_merge_sort(arr,n);
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
