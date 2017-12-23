#include <iostream>
using namespace std;

struct list_elem
{
    int list_num;
    int index;
    list_elem operator=(list_elem l1)
    {
        list_num=l1.list_num;
        index=l1.index;
    }
};
void swap(list_elem *l1, list_elem *l2)
{
    list_elem temp=*l1;
    *l1=*l2;
    *l2=temp;
}


int arr_max(list_elem arr[], int **p, int a, int r, int l)
{
    if(p[arr[a].list_num][arr[a].index]>p[arr[r].list_num][arr[r].index]&&p[arr[a].list_num][arr[a].index]>p[arr[l].list_num][arr[l].index])
        return a;
    else if(p[arr[r].list_num][arr[r].index]>p[arr[l].list_num][arr[l].index])
        return r;
    else
        return l;
}

void max_heapify(list_elem arr[], int **p, int heapsize, int a)
{
    int r, l, largest;
    l=2*a+1;
    r=2*a+2;
    if(r<=heapsize-1)
    {
        largest=arr_max(arr, p, a, r, l);
        if(largest!=a)
        {
            if(largest==r)
            {
                swap(&arr[a], &arr[r]);
                max_heapify(arr, p, heapsize, r);
            }
            else
            {
                swap(&arr[a], &arr[l]);
                max_heapify(arr, p, heapsize, l);
            }
        }
    }
    else if(l==heapsize-1)
    {
        if(p[arr[a].list_num][arr[a].index]<p[arr[l].list_num][arr[l].index])
            swap(&arr[a], &arr[l]);
    }
}

void build_max_heap(list_elem arr[], int **p, int n, int heapsize)       //Here, n is the immediate larger power of 2(just greater than size of the array) minus 1 and heapsize is the size of the array
{
    int i;
    for(i=(n/2)-1; i>=0; i--)
    {
        max_heapify(arr, p, heapsize, i);
    }
}

list_elem max_priority(list_elem arr[], int heapsize)
{
    return arr[0];
}

list_elem extract_max(list_elem arr[], int **p, int heapsize)
{
    list_elem temp;
    temp=arr[0];

    arr[0]=arr[heapsize-1];
    cout << "\nCheck3";
    max_heapify(arr, p, heapsize-1, 0);

    return temp;
}

void increase_key(list_elem arr[], int **p, int a, list_elem new_key)
{
    /*if(p[arr[a].list_num][arr[a].index]>new_key)
        cout << "Error : New key value is lesser than old key.";*/
    //else
    {
        arr[a]=new_key;
        while(p[arr[a/2].list_num][arr[a/2].index]<p[arr[a].list_num][arr[a].index])
        {
            swap(&arr[a/2], &arr[a]);       //Watch out!! a/2th element of the array will only be the parent of the left child
            a=a/2;                          //and not the right child because of the shifting of indices(index 0 corresponds
        }                                   //to the first element of the array), so it may be possible to pervert the program
    }                                       //using a carefully designed input.
}

void insrt_in_queue(list_elem arr[], int **p, int heapsize, list_elem l1)
{
    arr[heapsize-1]=l1;
    increase_key(arr, p, heapsize-1, l1);
}

void checklogic(int **p)
{
    cout << "*****" << p[1][0] << "*****";
}

void display_list(list_elem arr[], int **p, int k)
{
    for(int s=0; s<k; s++)
        cout << p[arr[s].list_num][arr[s].index] << " ";
}

int main()
{
    list_elem temp, lnext;
    int i, j;
    int n, k;
    cout << "Enter the number of elements in one list and then the number of lists : ";
    cin >> n >> k;
    int ktemp=k;
    list_elem merged[n*k];
    int **ptr;
    ptr=new int*[k];
    for(i=0; i<k; i++)
    {
        ptr[i]=new int[n];
    }
    for(i=0; i<k; i++)
    {
        cout << "Enter the elements of list : " << i+1 << "\n";
        for(j=0; j<n; j++)
        {
            cin >> ptr[i][j];
        }
    }
    list_elem arr[k];
    for(i=0; i<k; i++)
    {
        arr[i].index=n-1;
        arr[i].list_num=i;
    }
    cout << "Check1";
    int pow=1;
    while(pow<=k)
        pow *= 2;
    build_max_heap(arr, ptr, pow-1, k);
    cout << "\nCheck2";
    /*checklogic(ptr);
    display_list(arr, ptr, k);
    */

    int counter;
    for(counter=1; counter<=n*k; counter++)
    {
        temp=extract_max(arr, ptr, ktemp);
        cout << "\nCheck4";
        merged[n*k-counter]=temp;
        cout << ptr[temp.list_num][temp.index] << "&\n";
        if(temp.index==0)
        {
            ktemp=ktemp-1;
        }
        else
        {
            lnext.list_num=temp.list_num;
            lnext.index=temp.index-1;
            insrt_in_queue(arr, ptr, ktemp, lnext);
        }
    }
    for(i=0; i<(n*k); i++)
        cout << "\n" << ptr[merged[i].list_num][merged[i].index] << "*";



    return 0;
}
