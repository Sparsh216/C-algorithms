#include<iostream>
using namespace std;
int main()
{
	int n=0;
	cout<<"Enter the range ";
	cin>>n;
	int a=0,b=0,i,j;
	for(i=2;i<=n;i++)
	{
		for(j=2;j<=(i/2);j++)
		{
			if(i%j==0)
			break;
			else
			b=i;
		}
		if(b-a==6)
		{
			cout<<b;
			a=b;
		}
		
	}
	return 0;
}
