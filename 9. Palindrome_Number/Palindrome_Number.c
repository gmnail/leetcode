
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int isPalindrome(int x) {
    char *str = (char *)malloc(sizeof(char));
	int i = 0, m = 0, n = 0;
	
	if(x < 0)
		return 0;
	while(x != 0)
	{
		str[i] = x%10;
		i++;
		x = x/10;
	}
	n = i-1;
	while(str[m] == str[n])
	{
		m++;
		n--;
		if(m == n || m >= n)
			return 1;
	}

	return 0;
}
//精简模式——速度还可以更快，只考虑一半的数字 反转 与前一半比较
bool isPalindrome(int x) {  
  
    int reverse = 0;  
    int back = x;  
      
    if(x < 0)  
        return false;  
    while(x)  
    {  
        reverse = reverse * 10 + x % 10;  
        x /= 10;  
    }  
      
   if(back == reverse)  
        return true;  
    return false;  
      
}  


int main(void)
{
	int x;
	printf("请输入一个数:\t");
	scanf("%d", &x);
	int k = isPalindrome(x);
	printf("%d\n", k);
	
	return 0;
}




