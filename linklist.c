#include "linklist.h"
#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>


// 创建链表
// data，数据数组
// data_length，数组长度
struct SnackLinkList *linklist_create(int x[], int y[], int data_length)
{
	struct SnackLinkList *head;
	struct SnackLinkList *tail;
	int i;

	// 创建并初始化头结点
	head = (struct SnackLinkList *)malloc(sizeof(struct SnackLinkList));
	head->id = -1;
    head->x = 0;
	head->next = NULL;

	tail = head;
	for (i = 0; i < data_length; i++) {
		// 1)创建节点并初始化
		struct SnackLinkList *node;
		node = (struct SnackLinkList *)malloc(sizeof(struct SnackLinkList));
		node->x = x[i];
		node->y = y[i];
		node->next = NULL;

		// 2)尾结点连接新节点
		tail->next = node;

		// 3)尾结点移动到新节点
		tail = node;
	}

	return head;
}

// 遍历链表，打印
void linklist_printf(struct SnackLinkList *head, int x, int y)
{
	struct SnackLinkList *p;

	// for (i = 0; i < n; i++)
	for (p = head; p != NULL; p = p->next)
	{
        if (p->x == x && p->y == y)
        {
            printw("[]");
        }
        else
        {
            printw("  ");
        }
	}
}

// return 0成功，-1失败
int linklist_delete(struct SnackLinkList *head, int id)
{
	struct SnackLinkList *prev;
	struct SnackLinkList *del;

	prev = head;
	// 1)找到待删除节点的上一个节点
	while(prev != NULL && prev->next != NULL) {
		if (prev->next->id == id) {
			break;
		}

		prev = prev->next;
	}

	// 没找到id
	if (prev->next == NULL) {
		return -1;
	}

	// 2)删除节点
	// 2.1)临时保存待删除节点del
	del = prev->next;

	// 2.2)从链表删除节点del
	prev->next = del->next;

	// 2.3)free del
	free(del);

	return 0;
}
