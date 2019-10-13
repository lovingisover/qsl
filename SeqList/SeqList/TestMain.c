#define _CRT_SECURE_NO_WARNINGS 1
//#include"seqlist.h"
#include"slist.h"
int main()
{
	//Seqlist mylist;
	//SeqlistInit(&mylist, SEQLIST_DEFAULT_SIZE);

	int select = 1;
	int pos = 0;
	DataType item;
	DataType ret;
	bool flag;
	while (select)
	{
		printf("******************************************\n");
		printf("* [1] push_back                    [2] push_front   *\n");
		printf("* [3] show_list                      [0] quit_system  *\n");
		printf("* [4] pop_back                      [5] pop_front    *\n");
		printf("* [6] insert_pos                     [7] insert_val    *\n");
		printf("* [8] delete_pos                    [9] delete_val    *\n");
		printf("* [10] find_pos                     [11] find_val     *\n");
		printf("* [12] sort                             [13] reverse       *\n");
		printf("* [14] length                         [15] clear           *\n");
		printf("* [16] modify_pos                [17] modify_val *\n");
		printf("* [18] capacity                                                *\n");
		printf("******************************************\n");
		printf("��ѡ��:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("������Ҫ���������<-1����>:>");
			while (scanf("%d", &item), item != -1)
			{
				SeqlistPushback(&mylist, item);
			}
			SeqlistShow(&mylist);
			break;
		case 2:
			printf("������Ҫ���������<-1����>:>");
			while (scanf("%d", &item), item != -1)
			{
				SeqlistPushFront(&mylist, item);
			}
			SeqlistShow(&mylist);
			break;
		case 3:
			SeqlistShow(&mylist);
			SeqlistShow(&mylist);
			break;
		case 4:
			SeqlistPopback(&mylist);
			SeqlistShow(&mylist);
			break;
		case 5:
			SeqlistPopfront(&mylist);
			SeqlistShow(&mylist);
			break;
		case 6:
			printf("������Ҫ�����λ�ã�\n");
			scanf("%d", &pos);
			printf("������Ҫ�����ֵ��\n");
			scanf("%d", &item);
			SeqlistInsertBypos(&mylist, pos, item);
			SeqlistShow(&mylist);
			break;
		case 7:
			printf("������Ҫ�����ֵ��\n");
			scanf("%d", item);
			SeqlistInsertByval(&mylist, item);
			SeqlistShow(&mylist);
			break;
		case 8:
			printf("������Ҫɾ����λ�ã�\n");
			scanf("%d ", &pos);
			SeqlistDeleteBypos(&mylist, pos);
			SeqlistShow(&mylist);
			break;
		case 9:
			printf("��������Ҫɾ����ֵ��\n");
			scanf("%d ", &item);
			SeqlistDeleteByval(&mylist, item);
			SeqlistShow(&mylist);
			break;
		case 10:
			printf("������Ҫ���ҵ�λ�ã�\n");
			scanf("%d", &pos);
		    flag =	SeqlistFindByPos(&mylist, pos, &ret);
			if (flag)
				printf("���ҵ�����Ϊ��.\n");
			else
				printf("���ҵ�����Ϊ��. \n");
			break;
		case 11:
			printf("��������Ҫ���ҵ�ֵ��\n");
			scanf("%d", &item);
		    pos =   SeqlistFindByVal(&mylist, item);
			if (pos == -1)
				printf("���ҵ��±겻����.\n");
			else
				printf("�������ڵ��±�Ϊ%d\n", pos);
			break;
		case 12:
			SeqlistSort(&mylist);
			SeqlistShow(&mylist);
			break;
		case 13:
			SeqlistReverse(&mylist);
			SeqlistShow(&mylist);
			break;
		case 14:
			SeqlistLength(&mylist);
			SeqlistShow(&mylist);
			break;
		case 15:
			SeqlistClear(&mylist);
			SeqlistShow(&mylist);
			break;
		case 16:
			printf("������λ�ã�\n");
			scanf("%d", &pos);
			printf("��������Ҫ�޸ĵ�ֵ��\n");
			scanf("%d ", &item);
			SeqlistModifyByPos(&mylist, pos, item);
			SeqlistShow(&mylist);
			break;
		case 17:
			printf("��������Ҫ�޸ĵ�ֵ��\n");
			scanf("%d ", &item);

			printf("�������޸��Ժ��ֵ��\n");
			scanf("%d ", &pos);
			SeqlistModifyVal(&mylist, item, pos);
			SeqlistShow(&mylist);
			break;
		case 18:
			printf("capacity = %d \n", SeqlistCapacity(&mylist));
			break;
		default:
			printf("�����������������......\n");
			break;
		}
		system("pause");
		system("cls");
	}
	SeqlistDestory(&mylist);
	return 0;
}