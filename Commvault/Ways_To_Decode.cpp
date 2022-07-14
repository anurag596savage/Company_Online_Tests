#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int Ways_To_Decode(string s,int* dp)
{
	if(s[0]=='0')
	{
		return 0;
	}
	if(s.length()<=1)
	{
		return 1;
	}
	if(dp[s.length()]!=-1)
	{
		return dp[s.length()];
	}
	int count = Ways_To_Decode(s.substr(1),dp);
	
	int n = 10*(s[0]-48)+(s[1]-48);
	if(n<=26)
	{
		count += Ways_To_Decode(s.substr(2),dp);
	}
	dp[s.length()] = count;
	return count;
}

int Ways_To_Decode(string s)
{
	int* dp = new int[s.length()+1];
	for(int i=0;i<=s.length();i++)
	{
		dp[i] = -1;
	}
	
	return Ways_To_Decode(s,dp);
}

int main()
{
	string s;
	cin>>s;
	
	cout<<Ways_To_Decode(s)<<endl;
	
	return 0;
}

