#include <stdio.h>
#include <stdlib.h>

typedef struct element {
	int code;
	char name[10];
	char v;
}element;

element arrN[1000];
int minN = 1000;
element arrY[1000];
int minY = 1000;

void insertY(int n, element temp) {	//arrY배열에 넣기
	arrY[n] = temp;
}
void insertN(int n, element temp) {	//arrN배열에 넣기
	arrN[n] = temp;
}
void SWAP(element arr[], int a, int b) {
	element temp;
	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
void sortArr(int n, element arr[]) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i].code > arr[j].code) {
				SWAP(arr, i, j);
			}
		}
	}
}
void printArr(element arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%03d %s %c ", arr[i].code, arr[i].name, arr[i].v);
	}
}

int main(int argc, char** argv) {
	FILE* fp;
	fp = fopen(argv[1], "r");
	if (argc != 2)
	{
		fprintf(stderr, "ERROR");
		exit(EXIT_FAILURE);
	}
	if (fp == NULL)
	{
		fprintf(stderr, "ERROR");
		exit(EXIT_FAILURE);
	}
	int n;
	fscanf(fp, "%d", &n);
	element temp;
	int a = 0;
	int b = 0;
	for (int i = 0; i < n; i++) {
		fscanf(fp, "%d %s %c ", &temp.code, temp.name, &temp.v);
		if (temp.v == 'Y') {
			insertY(a, temp);
			a++;
		}
		else if (temp.v == 'N') {
			insertN(b, temp);
			b++;
		}
	}
	sortArr(a, arrY);
	sortArr(b, arrN);
	printArr(arrN, b);
	printArr(arrY, a);
}
