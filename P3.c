/* P3.c */
/* Iasmin Martins */
/* 11811EBI003 */

#include <stdio.h>

int main(){
	char numero[256];
	int i = 0, j = 0;
	printf("Entre com uma frase: ");
	scanf("%s", numero);
	while(numero[i] != '\0'){
		if(numero[i] >= 48 && numero[i] <= 57){
			j = j * 10 + (numero[i] - '0');
		}
		i++;
	}
	printf("%d", j);
	return 0;
}
	
