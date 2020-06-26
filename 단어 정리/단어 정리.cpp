#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define DataType char

typedef struct tNode { // Ʈ���� ����ü
   DataType data[MAX];
   int Line[MAX];
   int count;
   struct tNode *Left;
   struct tNode *Right;
}tNode;

typedef struct List { // �ص���
   struct tNode *root;
}List;

void init_List(List *list) { //����� �ʱ�ȭ
   list->root = NULL;
}

void find_position(tNode **root, tNode *new) { //��ġ�� ã�� �����͸� �ִ� �Լ�
   tNode *searched = *root; //��ġ�� �ش�� ���
   tNode *parent = NULL; //�θ���
   int n = 1;

   while (searched) { //��ġ Ž��
      if (!strcmp(searched->data, new->data)) {
         searched->count++;
         free(new);
         n--; //���� ���� �־����� 46�� �� ������ ���ǹ��� �������� �ʵ��� �ϱ� ���� ǥ��
         break;
      }

      parent = searched;

      if (strcmp(searched->data, new->data) > 0) { //�ش�Ǵ� ��ġ�� ���ο� ������ ���� ���� ��ġ�� �����ϱ� ���� ���ǹ�
         searched = searched->Left;
      }
      else if (strcmp(searched->data, new->data) < 0) {
         searched = searched->Right;
      }

   }

   if (n == 1) { //�ش� ��ġ�� ��� ����
      if (strcmp(parent->data, new->data) > 0) {
         parent->Left = new;
      }
      else if (strcmp(parent->data, new->data) < 0) {
         parent->Right = new;
      }
   }
}

char *lower(char *txt) { //������ ��ҹ����� ������ ���ֱ� ���ؼ� ��� �ҹ��ڷ� �ٲٴ� �Լ�
   int i;
   for (i = 0;i<strlen(txt);i++) {
      if ('A' <= txt[i] && txt[i] <= 'Z') {
         txt[i] = txt[i] + 32;
      }
   }
   return txt;
}

void insertToTree(List *list, char *txt) { //list�� txt���� �������� �Լ�
   tNode *new = (tNode *)malloc(sizeof(tNode));
   
   if (!new) { //�޸𸮰� �Ҵ�ƴ��� Ȯ��
      printf("�޸� �Ҵ翡 ���� �Ͽ����ϴ�.");
      exit(1);
   }

   new->Left = NULL;
   new->Right = NULL;
   new->count = 1;
   strcpy(new->data, lower(txt)); //���ڰ� �ƴ� ���ڿ��̹Ƿ� strcpy�� ���

   if (!(list->root)) {
      list->root = new; //����ִ� list�� ���� ���
   }
   else {
      find_position(&(list->root), new);
   }
}

void printTree(tNode *root) { //������ȸ�� �ش� Ʈ�� ���
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
   FILE *file = fopen("data.txt", "r"); //data.txt��� ������ ����

   if (file == NULL) {
      printf("���� ���� ����\n");
      return 1;
   }

   init_List(&list);
    
   while(feof(file) == 0) { //������ ó������ ������ �������
      fgets(tmp,MAX,file);
      str = strtok(tmp," \n?",file); // �� ��, ��\n��, ��?���� �ش簪�� ������ ���� ���� ����
      while (str){
         insertToTree(&list, str);
         sum++;
         str = strtok(NULL, " \n?"); // �� ��, ��\n��, ��?���� �ش簪�� ������ ���� ���� ����
      }
   }
   printf("  �ܾ�    Ƚ��\n");
   printTree(list.root); //������ȸ�� ���� Ʈ�� ���
   printf("   ��      %d\n", sum);
   fclose(file);
}
