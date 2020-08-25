#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main(void) {
	
	int list[16] = { 96,4,26,49,75,103,43,42,21,7,15,97,13,11,8,48 };
	int i, j,k, index;
	int temp;
	
	/*초기 배열 출력.*/
	printf("<Not Sorted Array>\n");
	for (i = 0; i < 16; i++) {
		printf("%d, ", list[i]);
	}
	printf("\n");

	printf("<Sorting Procedure>\n");
	/*정렬을 위한 logic.*/
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
		
		/*정렬 단계를 순차적으로 print.*/
		for (k = 0; k < 16; k++) {
			printf("%d, ", list[k]);
		}
		printf("\n");
	}
	
	/*정렬된 배열 출력*/
	printf("<Sorted Array>\n");
	for (i = 0; i < 16; i++) {
		printf("%d, ", list[i]);
	}

}
	
