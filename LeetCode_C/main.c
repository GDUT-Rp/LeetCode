#include <stdio.h>

#include "LeetCode3.h"
#include "LeetCode27.h"

void LeetCode3_begin(){
    char str[50] = "abcabcbb";
    printf("%d\n", LeetCode3(str));
}

void LeetCode27_begin(){
    int nums1[] = {3, 2, 1, 2, 3};
    int nums2[] = {3, 2, 1, 2, 3};
    printf("%d\n", removeElement(nums1, 5, 2));
    printf("%d\n", removeElementBySwap(nums2, 5, 2));
}


int main() {
    printf("Hello, World!\n");
    LeetCode27_begin();
    return 0;
}