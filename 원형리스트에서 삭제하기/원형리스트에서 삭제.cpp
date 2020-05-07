#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node{ 
	struct Node *l_link;
	char name[30];
	struct Node *r_link;
}Node;

typedef struct Link { 
	int num;
	Node *tail;
} Link;

void init_list(Link *people) {
	people->num = 0;
	people->tail = NULL;
}

void print_list(Link *people) {
	Node *ptr = people->tail;

	if(people->num == 0)
		printf("마지막 남은 사람 %s ", ptr->name);
	else {
		printf("남은 학생의 이름 : ");

		for (int i = 1; i <= people->num; i++) {
			ptr = ptr->r_link;
			printf("%s ", ptr->name);
		}
	}
}

Node *create_node(char *name) {
	Node *new1 = (Node *)malloc(sizeof(Node));
	if (!new1)
	{
		printf("메모리 할당 실패");
		exit(1);
	}
	strcpy(new1->name, name);
	new1->r_link = new1;
	new1->l_link = new1;
	return new1;
}

Node *search_node(Link *people, char *name) {
	Node *ptr = people->tail->r_link;
	for (int i = 1; i <= people->num; i++, ptr = ptr->r_link)
		if (strcmp(ptr->name, name) == 0) break;
	return ptr;
}

void insert_node_last(Link *people, Node *new1){
	people->num++;

	if (people->tail == NULL)
		people->tail = new1;
	else
	{
		new1->r_link = people->tail->r_link;
		new1->l_link = people->tail;
		people->tail->r_link->l_link = new1;
		people->tail->r_link = new1;
		people->tail = new1;
	}
}

Node *delete_Node(Node *deleted, Link *STUDENT){
	if (deleted == STUDENT->tail)
		STUDENT->tail = STUDENT->tail->l_link;
	deleted->r_link->l_link = deleted->l_link;
	deleted->l_link->r_link = deleted->r_link;
	STUDENT->num--;

	return(deleted);
}

void delete_r_node(Link *people, int n,Node *ptr) { 
	char deleted[30];
	int i;

	for (i = 0; i < n; i++)	ptr = ptr->r_link;

	strcpy(deleted, delete_Node(ptr, people)->name);
	print_list(people);
	if(people->num) printf("\n제거된 학생 : %s\n", deleted);
	ptr = ptr->r_link;
}

void delete_l_node(Link *people, int n, Node *ptr) { 
	char deleted[30];
	int i;

	for (i = 0; i < n; i++)	ptr = ptr->l_link;

	strcpy(deleted, delete_Node(ptr, people)->name);
	print_list(people);
	if (people->num) printf("\n제거된 학생 : %s\n", deleted);
	ptr = ptr->l_link;
}

int main(void){
	int num, n, i;
	char name[30];
	char firstName[30];
	Link stu;

	printf("학생의 수 : ");
	scanf("%d", &num);

	init_list(&stu);

	for (i = 0; i < num; i++) {
		printf("학생 이름을 입력하세요\n");
		scanf("%s", name);
		insert_node_last(&stu, create_node(name));
	}

	printf("처음 사람의 이름 : ");
	scanf("%s", firstName);

	printf("숫자 : ");
	scanf("%d", &n);

	printf("\n\n");

	for (i = 1; i < num+1; i++) {
		if (i % 2 != 0)
			delete_r_node(&stu, n, search_node(&stu, firstName));
		else
			delete_l_node(&stu, n, search_node(&stu, firstName));
	}

}
