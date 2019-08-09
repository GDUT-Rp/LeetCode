//
// Created by Lenovo on 2019/8/9.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE140_H
#define LEETCODE_C_PLUSPLUS_LEETCODE140_H

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution_LeetCode140 {
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        set<string> wordset(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> m;
        return dfs(wordset, s, m);
    }

private:
    vector<string> dfs(set<string> &wordset, string s, unordered_map<string, vector<string>> m) {
        if (m.count(s)) {
            return m[s];
        }
        if (s.empty()) {
            return {""};
        }
        vector<string> res;
        for (string word : wordset) {
            if (s.substr(0, word.size()) != word) {
                continue;
            }
            vector<string> remain = dfs(wordset, s.substr(word.size()), m);
            for (string r : remain) {
                res.push_back(word + (r.empty() ? "" : " ") + r);
            }
        }
        return m[s] = res;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE140_H
