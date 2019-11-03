//
// Created by Lenovo on 2019/11/3.
// Author: Runpeng Zhang
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE321_H
#define LEETCODE_C_PLUSPLUS_LEETCODE321_H

#include <iostream>
#include <vector>

using namespace std;

class Solution_LeetCode321 {
public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<int> ans;
        const int n1 = nums1.size();
        const int n2 = nums2.size();
        for (int k1 = 0; k1 <= k; ++k1) {
            const int k2 = k - k1;
            if (k1 > n1 || k2 > n2) {
                continue;
            }
            ans = max(ans, maxNumber(maxNumber(nums1, k1), maxNumber(nums2, k2)));
        }
        return ans;
    }

private:
    vector<int> maxNumber(const vector<int> &nums, const int k) {
        if (k == 0) {
            return {};
        }
        vector<int> ans;
        int to_pop = nums.size() - k;
        for (const int num : nums) {
            while (!ans.empty() && num > ans.back() && to_pop-- > 0) {
                ans.pop_back();
            }
            ans.push_back(num);
        }
        ans.resize(k);
        return ans;
    }

    vector<int> maxNumber(const vector<int> &nums1, const vector<int> &nums2) {
        vector<int> ans;
        auto s1 = nums1.cbegin();
        auto e1 = nums1.cend();
        auto s2 = nums2.cbegin();
        auto e2 = nums2.cend();
        while (s1 != e1 || s2 != e2) {
            ans.push_back(lexicographical_compare(s1, e1, s2, e2) ? *s2++ : *s1++);
        }
        return ans;
    }
};


#endif //LEETCODE_C_PLUSPLUS_LEETCODE321_H
