#include <stdio.h>

void check_anagram(char a[], char b[])
{
    int s=0;
    char t[]="TRUE";
    char f[]="FALSE";
    int i;
    int freq[26]={0};
    i=0;
    while(a[i]!='\0')
    {
        freq[a[i]-'a']++;
        i++;
    }
    i=0;
    while(b[i]!='\0')
    {
        freq[b[i]-'a']--;
        i++;
    }
    //printf("\n");
    for(i=0; i<26; i++)
    {
        if(freq[i]!=0)
           {
              printf("FALSE");
              s=1;
              break;
           }
    }
    if(s==0)
    {printf("TRUE");}
}

char first(char a[])
{
    int freq[26]={0};
    int i=0;
    while(a[i]!='\0')
    {
        freq[a[i]-'a']++;
        i++;
    }
    i=0;
    while(a[i]!='\0')
    {
        if(freq[a[i]-'a']==1)
            return a[i];
        i++;
    }
    return '0';
}

struct substring
{
    int length;
    int f;
    int l;
};

int check_palindrome(char a[], struct substring s)
{
    int i;
    if((s.l-s.f)%2==1)
    {
        for(i=0;i<=(s.l-s.f)/2;i++)
        {
            if(a[s.f+i]!=a[s.l-i])
                return 0;
        }
    }
    else
    {
        for(i=0;i<(s.l-s.f)/2;i++)
        {
            if(a[s.f+i]!=a[s.l-i])
                return 0;
        }
    }
    return 1;
}

struct substring longest_palindrome(char a[])
{
    struct substring s1, big;
    int i,j, max, check;
    check=0;
    max=0;
    int len=0;
    while(a[len]!='\0')
        len++;
    for(i=0; i<len; i++)
    {
        s1.f=i;
        for(j=i+1; j<len; j++)
        {
            s1.l=j;
            s1.length=j-i+1;
            if(s1.length>max)
            {
                if(check_palindrome(a, s1)==1)
                {max=s1.length;
                big.f=s1.f;
                big.l=s1.l;
                big.length=s1.length;
                check=1;
                }
            }
        }
    }
    if(check==0)
    {
        big.length=0;
        return big;
    }
    else
        return big;
}

void most_freq(char a[])
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
    while(j>=0)
    {
        if(arr[j]>max)
            max=arr[j];
        j--;
    }
    int freq[1500]={0};
    for(j=0; j<=size; j++)
        freq[arr[j]]++;
    j--;
    int max_freq=0;
    j=1499;
    while(j>=0)
    {
        if(freq[j]>max_freq)
            max_freq=freq[j];
        j--;
    }
    for(j=size; j>=0; j--)
    {
        if(freq[arr[j]]==max_freq)
        {
            printf("%d ", arr[j]);
            freq[arr[j]]=0;
        }
    }
}

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
    int x;
    //int i=0;
    char a[100];
    char b2[100];
    char b1[50];
    char f;
    struct substring longest;
    char b[30];
    int i;
    char a1[100];
    int n;
    char a2[500];
    printf("Enter the question number whose solution you want immediately followed by the first input for that question : ");
    scanf("%d", &x);
    switch(x){
    case 1:

    //printf("Enter the first string : ");
    gets(a);
    //printf("Enter the second string : ");
    gets(b2);
    check_anagram(a,b2);
    break;
    case 2:

    gets(b1);
    f=first(b1);
    if(f=='0')
        printf("No character appears only once in the string");
    else
        printf("First character appearing only once is %c", f);
        break;
    case 3:

    gets(b);
    longest=longest_palindrome(b);
    if(longest.length==0)
    {
        printf("No palindrome in the given string.");
    }
    else
    {
        printf("Longest palindrome : \n");
        for(i=longest.f; i<=longest.l; i++)
            printf("%c", b[i]);
    }
    break;
    case 4:

    gets(a1);
    scanf("%d", &n);
    checksum(a1, n);
    break;
    case 5:

    gets(a2);
    most_freq(a2);
    break;
    }
}
