#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//함수 선언 
int binsearch(int list[], int searchnum, int left, int right);	

void main(void) {

	int i,result;
	int arr[16] = {4,7,8,11,13,15,21,26,42,43,48,49,75,96,97,103};
	
	/*초기 배열 출력*/
	printf("\narr ={");
	for (i = 0; i < 16; i++) {
		printf("%d,",arr[i]);
	}
	printf("}\n\n");
	
	/*문제의 요구에 따른 결과값들*/
	printf("<(1) '13' Search Procedure>\n"); result = binsearch(arr, 13, 0, 15);
	printf("list에서 searchnum(==13)의 index는 %d입니다.", result);
	printf("\n<(2) '97' Search Procedure>\n"); result = binsearch(arr, 97, 0, 15);
	printf("list에서 searchnum(==97)의 index는 %d입니다.", result);
	printf("\n<(3) '103' Search Procedure>\n"); result = binsearch(arr, 103, 0, 15);
	printf("list에서 searchnum(==103)의 index는 %d입니다.", result);
	printf("\n<(4) '7' Search Procedure>\n"); result = binsearch(arr, 7, 0, 15);
	printf("list에서 searchnum(==7)의 index는 %d입니다.", result);
	printf("\n<(5) '26' Search Procedure>\n"); result = binsearch(arr, 26, 0, 15);
	printf("list에서 searchnum(==26)의 index는 %d입니다.", result);
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


int binsearch(int list[], int searchnum, int left, int right) {			//함수 정의

	int middle;
	
	while (left <= right) {
		
		middle = (right + left) / 2;
		
		//left, right, middle 의 index값을 위치로
		printf(" - 현재 left는 %d, right는 %d, middle은 %d 에 있습니다.\n", left, right, middle);
		
		switch (compare(list[middle], searchnum)) {		//compare함수 호출

		case -1: return binsearch(list,searchnum,middle + 1,right);		//recursive 호출

		case 0: return middle;

		case 1: return binsearch(list, searchnum,left,middle - 1);		//recursive 호출
		
		}

	}

	return -1;
}

