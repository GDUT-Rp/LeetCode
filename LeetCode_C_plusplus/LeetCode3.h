//
// Created by Lenovo on 2019/1/1.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE3_H
#define LEETCODE_C_PLUSPLUS_LEETCODE3_H

#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <set>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, i = 0, j = 0;
        set<char> charset;
        int length = s.length();
        while (i < length && j < length){
            if (!charset.count(s[j])){
                charset.insert(s[j++]);
                ans = max(ans, j - i);
            } else{
                charset.erase(s[i++]);
            }
        }
        return ans;
    }

public:
    int improveByVector(string s){
        int length = s.length();
        int ans = 0, i = 0, j = 0;
        vector<int> index(128);
        for (; j < length ; j++) {
            i = max(index[s[j]], i);
            ans = max(ans, j - i + 1);
            index[s[j]] = j + 1;
        }
        return ans;
    }
};



#endif //LEETCODE_C_PLUSPLUS_LEETCODE3_H
