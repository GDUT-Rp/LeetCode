#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <set>

#include "LeetCode3.h"

using namespace std;

void LeetCode3(){
    string s = "abcabcbb";
    Solution solution;
    cout << solution.lengthOfLongestSubstring(s) << endl;
    cout << solution.improveByVector(s) << endl;
}

int main() {
    cout << "HelloWorld!" << endl;
    return 0;
}