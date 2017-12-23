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

void itermerge_sort(int a[], int n)
{
    int j;
    int i=1;
    while(i<=n/2)
    {
       j=0;
       while(j+(2*i)<=n)
       {
           merg_e(a, j, j+i-1, j+(2*i)-1);
           j+=2*i;
           //cout << "j*" << j << " ";
       }
           //j=j-(2*i);
       //cout << "j**" << j << "\n";
       //if((n-1-j)>i)
       {

           merg_e(a, j, j+i-1, n-1);
       }
       for(int k=0; k<n; k++)
       {
           //cout << a[k] << " ";
       }
       cout << "\n";
       i*=2;
       //cout << "*i" << i << " ";
    }
    merg_e(a, 0, i-1, n-1);
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
    itermerge_sort(arr,n);
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
