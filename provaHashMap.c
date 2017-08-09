// provaHashFunction

/* Nicolò Brunello */


#define maxLen 255
#define maxCom 10
#define maxPath 65025
#define N 588
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
unsigned long hash(unsigned char *);
int hashFunction (int ,int);
void gen(char *);


int main(int argc,char*argv[])

	int hashmap[1024],i;
	int collisioni=0;
	char * str;
	printf("ok");

	for (i=0; i< 1500; i++){
		gen(str); 
		printf("%s \n", str);
		
	}
	printf("%d\n", collisioni);
	return 0;
}

int hashFunction (int in,int j){
	
	return i;
}

unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

void gen(char *dst)
{
    int i, n;  

    srand(time(NULL));               /* init seed */
    if ((dst = malloc(N)) == NULL)   /* caller will need to free this */
        return;
    for (i = 0; i < N; )
        if ((n = rand()) < 'A' && n > 'Z')
            dst[i++] = n;
    dst[N - 1] = 0;                   /* null terminate the string */
}



