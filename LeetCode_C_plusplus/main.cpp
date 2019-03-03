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
#include "LeetCode27.h"

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

void LeetCode27() {
    vector<int> nums1 = {1, 2, 2, 3, 2, 4, 6, 6, 5, 5, 2, 2, 2, 2};
    vector<int> nums2 = {1, 2, 2, 3, 2, 4, 6, 6, 5, 5, 2, 2, 2, 2};
    Solution_LeetCode27 solution_leetCode27;
    cout << solution_leetCode27.removeElement(nums1, 2) << endl;
    cout << solution_leetCode27.removeElementBySwap(nums2, 2) << endl;
}

int main() {
    cout << "HelloWorld!" << endl;
    LeetCode4();
    return 0;
}