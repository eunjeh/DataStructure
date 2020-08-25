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
int binsearch(list_pointer ptr, int searchnum, list_pointer left, list_pointer right);
void insert(list_pointer*ptr, int value);
void print(list_pointer ptr);

void main(void) {

	list_pointer ptr = NULL;

	/*�Լ��� 16�� ȣ���Ͽ� List����*/
	insert(&ptr, 4); insert(&ptr, 7); insert(&ptr, 8); insert(&ptr, 11);
	insert(&ptr, 13); insert(&ptr, 15); insert(&ptr, 21); insert(&ptr, 26);
	insert(&ptr, 42); insert(&ptr, 43); insert(&ptr, 48); insert(&ptr, 49);
	insert(&ptr, 75); insert(&ptr,96); insert(&ptr, 97); insert(&ptr, 103);

	/*�ʱ� List ���.*/
	printf("<Singly-Linked-List>\n\n");
	print(ptr);		//print�Լ��� �����ϰ� List��ü print
	printf("\n");

	list_pointer left = ptr;
	list_pointer right = ptr;

	while (right->link != NULL) {
		right = right->link;
	}
	
	/*������ �䱸�� ���� �������*/
	printf("<(1) '13' Search Procedure>\n"); int result1 = binsearch(ptr, 13, left, right);
	printf("searchnum(==13)�� LinkedList�� %d��°�� �ִ� node�� ����ֽ��ϴ�.\n\n", result1 + 1);
	printf("<(2) '97' Search Procedure>\n"); int result2 = binsearch(ptr, 97, left, right);
	printf("searchnum(==97)�� LinkedList�� %d��°�� �ִ� node�� ����ֽ��ϴ�.\n\n", result2 + 1);
	printf("<(3) '103' Search Procedure>\n"); int result3 = binsearch(ptr, 103, left, right);
	printf("searchnum(==103)�� LinkedList�� %d��°�� �ִ� node�� ����ֽ��ϴ�.\n\n", result3 + 1);
	printf("<(4) '7' Search Procedure>\n"); int result4 = binsearch(ptr, 7, left, right);
	printf("searchnum(==7)�� LinkedList�� %d��°�� �ִ� node�� ����ֽ��ϴ�.\n\n", result4 + 1);
	printf("<(5) '26' Search Procedure>\n"); int result5 = binsearch(ptr, 26, left, right);
	printf("searchnum(==26)�� LinkedList�� %d��°�� �ִ� node�� ����ֽ��ϴ�.\n\n", result5 + 1);

}

int compare(int x, int y) {		//�Լ� ����

	if (x < y) {

		return -1;

	}
	else if (x == y) {

		return 0;

	}
	else {

		return 1;

	}
}

int binsearch(list_pointer ptr, int searchnum, list_pointer left, list_pointer right) {			//�Լ� ����

	int count1 = 0; int count2=0; int i;

	list_pointer middle = left;
	list_pointer gap = left;	//(left~right)�� ���� count1.
	list_pointer fin = ptr;		//middle�� return�� �� (ù node~middle)�� ���� count2.

	while (gap != right) {
		gap = gap->link;
		count1++;
	}

	do {
		
		for (i = 0; i < count1 / 2; i++) {
			middle = middle->link;	//middle�� gap�� 1/2 ��ŭ �̵�
		}

		printf(" - ���� left�� %d, right�� %d, middle�� %d �� ����Ű�� �ֽ��ϴ�.\n", left->data, right->data, middle->data);

		/*Algorithm�� Project #3�� ����*/
		switch (compare(middle->data, searchnum)) {		//compare�Լ� ȣ��

		case -1: return binsearch(ptr, searchnum, middle->link, right);		//recursive ȣ��

		case 0: while (fin != middle) {
					fin = fin->link;
					count2++;
				}
				return count2;

		case 1: return binsearch(ptr, searchnum, left, middle);		//recursive ȣ��

		}
	} while (left != right);

	return -1;
}

void insert(list_pointer * ptr, int value) {	//�Լ� ����

	list_pointer node = (list_pointer)malloc(sizeof(struct list_node));
	if (IS_FULL(node)) {	// malloc�� �������� check
		fprintf(stderr, "The memory is full\n"); exit(1);
	}
	list_pointer temp = *ptr;

	node->link = NULL;
	node->data = value;

	if (temp == NULL)	// ptr�� �ƹ��͵� ����Ű�� ���� ���� ��.
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

