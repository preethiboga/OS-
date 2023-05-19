#include<bits/stdc++.h>
using namespace std;
bool search(int key,vector<int>&frames)
{
	for(int i=0;i<frames.size();i++)
	{
		if(frames[i]==key)
		return true;
	}
	return false;
}
int pre(vector<int>&rs,vector<int>&frames,int n,int p)
{
	int far=p;
	int res=-1;
	for(int i=0;i<frames.size();i++)
	{
		int j;
		for(j=0;j<n;i++)
		{
			if(frames[i]==rs[j])
			{
				if(j>far)
				{
					far=j;
					res=i;
				}
				break;
			}
		}
		if(j==n)
		return i;
	}
	return (res==-1)?0:res;
}
int main()
{
	int n;
	cout<<"enter size of rs:"<<endl;
	cin>>n;
	vector<int>rs(n);
	for(int i=0;i<n;i++)
	{
		int s;
		cin>>s;
		rs.push_back(s);
    }
    cout<<"enter no.of frames:"<<endl;
    int nf;
    cin>>nf;
    vector<int>frames;
    int hit=0;
    for(int i=0;i<n;i++)
    {
    	if(search(rs[i],frames))
    	{
    		hit++;
    		continue;
		}
		if(frames.size()<nf)
		{
			frames.push_back(rs[i]);
		}
		else
		{
			int j=pre(rs,frames,n,i+1);
			frames[j]=rs[i];
		}
	}
	cout<<"hits:"<<hit<<endl;
	cout<<"faults:"<<n-hit<<endl;
	
	
    	
}

