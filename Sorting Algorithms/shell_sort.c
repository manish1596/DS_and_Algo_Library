#include<stdio.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void printer(int a[],int n)
{
    int i;
     printf("\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]); printf("\n");

}

void shell_sort(int a[],int n)
{
    int i=0,j,k,h;
    for(h=n/2;h>=1;h/=2)
    {
        for(i=h;i<n;i++)
        {

          for(j=i;j-h>=0;j-=h)
          {
              if(a[j]<a[j-h])
                swap(&a[j],&a[j-h]);
              else
                break;
          }


        }
        printer(a,n);
    }
}


int main()
{
    int a[1000],i,n;
    printf("ENTER NO. OF NUMBERS\n");
    scanf("%d",&n);
    printf("ENTER NOS. FOR SORT.\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    shell_sort(a,n);
    printf("\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}

