#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//判断一个字符串是否是回文
//两头凑法，找到字符串的最后一个字符，与第一个字符比较。然后各自向中间移动，逐个比较。如果////比较中出现不同，则不是回文。当二者相遇时，一直都相同，则字符串为回文。

int shrinkCheckPalindrome(char *s, int low, int high)
{
	while(low < high)
	{
		if(s[low] == s[high]) {
			low++;
			high--;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

char* longestPalindrome(char* s) 
{
	int Len = strlen(s);
	char *p = (char *)malloc(Len * sizeof(char));
	int m = 0;
    memset(p, 0 ,sizeof(p));
	
	for(int size = Len; size>0; size--) {
		for(int low = 0, high = low+size-1; high<Len;low++, high++) {
			if(shrinkCheckPalindrome(s, low, high)) {
				for(int k = low; k<=high;) 
				{
					p[m++] = s[k++];
				}	
				return p;  
			}
		}
	
	}
    return NULL;
}



int main()
{
	char *p = "dddddddd";
	char *s = (char *)malloc(strlen(p) * sizeof(char));
	s = longestPalindrome(p);
	
	printf("%s\n", s);
	
	return 0;
}














