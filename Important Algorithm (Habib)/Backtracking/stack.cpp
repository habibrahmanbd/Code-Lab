#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int cs;
	cin>>cs;
	for(long long c=1; c<=cs; c++)
	{
		long long int in;
		long fn;
		cin>> in >> fn;
		long long int q;
		cin>>q;
		bool flg= 1;
		for(long long int i=1; i<=q; i++)
		{
			string str;
			cin>>str;
			long long int val;
			cin>>val;
			if(str=="in")
				in+=val;
			else
			{
				if(in>=val)
					in-=val;
				else
				{
					flg=0;
				}
			}
		}
		if(flg==1 && in==fn)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}