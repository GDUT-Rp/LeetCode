//
// Created by Lenovo on 2019/3/19.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE1_H
#define LEETCODE_C_PLUSPLUS_LEETCODE1_H

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution_LeetCode1 {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> targetnum(2);
        map<int, int> temp_map;
        int complement;
        for (int i = 0; i < nums.size(); ++i) {
            complement = target - nums[i];
            if (temp_map.count(complement)) {
                targetnum[0] = i;
                targetnum[1] = temp_map[complement];
                break;
            } else {
                temp_map[nums[i]] = i;
            }
        }
        return targetnum;
    }

    vector<int> faster(vector<int> &nums, int target) {
        vector<int> v;
        std::unordered_map<int, int> hash;
        for (int i = nums.size() - 1; i >= 0; hash[nums[i]] = i, i--) {
            if (hash.find(target - nums[i]) == hash.end())
                continue;
            v.push_back(i);
            v.push_back(hash[target - nums[i]]);
            hash[nums[i]] = i;
        }
        return v;
    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE1_H
