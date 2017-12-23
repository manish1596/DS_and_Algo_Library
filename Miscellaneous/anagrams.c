//This Program outputs TRUE if both strings are anagrams of each other and FALSE otherwise
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

void main()
{
    int i=0;
    char a[100];
    char b[100];
    //printf("Enter the first string : ");
    gets(a);
    //printf("Enter the second string : ");
    gets(b);
    check_anagram(a,b);
}

