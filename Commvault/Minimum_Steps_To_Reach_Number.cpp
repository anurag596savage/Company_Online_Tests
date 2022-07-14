#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int Minimum_Steps_To_Reach_Number(int n)
{
	if(n<0)
	{
		n = -1*n;
	}
	
	int pos=0,step_count=0;
	while(pos<n)
	{
		step_count++;
		pos += step_count;
	}
	int difference = pos-n;
	if(difference%2==0)
	{
		return step_count;
	}
	while(difference%2!=0)
	{
		step_count++;
		pos += step_count;
		difference = pos-n;
	}
	
	return step_count;
}

int main()
{
	int n;
	cin>>n;

	cout<<Minimum_Steps_To_Reach_Number(n)<<endl;
	
	return 0;
}

