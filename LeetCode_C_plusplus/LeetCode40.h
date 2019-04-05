//
// Created by Lenovo on 2019/4/3.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE40_H
#define LEETCODE_C_PLUSPLUS_LEETCODE40_H

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution_LeetCode40 {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> pre;
        DFS_(ans, pre, target, 0, candidates);
        set<vector<int>> tmp(ans.begin(), ans.end());
        ans.assign(tmp.begin(), tmp.end());
        return ans;
    }

    void DFS_(vector<vector<int>> &ans, vector<int> &pre, int target, int index, vector<int> &candidates) {
        int len = candidates.size();
        if (index >= len) return;
        for (int i = index; i < len; ++i) {
            vector<int> tmp(pre);
            if (candidates[i] < target) {
                tmp.push_back(candidates[i]);
                DFS_(ans, tmp, target - candidates[i], i + 1, candidates);
            } else if (candidates[i] > target) return;
            else {
                tmp.push_back(candidates[i]);
                ans.push_back(tmp);
            }
        }
    }

    vector<vector<int>> combinationSum2_dfs(vector<int> &candidates, int target) {
        set<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, res, tmp, target, 0);
        return vector<vector<int>>(res.begin(), res.end());
    }

    void dfs(vector<int> &candidates, set<vector<int>> &res, vector<int> tmp, int target, int start) {
        if (target < 0) return;
        if (target == 0) {
            res.insert(tmp);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            int n = candidates[i];
            if (target >= n) {
                tmp.push_back(n);
                dfs(candidates, res, tmp, target - n, i + 1);
                tmp.pop_back();
            }
        }
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE40_H
