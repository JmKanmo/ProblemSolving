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

	printf("--> ���Ḯ��Ʈ ������ <--\n\n");

	for (i = 0;i < 3;i++)
	{
		setNodeInfo(&node);
		Insert_Node(node);
	}//for(i)
    
	printf("\n---> ����Ʈ������� <---\n\n");

	Circulate_List();

	printf("--> ���Ḯ��Ʈ ������ <--\n\n");

	int tok = 1;

	while (tok)
	{
		printf("\n������� �����Է�\n\n");
		int age;
		char name[30];

		printf("�̸�:");
		scanf("%s", name);
		printf("����:");
		scanf("%d", &age);

		if (Delete_Node(age, name) == 1)
		{
			printf("\n\n����������\n");
		}
		else
		{
			printf("\n\n����������\n");
		}

		printf("\n��带 �����Ͻðڽ��ϱ�? yes�� 1 �׿��� �Է��� no");
		printf("�Է�:");
		scanf("%d", &tok);
		tok = (tok == 1) ? tok : 0;
	}//while(i)

	printf("\n--> ���� �� ����Ʈ������ <--\n\n");
	Circulate_List();
	return 0;
}//End of main()

Node*makeNode(void){ return (Node*)malloc(sizeof(Node)); }//End of makeNode()

void setNodeInfo(Node**node)
{
	*node = makeNode();
	printf("�̸�:");
	scanf("%s", (*node)->Name);
	printf("����:");
	scanf("%d",&(*node)->age);
	putchar('\n');
}//End of makeNode()
