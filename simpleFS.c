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
	int type;
	char *content; // 0= file , 1= directory
	struct node_s *sons[maxSons];

} node;

// Read from stdin the command and decides what to do 
node *  detectAction(char[], node * root);

// it takes the charcacter as parameter and calculate the index of the has table[1024]
unsigned long hash(unsigned char *);

//It take as parameters the characters table where to save the path splitted, and the string-path to split
void getTokens(char[][maxLen+1], char[maxPath]);

//Create a node of the tree and returns the pointing variable
node* initNode( char *, int, char * );

//call hash and handle probing 
long hashFunction(unsigned char *, int);

//create a node taken as parameter
node* create (node*, int type);

// returns 1 if the resource exists, 0 otherwise
int  find(node*, node **,char [][maxLen+1], char [maxPath]);

//read from stdin and call getTokens
void parsePath(char[][maxLen+1], char[maxPath]);

// flow through the tree and returns the father of the resource takens as parameter
node* runPath(node * , char [][maxLen+1], int);


//da eliminare
void scorriAlbero(node*);



int main(int argc,char*argv[]){

	char command[maxCom],n;
	int action,foundEOF=0;
	node *root, *temp;

	root= initNode( "root", 1, NULL);

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
	
	return 0;
}

node* detectAction(char input[maxCom],node * root){

	int i=0,res;

	//detectAction
	if(!strcmp(input,"create")){
		root= create(root, 0);	
	} else if(!strcmp(input, "find")){
		//res=find(root);

		} else if(!strcmp(input, "create_dir")) {
			root=  create(root, 1);
			}

	return root;
}

node* initNode( char * name, int type, char* contet){
	node* n;
	if(n = (node*) malloc(sizeof(node))){
		n->name= name;
		n->numberOfSons= 0;
		n->type= type;
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
	free(root);

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

node* create (node*root, int type){
	node * temp=root;
	node * resFather=NULL;
	int i=0, index=0, j, end=0,k=0;
	char path[maxPath], tokens[maxLen][maxLen+1];
	
	//initPath
	for (int j=0; j<maxLen; j++){
			strcpy(tokens[j], "--");
		}
	
	parsePath(tokens, path);

	while(strcmp(tokens[k+1], "--"))
		k++;

	if(k==0)
		resFather=root;
	else if(k==1){
			index=hashFunction(tokens[0],0);
			if(root->sons[index]!=NULL && !strcmp(root->sons[index]->name, tokens[0]))
				resFather=root->sons[index];
		}
		else {
			resFather= runPath(temp, tokens, 0);
		}

	if(resFather!=NULL){
		j=0;
		while(strcmp(tokens[j+1],"--"))
			j++;
		index= hashFunction(tokens[j],0);
		resFather->sons[index]= initNode(tokens[j], type, NULL);
		resFather->numberOfSons ++;
		printf("Created : %s at %d of %s\n",resFather->sons[index]->name,index, resFather->name);
	}
	
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

node* runPath(node *root, char tokens[][maxLen+1], int count){
	int index;
	if(!strcmp(tokens[count+2],"--"))
		return root;
	index= hashFunction(tokens[count],0);
	printf("Looking at %d of %s\n", index, root->name);

	if(root->sons[index]!=NULL && !strcmp(root->sons[index]->name, tokens[count]))
		return runPath(root->sons[index],tokens,count+1);
	else
		return NULL;

}







