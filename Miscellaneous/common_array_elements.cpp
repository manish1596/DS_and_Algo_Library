#include <iostream>

using namespace std;
int main()
{
	int m,n, i;
	int p=0,k=0;
	int a[n], b[m];
cout << "Enter the number of elements in the two arrays";
cin >> n >> m;
cout << "Enter the elements of first array";
for(i=0;i<n;i++)
	{
		cin >>a[i];
	}
cout << "Enter the elements of second array";
for(i=0;i<m;i++)
		{
			cin >>b[i];
		}
for(int j=0;j<n;j++)
		{
			for(i=0;i<m;i++)
			{
				if(a[j]==b[i])
				{
					k+=1;
					break;
				}
			}
		}
int c[k];
for(int j=0;j<n;j++)
	{
		for(i=0;i<m;i++)
		{
			if(a[j]==b[i])
			{
				c[p]=a[j];
				p+=1;
				break;
			}
		}
	}

for(i=0;i<p;i++)
		{
			cout <<c[i] << "\n";
		}
	cout << "\n p=" << p;
return 0;
}

