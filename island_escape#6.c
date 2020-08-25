#include <stdio.h>
#include<time.h>
#define _CRT_SECURE_NO_WARNINGS
#define IS_EMPTY(ptr) (!(ptr))
#define IS_FULL(ptr) (!(ptr))

/* struct for "Singly-Circular-Linked-List" */
typedef struct list_node*list_pointer;
struct list_node {
	
	int num; //ex)1
	char*name;	//ex)은제
	list_pointer link;

};

//함수 선언
void insert(list_pointer*ptr, int num, char*name);
void print(list_pointer ptr);

void main(void) {

	int count = 0; int i;
	
	/*무인도에 남을 사람들 정보 담기*/
	int popnum;
	char*popname;
	
	/*난수 생성*/
	srand((unsigned)time(NULL));
	int skipnum = rand() % 30+1;	//1부터 30까지 랜덤으로 정수 생성
	
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

	list_pointer cir = ptr;
	while (cir->link != NULL) {
		cir = cir->link;
	}
	cir->link = ptr;	//circulalr로 연결하기
	
	/*잘 연결되었는지 확인*/
	printf("맨마지막 node의 link가 가리키는 첫 node는 (%d-%s)입니다.\n\n", cir->link->num, cir->link->name);

	printf("skip number 은 %d 입니다.\n\n", skipnum);
	printf("<무인도에 남을 사람들>\n\n");

	list_pointer poptemp = ptr;
	while (count != 34) {	//34명은 무인도에 남는다 (pop해버린다!)
		for (i = 0; i < skipnum - 1; i++) {
			poptemp = poptemp->link;
		}
		//List에서 빠지는 사람 정보 출력
		popnum = poptemp->link->num;
		popname = poptemp->link->name;
		printf("(%d-%s),", popnum, popname);	
		
		/*pop하고 연결하기*/
		poptemp->link = poptemp->link->link;	

		poptemp = poptemp->link;
		count++;
	}

	printf("\n\n<무인도를 탈출할 행운의 3인!>\n\n"); 
	while (count!= 37) {	//List에는 3개의 node만 남아 있기때문.
		ptr = ptr->link;
		printf("(%d-%s),",ptr->num,ptr->name);
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
	node->link = NULL;
	node->name = name;

	if (temp == NULL){	// ptr이 아무것도 가리키고 있지 않을 때.
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
		printf("(%d-%s)->", temp->num, temp->name);
		temp = temp->link;
	}
	printf("\n\n");
}

