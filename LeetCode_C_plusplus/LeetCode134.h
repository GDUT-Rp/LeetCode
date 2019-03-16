//
// Created by Lenovo on 2019/3/16.
//

#ifndef LEETCODE_C_PLUSPLUS_LEETCODE134_H
#define LEETCODE_C_PLUSPLUS_LEETCODE134_H

#include <iostream>
#include <vector>

using namespace std;

class Solution_LeetCode134 {
public:
    int myself(vector<int> &gas, vector<int> &cost) {
        if (gas.empty() or cost.empty()) return 0;
        vector<int> nums = {};      //  数组相减
        int len = gas.size();
        for (int i = 0; i < len; ++i) {
            nums.push_back(gas[i] - cost[i]);
        }
        int index = 0;
        int l, r, ans = 0;
        while (index < len) {
            if (nums[index] < 0) {
                index++;
                continue;
            }
            l = 0, r = index, ans = 0;
            int flag = 1;
            while (l < index or r < len) {  //  绕一圈
                if (ans < 0) {
                    flag = 0;
                    break;
                }
                if (r < len) {
                    ans += nums[r++];
                } else {
                    ans += nums[l++];
                }
            }
            if (flag and ans >= 0)
                return index;
            index++;
        }
        return -1;
    }

    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        /*顺序绕一周*/
        int cur = 0;
        int start = gas.size();
        int total = 0;
        //  从第一个开始，够油就继续跑，不够就往后看看有没有剩，最后跑完一圈，剩油还是超支
        do {
            if (total + gas[cur] - cost[cur] >= 0) //汽油够
            {
                total += (gas[cur] - cost[cur]);
                cur++;
            } else {
                start--;
                total += (gas[start] - cost[start]);
            }
        } while (cur != start);

        return total >= 0 ? start % gas.size() : -1;

    }
};

#endif //LEETCODE_C_PLUSPLUS_LEETCODE134_H
