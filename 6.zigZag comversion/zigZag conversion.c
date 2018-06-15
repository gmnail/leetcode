#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* convert(char* s, int numRows) {
	int Len = strlen(s);
	char *p = (char *)malloc(Len * sizeof(char));
	int m = 0, i,j;
	int nodelen = 2*(numRows-1);
	
	if (Len == 0 || numRows == 0 || numRows == 1)//特殊情况特殊处理  
        return s; 
	
	memset(p, 0, sizeof(p));
	for(i=0; i<numRows; i++)
	{
		for(j=i; j<Len; j+=nodelen)
		{
			p[m++] = s[j];
			if(i != 0 && i != numRows-1 && j - 2*i + nodelen < Len)
				p[m++] = s[j-2*i+nodelen];
		}
	
	}
	return p;
}

int main(void)
{
	char *p = "PAYPALISHIRING";
	int numRows = 4;
	char *pZig = (char *)malloc(strlen(p) * sizeof(char));
	if(pZig == NULL)
		return -1;
	memset(pZig, 0, sizeof(pZig));
	printf("%s\n", p);
	pZig = convert(p, numRows);
	
	printf("%s\n", pZig);
	
	return 0;
}










