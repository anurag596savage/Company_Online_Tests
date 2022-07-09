#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int Find_Shortest_Substring(string s)
{
	unordered_map<char,int>ourMap;
	for(int i=0;i<s.length();i++)
	{
		ourMap[s[i]]++;
	}
	for(int i=0;i<s.length();i++)
	{
		if(ourMap[s[i]]==1)
		{
			ourMap.erase(s[i]);
		}
	}
	int count = ourMap.size();
	int i=0,j=0;
	int ans=INT_MAX;
	while(j<s.length())
	{
		if(ourMap.count(s[j])>0)
		{
			ourMap[s[j]]--;
			if(ourMap[s[j]]==1)
			{
				count--;
			}
		}
		if(count>0)
		{
			j++;
		}
		else if(count==0)
		{
			while(count==0)
			{
				ans = min(ans,j-i+1);
				if(ourMap.count(s[i])>0)
				{
					ourMap[s[i]]++;
					if(ourMap[s[i]]==2)
					{
						count++;
					}
				}
				i++;
			}
			j++;
		}
	}
	
	return ans;
}

int main()
{
	string s;
	cin>>s;
	
	cout<<Find_Shortest_Substring(s)<<endl;
	
	return 0;
}

