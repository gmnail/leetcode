#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//start用来判断指针的位置，避免重复比较两个字符
int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
	int count = 0;
	int start = 0;
	bool isOk = true;
	
	int longlength = 0;
	
	for(int i=0; i<len; i++)
	{
		isOk = true;
		for(int j=0; j<count; j++)
		{
			if(s[j+start] == s[i])
			{
				isOk = false;
				start = j+start+1;	//不能用i
				break;
			}
		}
		
		if(isOk) {
			count++;
			if(i==len-1&&longLenth<count){
                longLenth=count;
            }
		}
		else {
			if(longLenth<count){
                longLenth=count;
            }
			count = i-start+1;
		}
	}
	return longLenth;
}

















