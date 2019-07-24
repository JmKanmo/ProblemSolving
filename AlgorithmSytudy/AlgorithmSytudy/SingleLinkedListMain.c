#include <stdio.h>
#include <stdlib.h>
#include "SingleLinkedList.h"

Node*makeNode(void);
void setNodeInfo(Node**node);

int main(void)
{
	Node*node;
	int i;
	Init_List();

	printf("--> 연결리스트 노드삽입 <--\n\n");

	for (i = 0;i < 3;i++)
	{
		setNodeInfo(&node);
		Insert_Node(node);
	}//for(i)
    
	printf("\n---> 리스트정보출력 <---\n\n");

	Circulate_List();

	printf("--> 연결리스트 노드삭제 <--\n\n");

	int tok = 1;

	while (tok)
	{
		printf("\n삭제노드 정보입력\n\n");
		int age;
		char name[30];

		printf("이름:");
		scanf("%s", name);
		printf("나이:");
		scanf("%d", &age);

		if (Delete_Node(age, name) == 1)
		{
			printf("\n\n노드삭제성공\n");
		}
		else
		{
			printf("\n\n노드삭제실패\n");
		}

		printf("\n노드를 삭제하시겠습니까? yes는 1 그외의 입력은 no");
		printf("입력:");
		scanf("%d", &tok);
		tok = (tok == 1) ? tok : 0;
	}//while(i)

	printf("\n--> 삭제 후 리스트노드출력 <--\n\n");
	Circulate_List();
	return 0;
}//End of main()

Node*makeNode(void){ return (Node*)malloc(sizeof(Node)); }//End of makeNode()

void setNodeInfo(Node**node)
{
	*node = makeNode();
	printf("이름:");
	scanf("%s", (*node)->Name);
	printf("나이:");
	scanf("%d",&(*node)->age);
	putchar('\n');
}//End of makeNode()
