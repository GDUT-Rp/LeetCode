//
// Created by Lenovo on 2019/3/12.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE78_H
#define LEETCODE_C_PLUSPLUS_LEETCODE78_H

#include <iostream>
#include <vector>

using namespace std;

class Solution_LeetCode78 {
public:

    vector<vector<int>> res;
    vector<bool> visit;

    void permuten(vector<int> &nums, int p, vector<int> &tmp, int count, int begin)
    //p:位置 表示当前 执行到要确定 哪一个位置了
    {
        if (p == count) {
            res.push_back(tmp);
            return;
        }
        for (int i = begin; i < nums.size(); i++) {
            if (!visit[i]) {
                visit[i] = true;    // !!!  一定加上 改变 visit
                tmp.push_back(nums[i]);//当前位置上的数确定了
                //继续确定下一个位置
                permuten(nums, p + 1, tmp, count, i + 1);

                //执行到这里  表示所有位置上的数已经确定了 本次可以结束了
                //弹出当前的数  看还有没有其他可能
                //回溯
                tmp.pop_back();
                // !!!  一定加上 改变 visit
                visit[i] = false;
            }
        }
    }

    vector<vector<int>> subsets(vector<int> &nums) {
        res.clear();
        if (nums.size() == 0) return {};
        vector<int> tmp;
        res.push_back({});
        for (int i = 1; i < nums.size() + 1; i++) {
            visit = vector<bool>(nums.size(), false);//vector赋值
            permuten(nums, 0, tmp, i, 0);
        }
        return res;
    }

    vector<vector<int>> fastest(vector<int> &nums) {
        vector<vector<int>> res(1, vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            int n = res.size();
            for (int j = 0; j < n; j++) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};


#endif //LEETCODE_C_PLUSPLUS_LEETCODE78_H
