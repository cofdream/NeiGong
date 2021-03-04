#include <iostream>
#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

typedef int ElemType;

#pragma region SQList

typedef struct SQList {
	ElemType data[MAXSIZE];
	int length;
}SQList;

Status GetElem(SQList list, int i, ElemType* elem) {
	if (list.length == 0 || i<1 || i>list.length) return ERROR;

	*elem = list.data[i - 1];
	return OK;
}
Status ListInsert(SQList* list, int i, ElemType elem) {
	if (list->length == MAXSIZE) return ERROR;
	if (i < 1 || i < list->length) return ERROR;

	if (i <= list->length)
		for (int k = list->length; k >= i - 1; k--)
			list->data[k + 1] = list->data[k];

	list->data[i] = elem;
	list->length++;
	return OK;
}
Status ListDelete(SQList* list, int i, ElemType* elem) {
	if (list->length == 0) return ERROR;
	if (i > list->length || i < 1) return ERROR;

	*elem = list->data[i];
	for (int k = i; k < list->length; k++)
	{
		list->data[k - 1] = list->data[k];
	}
	list->length--;
	return OK;
}

#pragma endregion


#pragma region LinkList

typedef struct Node {
	ElemType data;
	struct Node* next;
}Node;

typedef struct Node* LinkList;

Status GetElem(LinkList list, int i, ElemType* elem) {
	int j;
	LinkList node;
	node = list->next;
	j = 1;

	while (node != NULL && j < i)
	{
		node = node->next;
		j++;
	}
	if (node == NULL || j > i) return ERROR;

	*elem = node->data;
	return OK;
}
Status ListInsert(LinkList* list, int i, ElemType elem) {
	int j;
	LinkList node, newNode;

	node = *list;
	j = 1;

	while (node != NULL && j < i)
	{
		node = node->next;
		j++;
	}

	if (node == NULL || j > i)return ERROR;

	newNode = (LinkList)malloc(sizeof(Node));
	if (newNode == NULL) return ERROR;
	newNode->data = elem;
	newNode->next = node->next;
	node->next = newNode;
	return OK;
}
Status ListDelete(LinkList* list, int i, ElemType* elem) {
	int k;
	LinkList node, nextNode;
	node = *list;
	k = 1;
	while (node->next != NULL && k < i)
	{
		node = node->next;
		k++;
	}
	if (node->next == NULL || k > i) return ERROR;

	nextNode = node->next;
	node->next = nextNode->next;
	*elem = nextNode->data;
	free(nextNode);
	return OK;
}
//头插法
void CreateListHead(LinkList* list, int n) {
	int k;
	LinkList node;

	k = 1;
	srand(time(0));
	*list = (LinkList)malloc(sizeof(Node));
	if (*list == NULL) return;
	(*list)->next = NULL;

	for (int i = 0; i < n; i++)
	{
		node = (LinkList)malloc(sizeof(Node));
		if (node == NULL) return;
		node->data = rand() % 100 + 1;
		node->next = (*list)->next;
		(*list)->next = node;
	}
}
//尾插法
void CreateListTail(LinkList* list, int n) {
	int k;
	LinkList node, next;

	k = 1;
	srand(time(0));
	*list = (LinkList)malloc(sizeof(Node));
	if (*list == NULL) return;
	next = *list;
	for (int i = 0; i < n; i++)
	{
		node = (LinkList)malloc(sizeof(Node));
		if (node == NULL) return;
		node->data = rand() % 100 + 1;
		next->next = node;
		next = node;
	}
	next->next = NULL;
}
Status ClearList(LinkList* list) {
	LinkList node, next;
	node = (*list)->next;
	while (node != NULL)
	{
		next = node->next;
		free(node);
		node = next;
	}
	(*list)->next = NULL;
	return OK;
}
#pragma endregion


int main()
{
	std::cout << "Hello World!\n";
}