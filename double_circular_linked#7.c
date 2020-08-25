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

//함수선언
void insert(list_pointer*ptr, int num, char*name);
void print(list_pointer ptr);

void main(void) {

	list_pointer ptr = NULL;

	printf("<Inserting Procedure>\n\n");
	/*모든 삽입 단계를 순차적으로 print*/
	insert(&ptr, 1, "은제"); print(ptr); insert(&ptr, 2, "민희"); print(ptr); insert(&ptr, 3, "지영"); print(ptr); insert(&ptr, 4, "수빈"); print(ptr);
	insert(&ptr, 5, "지연"); print(ptr); insert(&ptr, 6, "새연"); print(ptr); insert(&ptr, 7, "현지"); print(ptr); insert(&ptr, 8, "다영"); print(ptr);
	insert(&ptr, 9, "성정"); print(ptr); insert(&ptr, 10, "동연"); print(ptr); insert(&ptr, 11, "유진"); print(ptr); insert(&ptr, 12, "하연"); print(ptr);
	insert(&ptr, 13, "선영"); print(ptr); insert(&ptr, 14, "혜린"); print(ptr); insert(&ptr, 15, "영서"); print(ptr); insert(&ptr, 16, "서영"); print(ptr);
	insert(&ptr, 17, "서원"); print(ptr); insert(&ptr, 18, "가연"); print(ptr); insert(&ptr, 19, "윤주"); print(ptr); insert(&ptr, 20, "예진"); print(ptr);
	insert(&ptr, 21, "혜민"); print(ptr); insert(&ptr, 22, "수연"); print(ptr); insert(&ptr, 23, "시은"); print(ptr); insert(&ptr, 24, "서연"); print(ptr);
	insert(&ptr, 25, "해림"); print(ptr); insert(&ptr, 26, "현진"); print(ptr); insert(&ptr, 27, "선희"); print(ptr); insert(&ptr, 28, "예빈"); print(ptr);
	insert(&ptr, 29, "세림"); print(ptr); insert(&ptr, 30, "지은"); print(ptr); insert(&ptr, 31, "지원"); print(ptr); insert(&ptr, 32, "원"); print(ptr);
	insert(&ptr, 33, "선정"); print(ptr); insert(&ptr, 34, "하민"); print(ptr); insert(&ptr, 35, "본"); print(ptr); insert(&ptr, 36, "수지"); print(ptr);
	insert(&ptr, 37, "유정");

	printf("<Final Linked-List>\n\n"); print(ptr);
	
	list_pointer rear = ptr;
	while (rear->rlink != NULL) {
		rear = rear->rlink;
	}
	rear->rlink = ptr;	//doubly-circulalr로 연결하기
	ptr->llink = rear;

	/*잘 연결되었는지 확인*/
	printf("\n맨마지막 node의 rlink가 가리키는 첫 node는 (%d-%s)입니다.\n", rear->rlink->num, rear->rlink->name);
	printf("첫 node의 llink가 가리키는 맨마지막 node는 (%d-%s)입니다.\n", ptr->llink->num, ptr->llink->name);

	/*dummy node 생성 및 연결*/
	list_pointer dummy = (list_pointer)malloc(sizeof(struct list_node));
	if (IS_FULL(dummy)) {	// malloc이 가능한지 check
		fprintf(stderr, "The memory is full\n"); exit(1);
	}
	dummy->num = NULL;
	dummy->name = NULL;
	dummy->llink = rear;	//왼쪽방향 돌기
	dummy->rlink = ptr;		//오른쪽방향 돌기
	
	/*잘 연결되었는지 확인*/
	printf("\ndummy node의 rlink에는 (%d-%s) node의 주소가 담겨 있습니다.\n", dummy->rlink->num, dummy->rlink->name);
	printf("dummy node의 llink에는 (%d-%s) node의 주소가 담겨 있습니다.\n", dummy->llink->num, dummy->llink->name);
}

void insert(list_pointer * ptr, int num, char*name) {	//함수 정의

	list_pointer node = (list_pointer)malloc(sizeof(struct list_node));
	if (IS_FULL(node)) {	// malloc이 가능한지 check
		fprintf(stderr, "The memory is full\n"); exit(1);
	}
	list_pointer temp = *ptr;

	node->num = num;
	node->rlink = NULL;
	node->name = name;

	if (temp == NULL)	// ptr이 아무것도 가리키고 있지 않을 때.
	{
		*ptr = node;
		return;
	}

	while (temp->rlink != NULL) {
		temp = temp->rlink;
	}
	
	/*(Doubly)로 연결*/
	temp->rlink = node;		
	node->llink = temp;		


}

void print(list_pointer ptr) {	//함수 정의

	list_pointer temp = ptr;
	while (temp != NULL) {
		printf("(%d-%s)->", temp->num, temp->name);
		temp = temp->rlink;
	}
	printf("\n\n");
}

