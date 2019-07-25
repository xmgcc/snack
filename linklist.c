#include "linklist.h"
#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>


// 创建链表
struct SnackLinkList *linklist_create(int x, int y, int length)
{
	struct SnackLinkList *head;
	struct SnackLinkList *tail;
	int i;

	// 蛇头, 创建并初始化
	head = (struct SnackLinkList *)malloc(sizeof(struct SnackLinkList));
	head->id = -1;
    // 蛇头在最前面
    // 0, 0创建长度为3的蛇
    // (0,0), (1,0), (2, 0)
    // (0,0), (1,0)为蛇身，
    // (2,0)为蛇头
    head->x = x + length - 1;
    head->y = y;
	head->next = NULL;

	tail = head;

    // length-1创建蛇身
	for (i = 0; i < length - 1; i++) {
		// 1)创建节点并初始化
		struct SnackLinkList *node;
		node = (struct SnackLinkList *)malloc(sizeof(struct SnackLinkList));
		node->x = x + i;
		node->y = y;
		node->next = NULL;

		// 2)尾结点连接新节点
		tail->next = node;

		// 3)尾结点移动到新节点
		tail = node;
	}

	return head;
}

int linklist_find(struct SnackLinkList *head, int x, int y)
{
	struct SnackLinkList *p;

	// for (i = 0; i < n; i++)
	for (p = head; p != NULL; p = p->next)
	{
        if (p->x == x && p->y == y)
        {
            return 0;
        }
	}

    return -1;
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
