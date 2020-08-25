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

//함수 선언
void insert(list_pointer*ptr, int num, char*name);
void print(list_pointer ptr);

void main(void) {

	int count = 3; int i;
	
	/*무인도에 남을 사람들 정보 담기*/
	int popnum;
	char*popname;
	
	srand((unsigned)time(NULL));
	int skipnum = rand() % 30 + 1;

	list_pointer ptr = NULL;

	/*함수를 16번 호출하여 List생성*/
	insert(&ptr, 1, "은제"); insert(&ptr, 2, "민희"); insert(&ptr, 3, "지영"); insert(&ptr, 4, "수빈");
	insert(&ptr, 5, "지연"); insert(&ptr, 6, "새연"); insert(&ptr, 7, "현지"); insert(&ptr, 8, "다영"); 
	insert(&ptr, 9, "성정"); insert(&ptr, 10, "동연"); insert(&ptr, 11, "유진"); insert(&ptr, 12, "하연"); 
	insert(&ptr, 13, "선영"); insert(&ptr, 14, "혜린"); insert(&ptr, 15, "영서"); insert(&ptr, 16, "서영"); 
	insert(&ptr, 17, "서원"); insert(&ptr, 18, "가연"); insert(&ptr, 19, "윤주"); insert(&ptr, 20, "예진");
	insert(&ptr, 21, "혜민"); insert(&ptr, 22, "수연"); insert(&ptr, 23, "시은"); insert(&ptr, 24, "서연"); 
	insert(&ptr, 25, "해림"); insert(&ptr, 26, "현진"); insert(&ptr, 27, "선희"); insert(&ptr, 28, "예빈"); 
	insert(&ptr, 29, "세림"); insert(&ptr, 30, "지은"); insert(&ptr, 31, "지원"); insert(&ptr, 32, "원"); 
	insert(&ptr, 33, "선정"); insert(&ptr, 34, "하민"); insert(&ptr, 35, "본"); insert(&ptr, 36, "수지"); 
	insert(&ptr, 37, "유정");

	printf("<Final Linked-List>\n\n"); print(ptr);

	list_pointer rear = ptr;
	while (rear->rlink != NULL) {
		rear = rear->rlink;
	}
	rear->rlink = ptr;	//doubly-circulalr로 연결하기
	ptr->llink = rear;

	/*잘 연결되었는지 확인*/
	printf("\n맨마지막 node의 rlink가 가리키는 첫 node의 data는 (%d-%s)입니다.\n", rear->rlink->num, rear->rlink->name);
	printf("첫 node의 llink가 가리키는  맨마지막 node의 data는 (%d-%s)입니다.\n\n", ptr->llink->num, ptr->llink->name);

	/*dummy node 생성 및 연결*/
	list_pointer dummy = (list_pointer)malloc(sizeof(struct list_node));
	if (IS_FULL(dummy)) {
		fprintf(stderr, "The memory is full\n"); exit(1);
	}
	dummy->num = NULL;
	dummy->name = NULL;
	dummy->llink = rear;	//오른쪽돌기
	dummy->rlink = ptr;		//왼쪽돌기

	/*잘 연결되었는지 확인*/
	printf("dummy node의 rlink에는 (%d-%s) node의 주소가 담겨 있습니다.\n", dummy->rlink->num, dummy->rlink->name);
	printf("dummy node의 llink에는 (%d-%s) node의 주소가 담겨 있습니다.\n\n", dummy->llink->num, dummy->llink->name);

	printf("skip number 은 %d 입니다.\n", skipnum);

	printf("\n<무인도에 남을 사람들>\n\n");
	
	list_pointer r_poptemp = ptr; list_pointer l_poptemp = rear;
	while(count != 37){		//(37-3)명은 무인도에 남는다 (pop해버린다!)

		switch (count % 2) {	//짝수와 홀수로 나눠 우->좌->우->좌 ...

		case 1: for (i = 0; i < skipnum - 1; i++) {		//오른쪽돌기
					r_poptemp = r_poptemp->rlink;
				}
				/*List에서 빠지는 사람 정보 출력*/
				popnum = r_poptemp->rlink->num;
				popname = r_poptemp->rlink->name;
				printf("(%d-%s),", popnum, popname);
				
				/*pop하고 연결하기*/
				r_poptemp->rlink->rlink->llink = r_poptemp;
				r_poptemp->rlink = r_poptemp->rlink->rlink;
				
				r_poptemp = r_poptemp->rlink;
				count++; break;

		case 0: for (i = 0; i < skipnum - 2; i++) {		//왼쪽돌기
					l_poptemp = l_poptemp->llink;
				}
				/*List에서 빠지는 사람 정보 출력*/
				popnum = l_poptemp->llink->num;
				popname = l_poptemp->llink->name;
				printf("(%d-%s),", popnum, popname);
				
				/*pop하고 연결하기*/
				l_poptemp->llink->llink->rlink = l_poptemp;
				l_poptemp->llink = l_poptemp->llink->llink;

				l_poptemp = l_poptemp->llink;
				count++; break;
		}
		
	}

	printf("\n\n<무인도를 탈출할 행운의 3인!>\n\n");
	while (count != 40) {	//List에는 3개의 node만 남아 있기때문.
		
		ptr = ptr->rlink;
		printf("(%d-%s),", ptr->num, ptr->name);
		count++;

	}
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

	if (temp == NULL){	// ptr이 아무것도 가리키고 있지 않을 때.
	
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
	printf("\n");
}

