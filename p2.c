/* P2.c */
/* Iasmin */
/* 11811EBI003 */

#include <stdio.h>

void inv(char vet[]){
	int i, j, cont = 0, aux;
	for(i = 0; vet[i] != '\0'; i++, cont++);
	j = cont - 1;
	for(i = 0; i < j; i++, j--){
		aux = vet[i];
		vet[i] = vet[j];
		vet[j] = aux;
	}
	vet[cont] = '\0';
}

int pot(int n, int n2){
	int i, r = 1;
	for(i = 0; i < n2; i++, r*=n);
	return r;
}

int b_d(char vet[]){
	inv(vet);
	int i, soma = 0;
	for(i = 0; vet[i] != '\0'; i++){
		if(vet[i] == '1'){
			soma += vet[i] * pot(2, i);
		}
	}
	return soma/49;
}

void d_b(int n){
	int i, flag = 0, vet[256], j;
	j = n;
	for(i = 0; flag < 1; i++){
		vet[i] = j % 2;
		j /= 2;
		if(j == 0 || j == 1){
			vet[i + 1] = j;
			j = i + 1;
			flag++;
		}
	}
	printf("\nEm binario ele eh ");
	for(j; j >= 0; j--){
		printf("%d", vet[j]);
	}
}

int main(){
	char n[256];
	int esc = 0;
	do{
		printf("-------------- Menu --------------\nEscolha uma opcao de conversao:\n[1]-Binario para decimal\n[2]-Binario para hexadecimal\n[3]-Hexadecimal para decimal\n[4]-Hexadecimal para binario\n[5]-Decimal para binario\n[6]-Decimal para hexadecimal\n[7]-Octal para decimal\n[8]-Decimal para octal\nEntre com a sua escolha: ");
		scanf("%d", &esc);
		if(esc == 1){
			printf ("\nEntre com numero em binario: ");
			scanf("%s", &n[0]);
			printf("\nEm decimal ele eh %d", b_d(n));
		}
		if(esc == 2){
			printf ("\nEntre com numero em binario: ");
			scanf ("%s", &n[0]);
			printf ("\nEm hexadecimal ele eh %x", b_d(n));
		}
		if(esc == 3){
			int(n);
			printf ("\nEntre com o numero em hexadecimal: ");
			scanf ("%x", &n);
			printf ("\nEm decimal ele eh %d", n);
		}
		if(esc == 4){
			int(n);
			printf ("\nEntre com o numero em hexadecimal: ");
			scanf ("%x", &n);
			d_b(n);
		}
		if(esc == 5){
			int(n);
			printf ("\nEntre com o numero em decimal: ");
			scanf("%d", &n);
			d_b(n);
		}
		if(esc == 6){
			int(n);
			printf ("\nEntre com o numero em decimal: ");
			scanf("%d", &n);
			printf ("\nEm hexadecimal ele eh %x", n);
		}
		if(esc == 7){
			int(n);
			printf ("\nEntre com o numero em octal: ");
			scanf("%o", &n);
			printf("\nEm decimal ele eh %d", n);
		}		
		if(esc == 8){
			int(n);
			printf ("\nEntre com o numero em decimal: ");
			scanf("%d", &n);
			printf ("\nEm octal ele eh %o", n);
		}
	}while(esc < 1 || esc > 8);
	return 0;
}
