/* P5.c */
/* Iasmin Martins */
/* 11811EBI003 */

#include <stdio.h>

typedef
	unsigned long long int
Bytes8;

typedef
	struct LCG { Bytes8 a, c, m, rand_max, atual;}
LCG;

void semente(LCG * r, Bytes8 seed){
	r->a = 0x5DEECE66DULL;
	r->c = 11ULL;
	r->m = (1ULL << 48);
	r->rand_max = r->m - 1;
	r->atual = seed;
}

Bytes8 lcg_rand(LCG * r){
	r->atual = (r->a * r->atual + r->c) % r->m;
	return r->atual;
}

double lcg_rand_01(LCG * r){
	return ((double) lcg_rand(r))/(r->rand_max);
}

void gera_numeros(float * vetor, int tam, float min, float max, LCG * r){
	int i;
	for(i = 0; i < tam; i++)
		vetor[i] = (max-min)*lcg_rand_01(r) + min;
}

float soma(float *inicio_vetor, float *fim_vetor){
	while(inicio_vetor != fim_vetor + 1)
		return(*inicio_vetor + soma(inicio_vetor + 1, fim_vetor));
	return 0;
}

float produto(float *inicio_vetor, float *fim_vetor){
	while(inicio_vetor != fim_vetor + 1) 
		return(*inicio_vetor * produto(inicio_vetor + 1, fim_vetor));
	return 1;	
}

int main(){
	LCG random;
   	semente(&random, 123456);
	int opc = 0, i;
	float numeros[50];
	gera_numeros(numeros, 50, 0.5, 1.5, &random);
	printf("Os 50 numeros aleatorios gerados sao:\n\n");
	for(i = 0; i < 50; i++)
		printf("[%02d] - %.2f\n", i+1, numeros[i]);
	do{
		printf("\n\nEscolha uma das opcoes abaixo: \n[1]- Somatorio dos numeros \n[2]- Produtorio dos numeros \n[3]- Sair do programa. \n\n");
		scanf("%d", &opc);
		switch(opc){
			case 1:
				printf("\nO somatorio eh %g.", soma(&numeros[0], &numeros[49]));
				break;
			case 2:
				printf("\nO produtorio eh %g.", produto(&numeros[0], &numeros[49]));
				break;	
			default:
				if(opc != 3)
					printf("\nEscolha uma opcao valida.");
		}	
	}while(opc != 3);
	return 0;
}
