#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


long partitio_n(long x[], long y[], long lb, long ub)
{
    long up, down;
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
            swap(y[down], y[up]);
        }
    }
    swap(x[lb], x[up]);
    swap(y[lb], y[up]);
    return up;
}

long elemat(long** a, long x, long y){
if(x>=0 && y>=0)
    return a[x][y];
else
    return 0;
}

void quicksort(long a[], long b[], long n, long lb, long ub)
{
    int i;
    if(lb<ub)
    {
        long temp;
    temp=partitio_n(a, b, lb, ub);
        quicksort(a, b, n, lb, temp-1);
    //for(long i=0;i<n;i++)
      //  cout << a[i] << " ";
    quicksort(a, b, n, temp+1, ub);}
    //for(long i=0;i<n;i++)
       // cout << a[i] << " ";}
    else{}

    //cout << "\n";
}

int main() {

    long N, K, i, j, temp;
    long cost[101];
    long Q[101];
    long** rec;
    cin >> N >> K;
    K=K+1;
    for(i=0; i<N; i++){
        cin >> temp;
        cost[i]=temp;
    }
    for(i=0; i<N; i++){
        cin >> temp;
        Q[i]=temp;
    }
    rec=new long*[N];
    for(i=0; i<N; i++){
        rec[i]=new long[K];
    }

    //cout << "Size should be same as N " << N << " " << cost.size() << " " << Q.size() << "\n";

    quicksort(cost, Q, N, 0, N-1);

    //for(i=0; i<N; i++){
        //cout << cost[i] << "---" << Q[i] << "\n";
    //}
    for(i=0; i<N; i++)
        rec[i][0]=1;
    for(i=0; i<N; i++){
        for(j=1; j<K; j++){
            temp=elemat(rec, i-1, j)+elemat(rec, i, j-cost[i])-elemat(rec, i, j-(Q[i]+1)*cost[i]) ;
            if(temp>=0){
                rec[i][j]=temp;
            }
            else{
                rec[i][j]=0;
            }
        }
    }
    cout << rec[N-1][K-1];
    return 0;
}
