//
// Created by Lenovo on 2019/1/1.
//

#ifndef LEETCODE_C_LEETCODE3_H
#define LEETCODE_C_LEETCODE3_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int LeetCode3(char* s) {
    int len=strlen(s);
    int count=0;
    int start=0;   //记录新子串的起始位置
    bool isOk=true;
    //char *tempS;
    //tempS=(char *)malloc(len);     无需额外的数组来存储

    int longLastIndex=0;
    int longLenth=0;

    for(int i=0;i<len;i++){
        isOk=true;
        for(int j=0;j<count;j++){
            if(s[j+start]==s[i]){     //改动处
                isOk=false;
                start=j+start+1;             //改动处
                break;
            }

        }
        if(isOk){
            count++;
            if(i==len-1&&longLenth<count){
                longLenth=count;
            }
        }
        else{
            if(longLenth<count){
                longLenth=count;
            }
            count=i-start+1;   //改动处

        }
    }

    return longLenth;
}


#endif //LEETCODE_C_LEETCODE3_H
