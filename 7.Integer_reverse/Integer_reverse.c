#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long ten_plus(long x, int cnt)
{
	while(cnt !=0) {
		x = x *10;
		cnt--;
	}
	return x;
}


//伪算法
int reverse(int x) {
	int k = 0, j;
	int cnt = 0;
	long result = 0;
	int buf[100];
    
    if(x >= 2147483648 || x<= -2147483648)
		return 0;
	
    while(x != 0)
	{
		k = x%10;
		buf[cnt] = k;
		cnt++;
		x = x/10;
	}
	
	k = cnt;
	for(j = 0; j < k; j++) {
		cnt--;
		result += ten_plus(buf[j], cnt);
		if(result >= 2147483648 || result <= -2147483648)
			return 0;
	}

	return result;
}

int main(void)
{
	int x = 1534236469;
	long rev = 0;
	
	rev = reverse(x);
	printf("%ld\n",rev);
	return 0;
}






































