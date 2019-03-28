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

class RLEIterator {
public:
    vector<int> arrayList;
    long last_pos = 0;
    long cur_pos = 0;
    long total_size = 0;

    RLEIterator(vector<int> A) {
        arrayList = A;
        int length = A.size();
        for(int i = 0;i<length;i+=2)
        {
            total_size += A[i];
        }
    }

    int next(int n) {
        last_pos = cur_pos;
        cur_pos += n;
        if(last_pos+n>total_size)
            return -1;

        long now_pos = last_pos+n;

        for(int i = 0;i<arrayList.size();i+=2)
        {
            if(now_pos-arrayList[i]<=0)
            {
                return arrayList[i+1];
            }
            else
            {
                now_pos-=arrayList[i];
            }
        }
        return -1;
    }
};

//class RLEIterator {
//public:
//    RLEIterator(vector<int> A) {
//
//    }
//
//    int next(int n) {
//
//		return 0;
//    }
//};

int main() 
{
	printf("\n");
	return 0;
}
