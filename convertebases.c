#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>

void gotoxy();
void sair();
void menu();
void sobre();
void ajuda();
void decToAll();
void decToBin(int dec, char bin[]);
void decToOctal(int dec, char octal[]);
void decToHexa(int dec, char hexa[]);
void binToAll();
int verificaBin(char bin[]);
int binToDec(char bin[]);
void binToOctal(char bin[], char octal[]);
void binToHexa(char bin[], char hexa[]);
void octalToAll();
int verificaOctal(char octal[]);
void octalBase(char octal, int *mult8, int *dec);
void octalToBin(char octal[], char bin[]);
void octalToHexa(char bin[], char hexa[]);
int verificaHexa(char hexa[]);
void hexaToAll();
int hexaToDec(char hexa[]);
void hexaBase(char hexa, int *mult16, int *dec);
void hexaToBin(char hexa[], char bin[]);
void hexaToOctal(char bin[], char octal[]);

int main() {
	system("mode con:cols=80 lines=30");
	menu();
}

void menu() {
    int opc = 1, //para selecionar as opcoes
    x = 7,  //marco inicial de posicao do icone.
    tecla;
    system("cls");
    gotoxy(20,5); printf("MENU - CONVERSAO DE BASES"); //posiciona o MENU
    gotoxy(18,7); printf("%c", 254); //posiciona o icone na primeira opcao do menu.
    while(tecla != 27){
        gotoxy(20,7); printf("Decimal para todas as bases");
        gotoxy(20,9); printf("Binario para todas as bases");
        gotoxy(20,11); printf("Octal para todas as bases");
        gotoxy(20,13); printf("Hexadecimal para todas as bases");
        gotoxy(20,17); printf("F1 - Ajuda");
        gotoxy(38,17); printf("F2 - Sobre");
        gotoxy(20,19); printf("Esc - Sair");

        tecla = getch();

        if(tecla == 80 && x != 13){ // x != da posicao maxima, para nao fz uma posicao abaixo da ultima.
            gotoxy(18,x); printf("  "); //vai para p posicao (18,7) e coloca espaco vazio;
            x += 2;                        //soma 2 no x;
            gotoxy(18,x); printf("%c",254); // vai para a posicao (18,8), a primeira de baixo, e printa o icone;
            opc++;                       // soma 1 em opc;
            continue; //nao fazer mais nada, e ir pro proximo bloco
        }
         if(tecla == 72 && x != 7){ //x != da posicao minima, para nao fz uma posicao acima da primeira.
            gotoxy(18,x); printf("  ");
            x -= 2;
            gotoxy(18,x); printf("%c",254);
            opc--;
            continue; //nao fazer mais nada, e ir pro proximo bloco
        }
        if(tecla == 13){
            switch(opc){
                case 1:
                	system("cls");
                	decToAll();
                    break; 
                case 2:
                    system("cls");
                    binToAll();
                    break;
                case 3:
                    system("cls");
                    octalToAll();
                    break;
                case 4:
                	system("cls");
                	hexaToAll();
                    break;
                            
            }
        }
        
        if(GetAsyncKeyState(VK_F1)){
            system("cls");
            ajuda();
        }
        
         if(GetAsyncKeyState(VK_F2)){
        	system("cls");
            sobre();
            
        }
        
    }
    
    if(tecla == 27){
    	sair();
    }
}

void decToAll() {
	int dec, tecla;
	char bin[30], octal[30], hexa[30];
	gotoxy(20,5); printf("DECIMAL PARA TODAS AS BASES\n");
	do{
		printf("\n\t\tDigite um numero positivo em decimal: ");
		scanf("%d", &dec);
		if(dec < 0)
			printf("\n\t\tPor favor, digite um numero positivo.\n");
	} while (dec < 0);
	decToBin(dec, bin);
	decToOctal(dec, octal);
	decToHexa(dec, hexa);
	system("cls");
	gotoxy(20,5); 
	printf("\n\t\tDecimal: %d\n", dec);
	printf("\n\t\tBinario: %s\n", bin);
	printf("\n\t\tOctal: %s\n", octal);
	printf("\n\t\tHexadecimal: %s\n", hexa);
	printf("\n\t\tPressione alguma tecla para continuar..");
	getch();
	system("cls");
	gotoxy(20,5); printf("Deseja fazer com outro numero?");
	printf("\n\t\tEnter - Sim\t\t\tEspaco - Voltar ao menu\n\t\tEsc - Sair");
	
	do{
		tecla = getch();
		if(tecla == 13){
			system("cls");
			decToAll();
		}
		else if(tecla == 32)
			menu();
		else if(tecla == 27)
			sair();
	} while(tecla != 27 && tecla != 13 && tecla != 32);
}

void decToBin(int dec, char bin[]) {
	int mod;
	strcpy (bin,"");
	
	if(dec == 0)
		strcpy(bin, "000");
		
	while(dec != 0){
		mod = dec % 2;
		dec /= 2;
		if(mod == 1)
			strcat(bin,"1");
		else if(mod == 0)
			strcat(bin,"0");
	}
	strrev(bin);
}

void decToOctal(int dec, char octal[]) {
	int mod;
	strcpy (octal,"");
	
	if(dec == 0)
		strcpy(octal, "0");
		
	while(dec != 0){
		mod = dec % 8;
		dec /= 8;
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
}

void decToHexa(int dec, char hexa[]) {
	int mod;
	strcpy (hexa,"");
	
	if(dec == 0)
		strcpy(hexa, "0");
		
	while(dec != 0){
		mod = dec % 16;
		dec /= 16;
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
}

void binToAll(){
	int tecla, valido, dec;
	char bin[30], octal[30], hexa[30];
	gotoxy(20,5); printf("BINARIO PARA TODAS AS BASES\n");
	do{
		printf("\n\t\tDigite um numero em binario: ");
		scanf("%s", &bin);
		valido = verificaBin(bin);
	} while (strlen(bin) > 30 || valido == 0);
	dec = binToDec(bin);
	binToOctal(bin, octal);
	binToHexa(bin, hexa);
	system("cls");
	gotoxy(20,5);
	printf("\n\t\tBinario: %s\n", bin);
	printf("\n\t\tDecimal: %d\n", dec);
	printf("\n\t\tOctal: %s\n", octal);
	printf("\n\t\tHexadecimal: %s\n", hexa);
	printf("\n\t\tPressione alguma tecla para continuar..");
	getch();
	system("cls");
	gotoxy(20,5); printf("Deseja fazer com outro numero?");
	printf("\n\t\tEnter - Sim\t\t\tEspaco - Voltar ao menu\n\t\tEsc - Sair");
	
	do{
		tecla = getch();
		if(tecla == 13){
			system("cls");
			binToAll();
		}
		else if(tecla == 32)
			menu();
		else if(tecla == 27)
			sair();
	} while(tecla != 27 && tecla != 13 && tecla != 32);	
}

int verificaBin(char bin[]){
	int i;
	for(i = 0; i < strlen(bin); i++){
		if(bin[i] != '1' && bin[i] != '0'){
			return 0;
		}
	}
	return 1;
}

int binToDec(char bin[]){
	int dec = 0, mult2 = 1, i;
	for(i = strlen(bin)-1; i >= 0; i--){
		if(i == strlen(bin)-1){
			if(bin[i] == '1')
				dec = 1;
			else
				dec = 0;
		}
		else if(bin[i] == '1'){
			mult2 *= 2;
			dec += mult2;
		}
		else
			mult2 *= 2;
	}
	return dec;
}

void binToOctal(char bin1[], char octal[]){
	char aux[4], bin[30];
	int  i, part, x = 2;
	
	strcpy(bin, bin1);
	
	strrev(bin);
	
	while(strlen(bin) % 3 != 0){
		strcat(bin,"0");	
	}
	strrev(bin);
	
	for(i = 0; i < strlen(bin); i++){
		if((i+1) % 3 == 0){
			aux[x-2] = bin[i-2];
			aux[x-1] = bin[i-1];
			aux[x] = bin[i];
			
			if(stricmp(aux, "000") == 0 && i == 2)
				continue;
				
			x = 2;
			part = binToDec(aux);
			
			switch(part){
				case 0: strcat(octal, "0"); break;
				case 1: strcat(octal, "1"); break;
				case 2: strcat(octal, "2");	break;
				case 3: strcat(octal, "3");	break;
				case 4: strcat(octal, "4");	break;
				case 5: strcat(octal, "5");	break;
				case 6: strcat(octal, "6");	break;
				case 7: strcat(octal, "7");	break;
			}		
		}
	}	
}

void binToHexa(char bin1[], char hexa[]){
	char aux[5], bin[30];
	int  i, part, x = 3;
	
	strcpy(bin, bin1);
	
	strrev(bin);
	
	while(strlen(bin) % 4 != 0){
		strcat(bin,"0");	
	}
	strrev(bin);

	for(i = 0; i < strlen(bin); i++){
		if((i+1) % 4 == 0){
			aux[x-3] = bin[i-3];
			aux[x-2] = bin[i-2];
			aux[x-1] = bin[i-1];
			aux[x] = bin[i];
			
			if(stricmp(aux, "0000") == 0 && i == 3)
				continue;
				
			x = 3;
			part = binToDec(aux);
			
			switch(part){
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
	}	
}

void octalToAll(){
	int tecla, valido, dec;
	char bin[30], octal[30], hexa[30];
	gotoxy(20,5); printf("OCTAL PARA TODAS AS BASES\n");
	do{
		printf("\n\t\tDigite um numero em octal: ");
		scanf("%s", &octal);
		valido = verificaOctal(octal);
	} while (strlen(octal) > 30 || valido == 0);
	dec = octalToDec(octal);
	octalToBin(octal, bin);
	octalToHexa(bin, hexa);
	
	system("cls");
	gotoxy(20,5);
	printf("\n\t\tOctal: %s\n", octal);
	printf("\n\t\tDecimal: %d\n", dec);
	printf("\n\t\tBinario: %s\n", bin);
	printf("\n\t\tHexadecimal: %s\n", hexa);
	printf("\n\t\tPressione alguma tecla para continuar..");
	getch();
	
	system("cls");
	gotoxy(20,5); printf("Deseja fazer com outro numero?");
	printf("\n\t\tEnter - Sim\t\t\tEspaco - Voltar ao menu\n\t\tEsc - Sair");
	
	do{
		tecla = getch();
		if(tecla == 13){
			system("cls");
			octalToAll();
		}
		else if(tecla == 32)
			menu();
		else if(tecla == 27)
			sair();
	} while(tecla != 27 && tecla != 13 && tecla != 32);	
}

int verificaOctal(char octal[]){
	int i;
	
	for(i = 0; i < strlen(octal); i++){
		if(octal[i] < 48 || octal[i] > 55){
			return 0;
		}
	}
	return 1;
}

int octalToDec(char octal[]){
	int dec = 0, mult8 = 1, i;
	for(i = strlen(octal)-1; i >= 0; i--){
		if(i == strlen(octal)-1){
			octalBase(octal[i], &mult8, &dec);
			dec = dec/8;
			mult8 = 1;
		}
		else
			octalBase(octal[i], &mult8, &dec);
	}
	return dec;
}

void octalBase(char octal, int *mult8, int *dec){
	switch(octal){
		case '0': *mult8 *= 8; break;
		case '1':  *dec += (*mult8 *= 8); break;
		case '2':  *dec += (2*((*mult8)*= 8)); break;
		case '3':  *dec += (3*((*mult8)*= 8)); break;
		case '4':  *dec += (4*((*mult8)*= 8)); break;
		case '5':  *dec += (5*((*mult8)*= 8)); break;
		case '6':  *dec += (6*((*mult8)*= 8)); break;
		case '7':  *dec += (7*((*mult8)*= 8)); break;
	}
}

void octalToBin(char octal[], char bin[]){
	int i;
	char aux[4];
	strcpy(bin, "");
	for(i = 0; i < strlen(octal); i++){
		
		switch(octal[i]){
			case '0': 	decToBin(0, aux);
						strrev(aux);
					  	while(strlen(aux) % 3 != 0)
				      		strcat(aux, "0");
				      	strrev(aux);
				      	strcat(bin, aux);
				      	strcpy(aux, "");
				      	break;
				      	
			case '1': 	decToBin(1, aux);
						strrev(aux);
					  	while(strlen(aux) % 3 != 0)
				      		strcat(aux, "0");
				      	strrev(aux);
				      	strcat(bin, aux);
				      	strcpy(aux, "");
				      	break;
				      	
			case '2': 	decToBin(2, aux);
						strrev(aux);
					  	while(strlen(aux) % 3 != 0)
				      		strcat(aux, "0");
				      	strrev(aux);
				      	strcat(bin, aux);
				      	strcpy(aux, "");
				      	break;
				      	
			case '3': 	decToBin(3, aux);
						strrev(aux);
					  	while(strlen(aux) % 3 != 0)
				      		strcat(aux, "0");
				      	strrev(aux);
				      	strcat(bin, aux);
				      	strcpy(aux, "");
				      	break;
				      	
			case '4': 	decToBin(4, aux);
						strrev(aux);
					  	while(strlen(aux) % 3 != 0)
				      		strcat(aux, "0");
				      	strrev(aux);
				      	strcat(bin, aux);
				      	strcpy(aux, "");
				      	break;
				      	
			case '5': 	decToBin(5, aux);
						strrev(aux);
					  	while(strlen(aux) % 3 != 0)
				      		strcat(aux, "0");
				      	strrev(aux);
				      	strcat(bin, aux);
				      	strcpy(aux, "");
				      	break;
				      	
			case '6': 	decToBin(6, aux);
			    		strrev(aux);
					  	while(strlen(aux) % 3 != 0)
				      		strcat(aux, "0");
				      	strrev(aux);
				      	strcat(bin, aux);
				      	strcpy(aux, "");
				      	break;
				      	
			case '7': 	decToBin(7, aux);
						strrev(aux);
					  	while(strlen(aux) % 3 != 0)
				      		strcat(aux, "0");
				      	strrev(aux);
				      	strcat(bin, aux);
				      	strcpy(aux, "");
				      	break;
				      		      		      		      		      		      		      	
		}	
	}
}

void octalToHexa(char bin[], char hexa[]){
	
	binToHexa(bin, hexa);	
}

int verificaHexa(char hexa[]){
	int i, cont;
	
	for(i = 0; i < strlen(hexa); i++){
		hexa[i] = toupper(hexa[i]);
		
		if((hexa[i] < 65 || hexa[i] > 70) && (hexa[i] < 48 || hexa[i] > 67))
			return 0;
	}
	
	return 1;	
}

void hexaToAll(){
	int tecla, valido, dec;
	char bin[30], octal[30], hexa[30];
	gotoxy(20,5); printf("HEXA PARA TODAS AS BASES\n");
	do{
		printf("\n\t\tDigite um numero em hexadecimal: ");
		scanf("%s", &hexa);
		valido = verificaHexa(hexa);
	} while (strlen(hexa) > 30 || valido == 0);
	dec = hexaToDec(hexa);
	hexaToBin(hexa, bin);
	hexaToOctal(bin, octal);
	system("cls");
	gotoxy(20,5);
	printf("\n\t\tHexadecimal: %s\n", hexa);
	printf("\n\t\tDecimal: %d\n", dec);
	printf("\n\t\tBinario: %s\n", bin);
	printf("\n\t\tOctal: %s\n", octal);
	printf("\n\t\tPressione alguma tecla para continuar..");
	getch();

	system("cls");
	gotoxy(20,5); printf("Deseja fazer com outro numero?");
	printf("\n\t\tEnter - Sim\t\t\tEspaco - Voltar ao menu\n\t\tEsc - Sair");
	
	do{
		tecla = getch();
		if(tecla == 13){
			system("cls");
			hexaToAll();
		}
		else if(tecla == 32)
			menu();
		else if(tecla == 27)
			sair();
	} while(tecla != 27 && tecla != 13 && tecla != 32);	
}

int hexaToDec(char hexa[]){
	int dec = 0, mult16 = 1, i;
	for(i = strlen(hexa)-1; i >= 0; i--){
		if(i == strlen(hexa)-1){
			hexaBase(hexa[i], &mult16, &dec);
			dec = dec/16;
			mult16 = 1;
		}
		else
			hexaBase(hexa[i], &mult16, &dec);
	}
	return dec;
}

void hexaBase(char hexa, int *mult16, int *dec){
	
	hexa = toupper(hexa);
	
	switch(hexa){
		case '0': *mult16 *= 16; break;
		case '1':  *dec += (*mult16 *= 16); break;
		case '2':  *dec += (2*((*mult16)*= 16)); break;
		case '3':  *dec += (3*((*mult16)*= 16)); break;
		case '4':  *dec += (4*((*mult16)*= 16)); break;
		case '5':  *dec += (5*((*mult16)*= 16)); break;
		case '6':  *dec += (6*((*mult16)*= 16)); break;
		case '7':  *dec += (7*((*mult16)*= 16)); break;
		case '8':  *dec += (8*((*mult16)*= 16)); break;
		case '9':  *dec += (9*((*mult16)*= 16)); break;
		case 'A':  *dec += (10*((*mult16)*= 16)); break;
		case 'B':  *dec += (11*((*mult16)*= 16)); break;
		case 'C':  *dec += (12*((*mult16)*= 16)); break;
		case 'D':  *dec += (13*((*mult16)*= 16)); break;
		case 'E':  *dec += (14*((*mult16)*= 16)); break;
		case 'F':  *dec += (15*((*mult16)*= 16)); break;
	}
	
}

void hexaToBin(char hexa[], char bin[]){
	int i;
	char aux[5];
	strcpy(bin, "");
	for(i = 0; i < strlen(hexa); i++){
		
		hexa[i] = toupper(hexa[i]);
		
		switch(hexa[i]){
			case '0': 	decToBin(0, aux);
						strrev(aux);
					  	while(strlen(aux) % 4 != 0)
				      		strcat(aux, "0");
				      	strrev(aux);
				      	strcat(bin, aux);
				      	strcpy(aux, "");
				      	break;
				      	
			case '1': 	decToBin(1, aux);
						strrev(aux);
					  	while(strlen(aux) % 4 != 0)
				      		strcat(aux, "0");
				      	strrev(aux);
				      	strcat(bin, aux);
				      	strcpy(aux, "");
				      	break;
				      	
			case '2': 	decToBin(2, aux);
						strrev(aux);
					  	while(strlen(aux) % 4 != 0)
				      		strcat(aux, "0");
				      	strrev(aux);
				      	strcat(bin, aux);
				      	strcpy(aux, "");
				      	break;
				      	
			case '3': 	decToBin(3, aux);
						strrev(aux);
					  	while(strlen(aux) % 4 != 0)
				      		strcat(aux, "0");
				      	strrev(aux);
				      	strcat(bin, aux);
				      	strcpy(aux, "");
				      	break;
				      	
			case '4': 	decToBin(4, aux);
						strrev(aux);
					  	while(strlen(aux) % 4 != 0)
				      		strcat(aux, "0");
				      	strrev(aux);
				      	strcat(bin, aux);
				      	strcpy(aux, "");
				      	break;
				      	
			case '5': 	decToBin(5, aux);
						strrev(aux);
					  	while(strlen(aux) % 4 != 0)
				      		strcat(aux, "0");
				      	strrev(aux);
				      	strcat(bin, aux);
				      	strcpy(aux, "");
				      	break;
				      	
			case '6': 	decToBin(6, aux);
			    		strrev(aux);
					  	while(strlen(aux) % 4 != 0)
				      		strcat(aux, "0");
				      	strrev(aux);
				      	strcat(bin, aux);
				      	strcpy(aux, "");
				      	break;
				      	
			case '7': 	decToBin(7, aux);
						strrev(aux);
					  	while(strlen(aux) % 4 != 0)
				      		strcat(aux, "0");
				      	strrev(aux);
				      	strcat(bin, aux);
				      	strcpy(aux, "");
				      	break;
			case '8': 	decToBin(8, aux);
						strrev(aux);
					  	while(strlen(aux) % 4 != 0)
				      		strcat(aux, "0");
				      	strrev(aux);
				      	strcat(bin, aux);
				      	strcpy(aux, "");
				      	break;
				      	
			case '9': 	decToBin(9, aux);
						strrev(aux);
					  	while(strlen(aux) % 4 != 0)
				      		strcat(aux, "0");
				      	strrev(aux);
				      	strcat(bin, aux);
				      	strcpy(aux, "");
				      	break;
				      	
			case 'A': 	decToBin(10, aux);
						strrev(aux);
					  	while(strlen(aux) % 4 != 0)
				      		strcat(aux, "0");
				      	strrev(aux);
				      	strcat(bin, aux);
				      	strcpy(aux, "");
				      	break;
				      	
			case 'B': 	decToBin(11, aux);
						strrev(aux);
					  	while(strlen(aux) % 4 != 0)
				      		strcat(aux, "0");
				      	strrev(aux);
				      	strcat(bin, aux);
				      	strcpy(aux, "");
				      	break;
				      	
			case 'C': 	decToBin(12, aux);
						strrev(aux);
					  	while(strlen(aux) % 4 != 0)
				      		strcat(aux, "0");
				      	strrev(aux);
				      	strcat(bin, aux);
				      	strcpy(aux, "");
				      	break;
				      	
			case 'D': 	decToBin(13, aux);
			    		strrev(aux);
					  	while(strlen(aux) % 4 != 0)
				      		strcat(aux, "0");
				      	strrev(aux);
				      	strcat(bin, aux);
				      	strcpy(aux, "");
				      	break;
				      	
			case 'E': 	decToBin(14, aux);
						strrev(aux);
					  	while(strlen(aux) % 4 != 0)
				      		strcat(aux, "0");
				      	strrev(aux);
				      	strcat(bin, aux);
				      	strcpy(aux, "");
				      	break;
				      	
			case 'F': 	decToBin(15, aux);
						strrev(aux);
					  	while(strlen(aux) % 4 != 0)
				      		strcat(aux, "0");
				      	strrev(aux);
				      	strcat(bin, aux);
				      	strcpy(aux, "");
				      	break;	      		      		      		      		      		      		      		      	
		}	
	}
}

void hexaToOctal(char bin[], char octal[]){
	
	binToOctal(bin, octal);
}

void sobre() {
	int tecla;
	printf("\n\n\t\tPrograma desenvolvido por Henrique Marciano da Silva, \n\t\t2 termo - BSI 2018, para a disciplina Fundamentos da \n\t\tComputacao como 1%c trabalho.", 167);
	printf("\n\n\t\tEspaco - Voltar ao menu");
	
	do{
		tecla = getch();
		if(tecla == 32){
			menu();
		}
	} while (tecla != 32);
	
}

void ajuda() {
	int tecla;
	printf("\n\n\t\tUtilize as setas do teclado para alternar \n\t\tentre as opcoes do menu e o enter para \n\t\tentrar na opcao escolhida.");
	printf("\n\n\t\tEspaco - Voltar ao menu");
	
	do{
		tecla = getch();
		if(tecla == 32){
			menu();
		}
	} while (tecla != 32);
}

void sair() {
	system("cls");
	gotoxy(20,2);
	printf("Obrigado por usar este programa!");
	exit(0);
}
void gotoxy(int x, int y){
    HANDLE handle;
    COORD coord;

    coord.X = x;
    coord.Y = y;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(handle,coord);
}
