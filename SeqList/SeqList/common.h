#ifndef _COMMON_H_
#define _COMMON_H_


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>

//提高了程序的适用性
#define DataType int 
void Swap(DataType *a, DataType *b)
{
	DataType tmp = *a;
	*a = *b;
	*b = tmp;
}

#endif



