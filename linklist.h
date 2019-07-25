#ifndef __LINKLIST_H__
#define __LINKLIST_H__

// c++�������ᶨ��__cplusplus�����
#ifdef __cplusplus
// ����c++����������δ�����c����
extern "C" {
#endif

struct LinkList {
	int id;
	struct LinkList *next;
};

// ��������
// data����������
// data_length�����鳤��
struct LinkList *linklist_create(int data[], int data_length);

// ����������ӡ
void linklist_printf(struct LinkList *head);

// return 0�ɹ���-1ʧ��
int linklist_delete(struct LinkList *head, int id);

#ifdef __cplusplus
}
#endif
#endif // __LINKLIST_H__