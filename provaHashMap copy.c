// provaHashFunction

/* Nicolò Brunello */


#define maxLen 255
#define maxCom 10
#define maxPath 65025

#include <stdio.h>
#include <stdlib.h>


int hashFunction (int in,int j){
	int i = (in+3*j+17*(j*j))%1024;
	return i;
}


int main(int argc,char*argv[]){

	int hashmap[1024],i;
	int collisioni=0;

	for (i=0; i< 1023; i++){
		int n= hashFunction(i,0);
		if(hashmap[n]>0){
			collisioni++;
			int k=1;
			int fine=0;
			while(!fine){
				n=hashFunction(i,k);
				if(hashmap[n]>0)
					collisioni++;
				else {
					fine=1;
					hashmap[n]=i;
				}

			}
		}
		else
			hashmap[n]= i;
	}
	printf("%d\n", collisioni);
	return 0;
}




