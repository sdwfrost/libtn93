#include <stdio.h>
#include <stdlib.h>

int main(void) {
	const unsigned char alphabet[] = "ACGTURYSWKMBDHVN?-";
	const unsigned char lcalphabet[] = "acgturyswkmbdhvn";
	for(int i=0;i<=17;i++){
		printf("%i\t%i\t%c\n",alphabet[i],i,alphabet[i]);
		//map_char[alphabet[i]] = i;
	}
	for(int i=0;i<=15;i++){
		printf("%i\t%i\t%c\n",lcalphabet[i],i,lcalphabet[i]);
	}
	return(0);
}
