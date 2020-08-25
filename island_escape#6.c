#include <stdio.h>
#include<time.h>
#define _CRT_SECURE_NO_WARNINGS
#define IS_EMPTY(ptr) (!(ptr))
#define IS_FULL(ptr) (!(ptr))

/* struct for "Singly-Circular-Linked-List" */
typedef struct list_node*list_pointer;
struct list_node {
	
	int num; //ex)1
	char*name;	//ex)����
	list_pointer link;

};

//�Լ� ����
void insert(list_pointer*ptr, int num, char*name);
void print(list_pointer ptr);

void main(void) {

	int count = 0; int i;
	
	/*���ε��� ���� ����� ���� ���*/
	int popnum;
	char*popname;
	
	/*���� ����*/
	srand((unsigned)time(NULL));
	int skipnum = rand() % 30+1;	//1���� 30���� �������� ���� ����
	
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

	list_pointer cir = ptr;
	while (cir->link != NULL) {
		cir = cir->link;
	}
	cir->link = ptr;	//circulalr�� �����ϱ�
	
	/*�� ����Ǿ����� Ȯ��*/
	printf("�Ǹ����� node�� link�� ����Ű�� ù node�� (%d-%s)�Դϴ�.\n\n", cir->link->num, cir->link->name);

	printf("skip number �� %d �Դϴ�.\n\n", skipnum);
	printf("<���ε��� ���� �����>\n\n");

	list_pointer poptemp = ptr;
	while (count != 34) {	//34���� ���ε��� ���´� (pop�ع�����!)
		for (i = 0; i < skipnum - 1; i++) {
			poptemp = poptemp->link;
		}
		//List���� ������ ��� ���� ���
		popnum = poptemp->link->num;
		popname = poptemp->link->name;
		printf("(%d-%s),", popnum, popname);	
		
		/*pop�ϰ� �����ϱ�*/
		poptemp->link = poptemp->link->link;	

		poptemp = poptemp->link;
		count++;
	}

	printf("\n\n<���ε��� Ż���� ����� 3��!>\n\n"); 
	while (count!= 37) {	//List���� 3���� node�� ���� �ֱ⶧��.
		ptr = ptr->link;
		printf("(%d-%s),",ptr->num,ptr->name);
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
	node->link = NULL;
	node->name = name;

	if (temp == NULL){	// ptr�� �ƹ��͵� ����Ű�� ���� ���� ��.
		*ptr = node;
		return;
	}

	while (temp->link != NULL) {
		temp = temp->link;
	}
	temp->link = node;	// List�� �� ������ node�� �� node����.

}

void print(list_pointer ptr) {	//�Լ� ����

	list_pointer temp = ptr;
	while (temp != NULL) {
		printf("(%d-%s)->", temp->num, temp->name);
		temp = temp->link;
	}
	printf("\n\n");
}

