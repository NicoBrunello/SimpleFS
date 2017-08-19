//Final project: "Algoritmi e principi dell'informatica"

// Simple File System

/* Nicolò Brunello */

//TODO: control how to read the path (starting root)


#define maxLen 255
#define maxCom 10
#define maxPath 65025
#define maxSons 1024
#define knuthConst 0.6180339887



#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//node structure
typedef struct node_s{
	char *name;
	int numberOfSons;
	int type; // 0= file , 1= directory
	struct node_s *sons[maxSons];

} node;


node *  detectAction(char[], node * root);
unsigned long hash(unsigned char *);
void getTokens(char[][maxLen+1], char[maxPath]);
node* initNode( char *);
long hashFunction(unsigned char *, int);
node* create (node*);
int  find(node*, node **,char [][maxLen+1], char [maxPath]);
void parsePath(char[][maxLen+1], char[maxPath]);
node* runPath(node * , char [][maxLen+1]);


//da eliminare
void scorriAlbero(node*);



int main(int argc,char*argv[]){

	char command[maxCom],n;
	int action,foundEOF=0;
	node *root, *temp;

	root= initNode( "root");

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

	int i=0,res;

	//detectAction
	if(!strcmp(input,"create")){
		root= create(root);	
	} else if(!strcmp(input, "find")){
		//res=find(root);

	}

	return root;
}

node* initNode( char * name){
	node* n;
	if(n = (node*) malloc(sizeof(node))){
		n->name= name;
		n->numberOfSons= 0;
		n->type= 1;
	}	
	for(int i =0; i<maxSons; i++){
		n->sons[i]= NULL;
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
	index= floor(1024*((index*knuthConst)-floor(index*(knuthConst))));
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

node* create (node*root){
	node * temp=root;
	node * resFind=NULL;
	int i=0, index=0, j, end=0;
	char path[maxPath], tokens[maxLen][maxLen+1];
	
	//initPath
	for (int j=0; j<maxLen; j++){
			strcpy(tokens[j], "--");
		}
	
	parsePath(tokens, path);

	resFind= runPath(root, tokens);
	if(resFind!=NULL){
		printf("name father --> %s\n", resFind->name);
		j=0;
		while(strcmp(tokens[j+1],"--"))
			j++;
		index= hashFunction(tokens[j],0);
		resFind->sons[index]= initNode(tokens[j]);
		printf("Created : %s\n",resFind->sons[index]->name);
	}
	
	/*while(strcmp(tokens[i], "--")){
		printf("--> %s\n", tokens[i]);
		index =hashFunction(tokens[i], 0);
		printf("index: %d\n",index);

		j=0;

		while (temp->sons[index] != NULL  && j<1024){ 		
			j++;
			index= hashFunction(tokens[i],j);
			printf("index: %d\n",index);
			
		}
		/*
		while (!strcmp(temp->sons[index]->name ,tokens[i])){
			temp= temp->sons[index];
		}

		i++;
	}*/

	//scorro percorso
	/*if (i==1){
		//todo choose how to assign number of 1024 sons
		//root->sons[1024]
		printf("--> %s\n", tokens[0]);
		index =hashFunction(tokens[0], 0);
		root->sons[index]=initNode(root->sons, tokens[i]);
		root->numberOfSons= root->numberOfSons+1;
	
	}*/
	return root;
}

int find(node * root, node ** res, char tokens[][maxLen+1], char path[maxPath]){
	int found=0;
	return found;
	
}

void parsePath(char tokens[][maxLen+1], char path[maxPath]){

	scanf ("%s",path);
	getTokens(tokens, path );

}

node* runPath(node * root,  char tokens[][maxLen+1]){
	node *  temp=root;
	int i=0, index;
	while(strcmp(tokens[i+2],"--") && !strcmp(temp->name, tokens[i]) ){
		index= hashFunction(tokens[i+1], 0);
		printf("index inside--> %d of %s\n",index , tokens[i+1]);
		if( temp->sons[index] !=NULL && strcmp(temp->sons[index]-> name , tokens[i]) ){
			temp=temp->sons[index];
			i++;
		}else{
			printf("Errore percorso\n");
			return NULL;
		}
	}

	if(!strcmp(tokens[i+2], "--") ){
		return temp;
	}
	else
		return NULL;
}







