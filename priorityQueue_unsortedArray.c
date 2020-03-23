#include <stdio.h>
#define MAX_SIZE 10

int *pQueue = NULL;
int count = 0;

int* create();
void destroy();
void print();
int isEmpty();
int isFull();

void insert(int key);
void deleteMax();
int searchMax();

int main() {

	int idx;
	pQueue = create();
	print();

	   insert(1);
        insert(9);
        insert(3);
        insert(5);
        insert(2);
        insert(4);
        insert(7);
        insert(8);
        insert(10);
        insert(6);  // full
        insert(12); // full
        print();

		printf("max = %d\n\n", searchMax());

		// 삭제
		deleteMax();
		print();
		deleteMax();
		print();
		deleteMax();
		print();


		printf("max = %d\n\n", searchMax());

		// 삭제 
		destroy();

		system("pause");
		return 0;
}

int* create() {
	int i;
	pQueue = (int*)malloc(MAX_SIZE*sizeof(int));

	for (i = 0; i < MAX_SIZE; i++) {
		pQueue[i] = 0;
	}
	return pQueue;
}

void destroy() {
	free(pQueue);
	pQueue = NULL;
	count = 0;
	printf("free queue!, count = %d\n", count);
}

void print() {

	int i;
	printf("index\t");
	for (int i = 0; i < count; i++) {
		printf("%3d", i);
	}
	printf("\nkey\t");
	for (int i = 0; i < count; i++) {
		printf("%3d", pQueue[i]);
	}
	printf("\n\n");
}

int isEmpty() {
	return (count == 0);
}

int isFull() {

	return (count == MAX_SIZE - 1);
}

void insert(int key) {
	if (isFull()) {
		printf("full\n");
		return;
	}
	pQueue[count++] = key;
}

void deleteMax() {
	int i, max, maxIndex;

	if (isEmpty()) {
		printf("empty~\n");
		return;
	}
	maxIndex = count - 1;
	for (i = maxIndex; i >= 0; i--) {
		if (pQueue[maxIndex] < pQueue[i]) maxIndex = i;
	}

	for (i = maxIndex + 1; i < count; i++) {
		pQueue[i - 1] = pQueue[i];
	}
	count--;
}


int searchMax() {
	int i, max;
	if (isEmpty()) {
		printf("empty!\n");
		return;
	}
	max = pQueue[count - 1];
	for (i = count-1; i >=0 ; i--) {
		if (pQueue[i] > max) max = pQueue[i];
	}
	return max;
}