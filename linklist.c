#include "linklist.h"
#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>


// ��������
struct SnackLinkList *linklist_create(int x, int y, int length)
{
	struct SnackLinkList *head;
	struct SnackLinkList *tail;
	int i;

	// ��ͷ, ��������ʼ��
	head = (struct SnackLinkList *)malloc(sizeof(struct SnackLinkList));
	head->id = -1;
    // ��ͷ����ǰ��
    // 0, 0��������Ϊ3����
    // (0,0), (1,0), (2, 0)
    // (0,0), (1,0)Ϊ����
    // (2,0)Ϊ��ͷ
    head->x = x + length - 1;
    head->y = y;
	head->next = NULL;

	tail = head;

    // length-1��������
	for (i = 0; i < length - 1; i++) {
		// 1)�����ڵ㲢��ʼ��
		struct SnackLinkList *node;
		node = (struct SnackLinkList *)malloc(sizeof(struct SnackLinkList));
		node->x = x + i;
		node->y = y;
		node->next = NULL;

		// 2)β��������½ڵ�
		tail->next = node;

		// 3)β����ƶ����½ڵ�
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

// ����������ӡ
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

// return 0�ɹ���-1ʧ��
int linklist_delete(struct SnackLinkList *head, int id)
{
	struct SnackLinkList *prev;
	struct SnackLinkList *del;

	prev = head;
	// 1)�ҵ���ɾ���ڵ����һ���ڵ�
	while(prev != NULL && prev->next != NULL) {
		if (prev->next->id == id) {
			break;
		}

		prev = prev->next;
	}

	// û�ҵ�id
	if (prev->next == NULL) {
		return -1;
	}

	// 2)ɾ���ڵ�
	// 2.1)��ʱ�����ɾ���ڵ�del
	del = prev->next;

	// 2.2)������ɾ���ڵ�del
	prev->next = del->next;

	// 2.3)free del
	free(del);

	return 0;
}
