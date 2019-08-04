#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <set>

#include "LeetCode1.h"
#include "LeetCode2.h"
#include "LeetCode3.h"
#include "LeetCode4.h"
#include "LeetCode5.h"
#include "LeetCode6.h"
#include "LeetCode7.h"
#include "LeetCode8.h"
#include "LeetCode9.h"
#include "LeetCode10.h"
#include "LeetCode12.h"
#include "LeetCode16.h"
#include "LeetCode17.h"
#include "LeetCode19.h"
#include "LeetCode21.h"
#include "LeetCode22.h"
#include "LeetCode23.h"
#include "LeetCode24.h"
#include "LeetCode25.h"
#include "LeetCode26.h"
#include "LeetCode27.h"
#include "LeetCode28.h"
#include "LeetCode29.h"
#include "LeetCode30.h"
#include "LeetCode31.h"
#include "LeetCode33.h"
#include "LeetCode34.h"
#include "LeetCode35.h"
#include "LeetCode36.h"
#include "LeetCode37.h"
#include "LeetCode38.h"
#include "LeetCode39.h"
#include "LeetCode40.h"
#include "LeetCode41.h"
#include "LeetCode42.h"
#include "LeetCode43.h"
#include "LeetCode44.h"
#include "LeetCode45.h"
#include "LeetCode46.h"
#include "LeetCode50.h"
#include "LeetCode53.h"
#include "LeetCode55.h"
#include "LeetCode62.h"
#include "LeetCode63.h"
#include "LeetCode64.h"
#include "LeetCode69.h"
#include "LeetCode72.h"
#include "LeetCode74.h"
#include "LeetCode78.h"
#include "LeetCode81.h"
#include "LeetCode84.h"
#include "LeetCode85.h"
#include "LeetCode87.h"
#include "LeetCode91.h"
#include "LeetCode96.h"
#include "LeetCode97.h"
#include "LeetCode100.h"
#include "LeetCode121.h"
#include "LeetCode122.h"
#include "LeetCode123.h"
#include "LeetCode134.h"
#include "LeetCode135.h"
#include "LeetCode153.h"
#include "LeetCode154.h"
#include "LeetCode162.h"
#include "LeetCode415.h"
#include "LeetCode416.h"


using namespace std;

void LeetCode1() {
    Solution_LeetCode1 solution_leetCode1;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    nums = solution_leetCode1.twoSum(nums, target);
    cout << nums[0] << nums[1] << endl;
}

void LeetCode2() {
    Solution_LeetCode2 solution_leetCode2;
}

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

void LeetCode6() {
    vector<string> s = {"LEETCODEISHIRING", "LEETCODEISHIRING", "A", "AB"};
    vector<int> numRows = {3, 4, 1, 1};
    Solution_LeetCode6 solution_leetCode6;
    for (int i = 0; i < s.size(); ++i) {
        cout << solution_leetCode6.convert(s[i], numRows[i]) << endl;
    }
}

void LeetCode7() {
    int x[6] = {123, -123, 120, 21, 1534236469, -2147483648};
    Solution_LeetCode7 solution_leetCode7;
    for (int i : x) {
        cout << solution_leetCode7.reverse(i) << endl;
    }
}

void LeetCode8() {
    vector<string> strings = {"42", "-42", "4193 with words", "words and 987", "-91283472332", "+1"};
    Solution_LeetCode8 solution_leetCode8;
    for (int i = 0; i < strings.size(); ++i) {
        cout << solution_leetCode8.myAtoi(strings[i]) << endl;
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

void LeetCode12() {
    Solution_LeetCode12 solution_leetCode12;
    vector<int> nums = {3, 4, 9, 5, 8, 1994};
    for (int i = 0; i < nums.size(); ++i) {
        cout << solution_leetCode12.intToRoman(nums[i]) << endl;
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

void LeetCode17() {
    Solution_LeetCode17 solution_leetCode17;
    vector<string> str = {"23"};
    for (int i = 0; i < str.size(); ++i) {
        str = solution_leetCode17.letterCombinations(str[i]);
        for (int j = 0; j < str.size(); ++j) {
            cout << str[j] << " ";
        }
        cout << endl;
    }
}

void LeetCode19() {
    Solution_LeetCode19 solution_leetCode19;
}

void LeetCode21() {

}

void LeetCode22() {
    Solution_LeetCode22 solution_leetCode22;
    vector<int> nums = {3};
    for (int i = 0; i < nums.size(); ++i) {
        vector<string> ans = solution_leetCode22.generateParenthesis(nums[i]);
        for (int j = 0; j < ans.size(); ++j) {
            cout << ans[j] << endl;
        }
    }
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

void LeetCode30() {
    Solution_LeetCode30 solution_leetCode30;
    vector<string> strings = {"barfoothefoobarman", "wordgoodgoodgoodbestword"};
    vector<vector<string>> words = {{"foo",  "bar"},
                                    {"word", "good", "best", "word"}};
    for (int i = 0; i < strings.size(); ++i) {
        vector<int> nums = solution_leetCode30.findSubstring(strings[i], words[i]);
        for (int num : nums) {
            cout << num << " ";
        }
        cout << endl;
    }

}

void LeetCode31() {
    Solution_LeetCode31 solution_leetCode31;
    vector<vector<int>> nums = {{1, 2, 3},
                                {3, 2, 1},
                                {1, 1, 5},
                                {1, 3, 2}};
    for (int i = 0; i < nums.size(); i++) {
        solution_leetCode31.nextPermutation(nums[i]);
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

void LeetCode36() {
    Solution_LeetCode36 solution_leetcode36;
}

void LeetCode37() {
    Solution_LeetCode37 solution_leetCode37;
}

void LeetCode38() {
    Solution_LeetCode38 solution_leetCode38;
    vector<int> nums = {1, 4};
    for (int i = 0; i < nums.size(); ++i) {
        cout << solution_leetCode38.countAndSay(nums[i]) << endl;
    }
}

void LeetCode39() {
    Solution_LeetCode39 solution_leetCode39;
    vector<vector<int>> ans;
    vector<vector<int>> candidates = {{2, 3, 6, 7},
                                      {2, 3, 5}};
    vector<int> target = {7, 8};
    for (int i = 0; i < target.size(); ++i) {
        ans = solution_leetCode39.combinationSum(candidates[i], target[i]);
        for (int j = 0; j < ans.size(); ++j) {
            for (int z = 0; z < ans[j].size(); z++) {
                cout << ans[j][z] << " ";
            }
            cout << endl;
        }
        cout << "******" << endl;
    }
}

void LeetCode40() {
    Solution_LeetCode40 solution_leetCode40;
    vector<vector<int>> candidates = {{10, 1, 2, 7, 6, 1, 5},
                                      {2,  5, 2, 1, 2}};
    vector<int> target = {8, 5};
    vector<vector<int>> ans;
    for (int i = 0; i < candidates.size(); ++i) {
        ans = solution_leetCode40.combinationSum2(candidates[i], target[i]);
        for (int j = 0; j < ans.size(); ++j) {
            for (int k = 0; k < ans[j].size(); ++k) {
                cout << ans[j][k] << " ";
            }
            cout << endl;
        }
        cout << "*************" << endl;
    }
}

void LeetCode41() {
    Solution_LeetCode41 solution_leetCode41;
    vector<vector<int>> nums = {{1, 2, 0},
                                {3, 4, -1, 1},
                                {7, 8, 9,  11, 12}};
    for (int i = 0; i < nums.size(); ++i) {
        cout << solution_leetCode41.firstMissingPositive(nums[i]) << endl;
    }
}

void LeetCode42() {
    Solution_LeetCode42 solution_leetCode42;
    vector<int> nums = {0, 1, 0, 2, 1, 0, 3, 2, 1, 2, 1};
    cout << solution_leetCode42.trap1(nums) << endl;
}

void LeetCode43() {
    Solution_LeetCode43 solution_leetCode43;
    vector<string> nums1 = {"123", "65", "100", "123456789", "167141802233061013023557397451289113296441069", "654"};
    vector<string> nums2 = {"456", "654", "100", "987654321", "401716832807512840963", "0"};
    for (int i = 0; i < nums1.size(); ++i) {
        cout << solution_leetCode43.multiply(nums1[i], nums2[i]) << endl;
    }
}

void LeetCode44() {
    Solution_LeetCode44 solution_leetCode44;
    vector<string> s = {"aa", "aa", "cb", "adceb", "acdcb"};
    vector<string> p = {"a", "*", "?a", "*a*b", "a*c?b"};
    for (int i = 0; i < s.size(); ++i) {
        cout << solution_leetCode44.isMatch(s[i], p[i]) << endl;
    }

}

void LeetCode45() {
    vector<vector<int>> nums = {{2, 3, 1, 1, 4},
                                {2, 1},
                                {1, 2, 3},
                                {2, 3, 1}};
    Solution_LeetCode45 solution_leetCode45;
    for (int i = 0; i < nums.size(); ++i) {
        cout << solution_leetCode45.jump(nums[i]) << endl;
    }
}

void LeetCode46() {
    Solution_LeetCode46 solution_leetCode46;
    vector<vector<int>> nums = {{1, 2, 3}};
    vector<vector<int>> ans;
    for (int i = 0; i < nums.size(); ++i) {
        ans = solution_leetCode46.permute(nums[i]);
        for (int j = 0; j < ans.size(); ++j) {
            for (int k = 0; k < ans[j].size(); ++k) {
                cout << ans[j][k] << " ";
            }
            cout << endl;
        }
    }
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

void LeetCode55() {
    Solution_LeetCode55 solution_leetCode55;
    vector<vector<int>> nums = {{2, 3, 1, 1, 4},
                                {3, 2, 1, 0, 4},
                                {0, 2, 3}};
    for (int i = 0; i < nums.size(); ++i) {
        cout << solution_leetCode55.canJump(nums[i]) << "\n";
    }
}

void LeetCode62() {
    Solution_LeetCode62 solution_leetCode62;
    vector<int> m = {3, 7};
    vector<int> n = {2, 3};
    for (int i = 0; i < m.size(); ++i) {
        cout << solution_leetCode62.uniquePaths(m[i], n[i]) << endl;
    }
}

void LeetCode63() {
    Solution_LeetCode63 solution_leetCode63;
    vector<vector<vector<int>>> nums = {{{0, 0, 0},
                                                {0, 1, 0},
                                                {0, 0, 0}},
    };
    for (int i = 0; i < nums.size(); ++i) {
        cout << solution_leetCode63.uniquePathsWithObstacles(nums[i]) << endl;
    }
}

void LeetCode64() {
    Solution_LeetCode64 solution_leetCode64;
    vector<vector<vector<int>>> nums = {{{1, 3, 1},
                                                 {1, 5, 1},
                                                         {4, 2, 1}},
                                        {
                                         {1, 2}, {5, 6}, {1, 1}}};
    for (int i = 0; i < nums.size(); ++i) {
        cout << solution_leetCode64.minPathSum(nums[i]) << endl;
    }
}

void LeetCode69() {
    int x[10] = {4, 8};
    Solution_LeetCode69 solution_leetCode69;
    for (int i = 0; i < 2; ++i) {
        cout << solution_leetCode69.mySqrt_newton(x[i]) << endl;
    }
}

void LeetCode72() {
    vector<string> word1 = {"horse", "intention"};
    vector<string> word2 = {"ros", "execution"};
    Solution_LeetCode72 solution_leetCode72;
    for (int i = 0; i < word1.size(); ++i) {
        cout << solution_leetCode72.minDistance(word1[i], word2[i]) << endl;
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

void LeetCode84() {
    Solution_LeetCode84 solution_leetCode84;
    vector<vector<int>> nums = {{2, 1, 5, 6, 2, 3}};
    for (int i = 0; i < nums.size(); ++i) {
        cout << solution_leetCode84.largestRectangleArea_stack(nums[i]) << endl;
    }
}

void LeetCode85() {
    Solution_LeetCode85 solution_leetCode85;
    vector<vector<char>> matrix = {
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'}
    };
    cout << solution_leetCode85.maximalRectangle_stack(matrix) << endl;
}

void LeetCode87() {
    Solution_LeetCode87 solution_leetCode87;
    vector<string> s1 = {"great", "rgeat"};
    vector<string> s2 = {"abcde", "caebd"};
    for (int i = 0; i < s1.size(); ++i) {
        cout << solution_leetCode87.isScramble(s1[i], s2[i]) << endl;
    }
}

void LeetCode91() {
    Solution_LeetCode91 solution_leetCode91;
    vector<string> s = {"12", "226", "10", "01", "301"};
    for (string a : s) {
        cout << solution_leetCode91.numDecodings(a) << endl;
    }
}

void LeetCode96() {
    Solution_LeetCode96 solution_leetCode96;
    vector<int> nums = {3, 4};
    for (int i = 0; i < nums.size(); ++i) {
        cout << solution_leetCode96.numTrees(nums[i]) << endl;
    }
}

void LeetCode97() {
    vector<string> s1 = {"aabcc", "aabcc"};
    vector<string> s2 = {"dbbca", "dbbca"};
    vector<string> s3 = {"aadbbcbcac", "aadbbbaccc"};
    Solution_LeetCode97 solution_leetCode97;
    for (int i = 0; i < s1.size(); ++i) {
        cout << solution_leetCode97.isInterleave(s1[i], s2[i], s3[i]) << endl;
    }
}

void LeetCode100() {
    Solution_LeetCode100 solution_leetCode100;
}

void LeetCode121() {
    Solution_LeetCode121 solution_leetCode121;
    vector<vector<int>> nums = {{7, 1, 5, 3, 6, 4},
                                {7, 6, 4, 3, 1}};
    for (int i = 0; i < nums.size(); ++i) {
        cout << solution_leetCode121.maxProfit(nums[i]) << endl;
    }
}

void LeetCode123() {
    Solution_LeetCode123 solution_leetCode123;
    vector<vector<int>> nums = {{3, 3, 5, 0, 0, 3, 1, 4},
                                {1, 2, 3, 4, 5}};
    for (int i = 0; i < nums.size(); ++i) {
        cout << solution_leetCode123.maxProfit(nums[i]) << endl;
    }
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

void LeetCode134() {
    Solution_LeetCode134 solution_leetCode134;
    vector<vector<int>> gas = {{1, 2, 3, 4, 5},
                               {2, 3, 4},
                               {4},
                               {5, 1, 2, 3, 4}};
    vector<vector<int>> cost = {{3, 4, 5, 1, 2},
                                {3, 4, 3},
                                {5},
                                {4, 4, 1, 5, 1}};
    for (int i = 0; i < gas.size(); ++i) {
        cout << solution_leetCode134.canCompleteCircuit(gas[i], cost[i]) << endl;
    }
}

void LeetCode135() {
    Solution_LeetCode135 solution_leetCode135;
    vector<vector<int>> nums = {{1, 0, 2},
                                {1, 2, 2},
                                {1, 2, 87, 87, 87, 2, 1},
                                {1, 3, 4,  5,  2}};
    for (int i = 0; i < nums.size(); ++i) {
        cout << solution_leetCode135.candy(nums[i]) << endl;
    }
}

void LeetCode153() {
    Solution_LeetCode153 solution_leetCode153;
    vector<vector<int>> nums = {{3, 4, 5, 1, 2},
                                {4, 5, 6, 7, 0, 1, 2},
                                {1},
                                {4, 5, 1, 2, 3},
                                {2, 1}};
    for (int i = 0; i < nums.size(); ++i) {
        cout << solution_leetCode153.findMin(nums[i]) << endl;
    }
}

void LeetCode154() {
    Solution_LeetCode154 solution_leetCode154;
    vector<vector<int>> nums = {{1, 3, 5},
                                {2, 2, 2, 0, 1},
                                {1, 1}};
    for (int i = 0; i < nums.size(); ++i) {
        cout << solution_leetCode154.findMin(nums[i]) << endl;
    }
}

void LeetCode162() {
    Solution_LeetCode162 solution_leetCode162;
    vector<vector<int>> nums = {{1, 2, 3, 1},
                                {1, 2, 1, 3, 5, 6, 4}};
    for (int i = 0; i < nums.size(); ++i) {
        cout << solution_leetCode162.findPeakElement(nums[i]) << endl;
    }
}

void LeetCode415() {
    Solution_LeetCode415 solution_leetCode415;
    vector<string> nums1 = {"2", "123", "654987", "1", "19", "91"};
    vector<string> nums2 = {"3", "456", "123", "9", "1", "9"};
    for (int i = 0; i < nums1.size(); ++i) {
        cout << solution_leetCode415.addStrings(nums1[i], nums2[i]) << endl;
    }
}

void LeetCode416() {
    Solution_LeetCode416 solution_leetCode416;
    vector<vector<int>> nums = {{1, 5, 11, 5},
                                {1, 2, 3,  5},
                                {7, 2, 3,  8}};
    for (int i = 0; i < nums.size(); ++i) {
        cout << solution_leetCode416.dfs(nums[i]) << endl;
    }
}


int main() {
    cout << "HelloWorld!" << endl;
    LeetCode97();
    return 0;
}