#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DataType char
#define MAX 100

typedef struct Qnode {
	DataType data[MAX];
	struct Qnode *link;
}Qnode;

typedef struct List { //리스트의 헤드노드
	struct Qnode *front;
	struct Qnode *rear;
	int length;
}List;

void init_list(List *list) { //리스트 초기화
	list->front = NULL;
	list->rear = NULL;
	list->length = 0;
}

void insert_node(List *list, DataType *name) { // List가 front랑 rear 라는 포인터가 있다. 
	Qnode *new1 = (Qnode *)malloc(sizeof(Qnode));
	if (!new1) {
		printf("더 이상 메모리를 할당 할 수 없습니다.\n");
		exit(1);
	}
	strcpy(new1->data, name);
	new1->link = NULL;

	if (list->rear == NULL) { // 비어있는 리스트에 넣었을 경우
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
	Qnode *deleted_m = m->front; // 삭제할 노드를 지정할 포인터를 선언
	Qnode *deleted_f = f->front; // 삭제할 노드를 지정할 포인터를 선언

	m->length--;
	f->length--;

	printf("커플이 탄생했습니다. %s과 %s\n", m->front->data, f->front->data);

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
		printf("이름 입력 : ");
		scanf("%s", name);

		getchar(); // 버퍼값 제거

		printf("성별을 입력하세요! (f or m) ");
		scanf("%c", &fm);

		if (fm == 'f') insert_node(&f, name);
		else if (fm == 'm') insert_node(&m, name);
		
		if (f.length > 0 && m.length > 0) matching(&m, &f);
		else printf("아직 대상자가 없습니다. 기다려 주십시오.\n");
	}
}
