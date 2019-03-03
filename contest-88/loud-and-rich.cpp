/*************************************************************************
  > File Name: loud-and-rich.cpp
  > Author: luminglin
  > Mail: luminglin@foxmail.com 
  > Created Time: Sun Mar  3 18:05:54 2019
 ************************************************************************/

#include<iostream>
#include<string>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
	public:
		vector<int> result;
		void getMaybeRicherThanX(int x,int y,vector<vector<int> >& richer,vector<int>& quiet)
		{
			for(int i=0;i<richer.size();i++)
			{
				if(richer[i][1]==y)
				{
					if(quiet[richer[i][0]]<quiet[result[x]])
					{
						result[x]=richer[i][0];
					}
					getMaybeRicherThanX(x,richer[i][0],richer,quiet);
				}
			}
		}

		vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
			result.resize(quiet.size());
			for(int i=0;i<quiet.size();i++)
			{
				result[i]=i;
				getMaybeRicherThanX(i,i,richer,quiet);
			}
			return result;
		}
};

int main() 
{
	vector<vector<int>> richer;
	vector<int> quiet;
	vector<int> ans;

	richer = {{1,0},{2,1},{3,1},{3,7},{4,3},{5,3},{6,3}};
	quiet = {3,2,5,4,6,1,7,0};

	Solution so;
	ans = so.loudAndRich(richer,quiet);

	for(int i=0;i<ans.size();i++)
	{
		printf("%d,",ans[i]);
	}
	printf("\n");

	return 0;
}
