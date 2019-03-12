//
// Created by Lenovo on 2019/3/12.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE10_H
#define LEETCODE_C_PLUSPLUS_LEETCODE10_H

#include <iostream>

using namespace std;

class Solution_LeetCode10 {
public:
    bool isMatch(string s, string p) {
        // p为空时的讨论
        if (!p.length() && !s.length())
            return true;
        if (!p.length() && s.length() > 0)
            return false;

        // s为空时的讨论，只有p为 .*.*.*.* 的形式出现才能匹配
        if (!s.length()) {
            if (p.length() % 2 == 1) return false;
            int i = 1;
            while (i < p.length() && p[i] == '*') {
                i += 2;
            }
            return i == p.length() + 1;
        }

        // p[i]为*时，用p+2匹配s+0, s+1, s+2, s+3...成功返回true，否则false
        int i = -1;
        if (p.length() >= 2 and p[1] == '*') {
            do {
                // 当++i为len+1时截取字符串才会越界报错，但是++i为len时截取的子串为空就已经返回结果了，所以永远没有机会截取len+1
                if (isMatch(s.substr(++i), p.substr(2)))
                    return true;
                    // 匹配失败且i已经为len了，即p+2匹配到s的最后了任然匹配失败，return false
                else if (i == s.length())
                    return false;
                // 由于上面的++i截取到len时就会return退出，所以s[i]也永远不会越界
            } while ((s[i] == p[0] || p[0] == '.'));
            return false;
        }

            // p[1]不为*时
        else {
            if (s[0] == p[0] || p[0] == '.')
                return isMatch(s.substr(1), p.substr(1));
            else
                return false;
        }
    }

    vector<vector<int>> f;
    int m, n;

    bool isMatch_faster(string s, string p) {
        n = s.size();
        m = p.size();
        f = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
        return dp(0, 0, s, p);
    }

    int dp(int x, int y, string &s, string &p) {
        if (f[x][y] != -1)
            return f[x][y];
        if (y == m)
            return f[x][y] = x == n;
        bool first_match = x < n && (s[x] == p[y] || p[y] == '.');
        bool ans;
        if (y + 1 < m && p[y + 1] == '*') {
            ans = dp(x, y + 2, s, p) || first_match && dp(x + 1, y, s, p);
        } else
            ans = first_match && dp(x + 1, y + 1, s, p);
        return f[x][y] = ans;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE10_H
