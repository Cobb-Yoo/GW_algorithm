#include <stdio.h>
#include <stdlib.h>
void right(int n, int cnt, char *line);

void left(int n, int cnt, int stairs, char *line){
	char *tmp = line;
	
	if(n < cnt){
		return;
	}
	else if(n == cnt){
		strcat(*tmp, (char)stairs);
		strcat(*tmp, "L");
		printf("%s\n",*tmp);
		return;
	}
	else{
		strcat(*tmp, (char)stairs);
		strcat(*tmp, "L, ");
		right(n, cnt+1, *tmp);
	}
}

void right(int n, int cnt, char *line){;
	int i;
	char *tmp = line;
	if(n < cnt) return;
	else if(n == cnt){
		strcat(*tmp, "1R");
		printf("%s\n", *tmp);
		return;
	}
	else{
		strcat(*tmp, "1R, ");
	}
	
	for(i=3;i>=1;i++){
		left(n,cnt+1,i,*tmp);
	}
}
main(){
	int n,i;
	printf("How many step do you want: ");
	scanf("%d",&n);
	
	for(i=3;i>=1;i--){
		left(n,i,i,"");
	}
	right(n,1,"");
}
