#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct{
	char dname[10],fname[10][10];
	int fcnt;
}dir;

int main(){
	int i,ch;
	char f[30];
	dir.fcnt=0;

	printf("\nEnter name of directory : ");
	scanf("%s",dir.dname);

	printf("\n1. Create File\n2. Delete File\n3. Search File\n4. Display Files\n5. Exit");
	while(1){
		printf("\n> ");
		scanf("%d",&ch);

		switch(ch){
			case 1:
				printf("\nEnter the name of the file : ");
				scanf("%s",dir.fname[dir.fcnt]);
				dir.fcnt++;
				break;
			case 2:
				printf("\nEnter the name of the file : ");
				scanf("%s",f);
				for(i=0;i<dir.fcnt;i++)
					if(strcmp(f,dir.fname[i])==0){
						printf("\nFile %s is deleted !",f);
						strcpy(dir.fname[i],dir.fname[dir.fcnt-1]);
						break;
					}

				if(i==dir.fcnt)
					printf("\nFile %s not found !",f);
				else
					dir.fcnt--;
				break;
			case 3:
				printf("\nEnter the name of the file : ");
				scanf("%s",f);
				for(i=0;i<dir.fcnt;i++)
					if(strcmp(f,dir.fname[i])==0){
						printf("\nFile %s is found !",f);
						break;
					}

				if(i==dir.fcnt)
					printf("\nFile %s not found !",f);
				break;
			case 4:
				if(dir.fcnt==0)
					printf("\nDirectory Empty !");
				else{
					printf("\nThe Files are :\n");
					for(i=0;i<dir.fcnt;i++)
						printf("%s ",dir.fname[i]);
					printf("\n");
				}
				break;
			default:
				exit(0);
		}
	}
}
