#include<stdio.h>

void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int a[],int first,int last)
{
    int i=first+1,j=first+1;
    for(i;i<=last;i++)
    {
        if(a[i]<a[first])
        {
            swap(&a[j],&a[i]);
            j++;
        }
    }
    swap(&a[first],&a[j-1]);
    return j-1;
}
void k_large(int a[],int first,int last,int k)
{
    int piv=partition(a,first,last);
    if(piv==k-1)
        return;
    if(k-1<piv)
        k_large(a,first,piv-1,k);
    else
        k_large(a,piv+1,last,k);

}

int main()
{int a[1000],n,i,ch=1,k;
printf("enter n\n");
scanf("%d",&n);
printf("enter elements\n");
 for(i=0;i<n;i++)
    {scanf("%d",&a[i]);}
 printf("\n");
 while(ch==1)
 {
     printf("\nenter k :\n");
     scanf("%d",&k);
     k_large(a,0,n-1,k);
     printf("kth largest element is : %d\n",a[k-1]);
     printf("enter 0 to discontinue.\n");
     scanf("%d",&ch);
 }
  return 0;
}
