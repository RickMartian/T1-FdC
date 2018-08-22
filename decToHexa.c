#include <stdio.h>
#include <string.h>
int main (){
	int dec, quo, mod;
	char hexa[30];
	strcpy (hexa,"");
	do{
	printf("\n\tDigite um numero positivo em Decimal: ");
	scanf("%d", &dec);
	} while(dec < 0);
	quo = dec;
	while(quo != 0){
		mod = quo % 16;
		quo /= 16;
		switch (mod){
			case 0: strcat(hexa,"0"); break; 
			case 1: strcat(hexa,"1"); break;
			case 2: strcat(hexa,"2"); break;
			case 3: strcat(hexa,"3"); break;
			case 4: strcat(hexa,"4"); break;
			case 5: strcat(hexa,"5"); break;
			case 6: strcat(hexa,"6"); break;
			case 7: strcat(hexa,"7"); break;
			case 8: strcat(hexa,"8"); break; 
			case 9: strcat(hexa,"9"); break;
			case 10: strcat(hexa,"A"); break;
			case 11: strcat(hexa,"B"); break;
			case 12: strcat(hexa,"C"); break;
			case 13: strcat(hexa,"D"); break;
			case 14: strcat(hexa,"E"); break;
			case 15: strcat(hexa,"F"); break;	
		}
	}
	strrev(hexa);
	printf("\nDecimal: %d\n",dec);
	printf("\nHexadecimal: %s\n",hexa);
}
