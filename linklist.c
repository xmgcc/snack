#include "linklist.h"
#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>


// ��������
// data����������
// data_length�����鳤��
struct LinkList *linklist_create(int data[], int data_length)
{
	struct LinkList *head;
	struct LinkList *tail;
	int i;

	// ��������ʼ��ͷ���
	head = (struct LinkList *)malloc(sizeof(struct LinkList));
	head->id = -1;
	head->next = NULL;

	tail = head;
	for (i = 0; i < data_length; i++) {
		// 1)�����ڵ㲢��ʼ��
		struct LinkList *node;
		node = (struct LinkList *)malloc(sizeof(struct LinkList));
		node->id = data[i];
		node->next = NULL;

		// 2)β��������½ڵ�
		tail->next = node;

		// 3)β����ƶ����½ڵ�
		tail = node;
	}

	return head;
}

// ����������ӡ
void linklist_printf(struct LinkList *head)
{
	struct LinkList *p;

	// for (i = 0; i < n; i++)
	for (p = head; p != NULL; p = p->next)
	{
		printf("%d\n", p->id);
	}
}

// return 0�ɹ���-1ʧ��
int linklist_delete(struct LinkList *head, int id)
{
	struct LinkList *prev;
	struct LinkList *del;

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