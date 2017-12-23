#include <iostream>
#include <algorithm>
using namespace std;

int partitio_n(int x[], int lb, int ub)
{
    int up, down;
    down=lb;
    up=ub;
    while(up>=down)
    {
        if(x[down]<=x[lb])
            down++;
        if(x[up]>=x[lb])
            up--;
        if(down<up)
        {
            swap(x[down], x[up]);
        }
    }
    swap(x[lb], x[up]);
    return up;
}

void quicksort(int a[],int n, int lb, int ub)
{
    if(lb<ub)
    {
        int temp;
    temp=partitio_n(a, lb, ub);
        quicksort(a, n, lb, temp-1);
    //for(int i=0;i<n;i++)
      //  cout << a[i] << " ";
    quicksort(a, n, temp+1, ub);}
    //for(int i=0;i<n;i++)
       // cout << a[i] << " ";}
    else{}
    //cout << "\n";
}

int main()
{
    int n, i, temp;
    cin >> n;
    int a[n];
    for(i=0;i<n;i++)
        cin >> a[i];
    quicksort(a, n, 0, n-1);
    for(i=0;i<n;i++)
        cout << a[i] << " ";
    return 0;
}
