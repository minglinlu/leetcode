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
    char shift(char c,int num)
    {
        return 'a'+(c-'a'+num)%26;
    }
    
    string shiftingLetters(string& S, vector<int>& shifts) 
	{
        
        for(int i=0;i<S.size();i++)
        {
            for(int j=0;j<=i;j++)
            {
                S[j]=shift(S[j],shifts[i]);
            }
        }
        return S;
    }
};

int main() 
{
	string S;
	vector<int> shifts;

	S = "abc";
	shifts = {3,5,9};
	Solution so;
	so.shiftingLetters(S,shifts);

	for(int i=0;i<S.size();i++)
	{
		printf("%c",S[i]);
	}
	printf("\n");

	return 0;
}

