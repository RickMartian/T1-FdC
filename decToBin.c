#include <stdio.h>
#include <string.h>
int main (){
	int dec, quo, mod;
	char bin[30];
	strcpy (bin,"");
	do{
	printf("\n\tDigite um numero positivo em Decimal: ");
	scanf("%d", &dec);
	} while(dec < 0);
	quo = dec;
	while(quo != 0){
		mod = quo % 2;
		quo /= 2;
		if(mod == 1)
			strcat(bin,"1");
		else if(mod == 0)
			strcat(bin,"0");
	}
	strrev(bin);
	printf("\nDecimal: %d\n",dec);
	printf("\nBinario: %s\n",bin);
}
