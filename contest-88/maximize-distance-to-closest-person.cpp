/*************************************************************************
  > File Name: shifting-letters.cpp
  > Author: luminglin
  > Mail: luminglin@foxmail.com 
  > Created Time: Sun Mar  3 17:43:59 2019
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
		int calDistance(vector<int>& seats,int loc)
		{
			int ori_loc=loc;
			int left=1,right=1;
			while(loc-1>=0&&seats[loc-1]!=1)
			{
				left++;
				loc--;
			}

			loc = loc+left-1;

			while(loc+1<seats.size()&&seats[loc+1]!=1)
			{
				right++;
				loc++;
			}

			if(ori_loc+1==seats.size())
			{
				return left;
			}
			else if(ori_loc==0)
			{
				return right;
			}
			else
			{
				return left>right?right:left;
			}

		}

		int maxDistToClosest(vector<int>& seats) {
			int maxDistance = 1;
			for(int i=0;i<seats.size();i++)
			{
				if(seats[i]==0)
				{
					if(maxDistance<calDistance(seats,i))
					{
						maxDistance = calDistance(seats,i);
					}
				}
			}
			return maxDistance;
		}
};

int main() 
{
	vector<int> data;

	data = {1,0,0,0,1,0,1};

	Solution so;
	cout<<so.maxDistToClosest(data)<<endl;

	return 0;
}
