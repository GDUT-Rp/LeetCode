//
// Created by Lenovo on 2019/7/16.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE42_H
#define LEETCODE_C_PLUSPLUS_LEETCODE42_H

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution_LeetCode42 {
public:
    // 暴力解法
    int trap(vector<int> &height) {
        int ans = 0;
        int size = height.size();
        for (int i = 1; i < size; ++i) {
            int max_left = 0, max_right = 0;
            for (int j = i; j >= 0; --j) {      //  对每个点找到其左边的最大值
                max_left = max(max_left, height[j]);
            }
            for (int j = i; j < size; ++j) {    //  对每个点找到其右边的最大值
                max_right = max(max_right, height[j]);
            }
            ans += min(max_left, max_right) - height[i];    //  该凹处的大小
        }
        return ans;
    }

    // 动态调整
    int trap1(vector<int> &height) {
        int ans = 0;
        int size = height.size();
        if (size == 0) return 0;
        vector<int> left_max(size), right_max(size);
        left_max[0] = height[0];    //  初始化
        for (int i = 1; i < size; ++i) {    //  left_max数组来表示每个值其左边最大值是多少
            left_max[i] = max(height[i], left_max[i - 1]);
        }
        right_max[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; --i) {   //  right_max数组来表示每个值其右边最大值是多少
            right_max[i] = max(height[i], right_max[i + 1]);
        }
        for (int i = 1; i < size - 1; ++i) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }

    // 栈的应用
    int trap2(vector<int> &height) {
        int ans = 0, current = 0;
        stack<int> st;
        while (current < height.size()) {
            while (!st.empty() && height[current] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty()) {
                    break;
                }
                int distance = current - st.top() - 1;
                int bounded_height = min(height[current], height[st.top()]) - height[top];
                ans += distance * bounded_height;
            }
            st.push(current++);
        }
        return ans;
    }

    // 双指针法
    int trap3(vector<int> &height) {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
                ++left;
            } else {
                height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
                --right;
            }
        }
        return ans;
    }
};


#endif //LEETCODE_C_PLUSPLUS_LEETCODE42_H
