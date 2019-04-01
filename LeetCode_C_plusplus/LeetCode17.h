//
// Created by Lenovo on 2019/4/1.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE17_H
#define LEETCODE_C_PLUSPLUS_LEETCODE17_H

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution_LeetCode17 {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> aa{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if (digits.empty()) return vector<string>{};
        queue<string> re;
        re.push("");
        for (int i = 0; i < digits.size(); ++i) {
            int length = re.size();
            for (int j = 0; j < length; ++j) {
                string temp = re.front();
                re.pop();
                for (char x: aa[digits[i] - '0']) {
                    re.push(temp + x);
                }
            }
        }
        vector<string> ans;
        while (!re.empty()) {
            ans.push_back(re.front());
            re.pop();
        }
        return ans;
    }
};


#endif //LEETCODE_C_PLUSPLUS_LEETCODE17_H
