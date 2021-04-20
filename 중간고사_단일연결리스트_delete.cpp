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
	// ������ ppt �ڵ� ��Ÿ���� ���������� ����Ʈ(Head)�� �����ϼż�
	// �켱 ���������� �ʱ�ȭ�߽��ϴ�! 
	// ������ ���߿� main ���������ε� ����Ʈ�� ����� �� �ְ� �� �Լ�����
	// �Ű������� **Head�� �����߽��ϴ�

	// �߰���� �ȳ������� �߰� + ������ �����־
	// ����Ʈ �ʱ�ȭ �Լ��� ���� �Լ��� ���� �ʾҽ��ϴ�..!

	// �������� ���� ���Ǹ� ���� �� �־ �׻� ����帳�ϴ�!
	// �ڷγ� �����Ͻð� ���߿� �ǰ��ϰ� ������ ���ڽ��ϴ� :)

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