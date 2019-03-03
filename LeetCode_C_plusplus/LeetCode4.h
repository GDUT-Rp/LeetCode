//
// Created by Lenovo on 2019/3/3.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE4_H
#define LEETCODE_C_PLUSPLUS_LEETCODE4_H

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution_LeetCode4 {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        if (nums1.size() == 0) return 0;
        sort(nums1.begin(), nums1.end());
        if (nums1.size() % 2 == 1) {
            return nums1[nums1.size() / 2];
        } else {
            return 1.0 * (nums1[nums1.size() / 2 - 1] + nums1[nums1.size() / 2]) / 2;
        }
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE4_H
