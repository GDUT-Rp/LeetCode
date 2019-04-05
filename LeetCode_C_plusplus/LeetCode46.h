//
// Created by Lenovo on 2019/4/5.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE46_H
#define LEETCODE_C_PLUSPLUS_LEETCODE46_H

#include <iostream>
#include <vector>

using namespace std;

class Solution_LeetCode46 {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> ans;                    //  存放答案集合
        vector<int> tmp;                            //  每一组答案
        vector<bool> used(nums.size(), false);      //  用来标记是否某个下标的数是否使用过
        dfs(ans, tmp, nums, used);
        return ans;
    }

    void dfs(vector<vector<int>> &ans, vector<int> &tmp, vector<int> &nums, vector<bool> used) {
        if (tmp.size() == nums.size()) {
            ans.push_back(tmp);                     //  添加答案
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!used[i]) {
                tmp.push_back(nums[i]);
                used[i] = true;
                dfs(ans, tmp, nums, used);
                tmp.pop_back();
                used[i] = false;
            }
        }
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE46_H
