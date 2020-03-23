#include <stdio.h>

typedef struct _Node {
	int key;
	struct _Node *link;
}Node;


Node *pQueue = NULL;
int count = 0;

void create();
void destroy();
void print();
int isEmpty();
int isFull();

Node* createNode(int key);
void insert(int key);
void deleteMax();
int searchMax();

int main() {

	int idx;
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

void create() {
	//없음
}

void destroy() {
	Node *del;
	while (pQueue) {
		del = pQueue;
		pQueue = pQueue->link;
		count--;
		free(del);
		printf("free node!, remains count=%d\n", count);
	}
}

void print() {
	Node *nptr = pQueue;
	
	printf("\npriority\t");
	nptr = pQueue;
	while (nptr) {
		printf("%d\t", nptr->key);
		nptr = nptr->link;
	}
	printf("\n\n");
}

int isEmpty() {
	return (count == 0);
}

int isFull() {

	return 0;
}

Node* createNode(int key) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->key = key;
	newNode->link = NULL;

	return newNode;
}

void insert(int key) {
	Node *newNode;
	Node *prev;
	Node *current;
	if (isEmpty()) {
		pQueue = createNode(key);
	}
	else {
		prev = NULL;
		current = pQueue;
		newNode = createNode(key);

		while (current && current->key > key) {
			prev = current;
			current = current->link;
		}
		if (prev==NULL) {
			newNode->link = pQueue;
			pQueue = newNode;
		}
		else {
			newNode->link = prev->link;
			prev->link = newNode;
		}

	}
	count++;
}

void deleteMax() {
	Node *max = NULL;
	//pQ가 없는 경우
	if (isEmpty()) {
		printf("empty\n");
		return;
	}
	else {
		Node *current = pQueue;
		pQueue = pQueue->link;
		free(current);
		count--;
	}
}
int searchMax() {
	int max = pQueue->key;
	return max;
}