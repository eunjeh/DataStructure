#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//�Լ� ���� 
int binsearch(int list[], int searchnum, int left, int right);	

void main(void) {

	int i,result;
	int arr[16] = {4,7,8,11,13,15,21,26,42,43,48,49,75,96,97,103};
	
	/*�ʱ� �迭 ���*/
	printf("\narr ={");
	for (i = 0; i < 16; i++) {
		printf("%d,",arr[i]);
	}
	printf("}\n\n");
	
	/*������ �䱸�� ���� �������*/
	printf("<(1) '13' Search Procedure>\n"); result = binsearch(arr, 13, 0, 15);
	printf("list���� searchnum(==13)�� index�� %d�Դϴ�.", result);
	printf("\n<(2) '97' Search Procedure>\n"); result = binsearch(arr, 97, 0, 15);
	printf("list���� searchnum(==97)�� index�� %d�Դϴ�.", result);
	printf("\n<(3) '103' Search Procedure>\n"); result = binsearch(arr, 103, 0, 15);
	printf("list���� searchnum(==103)�� index�� %d�Դϴ�.", result);
	printf("\n<(4) '7' Search Procedure>\n"); result = binsearch(arr, 7, 0, 15);
	printf("list���� searchnum(==7)�� index�� %d�Դϴ�.", result);
	printf("\n<(5) '26' Search Procedure>\n"); result = binsearch(arr, 26, 0, 15);
	printf("list���� searchnum(==26)�� index�� %d�Դϴ�.", result);
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


int binsearch(int list[], int searchnum, int left, int right) {			//�Լ� ����

	int middle;
	
	while (left <= right) {
		
		middle = (right + left) / 2;
		
		//left, right, middle �� index���� ��ġ��
		printf(" - ���� left�� %d, right�� %d, middle�� %d �� �ֽ��ϴ�.\n", left, right, middle);
		
		switch (compare(list[middle], searchnum)) {		//compare�Լ� ȣ��

		case -1: return binsearch(list,searchnum,middle + 1,right);		//recursive ȣ��

		case 0: return middle;

		case 1: return binsearch(list, searchnum,left,middle - 1);		//recursive ȣ��
		
		}

	}

	return -1;
}

