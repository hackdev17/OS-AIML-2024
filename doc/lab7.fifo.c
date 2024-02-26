#include <stdio.h>
#include <stdlib.h>

int fr[3];

void display(){
	int i;
	printf("\n");

	for(i=0;i<3;i++)
		printf("\t%d",fr[i]);
}

void main(){
	int page[12]={2,3,2,1,5,2,4,5,3,2,5,2};
	int i,j,flag1=0,flag2=0,pf=0,frsize=3,top=0;

	for(i=0;i<3;i++)
		fr[i]=-1;

	for(j=0;j<12;j++){
		flag1=flag2=0;

		for(i=0;i<12;i++)
			if(fr[i]==page[j]){
				flag1=flag2=1;
				break;
			}

		if(flag1==0)
			for(i=0;i<frsize;i++)
				if(fr[i]==-1){
					fr[i]=page[j];
					flag2=1;
					break;
				}

		if(flag2==0){
			fr[top]=page[j];
			top++;
			pf++;
			if(top>=frsize)
			top=0;
		}

		display();
	}

	printf("\n\nNumber of page faults : %d\n",pf+frsize);
	exit(0);
}
