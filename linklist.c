#include "linklist.h"
#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>


// 创建链表
// data，数据数组
// data_length，数组长度
struct LinkList *linklist_create(int data[], int data_length)
{
	struct LinkList *head;
	struct LinkList *tail;
	int i;

	// 创建并初始化头结点
	head = (struct LinkList *)malloc(sizeof(struct LinkList));
	head->id = -1;
	head->next = NULL;

	tail = head;
	for (i = 0; i < data_length; i++) {
		// 1)创建节点并初始化
		struct LinkList *node;
		node = (struct LinkList *)malloc(sizeof(struct LinkList));
		node->id = data[i];
		node->next = NULL;

		// 2)尾结点连接新节点
		tail->next = node;

		// 3)尾结点移动到新节点
		tail = node;
	}

	return head;
}

// 遍历链表，打印
void linklist_printf(struct LinkList *head)
{
	struct LinkList *p;

	// for (i = 0; i < n; i++)
	for (p = head; p != NULL; p = p->next)
	{
		printf("%d\n", p->id);
	}
}

// return 0成功，-1失败
int linklist_delete(struct LinkList *head, int id)
{
	struct LinkList *prev;
	struct LinkList *del;

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