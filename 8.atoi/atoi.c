#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int myAtoi(char* str) {
    long long value = 0;
	int sign = 1;
	
	if(str == NULL)
		return 0;
	while(*str == ' ') {
		str++;
		if(*str == '\n')
			return 0;
	}

	if(*str == '-') {
		str++;
		sign = -1;
	}
	else if(*str == '+') {
		str++;
		sign = 1;
	}
	
	if((*str - '0') < 0 || (*str - '9') > 0)
		return 0;
	
	while(*str)
	{
		value = value * 10 + (*str-'0');
		if(value >= 2147483648UL && sign == 1) {
			return 2147483647UL;
		}
		else if(value >= 2147483648UL && sign == -1) {
			return -2147483648UL;
		}
		str++;
		if((*str - '0') < 0 || (*str - '9') > 0)
			break;
	}
	return sign * value;
}

int main(void)
{
	char *p = "18446744073709551617";
	int k = myAtoi(p);
	printf("%d\n", k);

	return 0;
}




