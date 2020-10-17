#define _CRT_SECURE_NO_WARNINGS 1
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* deleteNode(struct ListNode* head, int val)
{
	if (NULL == head)
	{
		return NULL;
	}
	if (val == head->val)
	{
		return head->next;
	}
	struct ListNode*pre = head;
	while ((pre->next != NULL) && (pre->next->val != val))
	{
		pre = pre->next;
	}
	if (pre->next != NULL)
	{
		pre->next = pre->next->next;
	}
	return head;
}
