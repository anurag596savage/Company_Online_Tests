#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int findNumberOfWays(int n_intervals, int n_processes,vector<int>input,vector<int>output) 
{
	if(output.size()==n_intervals)
	{
		for(int i=0;i<n_intervals;i++)
		{
			cout<<output[i]<<" ";
		}
		cout<<endl;
		return 1;
	}
	int ans = 0;
	for(int i=0;i<n_processes;i++)
	{
		vector<int>input_ith = input;
		int element = input_ith[i];
		input_ith.erase(input_ith.begin()+i);
		input_ith.push_back(element);
		output.push_back(element);
		if((output.size()==1) || (output.size()>1 && output[output.size()-1]!=output[output.size()-2]))
		ans += findNumberOfWays(n_intervals,n_processes,input_ith,output);
		output.pop_back();
		
	}
	
	return ans;
}


int main()
{
	
	int n_intervals,n_processes;
	cin>>n_intervals>>n_processes;
	vector<int>input;
	for(int i=1;i<=n_processes;i++)
	{
		input.push_back(i);
	}
	vector<int>output;
	cout<<findNumberOfWays(n_intervals,n_processes,input,output)<<endl;
	return 0;
	
}

