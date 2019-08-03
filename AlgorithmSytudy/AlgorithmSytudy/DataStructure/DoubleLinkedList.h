#ifndef DOUBLE__LINKED__LIST__H
#define DOUBLE__LINKED__LIST__H

typedef struct _Node
{
	int age;
	char name[30];
	struct _Node* prev;
	struct _Node* next;
}Node;

Node* head;
Node* tail;

void Init_List(void);
void Insert_Node(Node*);
void Circulate_Node(void);
int Delete_Node(int, char[]);
void deleteAll(void);

#endif