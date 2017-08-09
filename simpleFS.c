//Final project: "Algoritmi e principi dell'informatica"

// Simple File System

/* Nicolò Brunello */


#define maxLen 255
#define maxCom 10
#define maxPath 65025

#include <stdio.h>
#include <stdlib.h>

//node structure
typedef struct node_s{
	char *name;
	int numberOfSons;
	int type; // 0= file , 1= directory
	struct node_s *sons;

} node;


void detectAction(char[]);
node* initTree(node*);
unsigned long hash(unsigned char *);

//da eliminare
void scorriAlbero(node*);



int main(int argc,char*argv[]){

	char command[maxCom],n;
	int action,foundEOF=0;
	node *root, *temp;

	root= initTree(root);

	while (!foundEOF){
		scanf ("%s",command);
		n= getchar();
		if(n == EOF)
			foundEOF= 1;
		else
			detectAction(command);
	}
	scorriAlbero(root);
	return 0;
}

void detectAction(char input[maxCom]){
	char path[maxPath];
	if(!strcmp(input,"create")){
		scanf ("%s",&path);

		//todo choose how to assign number of 1024 sons

	}
}

node* initTree(node * root){
	if(root = (node*) malloc(sizeof(node)*1024)){
		root->name= "root";
		root->numberOfSons= 0;
		root->type= 1;
	}	

return root;
}

void scorriAlbero(node* root){
	node* temp;

	temp=root;
	if(temp->numberOfSons == 0)
		printf("%s \n",root->name);
	else{
		printf("Albero non vuoto");
	}

}

unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}


