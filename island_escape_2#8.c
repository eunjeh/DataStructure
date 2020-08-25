#include <stdio.h>
#include<time.h>
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

//�Լ� ����
void insert(list_pointer*ptr, int num, char*name);
void print(list_pointer ptr);

void main(void) {

	int count = 3; int i;
	
	/*���ε��� ���� ����� ���� ���*/
	int popnum;
	char*popname;
	
	srand((unsigned)time(NULL));
	int skipnum = rand() % 30 + 1;

	list_pointer ptr = NULL;

	/*�Լ��� 16�� ȣ���Ͽ� List����*/
	insert(&ptr, 1, "����"); insert(&ptr, 2, "����"); insert(&ptr, 3, "����"); insert(&ptr, 4, "����");
	insert(&ptr, 5, "����"); insert(&ptr, 6, "����"); insert(&ptr, 7, "����"); insert(&ptr, 8, "�ٿ�"); 
	insert(&ptr, 9, "����"); insert(&ptr, 10, "����"); insert(&ptr, 11, "����"); insert(&ptr, 12, "�Ͽ�"); 
	insert(&ptr, 13, "����"); insert(&ptr, 14, "����"); insert(&ptr, 15, "����"); insert(&ptr, 16, "����"); 
	insert(&ptr, 17, "����"); insert(&ptr, 18, "����"); insert(&ptr, 19, "����"); insert(&ptr, 20, "����");
	insert(&ptr, 21, "����"); insert(&ptr, 22, "����"); insert(&ptr, 23, "����"); insert(&ptr, 24, "����"); 
	insert(&ptr, 25, "�ظ�"); insert(&ptr, 26, "����"); insert(&ptr, 27, "����"); insert(&ptr, 28, "����"); 
	insert(&ptr, 29, "����"); insert(&ptr, 30, "����"); insert(&ptr, 31, "����"); insert(&ptr, 32, "��"); 
	insert(&ptr, 33, "����"); insert(&ptr, 34, "�Ϲ�"); insert(&ptr, 35, "��"); insert(&ptr, 36, "����"); 
	insert(&ptr, 37, "����");

	printf("<Final Linked-List>\n\n"); print(ptr);

	list_pointer rear = ptr;
	while (rear->rlink != NULL) {
		rear = rear->rlink;
	}
	rear->rlink = ptr;	//doubly-circulalr�� �����ϱ�
	ptr->llink = rear;

	/*�� ����Ǿ����� Ȯ��*/
	printf("\n�Ǹ����� node�� rlink�� ����Ű�� ù node�� data�� (%d-%s)�Դϴ�.\n", rear->rlink->num, rear->rlink->name);
	printf("ù node�� llink�� ����Ű��  �Ǹ����� node�� data�� (%d-%s)�Դϴ�.\n\n", ptr->llink->num, ptr->llink->name);

	/*dummy node ���� �� ����*/
	list_pointer dummy = (list_pointer)malloc(sizeof(struct list_node));
	if (IS_FULL(dummy)) {
		fprintf(stderr, "The memory is full\n"); exit(1);
	}
	dummy->num = NULL;
	dummy->name = NULL;
	dummy->llink = rear;	//�����ʵ���
	dummy->rlink = ptr;		//���ʵ���

	/*�� ����Ǿ����� Ȯ��*/
	printf("dummy node�� rlink���� (%d-%s) node�� �ּҰ� ��� �ֽ��ϴ�.\n", dummy->rlink->num, dummy->rlink->name);
	printf("dummy node�� llink���� (%d-%s) node�� �ּҰ� ��� �ֽ��ϴ�.\n\n", dummy->llink->num, dummy->llink->name);

	printf("skip number �� %d �Դϴ�.\n", skipnum);

	printf("\n<���ε��� ���� �����>\n\n");
	
	list_pointer r_poptemp = ptr; list_pointer l_poptemp = rear;
	while(count != 37){		//(37-3)���� ���ε��� ���´� (pop�ع�����!)

		switch (count % 2) {	//¦���� Ȧ���� ���� ��->��->��->�� ...

		case 1: for (i = 0; i < skipnum - 1; i++) {		//�����ʵ���
					r_poptemp = r_poptemp->rlink;
				}
				/*List���� ������ ��� ���� ���*/
				popnum = r_poptemp->rlink->num;
				popname = r_poptemp->rlink->name;
				printf("(%d-%s),", popnum, popname);
				
				/*pop�ϰ� �����ϱ�*/
				r_poptemp->rlink->rlink->llink = r_poptemp;
				r_poptemp->rlink = r_poptemp->rlink->rlink;
				
				r_poptemp = r_poptemp->rlink;
				count++; break;

		case 0: for (i = 0; i < skipnum - 2; i++) {		//���ʵ���
					l_poptemp = l_poptemp->llink;
				}
				/*List���� ������ ��� ���� ���*/
				popnum = l_poptemp->llink->num;
				popname = l_poptemp->llink->name;
				printf("(%d-%s),", popnum, popname);
				
				/*pop�ϰ� �����ϱ�*/
				l_poptemp->llink->llink->rlink = l_poptemp;
				l_poptemp->llink = l_poptemp->llink->llink;

				l_poptemp = l_poptemp->llink;
				count++; break;
		}
		
	}

	printf("\n\n<���ε��� Ż���� ����� 3��!>\n\n");
	while (count != 40) {	//List���� 3���� node�� ���� �ֱ⶧��.
		
		ptr = ptr->rlink;
		printf("(%d-%s),", ptr->num, ptr->name);
		count++;

	}
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

	if (temp == NULL){	// ptr�� �ƹ��͵� ����Ű�� ���� ���� ��.
	
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
	printf("\n");
}

