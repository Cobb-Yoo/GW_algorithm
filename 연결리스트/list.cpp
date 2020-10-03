#include <stdio.h>
#include <stdlib.h> 
#define null NULL// NULL로 쓰기 귀찮아서 null이 NULL처럼 사용 할 수 있게 표현함. 

typedef struct Node{
	int coef;
	int expen;
	Node *link;
}Node;

typedef struct head{
	Node *link;
}head;

Node* creatNode(int a, int b) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->coef = a;
	newNode->expen = b;
	newNode->link = NULL;
	
	return newNode;
}

void insertNode(head *list, int a, int b){
	Node *newNode = creatNode(a,b,cnt);
	head *tmpNode = (head*)malloc(sizeof(head));
	tmpNode->link = list->link;  
	
	if(list->link == null){  
		list->link = newNode;
	}
	else{
		while(tmpNode->link->link != null){		 
			tmpNode->link = tmpNode->link->link;
		}
		
		tmpNode->link->link = newNode; 
	}
	
	free(tmpNode);
}

void init(head *list){
	list->link = NULL;
}

main(){
	int i,n,a,b;
	
	head list;
	
	init(&list);
	
	scanf("%d",&n);
	 
	for(i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		 
		insertNode(&list, a, b);
	}
	
	
	head *tmp = (head*)malloc(sizeof(head));
	tmp->link = list.link;
	
	for(i=0;i<n;i++){ 
		printf("%d %d\n",tmp->link->coef,tmp->link->expen);
		
		tmp->link = tmp->link->link;
		
	}
	
	free(tmp);
}
