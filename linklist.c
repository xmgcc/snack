#include "linklist.h"
#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>


// ��������
// data����������
// data_length�����鳤��
struct SnackLinkList *linklist_create(int x[], int y[], int data_length)
{
	struct SnackLinkList *head;
	struct SnackLinkList *tail;
	int i;

	// ��������ʼ��ͷ���
	head = (struct SnackLinkList *)malloc(sizeof(struct SnackLinkList));
	head->id = -1;
    head->x = 0;
	head->next = NULL;

	tail = head;
	for (i = 0; i < data_length; i++) {
		// 1)�����ڵ㲢��ʼ��
		struct SnackLinkList *node;
		node = (struct SnackLinkList *)malloc(sizeof(struct SnackLinkList));
		node->x = x[i];
		node->y = y[i];
		node->next = NULL;

		// 2)β��������½ڵ�
		tail->next = node;

		// 3)β����ƶ����½ڵ�
		tail = node;
	}

	return head;
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
