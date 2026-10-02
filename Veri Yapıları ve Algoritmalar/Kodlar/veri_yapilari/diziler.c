#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// fonksiyon imzasi asagidaki sekilde tanimlanir
void dondur(int [], int);
// veya fonksiyonu tamamen yukari alabiliriz

void solaDondur(int arr[], int d, int n) {
	for (int i = 0; i < d; i++)
		dondur(arr, n);
}

void printArray(int arr[]) {
	for (int i = 0; i < 7; i++)
		printf("%d. eleman = %d\n", i + 1, arr[i]);
}

int main() {
	int arr[] = { 1,2,3,4,5,6,7 };
	solaDondur(arr, 6, 7);
	printArray(arr);

	getch();
	return 0;
}

void dondur(int arr[], int n) {
	int i, temp;
	temp = arr[0];
	for (i = 0; i < n - 1; i++)
		arr[i] = arr[i + 1];
	arr[i] = temp;
}