#define _CRT_SECURE_NO_WARNINGS 1
typedef struct
{
	int stack1[10000];
	int stack2[10000];
	int top1;
	int top2;
} CQueue;


CQueue* cQueueCreate()
{
	CQueue *newQueue = (CQueue*)malloc(sizeof(CQueue));
	newQueue->top1 = -1;
	newQueue->top2 = -1;
	return newQueue;
}

void cQueueAppendTail(CQueue* obj, int value)
{
	obj->stack1[++(obj->top1)] = value;
}

int cQueueDeleteHead(CQueue* obj)
{
	if (obj->top2 > -1)
	{
		return obj->stack2[obj->top2--];
	}
	if (obj->top1 == -1)
	{
		return -1;
	}
	while (obj->top1 > -1)
	{
		obj->stack2[++obj->top2] = obj->stack1[obj->top1--];
	}
	return obj->stack2[obj->top2--];
}

void cQueueFree(CQueue* obj)
{
	free(obj);
}

/**
* Your CQueue struct will be instantiated and called as such:
* CQueue* obj = cQueueCreate();
* cQueueAppendTail(obj, value);

* int param_2 = cQueueDeleteHead(obj);

* cQueueFree(obj);
*/