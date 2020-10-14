#define _CRT_SECURE_NO_WARNINGS 1
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* reversePrint(struct ListNode* head, int* returnSize)
{
	struct ListNode* p;
	int *a;
	int j = 0;
	p = head;
	while (p)
	{
		p = p->next;
		j++;
	}
	a = (int*)malloc(sizeof(int)*j);
	*returnSize = j;
	p = head;
	j = j - 1;
	while (j >= 0 && p != NULL)
	{
		a[j] = p->val;
		p = p->next;
		j--;
	}
	return a;
}