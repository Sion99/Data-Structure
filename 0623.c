#include <stdio.h>

void sort(int arr[], int n) {
	int min, temp;
	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min])
				min = j;
		}
		if (i != min) {
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}

int binarysearch(int arr[], int left, int right, int key)
{
	if (left <= right)
	{
		int middle = (left + right) / 2;

		if (arr[middle] > key)
			return binarysearch(arr, left, middle - 1, key);

		else if (arr[middle] < key)
			return binarysearch(arr, middle + 1, right, key);

		else
			return middle;
	}

	return -1;
}
/*
int binsearch(int arr[], int searchnum, int left, int right) {
	int middle;
	if (left <= right) {
		middle = (left + right) / 2;
		if (searchnum > arr[middle]) {
			left = middle + 1;
		}
		else if (searchnum < arr[middle]) {
			right = middle - 1;
		}
		else {
			return middle;
		}
		binsearch(arr, searchnum, left, right);
	}
}
*/

int binsearch(int arr[], int searchnum, int left, int right) {
	int middle;
	while (left<=right) {
		middle = (left + right) / 2;
		if (searchnum < middle) {
			right = middle - 1;
		}
		else if (searchnum > middle) {
			left = middle + 1;
		}
		else {
			return middle;
		}
	}
	return -1;
}


int main() {
	int arr[10] = { 13, 55, 2, 75, 4, 12, 89, 19, 102, 63 };
	sort(arr, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
//	int n = binarysearch(arr, 0, 9, 55);
	int b = binsearch(arr, 13, 0, 9);
	printf("%d\n", b);
}
