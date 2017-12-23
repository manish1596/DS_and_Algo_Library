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

void merge_sort(int b[], int p, int q)
{
    int mid;
    mid=(p+q)/2;
    if(p<q)
    {
        merge_sort(b, p, mid);
        merge_sort(b, mid+1, q);
    }
    merg_e(b, p, mid, q);

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
    merge_sort(arr,0,n-1);
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
