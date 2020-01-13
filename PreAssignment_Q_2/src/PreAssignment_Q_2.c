/*
 ============================================================================
 Name        : PreAssignment_Q_2.c
 Author      : Shivam Palaskar
 Version     :
 Copyright   : Open source
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int len, temp, isSorted = 1,k,misTerm=-1;
	printf("Enter length of array : ");
	scanf("%d",&len);
	int array[len];
	printf("\nEnter %d Array Elements : ",len);
	for (int i = 0; i < len; i++) {
		scanf("%d", &array[i]);
	}
	printf("\nEnter the kth no. of Missing term  : ");
	scanf("%d",&k);

// Sorting the Array

	for (int i = 0; i < len; i++) {
		if (isSorted) {
			isSorted = 0;
			for (int j = 0; j < (len - i - 1); j++) {
				if (array[j] > array[j+1]) { // Bubble Sort Algorithm
					temp = array[j+1];
					array[j+1] = array[j];
					array[j] = temp;
					isSorted = 1;
				}
			}
		}
	}

// Finding Missing Term

	int len2 = ((array[len-1]-array[0])+1)-len;
	int count =0,check=0;
	if(len2>=k){
		temp = array[0];
		int i=0;
		while(i<len2){
			if(temp == array[i]){
				i++;
			}else
			{
				count++;
				if(count == k){
					printf("\nMissing Term is : %d",temp);
					check=1;
					break;
				}
			}
			temp++;
		}
		if (!check)
			printf("\nOutput : -1");
	} else
		printf("\nOutput : -1");
	return EXIT_SUCCESS;
}
