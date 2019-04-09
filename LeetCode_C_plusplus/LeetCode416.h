//
// Created by Lenovo on 2019/4/9.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE416_H
#define LEETCODE_C_PLUSPLUS_LEETCODE416_H

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution_LeetCode416 {
public:
    // 01背包解法
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (int a: nums) sum += a;
        if (sum % 2) return false;  //  如果总和为奇数，不成立
        sum /= 2;
        int n = nums.size();
        int dp[n][sum + 1];         //  表示如果我们取前i个数字，且背包容量为j的情况下，最后能放入多少东西
        memset(dp, 0, sizeof(dp));  //  需全部置0
        for (int i = nums[0]; i <= sum; ++i) {
            dp[0][i] = nums[0];     //  初始化
        }
        for (int i = 1; i < n; ++i) {
            for (int j = nums[i]; j <= sum; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
            }
        }
        return sum == dp[n - 1][sum];
    }

    //  第二种解法
    int target;

    bool check(vector<int> &nums, int cur1, int cur2, int index) {
        //剪枝，如果有一个和超过了target，则停止搜索（这个剪枝非常重要）
        if (target < cur1 || target < cur2 || index == -1) {
            return false;
        }
        if (target == cur1 || target == cur2) {
            return true;
        }
        cout << cur1 << " " << cur2 << " " << index << endl;
        //将nums[index]分配cur1或者cur2
        return check(nums, cur1 + nums[index], cur2, index - 1) || check(nums, cur1, cur2 + nums[index], index - 1);
    }

    bool dfs(vector<int> &nums) {
        //accumulate带有三个形参：头两个形参指定要累加的元素范围，第三个形参则是累加的初值。
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) {
            return false;
        }
        target = sum / 2;
        return check(nums, 0, 0, nums.size() - 1);
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE416_H
