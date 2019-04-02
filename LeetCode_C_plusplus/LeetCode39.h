//
// Created by Lenovo on 2019/4/2.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE39_H
#define LEETCODE_C_PLUSPLUS_LEETCODE39_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution_LeetCode39 {
public:
    // BFS
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        BFS(0, ans, target, tmp, candidates);
        return ans;
    }

    void BFS(int index, vector<vector<int>> &ans, int target, vector<int> &preAns, vector<int> &candidates) {
        int len = candidates.size();
        if (index >= len) {
            return;
        }
        for (int i = index; i < len; ++i) {
            vector<int> tmp(preAns);
            if (candidates[i] < target) {
                tmp.push_back(candidates[i]);
                BFS(i, ans, target - candidates[i], tmp, candidates);
            } else if (candidates[i] > target) {
                return;
            } else {
                tmp.push_back(candidates[i]);
                ans.push_back(tmp);
            }
        }
    }

    vector<vector<int>> ans;
    vector<int> t;

    void dfs(int i, int j, const vector<int> &v) {
        if (!j) {
            ans.push_back(t);
            return;
        }
        if (i == v.size())return;
        if (j >= v[i]) {
            t.push_back(v[i]);
            dfs(i, j - v[i], v);
            t.pop_back();
        }
        dfs(i + 1, j, v);
        return;
    }

    vector<vector<int>> combinationSum_DFS(vector<int> &v, int target) {
        dfs(0, target, v);
        return ans;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE39_H
