#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum pukeType {
	SOLA = 0,	//单张
	PAIR,
	STRAIGHT,	//顺子
	TRIPLETON,	//三张
	BOMB,
	KINGFRIED,
	NONE,
};


struct puKe {
	int number;		//第一个字符转换成的数字
	char *letter;	//输入的字符串
	int puketype;
};

struct puKe *strFirst;
struct puKe *strLast;

//将输入的字符串第一个字符转换成一定大小的数字 J--11 Q--12 K--13 A--14 2--15 joker--16 JOKER--17
int transfer(char *str)
{
	int number = 0;
	if(*str == 'Q')
		number = 12;
	else if(*str == 'K')
		number = 13;
	else if(*str == 'A')
		number = 14;
	else if(*str == '2')
		number = 15;
	else if(*str == 'j')
		number = 16;
	else if(*str == 'J') {
		str++;
		if(*str == 'O')
			number = 17;
		else
			number = 11;
	}
	else
		number = *str - '0';

	return number;
}

struct puKe *comPare(struct puKe *str1, struct puKe *str2)
{
	//处理不同PUKETYPE的情况
	if(str1->puketype != str2->puketype) {
		if(str1->puketype == KINGFRIED)
			return str1;
		else if(str2->puketype == KINGFRIED)
			return str2;
		else if(str1->puketype == BOMB)
			return str1;
		else if(str2->puketype == BOMB)
			return str2;
		else
			return NULL;
	}
	else 
	{
		//无论是单张、一对、三张、顺子、炸弹，对于相同的类型，比较第一个数就能知道大小
		if(transfer(str1->letter) <= transfer(str2->letter))
			return str2;
		else
			return str1;
	}
}

//将输入的一个字符串 拆分成两个子字符串
void split(char *str)
{
	int i = 0, j = 0;
	while(*str != '-') {
		strFirst->letter[i] = *str;
		i++;
		str++;
	}

	while(*str++ != '\0')
	{
		strLast->letter[j] = *str;
		j++;
	}
}

void init_struct(void)
{
	strFirst = (struct puKe *)malloc(sizeof(struct puKe));
	strFirst->letter = (char *)malloc(32 * sizeof(char));
	strLast = (struct puKe *)malloc(sizeof(struct puKe));
	strLast->letter = (char *)malloc(32 * sizeof(char));
}

char *remove_space(char *str)
{
	char *temp = (char *)malloc(64 * sizeof(char));
	int k = 0;
	while(*str != '\0')
	{
		while(*str == ' ')
			str++;
		temp[k] = *str;
		k++;
		str++;
	}
	return temp;
}

void handle_str(char **str1, struct puKe *strtmp)
{
	int i,j,flags = 1, k;
	char *str = *str1;
	int len = strlen(str);
		
	if(!strcmp(str, "jokerJOKER")) {
		strtmp->puketype = KINGFRIED;
		return;
	}

	for(j=0; j<=strlen(str); j++) {
		k = j;
		if(transfer(&str[j]) == 1) {
			j++;
			if(transfer(&str[j]) == 0) {
				j--;
				str[j] = ':';
				while((j+2) < strlen(str)) {
					j++;
					str[j] = str[j+1];
				}
				str[j+1] = '\0'; 
				j = k;
			}
		}
	}
	//这里分析比较字符串中的字符，设置puketype值
	if(strlen(str) == 5) 
	{
		if(transfer(&str[0])==(transfer(&str[1])-1))
			if(transfer(&str[0]) == (transfer(&str[2])-2))
				if(transfer(&str[0]) == (transfer(&str[3])-3))
					if(transfer(&str[0]) == (transfer(&str[4])-4))
					{
						strtmp->puketype = STRAIGHT;
					}
					else 
					{
						strtmp->puketype = NONE;
					}
	}
	else {
		if(strlen(str) == 1)
			flags = 1;
		else {
				while(*str != '\0') {
					if(*str == *(++str)) {
						flags++;
					}
				}
			}

		switch(flags) {
		case 1:
			strtmp->puketype = SOLA;
			break;
		case 2:
			strtmp->puketype = PAIR;
			break;
		case 3:
			strtmp->puketype = TRIPLETON;
			break;
		case 4:
			strtmp->puketype = BOMB;
			break;
		case 5:
			strtmp->puketype = NONE;
			break;
		}
	}

}

int main(void)
{
	char *strInput = (char *)malloc(64 * sizeof(char));
	struct puKe *puke = (struct puKe *)malloc(sizeof(struct puKe));
	char *tempstrFirst = (char *)malloc(64 * sizeof(char));
	char *tempstrLast = (char *)malloc(64 * sizeof(char));
	
	init_struct();
	scanf("%[^\n]", strInput);		//scanf遇到空格就会停止输入 这样的方法可以使它在遇到\n才会停止
	//printf("%s\n", strInput);
	split(strInput);
	
	//在这里对输入的字符串进行分类
	//1.先将字符串的空格去除后保存
	tempstrFirst = remove_space(strFirst->letter);
	
	tempstrLast = remove_space(strLast->letter);

	handle_str(&tempstrFirst, strFirst);
	handle_str(&tempstrLast, strLast);

	char *tmp1 = strFirst->letter;
	char *tmp2 = strLast->letter;

	strFirst->letter = tempstrFirst;
	strLast->letter = tempstrLast;
	puke = comPare(strFirst, strLast);
	
	strFirst->letter = tmp1;
	strLast->letter = tmp2;

	printf("%d\n", strFirst->puketype);
	printf("%d\n", strLast->puketype);
	if(puke == NULL)
		printf("error\n");
	else
		printf("%s\n", puke->letter);
	

	return 0;
}












