#ifndef __LINKLIST_H__
#define __LINKLIST_H__

// c++�������ᶨ��__cplusplus�����
#ifdef __cplusplus
// ����c++����������δ�����c����
extern "C" {
#endif

struct SnackLinkList {
	int id;
    int x;
    int y;
	struct SnackLinkList *next;
};

// ��������
// data����������
// data_length�����鳤��
struct SnackLinkList *linklist_create(int x[], int y[], int data_length);

// ����������ӡ
void linklist_printf(struct SnackLinkList *head, int x, int y);

// return 0�ɹ���-1ʧ��
int linklist_delete(struct SnackLinkList *head, int id);

#ifdef __cplusplus
}
#endif
#endif // __LINKLIST_H__
