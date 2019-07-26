//
// Created by Lenovo on 2019/7/26.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE84_H
#define LEETCODE_C_PLUSPLUS_LEETCODE84_H

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution_LeetCode84 {
public:
    //  纯暴力解法,TLE
    int largestRectangleArea_baoli(vector<int> &heights) {
        int maxarea = 0;
        for (int i = 0; i < heights.size(); ++i) {
            for (int j = i; j < heights.size(); ++j) {  //  对于任意两个柱子（i, j）
                int minheight = INT_MAX;
                for (int k = i; k <= j; ++k) {           //  找到两个柱子之间的最矮柱子
                    minheight = min(minheight, heights[k]);
                }
                maxarea = max(maxarea, minheight * (j - i + 1));    //  尝试更新最大面积
            }
        }
        return maxarea;
    }

    //  优化的暴力解法,TLE
    int largestRectangleArea_baoli_improved(vector<int> &heights) {
        int maxarea = 0;
        for (int i = 0; i < heights.size(); ++i) {
            int minheight = INT_MAX;
            for (int j = i; j < heights.size(); ++j) {  //  我们可以用前一对柱子之间的最低高度来求出当前柱子对间的最低高度
                minheight = min(minheight, heights[j]);
                maxarea = max(maxarea, (j - i + 1) * minheight);
            }
        }
        return maxarea;
    }

    //  分治解法TLE
    int largestRectangleArea_fenzhi(vector<int> &heights) {
        return calculateArea(heights, 0, heights.size() - 1);
    }

    int calculateArea(vector<int> heights, int start, int end) {
        if (start > end) {
            return 0;
        }
        int minindex = start;
        for (int i = start; i <= end; ++i) {
            if (heights[minindex] > heights[i]) {       //  找到最矮柱子
                minindex = i;
            }
        }
        return max(heights[minindex] * (end - start + 1),
                   max(calculateArea(heights, start, minindex - 1), calculateArea(heights, minindex + 1, end)));
    }

    int largestRectangleArea_stack(vector<int> &heights) {
        int n = heights.size();
        stack<int> index;
        int area = 0;       //  ans，维护最大面积
        for (int i = 0; i < heights.size(); i++) {
            if (index.empty() || heights[index.top()] < heights[i]) {   //  栈顶元素对应的高度小于下一个高度就进栈
                index.push(i);
            } else {
                while (!index.empty() && heights[index.top()] >= heights[i]) {  //  栈非空情况下并且栈顶元素对应值大于下一个高度
                    int tmp = index.top();      //  栈顶元素
                    index.pop();                //  出栈
                    int length = 0;
                    if (index.empty()) {        //  长度即从0开始到i这里
                        length = i;
                    } else {
                        length = i - index.top() - 1;   //  矩形宽
                    }
                    area = max(area, length * heights[tmp]);
                }
                index.push(i);  //  把高的都出栈了，现在可以把矮的这个进栈
            }
        }
        while (!index.empty()) {    //  把这个递增序列逐个出栈进行计算
            int tmp = index.top();
            index.pop();
            int length = 0;
            if (index.empty()) {
                length = n;
            } else {
                length = n - index.top() - 1;
            }
            area = max(area, length * heights[tmp]);
        }
        return area;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE84_H
