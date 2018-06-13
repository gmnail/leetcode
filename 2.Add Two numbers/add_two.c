#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//efinition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

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

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
	struct ListNode* final;
	int cnt = 0;
	int sum = 0;

	final = create_node(0);
	add_tail(final,create_node(0));
	add_tail(final,create_node(0));
	add_tail(final,create_node(0));
	
	while(l1->next != NULL || l2->next != NULL)
	{
		l1 = l1->next;
		l2 = l2->next;
		
		sum = l1->val + l2-> val + cnt;			//这里还要考虑某个链表为NULL的情况
		if(sum >= 10)
		{
			cnt = 1;
			sum = sum - 10;
		}
		final->val = sum;
		
		printf("%d\n", final->val);
		final = final->next;
	}
	return final;  
}




int main(void)
{
	struct ListNode *l1 = create_node(0);
	struct ListNode *l2 = create_node(0);
	struct ListNode *final;
	final = (struct ListNode*)malloc(sizeof(struct ListNode));
	if(NULL == final)
		return 0;
	
	printf("-----------\n");

	add_tail(l1,create_node(3));
	add_tail(l1,create_node(4));
	add_tail(l1,create_node(2));
	
	printf("1\n");

	add_tail(l2,create_node(4));
	add_tail(l2,create_node(6));
	add_tail(l2,create_node(5));
	
	printf("2\n");
	
	final = addTwoNumbers(l1, l2);
	//printf("%d%d%d\n", final->val,final->next->val,final->next->next->val);
	
	return 0;
}

