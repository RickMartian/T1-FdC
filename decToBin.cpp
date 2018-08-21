#include <stdio.h>
#include <string.h>
int main (){
	int dec, quo = 1, mod;
	char bin[20] = "\0";
	printf("\n\tDigite um valor em Decimal: ");
	scanf("%d", &dec);
	quo = dec;
	while(quo != 0){
		mod = quo % 2;
		printf("\nquo == %d\n", quo);
		quo /= 2;
		if(mod == 1)
			strcat(bin,"1");
		else if(mod == 0)
			strcat(bin,"0");
		printf("\nmod == %d\n", mod);
	}
	strrev(bin);
	printf("\nDecimal: %d\n",dec);
	printf("\nBinario: %s\n",bin);
}
