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

int main() {
	menu();
}

void menu() {
    int opc = 1, //para selecionar as opcoes
    continua = 1,//continua == 1 para manter o loop
    x = 7;  //marco inicial de posicao do icone.
    system("cls");
    gotoxy(20,5); printf("MENU - CONVERSAO DE BASES"); //posiciona o MENU
    gotoxy(18,7); printf("%c", 254); //posiciona o icone na primeira opcao do menu.
    while(continua){
        gotoxy(20,7); printf("Decimal para todas as bases");
        gotoxy(20,9); printf("Binario para todas as bases");
        gotoxy(20,11); printf("Octal para todas as bases");
        gotoxy(20,13); printf("Hexadecimal para todas as bases");
        gotoxy(20,17); printf("F1 - Ajuda");
        gotoxy(38,17); printf("F2 - Sobre");
        gotoxy(20,19); printf("Esc - Sair");

        system("pause>nul"); //pausa o programa até pegar um input, >nul nao retorna output, daí nao sai Pressione...

        if(GetAsyncKeyState(VK_DOWN) && x != 13){ // x != da posicao maxima, para nao fz uma posicao abaixo da ultima.
            gotoxy(18,x); printf("  "); //vai para p posicao (18,7) e coloca espaco vazio;
            x += 2;                        //soma 2 no x;
            gotoxy(18,x); printf("%c",254); // vai para a posicao (18,8), a primeira de baixo, e printa o icone;
            opc++;                       // soma 1 em opc;
            continue; //nao fazer mais nada, e ir pro proximo bloco
        }
         if(GetAsyncKeyState(VK_UP) && x != 7){ //x != da posicao minima, para nao fz uma posicao acima da primeira.
            gotoxy(18,x); printf("  ");
            x -= 2;
            gotoxy(18,x); printf("%c",254);
            opc--;
            continue; //nao fazer mais nada, e ir pro proximo bloco
        }
        if(GetAsyncKeyState(VK_RETURN)){
            switch(opc){
                case 1:
                	system("cls");
                	decToAll();
                    break; 
                case 2:
                    
                    printf("funcao binToAll");
                    break;
                case 3:
                    
                    printf("funcao OctalToAll");
                    break;
                case 4:
                    
                    printf("funcao HexaToAll");
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
        
        if(GetAsyncKeyState(VK_ESCAPE)){
            system("cls");
            sair();
           	exit(0);
        }
    }
}

void decToAll() {
	int dec, tecla;
	char bin[30], octal[30], hexa[30];
	gotoxy(20,5); printf("DECIMAL PARA TODAS AS BASES");
	do{
		printf("\n\t\tDigite um numero positivo em decimal: ");
		scanf("%d", &dec);
		if(dec < 0)
			printf("\n\t\tPor favor, digite um numero positivo.\n");
	} while (dec < 0);
	decToBin(dec, bin);
	decToOctal(dec, octal);
	decToHexa(dec, hexa);
	printf("\n\t\tDecimal: %d\n", dec);
	printf("\n\t\tBinario: %s\n", bin);
	printf("\n\t\tOctal: %s\n", octal);
	printf("\n\t\tHexadecimal: %s\n", hexa);
	printf("\n\t\tPressione alguma tecla para continuar..");
	getch();
	system("cls");
	gotoxy(20,5); printf("Deseja fazer com outro numero?");
	printf("\n\t\tEnter - Sim\t\t\tEspaco - Voltar ao menu\n\t\tEsc - Sair");
	tecla = getch();
	do{
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

void sobre() {
	int tecla;
	printf("\n\n\t\tPrograma desenvolvido por Henrique Marciano da Silva, 2 termo - BSI 2018, \n\t\tpara a disciplina Fundamentos da Computacao como 1%c trabalho.", 167);
	printf("\n\n\t\tEsc - Voltar ao menu");
	tecla = getch();
	do{
		if(GetAsyncKeyState(VK_ESCAPE)){
			menu();
		}
	} while (tecla != 27);
	
}

void ajuda() {
	int tecla;
	printf("\n\n\t\tUtilize as setas do teclado para alternar entre as opcoes do menu\n\t\t e o enter para entrar na opcao escolhida.");
	printf("\n\n\t\tEsc - Voltar ao menu");
	tecla = getch();
	do{
		if(GetAsyncKeyState(VK_ESCAPE)){
			menu();
		}
	} while (tecla != 27);
	
}

void sair() {
	system("cls");
	printf("\n\t\tObrigado por usar este programa!");
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
