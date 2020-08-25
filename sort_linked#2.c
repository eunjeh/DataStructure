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

//함수 선언
void insert(list_pointer*ptr, int value);
void print(list_pointer ptr);

void main(void) {
	
	list_pointer ptr = NULL;
	
	/*함수를 16번 호출하여 List생성*/
	insert(&ptr, 96); insert(&ptr, 4); insert(&ptr, 26); insert(&ptr, 49); 
	insert(&ptr, 75); insert(&ptr, 103); insert(&ptr, 43); insert(&ptr, 42);
	insert(&ptr, 21); insert(&ptr, 7); insert(&ptr, 15); insert(&ptr, 97);
	insert(&ptr, 13); insert(&ptr, 11); insert(&ptr, 8); insert(&ptr, 48);

	/*초기 List 출력.*/
	printf("<Not Sorted Linked-List>\n");
	print(ptr);		//print함수로 간단하게 List전체 print
	
	list_pointer ptr1 = ptr;	//최솟값을 가리킬 pointer
	list_pointer ptr2 = ptr;	//List 한 번을 훑을 pointer
	list_pointer ptr3 = ptr;	//기준을 가리킬 pointer
	int temp;
	
	printf("<Sorting Procedure>\n");
	while (ptr3->link != NULL) {
		while (ptr2->link != NULL) {

			ptr2 = ptr2->link;
			if (ptr1->data > ptr2->data) {
				ptr1 = ptr2;	//ptr1에 최솟값을 가진 node의 주소를 담는다.
			}

		}

		/*Swaping*/
		temp = ptr3->data;
		ptr3->data = ptr1->data;
		ptr1->data = temp;

		print(ptr);	//정렬 단계를 순차적으로 print.

		ptr3 = ptr3->link;

		/*기준값 초기화*/
		ptr1 = ptr3;
		ptr2 = ptr3;
	}

	/*정렬된 List 출력*/
	printf("<Sorted Linked-List>\n");
	print(ptr);
	
}

void insert (list_pointer * ptr, int value) {	//함수 정의

	list_pointer node = (list_pointer)malloc(sizeof(struct list_node));
	if (IS_FULL(node)) {	// malloc이 가능한지 check
		fprintf(stderr, "The memory is full\n"); exit(1);
	}
	
	node->link = NULL;
	node->data = value;

	list_pointer temp = *ptr;
	if(temp == NULL)	// ptr이 아무것도 가리키고 있지 않을 때.
	{
		*ptr = node;
		return;
	}

	while (temp->link != NULL) {
		temp = temp->link;
	}
	temp->link = node;	// List의 맨 마지막 node에 새 node연결.


}

void print(list_pointer ptr) {	//함수 정의

	list_pointer temp = ptr;
	while (temp != NULL) {
		printf("%d->", temp->data);
		temp = temp->link;
	}
	printf("\n");
}

