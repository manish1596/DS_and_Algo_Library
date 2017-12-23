#include <stdio.h>

int search(int a[], int size, int key)
{
    int i;
    for(i=0; i<=size; i++)
    {
        if(key==a[i])
            return 1;
    }
    return 0;
}

void sum(int a[], int size, int n)
{
    int s, i, max;
    for(i=0; i<=size; i++)
    {
        if(max<a[i])
            max=a[i];
    }
    int f[100]={0};
    i=0;
    while(i<=size)
    {if(f[a[i]]==0)
        {if(search(a,size,(n-a[i]))==1)
        {
            if(a[i]!=n-a[i])
            {printf("%d %d , ", a[i], n-a[i]);}
            else{
                for(s=i+1; s<=size; s++)
                {if(a[s]==a[i])
                printf("%d %d , ", a[i], n-a[i]);}
            }
            f[a[i]]=1;
            f[n-a[i]]=1;

        }}
    i++;
    }
}

void checksum(char a[], int n)
{
    int arr[200]={0};
    int s=0,len=0;
    while(a[len]!='\0')
        len++;
    int i, j, max, num, size;
    int pow=1;
    for(i=len-1,j=0; i>=0; i--,j++)
    {
        num=0;
        pow=1;
        while(a[i]!=' '&& i>=0)
        {
            num=num+(a[i]-'0')*pow;
            pow *=10;
            i--;
        }
        arr[j]=num;
    }
    j--;
    max=0;
    size=j;
    sum(arr, size, n);
}

void main()
{
    char a[100];
    int n;
    gets(a);
    scanf("%d", &n);
    checksum(a, n);
}
