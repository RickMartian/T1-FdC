#include <stdio.h>
#include <string.h>
int main (){
	int dec, quo, mod;
	char octal[30];
	strcpy (octal,"");
	do{
	printf("\n\tDigite um numero positivo em Decimal: ");
	scanf("%d", &dec);
	} while(dec < 0);
	quo = dec;
	while(quo != 0){
		mod = quo % 8;
		quo /= 8;
		switch (mod){
			case 0: strcat(octal,"0"); break; 
			case 1: strcat(octal,"1"); break;
			case 2: strcat(octal,"2"); break;
			case 3: strcat(octal,"3"); break;
			case 4: strcat(octal,"4"); break;
			case 5: strcat(octal,"5"); break;
			case 6: strcat(octal,"6"); break;
			case 7: strcat(octal,"7"); break;
			
		}
	}
	strrev(octal);
	printf("\nDecimal: %d\n",dec);
	printf("\nOctal: %s\n",octal);
}
