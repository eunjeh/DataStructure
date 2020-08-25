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
int binsearch(list_pointer ptr, int searchnum, list_pointer left, list_pointer right);
void insert(list_pointer*ptr, int value);
void print(list_pointer ptr);

void main(void) {

	list_pointer ptr = NULL;

	/*함수를 16번 호출하여 List생성*/
	insert(&ptr, 4); insert(&ptr, 7); insert(&ptr, 8); insert(&ptr, 11);
	insert(&ptr, 13); insert(&ptr, 15); insert(&ptr, 21); insert(&ptr, 26);
	insert(&ptr, 42); insert(&ptr, 43); insert(&ptr, 48); insert(&ptr, 49);
	insert(&ptr, 75); insert(&ptr,96); insert(&ptr, 97); insert(&ptr, 103);

	/*초기 List 출력.*/
	printf("<Singly-Linked-List>\n\n");
	print(ptr);		//print함수로 간단하게 List전체 print
	printf("\n");

	list_pointer left = ptr;
	list_pointer right = ptr;

	while (right->link != NULL) {
		right = right->link;
	}
	
	/*문제의 요구에 따른 결과값들*/
	printf("<(1) '13' Search Procedure>\n"); int result1 = binsearch(ptr, 13, left, right);
	printf("searchnum(==13)은 LinkedList의 %d번째에 있는 node에 들어있습니다.\n\n", result1 + 1);
	printf("<(2) '97' Search Procedure>\n"); int result2 = binsearch(ptr, 97, left, right);
	printf("searchnum(==97)은 LinkedList의 %d번째에 있는 node에 들어있습니다.\n\n", result2 + 1);
	printf("<(3) '103' Search Procedure>\n"); int result3 = binsearch(ptr, 103, left, right);
	printf("searchnum(==103)은 LinkedList의 %d번째에 있는 node에 들어있습니다.\n\n", result3 + 1);
	printf("<(4) '7' Search Procedure>\n"); int result4 = binsearch(ptr, 7, left, right);
	printf("searchnum(==7)은 LinkedList의 %d번째에 있는 node에 들어있습니다.\n\n", result4 + 1);
	printf("<(5) '26' Search Procedure>\n"); int result5 = binsearch(ptr, 26, left, right);
	printf("searchnum(==26)은 LinkedList의 %d번째에 있는 node에 들어있습니다.\n\n", result5 + 1);

}

int compare(int x, int y) {		//함수 정의

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

int binsearch(list_pointer ptr, int searchnum, list_pointer left, list_pointer right) {			//함수 정의

	int count1 = 0; int count2=0; int i;

	list_pointer middle = left;
	list_pointer gap = left;	//(left~right)의 간격 count1.
	list_pointer fin = ptr;		//middle이 return될 때 (첫 node~middle)의 간격 count2.

	while (gap != right) {
		gap = gap->link;
		count1++;
	}

	do {
		
		for (i = 0; i < count1 / 2; i++) {
			middle = middle->link;	//middle을 gap의 1/2 만큼 이동
		}

		printf(" - 현재 left는 %d, right는 %d, middle은 %d 를 가리키고 있습니다.\n", left->data, right->data, middle->data);

		/*Algorithm이 Project #3과 동일*/
		switch (compare(middle->data, searchnum)) {		//compare함수 호출

		case -1: return binsearch(ptr, searchnum, middle->link, right);		//recursive 호출

		case 0: while (fin != middle) {
					fin = fin->link;
					count2++;
				}
				return count2;

		case 1: return binsearch(ptr, searchnum, left, middle);		//recursive 호출

		}
	} while (left != right);

	return -1;
}

void insert(list_pointer * ptr, int value) {	//함수 정의

	list_pointer node = (list_pointer)malloc(sizeof(struct list_node));
	if (IS_FULL(node)) {	// malloc이 가능한지 check
		fprintf(stderr, "The memory is full\n"); exit(1);
	}
	list_pointer temp = *ptr;

	node->link = NULL;
	node->data = value;

	if (temp == NULL)	// ptr이 아무것도 가리키고 있지 않을 때.
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

