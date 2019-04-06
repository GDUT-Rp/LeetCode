//
// Created by Lenovo on 2019/4/6.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE62_H
#define LEETCODE_C_PLUSPLUS_LEETCODE62_H

#include <iostream>
#include <vector>

using namespace std;

class Solution_LeetCode62 {
public:
    int uniquePaths(int m, int n) {
        int dp[n][m];
        if(m==0||n==0)
            return 0;
        for(int i = 0;i<m;i++)
            dp[0][i]=1;         //  都只能是1
        for(int j = 0;j<n;j++)
            dp[j][0]=1;         //  都只能是1
        for(int i = 1;i<m;i++)
            for(int j =1;j<n;j++)
                dp[j][i] = dp[j-1][i] + dp[j][i-1];
        return dp[n-1][m-1];
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE62_H
