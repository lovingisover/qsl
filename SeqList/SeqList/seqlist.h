#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include"common.h"


#define SEQLIST_DEFAULT_SIZE 8
#define SEQLIST_INC_SIZE 5
typedef struct Seqlist
{
	DataType *base;
	size_t    capacite;
	size_t    size;
}Seqlist;



//函数的声明
void SeqlistInit(Seqlist *psl, int sz);
bool SeqlistPushback(Seqlist *psl, DataType x);
bool SeqlistPushFront(Seqlist *psl, DataType x);
bool SeqlistPopback(Seqlist *psl);
bool SeqlistPopfront(Seqlist *psl);
bool SeqlistInsertBypos(Seqlist *psl,size_t pos ,DataType x);
bool SeqlistInsertByval(Seqlist *psl, DataType x);
bool SeqlistDeleteBypos(Seqlist *psl, int pos);
bool SeqlistDeleteByval(Seqlist *psl, DataType x);
bool SeqlistFindByPos(Seqlist *psl, int pos, DataType *ret);
bool SeqlistFindByVal(Seqlist *psl, DataType x);
void SeqlistSort(Seqlist *psl);
void SeqlistReverse(Seqlist *psl);
void SeqlistClear(Seqlist *psl);
void SeqlistDestory(Seqlist *psl);
bool SeqlistModifyByPos(Seqlist *psl , int  pos, DataType x);
bool SeqlistModifyVal(Seqlist *psl, DataType x, DataType n);
size_t SeqlistCapacity(Seqlist *psl);
size_t SeqlistLength(Seqlist *psl);



//判断函数是否已满
bool SeqlistIsFull(Seqlist *psl)
{
	return psl->size >= psl->capacite;
}
//判断顺序表中是否为空
bool SeqlistEmpty(Seqlist *psl)
{
	return psl->size == 0;
}
//内部接口函数
bool _SeqlistInc(Seqlist *psl)
{
	assert(psl != NULL);
	psl->base = (int *)realloc(psl->base, sizeof(DataType)*(psl->capacite + SEQLIST_INC_SIZE));
	if (psl->base == NULL)
	{
		return false;
	}
	psl->capacite += SEQLIST_INC_SIZE;
	return true;


}
//初始化顺序表
void SeqlistInit(Seqlist *psl, int sz)
{
	psl->capacite = sz > SEQLIST_DEFAULT_SIZE ? sz : SEQLIST_DEFAULT_SIZE;
	psl->base = (DataType*)malloc(sizeof(DataType)*(psl->capacite));
	psl->size = 0;
}
//尾部插入数据
bool SeqlistPushback(Seqlist *psl, DataType x)
{
	assert(psl != NULL);
	if (SeqlistIsFull(psl) && !_SeqlistInc(psl))
	{
		printf("顺序表已满，%d无法插入.\n", x);
		return false;
	}
	psl->base[psl->size++] = x;
	return true;
}
//头部插入数据
bool SeqlistPushFront(Seqlist *psl, DataType x)
{

	if (SeqlistIsFull(psl) && !_SeqlistInc(psl))
	{
		printf("列表已满，请重新输入：\n");
		return false;
	}
	for (int i = psl->size; i > 0; --i)
	{
		psl->base[i] = psl->base[i - 1];
	}
	psl->base[0] = x;
	psl->size++;
	return true;
}
//打印出顺序表中的数据
void SeqlistShow(Seqlist *psl)
{
	assert(psl != NULL);

	for (int i = 0; i < psl->size; ++i)
	{
		printf("%d ", psl->base[i]);
	}
	printf("\n");
}
//尾部删除
bool  SeqlistPopback(Seqlist *psl)
{
	assert(psl != NULL);

	if (SeqlistEmpty(psl))
	{
		printf("顺序表已满，无法进行删除！\n");
		return false;
	}
	psl->size--;
	return true;
}
//头部删除(将前面的数据用后面的数据覆盖)
bool SeqlistPopfront(Seqlist *psl)
{
	assert(psl != NULL);
	if (SeqlistEmpty(psl))
	{
		printf("顺序表中没有数据，无法进行删除！\n");
		return false;
	}
	for (int i = 0; i < psl->size-1; ++i)
	{
		psl->base[i] = psl->base[i+1];
	}
	psl->size--;
	return true;
}
//按位置插入
 bool SeqlistInsertBypos(Seqlist *psl, int  pos, DataType x)
{
	 assert(psl != NULL);
	 if (pos < 0 || pos >psl->size)
	 {
		 printf("插入的坐标不合法. \n");
		 return false;
	 }
	 for (int i = psl->size; i > pos; --i)
	 {
		 psl->base[i] = psl->base[i - 1];
	 }
	 psl->base[pos] = x;
	 psl->size++;
	 return true;
}
 //按值插入
 bool SeqlistInsertByval(Seqlist *psl, DataType x)
 {
	 assert(psl != NULL);
	 if (SeqlistIsFull(psl) && !_SeqlistInc(psl))
	 {
		 printf("顺序表已满，无法插入！\n");
		 return false;
	 }
	 int i;
	 for (i = psl->size - 1; i >= 0 && x < psl->base[i]; --i)
	 {
		 psl->base[i + 1] = psl->base[i];
	 }
	 psl->base[i + 1] = x;
	 psl->size++;
	 return true;
 }
 bool SeqlistDeleteBypos(Seqlist *psl, int pos)
 {
	 assert(psl != NULL);
	 if (pos<0 || pos>psl->size - 1)
	 {
		 printf("输入的坐标不合法，请重新输入：\n");
		 return false;
	 }
	 for (int i = pos; i < psl->size - 1; ++i)
	 {
		 psl->base[i] = psl->base[i + 1];
	 }
	 psl->size--;
	 return true;
 }
 bool SeqlistFindByVal(Seqlist *psl, DataType x)
 {
	 assert(psl != NULL);
	 for (int i = 0; i < psl->size; ++i)
	 {
		 if (psl->base[i] = x)
		 {
			 return i;
		 }
	 }
	 return -1;
 }
 bool SeqlistDeleteByval(Seqlist *psl, DataType x)
 {
	 assert(psl != NULL);
	 int index = SeqlistFindByVal(psl, x);
	 if (index == -1)
	 {
		 printf("要删除的数据不存在\n");
		 return false;
	 }
	return  SeqlistDeleteBypos(psl, index);
	
 }
 bool SeqlistFindByPos(Seqlist *psl, int pos, DataType *ret)
 {
	 assert(psl != NULL);
	 if (pos < 0 || pos >psl->size-1)
	 {
		 printf("输入的坐标不合法\n");
		 return false;
	 }
	 *ret = psl->base[pos];
	 return true;
 }
 int SeqlistFindVal(Seqlist *psl, DataType x)
 {
	 assert(psl != NULL);
	 for (int i = 0; i < psl->size; ++i)
	 {
		 if (psl->base[i] == x)
		 {
			 return i;
		 }
		 return -1;
	 }


 }
 void SeqlistSort(Seqlist *psl)
 {
	 for (int i = 0; i<psl->size - 1; ++i)
	 {
		 for (int j = 0; j<psl->size - i - 1; ++j)
		 {
			 if (psl->base[j] > psl->base[j + 1])
			 {
				 Swap(&(psl->base[j]), &(psl->base[j + 1]));
			 }
		 }
	 }
 }
void SeqlistReverse(Seqlist *psl)
 {
	 assert(psl != NULL);
	 int begin = 0;
	 int end = psl->size - 1;
	 while (begin < end)
	 {
		 Swap(&(psl->base[begin]), &(psl->base[end]));
		 begin++;
		 end--;
	 }
 }
 void SeqlistClear(Seqlist *psl)
 {
	 assert(psl != NULL);
	  psl->size = 0;
 }
 void SeqlistDestory(Seqlist *psl)
 {
	 free(psl->base);
	 psl->base = NULL;
	 psl->capacite = psl->size = 0;
 }

 bool SeqlistModifyByPos(Seqlist  *psl, int pos, DataType x)
 {
	 assert(psl != NULL);
	 if (pos < 0 || pos > psl->size - 1)
	 {
		 printf("修改的位置不合法. \n");
		 return false;
	 }
	 psl->base[pos] = x;
	 return true;
 }
 bool SeqlistModifyVal(Seqlist *psl, DataType x, DataType n)
 {
	 assert(psl != NULL);
	 int index = SeqlistFindByVal(psl, x);
	 if (index == -1)
		 return false;
	 psl->base[index] = n;
	 return true;
 }
 size_t SeqlistLength(Seqlist *psl)
 {
	 return	psl->size;
 }
 size_t SeqlistCapacity(Seqlist *psl)
 {
	 assert(psl != NULL);
	 return psl->capacite;
 }















#endif