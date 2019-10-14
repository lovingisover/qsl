#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
int main()
{
	SList mylist;
	SListInit(&mylist);
	int select = 1;
	int flag = 0;
	int pos = 0;
	DataType item = 0;
	DataType x = 0;
	DataType key = 0;
	SListNode *p = NULL;
	while (select)
	{
		printf("*****************************************\n");
		printf("* [1] push_back         [2] push_front  *\n");
		printf("* [3] show_list         [0] quit_system *\n");
		printf("* [4] pop_back          [5] pop_front   *\n");
		printf("* [6] insert_pos        [7] insert_val  *\n");
		printf("* [8] delete_pos        [9] delete_val  *\n");
		printf("* [10] find_pos         [11] find_val   *\n");
		printf("* [12] sort             [13] reverse    *\n");
		printf("* [14] length           [15] clear      *\n");
		printf("* [16] modify_pos       [17] modify_val *\n");
		printf("* [18] capacity                         *\n");
		printf("*****************************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("请输入要插入的数据<-1结束>:>");
			while (scanf("%d", &item), item != -1)
			{
				SListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("请输入要插入的数据<-1结束>:>");
			while (scanf("%d", &item), item != -1)
			{
				SListPushFront(&mylist, item);
			}
			break;
		case 3:
			SListShowList(&mylist);
			break;
		case 4:
			SListPopBack(&mylist);
			break;
		case 5:
			SListPopFront(&mylist);
			break;
		case 6:
			break;
		case 7:
			    	printf("请输入要插入的值:>\n");
				    scanf("%d", &item);
					SListInsertVal(&mylist, item);
			break;
		case 8:
			break;
		case 9:
			printf("请输入需要删除的值:>\n");
			scanf("%d", &item);
			SListDeleteVal(&mylist, item);
			break;
		case 10:
			break;
		case 11:
			printf("请输入要查找的数据:>\n");
			scanf("%d", &key);
			p = SListFindVal(&mylist, key);
			if (p == NULL)
				printf("查找的数据不存在.\n");
			else
				printf("查找的数据的地址为:>%p\n", p);
			break;
		case 12:
			SListSort(&mylist);
			break;
		case 13:
			SListReverse(&mylist);
			break;
		case 14:
			SListLength(&mylist);
			break;
		case 15:
			SListClear(&mylist);
			break;
		case 16:
			break;
		case 17:
			break;
		case 18:
			break;
		default:
			printf("输入错误，请重新输入.........\n");
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}