//
// Created by Lenovo on 2019/8/7.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE132_H
#define LEETCODE_C_PLUSPLUS_LEETCODE132_H

#include <iostream>
#include <vector>
#include <string>
#include <vector>

using namespace std;

class Solution_LeetCode132 {
public:
    int minCut(string s) {
        int len = s.length();
        vector<int> list(len + 1);        //  list[i]代表前i个字符需要划分几次，特别的，list[0] = 1
        for (int i = 0; i < len + 1; ++i) {
            list[i] = i - 1;
        }
        for (int i = 0; i < len; ++i) {
            list[i + 1] = min(list[i + 1], list[i] + 1);    //  初始化，最坏情况下就比左边的多划分一次
            if (i == len - 1) {  //  最后一个了
                break;
            }
            //  回文串有两种，一种偶数个的ABBA，一种奇数个的ABA
            //  先找偶数个的
            int start = i, end = i + 1;
            while (s[start] == s[end]) {                            //  认为start -- end 之间是回文串
                list[end + 1] = min(list[end + 1], list[start] + 1);//  跟新回文串下一位的最少划分次数
                if (end == len - 1 || start == 0) {
                    break;
                }
                --start, ++end;
            }
            //  再找奇数个的
            start = i - 1, end = i + 1;
            if (start < 0){
                continue;
            }
            while (s[start] == s[end]) {                            //  认为start -- end 之间是回文串
                list[end + 1] = min(list[end + 1], list[start] + 1);//  跟新回文串下一位的最少划分次数
                if (end == len - 1 || start == 0) {
                    break;
                }
                --start, ++end;
            }
            //  如果整个串都是回文串，那么就中断
            if (list[len] == 0) {
                return 0;
            }
        }
        return list[len];
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE132_H
