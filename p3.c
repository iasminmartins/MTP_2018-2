/* P3.c */
/* Iasmin Martins */
/* 11811EBI003 */

#include <stdio.h>

int main(){
	char numero[256], n[256];
	int i = 0, j = 0;
	printf("Entre com uma frase: ");
	scanf("%s", numero);
	while(numero[i] != '\0'){
		if(numero[i] >= 48 && numero[i] <= 57){
			n[j] = numero[i];
			j++;
		}
		i++;
	}
	i = atoi(n);
	printf("%d", i);
	return 0;
}
