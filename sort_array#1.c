#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main(void) {
	
	int list[16] = { 96,4,26,49,75,103,43,42,21,7,15,97,13,11,8,48 };
	int i, j,k, index;
	int temp;
	
	/*�ʱ� �迭 ���.*/
	printf("<Not Sorted Array>\n");
	for (i = 0; i < 16; i++) {
		printf("%d, ", list[i]);
	}
	printf("\n");

	printf("<Sorting Procedure>\n");
	/*������ ���� logic.*/
	for (i = 0; i < 16; i++){
		
		index = i;
		
		for (j = i + 1; j < 16; j++){
			
			if (list[index] > list[j])
				index = j;
		
		}
		
		/*Swaping*/
		temp = list[i];
		list[i] = list[index];
		list[index] = temp;
		
		/*���� �ܰ踦 ���������� print.*/
		for (k = 0; k < 16; k++) {
			printf("%d, ", list[k]);
		}
		printf("\n");
	}
	
	/*���ĵ� �迭 ���*/
	printf("<Sorted Array>\n");
	for (i = 0; i < 16; i++) {
		printf("%d, ", list[i]);
	}

}
	
