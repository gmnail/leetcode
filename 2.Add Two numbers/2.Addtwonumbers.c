#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode *p1 = l1;
	struct ListNode *p2 = l2;
	struct ListNode *result=(struct ListNode *)malloc(sizeof(struct ListNode));  
    result->val=0;

	struct ListNode *p = NULL;
	int c = 0;
	
	while(p1 != NULL || p2 != NULL || c!=0)
	{
		if(p == NULL)
		{
			p = result;
		}
		else{
			p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
			p->next->val = 0;
			p = p->next;
		}
		int a = (p1==NULL?0:p1->val);
		int b = (p2==NULL?0:p2->val);
		int s = (a+b+c)%10;
		c = (a+b+c)/10;
		p->val = s;
		p->next = NULL;
		
		printf("%d\n", p->val);
		p1 = (p1==NULL?NULL:p1->next);
		p2 = (p2==NULL?NULL:p2->next);
	}

	return result;
}

struct ListNode* create_node(data)
{
	struct ListNode* l1 = NULL;
	
	l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	if(l1 == NULL)
		return NULL;
	memset(l1, 0 , sizeof(struct ListNode));
	
	l1->val = data;
	l1->next = NULL;
	
	return l1;
}

void add_tail(struct ListNode* pH,struct ListNode* new)
{
	struct ListNode* p = pH;
	
	while(NULL != p->next)
	{
		p = p->next;
	}
	p->next = new;
}

int main(void)
{
	struct ListNode *l1,*l2, *p; 
	l1 = create_node(0);
	l2 = create_node(0);
	
	add_tail(l1, create_node(2));
	add_tail(l1, create_node(4));
	add_tail(l1, create_node(3));
	printf("%d%d%d\n", l1->next->val,l1->next->next->val,l1->next->next->next->val);
	
	add_tail(l2, create_node(5));
	add_tail(l2, create_node(6));
	add_tail(l2, create_node(4));
	printf("%d%d%d\n", l2->next->val,l2->next->next->val, l2->next->next->next->val);
	
	
	p = addTwoNumbers(l1, l2);
	printf("%d%d%d\n", p->next->val,p->next->next->val, p->next->next->next->val);
	
	return 0;
}




























