//
// Created by Lenovo on 2019/4/12.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE96_H
#define LEETCODE_C_PLUSPLUS_LEETCODE96_H

#include <iostream>

using namespace std;

class Solution_LeetCode96 {
public:
    int numTrees(int n) {
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = dp[1] = 1;
        //  当n=1时，以1为根节点，左分支右分支个数均无，即G(1)=0
        //  当n=2时，以1为根节点，右分支个数为1，以2为根节点，左分支个数为1，G(2)=G(0)*G(1)+G(1)*G(0)
        //  假设n个结点，1为根节点，2为根节点，... n为根节点，
        //  G(n) = G(0)*G(n-1) + G(1)*G(n-2) + ... + G(n-2)*G(1) + G(n-1)*G(0)
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};


#endif //LEETCODE_C_PLUSPLUS_LEETCODE96_H
