#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <set>

#include "LeetCode3.h"
#include "LeetCode4.h"
#include "LeetCode5.h"
#include "LeetCode7.h"
#include "LeetCode9.h"
#include "LeetCode10.h"
#include "LeetCode16.h"
#include "LeetCode19.h"
#include "LeetCode26.h"
#include "LeetCode27.h"
#include "LeetCode28.h"
#include "LeetCode29.h"
#include "LeetCode33.h"
#include "LeetCode34.h"
#include "LeetCode35.h"
#include "LeetCode50.h"
#include "LeetCode53.h"
#include "LeetCode69.h"
#include "LeetCode74.h"
#include "LeetCode78.h"
#include "LeetCode81.h"
#include "LeetCode100.h"
#include "LeetCode122.h"


using namespace std;

void LeetCode3() {
    string s = "abcabcbb";
    Solution_LeetCode3 solution;
    cout << solution.lengthOfLongestSubstring(s) << endl;
    cout << solution.improveByVector(s) << endl;
}

void LeetCode4() {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    Solution_LeetCode4 solution_leetCode4;
    cout << solution_leetCode4.findMedianSortedArrays(nums1, nums2) << endl;
}

void LeetCode5() {
    string list[] = {"babad", "bb", "ccd", "leeteed"};
    Solution_LeetCode5 solution_leetCode5;
    for (string str: list) {
        cout << str << endl;
        cout << solution_leetCode5.longestPalindrome(str) << endl;
    }
}

void LeetCode7() {
    int x[6] = {123, -123, 120, 21, 1534236469, -2147483648};
    Solution_LeetCode7 solution_leetCode7;
    for (int i : x) {
        cout << solution_leetCode7.reverse(i) << endl;
    }
}

void LeetCode9() {
    int x[] = {121, -121, 10, 989, 999};
    Solution_LeetCode9 solution_leetCode9;
    for (int i: x) {
        cout << i << endl;
        cout << solution_leetCode9.isPalindrome(i) << endl;
        cout << solution_leetCode9.faster(i) << endl;
    }
}

void LeetCode10() {
    Solution_LeetCode10 solution_leetCode10;
    vector<string> s = {"aa", "aa", "ab", "aab", "mississippi"};
    vector<string> p = {"a", "a*", ".*", "c*a*b", "mis*is*p*."};
    for (int i = 0; i < s.size(); ++i) {
        cout << s[i] << endl << p[i] << endl << solution_leetCode10.isMatch(s[i], p[i]) << endl;
    }
}

void LeetCode16() {
    vector<vector<int>> nums = {{-1, 2, 1, -4}};
    vector<int> target = {1};
    Solution_LeetCode16 solution_leetCode16;
    for (int i = 0; i < target.size(); ++i) {
        cout << solution_leetCode16.threeSumClosest(nums[i], target[i]) << endl;
    }
}

void LeetCode19() {
    Solution_LeetCode19 solution_leetCode19;
}

void LeetCode26() {
    Solution_LeetCode26 solution_leetCode26;
    vector<vector<int>> nums = {{1, 1, 2},
                                {0, 0, 1, 1, 1, 2, 2, 3, 3, 4}};
    for (int i = 0; i < nums.size(); ++i) {
        cout << solution_leetCode26.faster(nums[i]) << endl;
    }
}

void LeetCode27() {
    vector<int> nums1 = {1, 2, 2, 3, 2, 4, 6, 6, 5, 5, 2, 2, 2, 2};
    vector<int> nums2 = {1, 2, 2, 3, 2, 4, 6, 6, 5, 5, 2, 2, 2, 2};
    Solution_LeetCode27 solution_leetCode27;
    cout << solution_leetCode27.removeElement(nums1, 2) << endl;
    cout << solution_leetCode27.removeElementBySwap(nums2, 2) << endl;
}

void LeetCode28() {
    Solution_LeetCode28 solution_leetCode28;
    vector<string> haystack = {"hello", "aaaaa"};
    vector<string> needle = {"ll", "bba"};
    for (int i = 0; i < haystack.size(); ++i)
        cout << solution_leetCode28.strStr(haystack[i], needle[i]) << endl;
}

void LeetCode29() {
    vector<int> nums1 = {10, 7, -2147483648};
    vector<int> nums2 = {3, -3, 1};
    Solution_LeetCode29 solution_leetCode29;
    for (int i = 0; i < nums1.size(); ++i) {
        cout << solution_leetCode29.divide(nums1[i], nums2[i]) << endl;
    }
}

void LeetCode33() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    Solution_LeetCode33 solution_leetCode33;
    cout << solution_leetCode33.search(nums, target) << endl;
}

void LeetCode34() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 6;
    nums = {2, 2};
    target = 3;
    Solution_LeetCode34 solution_leetCode34;
    nums = solution_leetCode34.searchRange(nums, target);
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << endl;
    }
}

void LeetCode35() {
    vector<int> nums = {1, 3, 5, 6};
    int target = 0;
    nums = {1, 3};
    target = 2;
    Solution_LeetCode35 solution_leetCode35;
    cout << solution_leetCode35.searchInsert(nums, target) << endl;
}

void LeetCode50() {
    double x[10] = {2, 2.1, 2};
    int n[10] = {10, 3, -2};
    Solution_LeetCode50 solution_leetCode50;
    for (int i = 0; i < 3; ++i) {
        cout << solution_leetCode50.myPow(x[i], n[i]) << endl;
    }
}

void LeetCode53() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution_LeetCode53 solution_leetCode53;
    cout << solution_leetCode53.maxSubArray(nums) << endl;
}

void LeetCode69() {
    int x[10] = {4, 8};
    Solution_LeetCode69 solution_leetCode69;
    for (int i = 0; i < 2; ++i) {
        cout << solution_leetCode69.mySqrt_newton(x[i]) << endl;
    }
}

void LeetCode74() {
    vector<vector<int>> matrix = {{1,  3,  5,  7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 50}};
    Solution_LeetCode74 solution_leetCode74;
    int target = 3;
    matrix = {{-8, -7, -5, -3, -3, -1, 1},
              {2,  2,  2,  3,  3,  5,  7},
              {8,  9,  11, 11, 13, 15, 17},
              {18, 18, 18, 20, 20, 20, 21},
              {23, 24, 26, 26, 26, 27, 27},
              {28, 29, 29, 30, 32, 32, 34}};
    target = -5;
    cout << solution_leetCode74.searchMatrix(matrix, target) << endl;
}

void LeetCode78() {
    Solution_LeetCode78 solution_leetCode78;
    vector<vector<int>> nums = {{1, 2, 3}};
    vector<vector<int>> result;
    for (int i = 0; i < nums.size(); ++i) {
        result = solution_leetCode78.subsets(nums[i]);
        for (int j = 0; j < result.size(); ++j) {
            for (int k = 0; k < result[j].size(); ++k) {
                cout << result[j][k] << " ";
            }
            cout << endl;
        }
    }
}

void LeetCode81() {
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 2;
//    nums = {1, 1, 3, 1};
//    nums = {3, 1, 1};
//    nums = {1, 1};
//    nums = {2,2,2,0,2,2};
    Solution_LeetCode81 solution_leetCode81;
    cout << solution_leetCode81.search(nums, target) << endl;
}

void LeetCode100() {
    Solution_LeetCode100 solution_leetCode100;
}

void LeetCode122() {
    Solution_LeetCode122 solution_leetCode122;
    vector<vector<int>> nums = {{7, 1, 5, 3, 6, 4},
                                {1, 2, 3, 4, 5},
                                {7, 6, 5, 4, 3, 1}};
    for (int i = 0; i < nums.size(); ++i) {
        cout << solution_leetCode122.maxProfit(nums[i]) << endl;
    }
}


int main() {
    cout << "HelloWorld!" << endl;
    LeetCode122();
    return 0;
}