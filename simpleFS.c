//Final project: "Algoritmi e principi dell'informatica"

// Simple File System

/* Nicolò Brunello */


#define maxLen 255
#define maxCom 10
#define maxPath 65025

#include <stdio.h>
#include <stdlib.h>
#include <math.h>



//node structure
typedef struct node_s{
	char *name;
	int numberOfSons;
	int type; // 0= file , 1= directory
	struct node_s *sons[1024];

} node;


node *  detectAction(char[], node * root);
node* initTree(node*);
unsigned long hash(unsigned char *);
void getTokens(char[][maxLen+1], char[maxPath]);
node* initNode(node * , char *);
long hashFunction(unsigned char *, int);

//da eliminare
void scorriAlbero(node*);



int main(int argc,char*argv[]){

	char command[maxCom],n;
	int action,foundEOF=0;
	node *root, *temp;

	root= initTree(root);

	while (!foundEOF){
		scanf ("%s",&command);
		n= getchar();
		if(n == EOF)
			foundEOF= 1;
		else
			root=detectAction(command, root);
	}
	printf("Fine lettura\n");
	scorriAlbero(root);
	free(root);
	return 0;
}

node* detectAction(char input[maxCom],node * root){
	char path[maxPath], tokens[maxLen][maxLen+1];
	int pathLen=0,i=0, index=0;
	node * temp=root;

	//initPath
	for (int j=0; j<maxLen; j++){
		strcpy(tokens[j], "--");
	}

	//detectAction
	if(!strcmp(input,"create")){
		scanf ("%s",&path);
		getTokens(tokens, path );
		while(strcmp(tokens[i], "--")){
			i++;
		}

		//scorro percorso
		if (i==1){
			//todo choose how to assign number of 1024 sons
			//root->sons[1024]
			printf("--> %s\n", tokens[0]);
			index =hashFunction(tokens[0], 0);
			root->sons[index]=initNode(root->sons, tokens[i]);
			root->numberOfSons= root->numberOfSons+1;
		
		}
	
	}
	return root;
}

node* initTree(node * root){
	if(root = (node*) malloc(sizeof(node))){
		root->name= "root";
		root->numberOfSons= 0;
		root->type= 1;
	}	

return root;
}

node* initNode(node * n, char * name){
	if(n = (node*) malloc(sizeof(node))){
		n->name= name;
		n->numberOfSons= 0;
		n->type= 1;
	}	

	return n;
}

void scorriAlbero(node* root){
	node* temp;
	temp=root;
	if(temp->numberOfSons == 0){
		printf("%s \n",root->name);
		printf("n: %d \n", root->numberOfSons);
	}

	else{
		printf("Albero non vuoto\n");
	}

}

unsigned long hash(unsigned char *str) {
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) ^c ; /*hash * 33 + c */

    return hash;
}

long hashFunction(unsigned char *str, int trial){
	uint32_t index;
	unsigned long h= hash(str);

	index = h+(0.5*trial)+(0.5*(trial*trial)); //quadratic probing
	printf("index: --> %ld\n", index);

	index= floor(1024*((index*(0.5*(sqrt(5) - 1)))-floor((index*(0.5*(sqrt(5) - 1))))));

	printf("--- index: %d\n",index);

	return index;
}

void getTokens(char tokens[][maxLen+1] , char path[maxPath] ){
   char s[2] = "/";
   char *tkn;
   int i=0;
   
   /* get the first token */
   tkn = strtok(path, s);
   
   /* walk through other tokens */
   while( tkn != NULL && i<=maxLen ) 
   {
      strcpy(tokens[i], tkn);
      i++;
      tkn = strtok(NULL, s);
   }

}






