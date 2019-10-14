#ifndef _SLIST_H_
#define _SLIST_H_
#include"common.h"
typedef struct SListNode
{
	DataType data;
	struct SListNode *next;
}SListNode;
typedef struct SList
{
	SListNode *first;
	SListNode *last;
	size_t          size;
}SList;
SListNode * _Buynode(DataType x)
{
	SListNode *s = (SListNode*)malloc(sizeof(SListNode));
	if (s == NULL)
		return NULL;
	s->next = NULL;
	s->data = x;
	return s;
}
void SListInit(SList *plist);
void SListShowList(SList *plist);
bool SListPushBack(SList *plist, DataType x);
bool SListPushFront(SList *plist, DataType x);
bool SListPopBack(SList *plist);
bool SListPopFront(SList *plist);
void SListInsertVal(SList *plist, DataType x);
bool SListDeleteVal(SList *plist, DataType x);
SListNode* SListFindVal(SList *plist, int pos);
void SListSort(SList *plist);
void SListReverse(SList *plist);
size_t SListLength(SList *plist);
void SListClear(SList *plist);
////////////////////////////////////////////////////////////////
void SListShowList(SList *plist)
{
	SListNode *p = plist->first->next;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("over.\n");
}
void SListInit(SList *plist)
{
	SListNode *s = _Buynode(0);
	plist->first = plist->last = s;
	plist->size = 0;
}
bool SListPushBack(SList *plist, DataType x)
{
	SListNode *s = _Buynode(x);
	if (s == NULL)
		return false;
	plist->last->next = s;
	plist->last = s;
	plist->size++;
	return true;
}
bool SListPushFront(SList *plist, DataType x)
{
	SListNode *s = _Buynode(x);
	if (s == NULL)
		return false;
	s->next = plist->first->next;
	plist->first->next = s;
	if (plist->size == 0)
		plist->last = s;
	plist->size++;
	return true;
}
bool SListPopBack(SList *plist)
{
	SListNode *p = NULL;
	if (plist->size == 0)
		return false;
	p = plist->first;
	while (p->next != plist->last)
		p = p->next;
	p->next = NULL;
	free(plist->last);
	plist->last = p;
	plist->size--;
	return true;
}
bool SListPopFront(SList *plist)
{
	SListNode *p = NULL;
	if (plist->size == 0)
		return false;
	p = plist->first->next;
	plist->first->next = p->next;
	free(p);
	plist->size--;
	if (plist->size == 0)
		plist->last = plist->first;
	return true;
}
void SListInsertVal(SList *plist, DataType x)
{
	SListNode *p = plist->first;
	while (p->next != NULL && x > p->next->data)
		p = p->next;
	SListNode *s = _Buynode(x);
	if (p->next == NULL)
	{
		p->next = s;
		plist->last = s;
	}
	else
	{
		s->next = p->next;
		p->next = s;
	}
	plist->size++;
}
bool SListDeleteVal(SList *plist, DataType x)
{
	SListNode *q;
	SListNode *p = plist->first;
	while (p->next != NULL && p->next->data != x)
		p = p->next;
	if (p->next == NULL)
		return false;
	q = p->next;
	if (p->next == plist->last)
		plist->last = p;
	p->next = q->next;
	free(q);
	plist->size--;
	return true;
}
SListNode* SListFindVal(SList *plist, int key)
{
	SListNode *p = plist->first->next;
	while (p != NULL && p->data != key)
		p = p->next;
	return p;
}
void SListSort(SList *plist)
{
	if (plist->size > 1)
	{
		SListNode *prev;
		SListNode *p = plist->first->next;
		SListNode *q = p->next;
		plist->last = p;
		plist->last->next = NULL;

		p = q;
		while (p != NULL)
		{
			q = q->next;
			prev = plist->first;
			while (prev->next != NULL && p->data>prev->next->data)
				prev = prev->next;

			if (prev->next == NULL)
			{
				prev->next = p;
				plist->last = p;
				p->next = NULL;
			}
			else
			{
				p->next = prev->next;
				prev->next = p;
			}
			p = q;
		}
	}
}
void SListReverse(SList *plist)
{

		SListNode *p = plist->first->next;
		SListNode *q = p->next;
		plist->last = p;
		plist->last->next = NULL;
		p = q;
		while (p != NULL)
		{
			q = p->next;
			p->next = plist->first->next;
			plist->first->next = p;
			p = q;
		}
}
size_t SListLength(SList *plist)
{
	return plist->size;
}
void SListClear(SList *plist)
{
	SListNode *p = plist->first->next;
	while (p != NULL)
	{
		plist->first->next = p->next;
		free(p);
			p = plist->first->next;
	}
	plist->last = plist->first;
	plist->size--;
}
#endif