#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, i, j, l, r, ans;
    scanf("%d", &n);
    int arr[n];
    for(i=0; i<n; i++) scanf("%d", &arr[i]);
    int B[n][int(log2(n))+3];
    for(i=0; i<n; i++) B[i][0]=i;
    for(j=1; (1<<j)<=n; j++){
        for(i=0; i<n; i++){
            if(arr[B[i][j-1]]>arr[B[min(i+(1<<(j-1)), n-1)][j-1]])
                B[i][j]=B[i][j-1];
            else
                B[i][j]=B[min(i+(1<<(j-1)), n-1)][j-1];
        }
    }
    while(1){
        printf("\nEnter the indices: \n");
        scanf("%d %d", &l, &r);
        for(j=0; (1<<j)<=r-l+1; j++){}
        j--;
        if(arr[B[l][j]]>arr[B[r+1-(1<<j)][j]])
            ans=arr[B[l][j]];
        else
            ans=arr[B[r+1-(1<<j)][j]];
        printf("\nMax. value = %d", ans);
    }
}
