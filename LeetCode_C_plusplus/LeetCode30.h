//
// Created by Lenovo on 2019/7/10.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE30_H
#define LEETCODE_C_PLUSPLUS_LEETCODE30_H

#include <iostream>
#include <vector>

using namespace std;

class Solution_LeetCode30 {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> res;
        map<string, int> dict;
        int len;
        for (int i = 0; i < words.size(); ++i) {
            dict[words[i]]++;
            len += words[i].size();
        }
        if (len > s.size()) return res;
        int word_len = words[0].size();
        for (int i = 0; i <= s.size() - len; ++i) {
            string temp = s.substr(i, len);
            if (fun(temp, dict, word_len)) res.push_back(i);
        }
        return res;
    }

    bool fun(string &temp, map<string, int> dict, int word_len) {
        for (int i = 0; i < temp.size();) {
            string sub = temp.substr(i, word_len);
            if (dict.find(sub) == dict.end()) return false;
            else {
                dict[sub]--;
                if (dict[sub] == 0) dict.erase(sub);
            }
            i += word_len;
        }
        if (dict.empty()) return true;
        else
            return false;
    }

    vector<int> findSubstring1(string s, vector<string> &words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;
        int n = words.size(), m = words[0].size();
        unordered_map<string, int> m1;
        for (auto &a : words) ++m1[a];
        for (int i = 0; i <= (int) s.size() - n * m; ++i) {
            unordered_map<string, int> m2;
            int j = 0;
            for (j = 0; j < n; ++j) {
                string t = s.substr(i + j * m, m);
                if (m1.find(t) == m1.end()) break;
                ++m2[t];
                if (m2[t] > m1[t]) break;
            }
            if (j == n) res.push_back(i);
        }
        return res;
    }
};


#endif //LEETCODE_C_PLUSPLUS_LEETCODE30_H
