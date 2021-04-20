#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedListNode
{
	int data;
	struct LinkedListNode* next;

}Node;

Node* Head = NULL;

Node* create_Node(int newData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = newData;
	newNode->next = NULL;

	return newNode;
}

void addNode(Node** head, Node* newNode)
{
	if ((*head) == NULL)
	{
		(*head) = (Node*)malloc(sizeof(Node));
		(*head)->next = newNode;
	}
	else
	{
		Node* current = (*head);

		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newNode;
	}
}


void delete_Node(Node** head, Node* removeNode)
{
	if (head == NULL || removeNode == NULL)
		return;

	Node* current = *head;

	while (current != NULL)
	{
		if (current->next == removeNode)
		{
			current->next = removeNode->next;
			free(removeNode);
			break;
		}
		current = current->next;
	}
}

void show_Node(Node** Head)
{
	if ((*Head) == NULL) return;

	Node* current = (*Head)->next;

	while (current != NULL)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
	printf("\n");
}
int main(void)
{
	// 교수님 ppt 코딩 스타일이 전역변수로 리스트(Head)를 생성하셔서
	// 우선 전역변수로 초기화했습니다! 
	// 하지만 나중에 main 지역변수로도 리스트를 사용할 수 있게 각 함수들은
	// 매개변수를 **Head로 선언했습니다

	// 중간고사 안내문에서 추가 + 삭제만 나와있어서
	// 리스트 초기화 함수나 삽입 함수는 넣지 않았습니다..!

	// 교수님의 좋은 강의를 들을 수 있어서 항상 감사드립니다!
	// 코로나 조심하시고 나중에 건강하게 뵀으면 좋겠습니다 :)

	/* Node Create + Add */
	Node* newNode1 = create_Node(100);
	addNode(&Head, newNode1);
	Node* newNode2 = create_Node(200);
	addNode(&Head, newNode2);
	Node* newNode3 = create_Node(300);
	addNode(&Head, newNode3);
	Node* newNode4 = create_Node(400);
	addNode(&Head, newNode4);

	/* print List */
	show_Node(&Head);

	/* Node Delete */
	delete_Node(&Head, newNode3);

	/* print List */
	show_Node(&Head);

	return 0;
}