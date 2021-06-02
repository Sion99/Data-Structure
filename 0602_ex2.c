#include <stdio.h>
#include <stdlib.h>

int init[100000];

int temp[100000];

void clear() {
	for (int i = 0; i < 1000; i++) {
		temp[i] = 0;
	}
}

void merge(int init[], int temp[], int n1, int n2) {
	int merged[100000];
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < n1 && j < n2) {
		if (init[i] < temp[j])
			merged[k++] = init[i++];
		else
			merged[k++] = temp[j++];
	}
	while (i < n1) {
		merged[k++] = init[i++];
	}
	while (j < n2) {
		merged[k++] = temp[i++];
	}
	for(int a = 0; a < k; a++) {
		init[a] = merged[a];
	}
//	init = merged;
}

void merge2(int initList[], int tempList[], int n1, int n2) {
	int merged[1000];
	int i, j, k, t;
	i = 0, j = 0, k = 0;
	while (i <= n1 && j <= n2) {
		if (initList[i] <= tempList[j])
			merged[k++] = initList[i++];
		else
			merged[k++] = initList[j++];
	}
	if (i > n1) {
		for (t = j; t <= n2; t++) {
			merged[t] = tempList[t];
		}
	}
	else {
		for (t = i; t <= n1; t++) {
			merged[k + t - i] = initList[t];
		}
	}
	for (int a = 0; a < k; a++) {
		initList[a] = merged[a];
	}

}

void merge3(int initList[], int tempList[], int n1, int n2) {
	int merged[100000];
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < n1 && j < n2) {
		if (initList[i] < tempList[j]) {
			merged[k++] = initList[i++];
		}
		else {
			merged[k++] = tempList[j++];
		}
	}
	while (i < n1)
		merged[k++] = initList[i++];
	while (j < n2)
		merged[k++] = tempList[j++];
	for (int i = 0; i < k; i++) {
		init[i] = merged[i];
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
	int num;
	int j = -1;
	fscanf(fp, "%d", &n);
	while (1) {
		fscanf(fp, "%d ", &num);
		if (num == -1)
			break;
		init[++j] = num;
	}
	j++;
	for (int i = 1; i < n; i++) {
		int k = -1;
		while (1) {
			fscanf(fp, "%d ", &num);
			if (num == -1)
				break;
			temp[++k] = num;
		}
		k++;
		merge3(init, temp, j, k);
		clear();
		j = j + k;
	}
	for (int i = 0; i < j; i++) {
		printf("%d ", init[i]);
	}
}
