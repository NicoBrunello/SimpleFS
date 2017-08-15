// provaHashFunction

/* Nicolò Brunello */


#define maxLen 255
#define maxCom 10
#define maxPath 65025
#define N 255

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/*
unsigned long hash(unsigned char *);
int hashFunction(int in  ,int j );
void gen(char *);*/



unsigned long hash(unsigned char *str) {
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c ; /*hash * 33 + c */

    return hash;
}

unsigned int hashFunction (unsigned char * str){
	int j ;
	j= hash(str)%1024;
	
	return j;
}
unsigned char* gen(unsigned char *dst) {
    int i, n;  

     
   	/* init seed */
    if (dst = (char*)malloc(N*sizeof(char))) {  
 
	   	while (i<N){

	    	n =rand()%122;
	    	if((n>65 && n<90) || (n>97 && n< 122)){
				dst[i++] = n;
	    	}
	            
	    }
	    dst[N] = '\0';       
	}
	else{
		printf("Allocaziona fallita");
	}
    /* null terminate the string */
    return dst;
    fre(dst);
}


int main(int argc,char*argv[]){
	srand(time(NULL));
	char* hashmap[1024][255];
	int collisioni=0,index=0;
	char * str;
	for (int i= 0; i<1024; i++)
		strcpy(hashmap[i], "--");

	for (int i=0; i< 1024; i++){
		str= gen(str); 
		index = hashFunction(str);
		printf("index --> %d\n", index);
		while (hashmap[index]=="--"){
			collisioni ++ ;
			index ++;
		}
		strcpy(hashmap[index], str); ;
		
		
	}
	for(int i=0; i<=1024;i++){
		printf(" %s | \n",hashmap[i]);

	}
	printf("\n%d\n", collisioni);
	free (str);
	return 0;
}
