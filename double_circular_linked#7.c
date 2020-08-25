#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define IS_EMPTY(ptr) (!(ptr))
#define IS_FULL(ptr) (!(ptr))

/* struct for "Doubly-Circular-Linked-List" */
typedef struct list_node*list_pointer;
struct list_node {
	
	int num; 
	char*name;
	list_pointer llink;
	list_pointer rlink;

};

//�Լ�����
void insert(list_pointer*ptr, int num, char*name);
void print(list_pointer ptr);

void main(void) {

	list_pointer ptr = NULL;

	printf("<Inserting Procedure>\n\n");
	/*��� ���� �ܰ踦 ���������� print*/
	insert(&ptr, 1, "����"); print(ptr); insert(&ptr, 2, "����"); print(ptr); insert(&ptr, 3, "����"); print(ptr); insert(&ptr, 4, "����"); print(ptr);
	insert(&ptr, 5, "����"); print(ptr); insert(&ptr, 6, "����"); print(ptr); insert(&ptr, 7, "����"); print(ptr); insert(&ptr, 8, "�ٿ�"); print(ptr);
	insert(&ptr, 9, "����"); print(ptr); insert(&ptr, 10, "����"); print(ptr); insert(&ptr, 11, "����"); print(ptr); insert(&ptr, 12, "�Ͽ�"); print(ptr);
	insert(&ptr, 13, "����"); print(ptr); insert(&ptr, 14, "����"); print(ptr); insert(&ptr, 15, "����"); print(ptr); insert(&ptr, 16, "����"); print(ptr);
	insert(&ptr, 17, "����"); print(ptr); insert(&ptr, 18, "����"); print(ptr); insert(&ptr, 19, "����"); print(ptr); insert(&ptr, 20, "����"); print(ptr);
	insert(&ptr, 21, "����"); print(ptr); insert(&ptr, 22, "����"); print(ptr); insert(&ptr, 23, "����"); print(ptr); insert(&ptr, 24, "����"); print(ptr);
	insert(&ptr, 25, "�ظ�"); print(ptr); insert(&ptr, 26, "����"); print(ptr); insert(&ptr, 27, "����"); print(ptr); insert(&ptr, 28, "����"); print(ptr);
	insert(&ptr, 29, "����"); print(ptr); insert(&ptr, 30, "����"); print(ptr); insert(&ptr, 31, "����"); print(ptr); insert(&ptr, 32, "��"); print(ptr);
	insert(&ptr, 33, "����"); print(ptr); insert(&ptr, 34, "�Ϲ�"); print(ptr); insert(&ptr, 35, "��"); print(ptr); insert(&ptr, 36, "����"); print(ptr);
	insert(&ptr, 37, "����");

	printf("<Final Linked-List>\n\n"); print(ptr);
	
	list_pointer rear = ptr;
	while (rear->rlink != NULL) {
		rear = rear->rlink;
	}
	rear->rlink = ptr;	//doubly-circulalr�� �����ϱ�
	ptr->llink = rear;

	/*�� ����Ǿ����� Ȯ��*/
	printf("\n�Ǹ����� node�� rlink�� ����Ű�� ù node�� (%d-%s)�Դϴ�.\n", rear->rlink->num, rear->rlink->name);
	printf("ù node�� llink�� ����Ű�� �Ǹ����� node�� (%d-%s)�Դϴ�.\n", ptr->llink->num, ptr->llink->name);

	/*dummy node ���� �� ����*/
	list_pointer dummy = (list_pointer)malloc(sizeof(struct list_node));
	if (IS_FULL(dummy)) {	// malloc�� �������� check
		fprintf(stderr, "The memory is full\n"); exit(1);
	}
	dummy->num = NULL;
	dummy->name = NULL;
	dummy->llink = rear;	//���ʹ��� ����
	dummy->rlink = ptr;		//�����ʹ��� ����
	
	/*�� ����Ǿ����� Ȯ��*/
	printf("\ndummy node�� rlink���� (%d-%s) node�� �ּҰ� ��� �ֽ��ϴ�.\n", dummy->rlink->num, dummy->rlink->name);
	printf("dummy node�� llink���� (%d-%s) node�� �ּҰ� ��� �ֽ��ϴ�.\n", dummy->llink->num, dummy->llink->name);
}

void insert(list_pointer * ptr, int num, char*name) {	//�Լ� ����

	list_pointer node = (list_pointer)malloc(sizeof(struct list_node));
	if (IS_FULL(node)) {	// malloc�� �������� check
		fprintf(stderr, "The memory is full\n"); exit(1);
	}
	list_pointer temp = *ptr;

	node->num = num;
	node->rlink = NULL;
	node->name = name;

	if (temp == NULL)	// ptr�� �ƹ��͵� ����Ű�� ���� ���� ��.
	{
		*ptr = node;
		return;
	}

	while (temp->rlink != NULL) {
		temp = temp->rlink;
	}
	
	/*(Doubly)�� ����*/
	temp->rlink = node;		
	node->llink = temp;		


}

void print(list_pointer ptr) {	//�Լ� ����

	list_pointer temp = ptr;
	while (temp != NULL) {
		printf("(%d-%s)->", temp->num, temp->name);
		temp = temp->rlink;
	}
	printf("\n\n");
}

