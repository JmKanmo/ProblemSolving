#ifndef SINGLE__LINKED__LIST__H
#define SINGLE__LINKED__LIST__H

typedef struct _Node
{
	char Name[30];
	int age;
	struct _Node*Next;
}Node;

Node *head, *tail;
Node*temp;

void Init_List(void);
void Insert_Node(Node*);
void Circulate_List(void);
int Delete_Node(int,char[]);

#endif