#ifndef __LINKLIST_H__
#define __LINKLIST_H__

// c++�������ᶨ��__cplusplus�����
#ifdef __cplusplus
// ����c++����������δ�����c����
extern "C" {
#endif

struct SnackLinkList {
    int x;
    int y;
	struct SnackLinkList *next;
};

// ��������
// ��x,yλ�ô�������Ϊlength����
struct SnackLinkList *linklist_create(int x, int y, int length);

// ����������ӡ
void linklist_printf(struct SnackLinkList *head, int x, int y);

// �������Ƿ�������x,y
// �ҵ�����0���Ҳ�������-1
int linklist_find(struct SnackLinkList *head, int x, int y);

// ͷ�巨
void linklist_insert(struct SnackLinkList **head, int x, int y);

// return 0�ɹ���-1ʧ��
int linklist_delete_tail(struct SnackLinkList *head);

#ifdef __cplusplus
}
#endif
#endif // __LINKLIST_H__
