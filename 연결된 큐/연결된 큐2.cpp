#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DataType char
#define MAX 100

typedef struct Qnode {
	DataType data[MAX];
	struct Qnode *link;
}Qnode;

typedef struct List { //����Ʈ�� �����
	struct Qnode *front;
	struct Qnode *rear;
	int length;
}List;

void init_list(List *list) { //����Ʈ �ʱ�ȭ
	list->front = NULL;
	list->rear = NULL;
	list->length = 0;
}

void insert_node(List *list, DataType *name) { // List�� front�� rear ��� �����Ͱ� �ִ�. 
	Qnode *new1 = (Qnode *)malloc(sizeof(Qnode));
	if (!new1) {
		printf("�� �̻� �޸𸮸� �Ҵ� �� �� �����ϴ�.\n");
		exit(1);
	}
	strcpy(new1->data, name);
	new1->link = NULL;

	if (list->rear == NULL) { // ����ִ� ����Ʈ�� �־��� ���
		list->front = new1;
		list->rear = new1;
		list->length++;
	}
	else {
		list->rear->link = new1;
		list->rear = new1;
		list->length++;
	}
}

void matching(List *m, List *f) {
	Qnode *deleted_m = m->front; // ������ ��带 ������ �����͸� ����
	Qnode *deleted_f = f->front; // ������ ��带 ������ �����͸� ����

	m->length--;
	f->length--;

	printf("Ŀ���� ź���߽��ϴ�. %s�� %s\n", m->front->data, f->front->data);

	if(!(m->length)) init_list(m);
	if(!(f->length)){
		init_list(f);
		return;
	}
	
	m->front = m->front->link;
	f->front = f->front->link;	
}

main() {
	char name[MAX];
	char fm;
	List m;
	List f;

	init_list(&m);
	init_list(&f);

	for (;;) {
		printf("�̸� �Է� : ");
		scanf("%s", name);

		getchar(); // ���۰� ����

		printf("������ �Է��ϼ���! (f or m) ");
		scanf("%c", &fm);

		if (fm == 'f') insert_node(&f, name);
		else if (fm == 'm') insert_node(&m, name);
		
		if (f.length > 0 && m.length > 0) matching(&m, &f);
		else printf("���� ����ڰ� �����ϴ�. ��ٷ� �ֽʽÿ�.\n");
	}
}
