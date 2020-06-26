#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define DataType char

typedef struct tNode { // 트리의 구조체
   DataType data[MAX];
   int Line[MAX];
   int count;
   struct tNode *Left;
   struct tNode *Right;
}tNode;

typedef struct List { // 해드노드
   struct tNode *root;
}List;

void init_List(List *list) { //노드의 초기화
   list->root = NULL;
}

void find_position(tNode **root, tNode *new) { //위치를 찾고 데이터를 넣는 함수
   tNode *searched = *root; //위치에 해당될 노드
   tNode *parent = NULL; //부모노드
   int n = 1;

   while (searched) { //위치 탐색
      if (!strcmp(searched->data, new->data)) {
         searched->count++;
         free(new);
         n--; //같은 것을 넣었을때 46번 줄 이후의 조건문일 실행하지 않도록 하기 위한 표시
         break;
      }

      parent = searched;

      if (strcmp(searched->data, new->data) > 0) { //해당되는 위치와 새로운 데이터 값에 따른 위치를 구별하기 위한 조건문
         searched = searched->Left;
      }
      else if (strcmp(searched->data, new->data) < 0) {
         searched = searched->Right;
      }

   }

   if (n == 1) { //해당 위치에 노드 삽입
      if (strcmp(parent->data, new->data) > 0) {
         parent->Left = new;
      }
      else if (strcmp(parent->data, new->data) < 0) {
         parent->Right = new;
      }
   }
}

char *lower(char *txt) { //문자의 대소문자의 구별을 없애기 위해서 모두 소문자로 바꾸는 함수
   int i;
   for (i = 0;i<strlen(txt);i++) {
      if ('A' <= txt[i] && txt[i] <= 'Z') {
         txt[i] = txt[i] + 32;
      }
   }
   return txt;
}

void insertToTree(List *list, char *txt) { //list에 txt값을 넣으려는 함수
   tNode *new = (tNode *)malloc(sizeof(tNode));
   
   if (!new) { //메모리가 할당됐는지 확인
      printf("메모리 할당에 실패 하였습니다.");
      exit(1);
   }

   new->Left = NULL;
   new->Right = NULL;
   new->count = 1;
   strcpy(new->data, lower(txt)); //문자가 아닌 문자열이므로 strcpy를 사용

   if (!(list->root)) {
      list->root = new; //비어있는 list에 넣을 경우
   }
   else {
      find_position(&(list->root), new);
   }
}

void printTree(tNode *root) { //중위순회로 해당 트리 출력
   if (root) {
      printTree(root->Left);
      printf("%7s %5d\n", root->data, root->count);
      printTree(root->Right);
   }
}

main(){
   int i;
   List list;
   int sum = 0;
   DataType tmp[MAX];
   DataType *str;
   FILE *file = fopen("data.txt", "r"); //data.txt라는 파일을 읽음

   if (file == NULL) {
      printf("파일 열기 실패\n");
      return 1;
   }

   init_List(&list);
    
   while(feof(file) == 0) { //파일의 처음부터 끝까지 계속읽음
      fgets(tmp,MAX,file);
      str = strtok(tmp," \n?",file); // “ ”, “\n”, “?”의 해당값이 있으면 끈고 읽지 않음
      while (str){
         insertToTree(&list, str);
         sum++;
         str = strtok(NULL, " \n?"); // “ ”, “\n”, “?”의 해당값이 있으면 끈고 읽지 않음
      }
   }
   printf("  단어    횟수\n");
   printTree(list.root); //중위순회를 통한 트리 출력
   printf("   계      %d\n", sum);
   fclose(file);
}
