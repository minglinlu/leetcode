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

class StockSpanner {
	public:
		vector<int> vecStockList;
		vector<int> days;
		StockSpanner() {

		}

		int GetLessEqual(int price)
		{
			int cnt=0;

			if(vecStockList.size()==1)
			{
				days.push_back(1);
				return 1;
			}
			else
			{
				if(vecStockList[vecStockList.size()-2]>vecStockList[vecStockList.size()-1])
				{
					days.push_back(1);
					return 1;
				}
				else if(vecStockList[vecStockList.size()-2]==vecStockList[vecStockList.size()-1])
				{
					cnt=days[days.size()-1]+1;
					days.push_back(cnt);
					return cnt;
				}
				else
				{
					cnt=days[vecStockList.size()-2];
					for(int i=vecStockList.size()-1-days[vecStockList.size()-2];i>=0;i--)
					{
						if(vecStockList[i]>price)
						{
							days.push_back(cnt);
							return cnt;
						}
						else
						{
							cnt++;
						}
					}
				}
			}
			days.push_back(cnt);
			return cnt;
		}
		int next(int price) {
			vecStockList.push_back(price);
			return GetLessEqual(price);
		}
};

int main() 
{
	printf("\n");
	return 0;
}
