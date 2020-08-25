#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define IS_EMPTY(ptr) (!(ptr))
#define IS_FULL(ptr) (!(ptr))

/* struct for "Singly-Linked-List" */
typedef struct list_node*list_pointer;
struct list_node {
	
	int data;
	list_pointer link;

};

//�Լ� ����
void insert(list_pointer*ptr, int value);
void print(list_pointer ptr);

void main(void) {
	
	list_pointer ptr = NULL;
	
	/*�Լ��� 16�� ȣ���Ͽ� List����*/
	insert(&ptr, 96); insert(&ptr, 4); insert(&ptr, 26); insert(&ptr, 49); 
	insert(&ptr, 75); insert(&ptr, 103); insert(&ptr, 43); insert(&ptr, 42);
	insert(&ptr, 21); insert(&ptr, 7); insert(&ptr, 15); insert(&ptr, 97);
	insert(&ptr, 13); insert(&ptr, 11); insert(&ptr, 8); insert(&ptr, 48);

	/*�ʱ� List ���.*/
	printf("<Not Sorted Linked-List>\n");
	print(ptr);		//print�Լ��� �����ϰ� List��ü print
	
	list_pointer ptr1 = ptr;	//�ּڰ��� ����ų pointer
	list_pointer ptr2 = ptr;	//List �� ���� ���� pointer
	list_pointer ptr3 = ptr;	//������ ����ų pointer
	int temp;
	
	printf("<Sorting Procedure>\n");
	while (ptr3->link != NULL) {
		while (ptr2->link != NULL) {

			ptr2 = ptr2->link;
			if (ptr1->data > ptr2->data) {
				ptr1 = ptr2;	//ptr1�� �ּڰ��� ���� node�� �ּҸ� ��´�.
			}

		}

		/*Swaping*/
		temp = ptr3->data;
		ptr3->data = ptr1->data;
		ptr1->data = temp;

		print(ptr);	//���� �ܰ踦 ���������� print.

		ptr3 = ptr3->link;

		/*���ذ� �ʱ�ȭ*/
		ptr1 = ptr3;
		ptr2 = ptr3;
	}

	/*���ĵ� List ���*/
	printf("<Sorted Linked-List>\n");
	print(ptr);
	
}

void insert (list_pointer * ptr, int value) {	//�Լ� ����

	list_pointer node = (list_pointer)malloc(sizeof(struct list_node));
	if (IS_FULL(node)) {	// malloc�� �������� check
		fprintf(stderr, "The memory is full\n"); exit(1);
	}
	
	node->link = NULL;
	node->data = value;

	list_pointer temp = *ptr;
	if(temp == NULL)	// ptr�� �ƹ��͵� ����Ű�� ���� ���� ��.
	{
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
		printf("%d->", temp->data);
		temp = temp->link;
	}
	printf("\n");
}

