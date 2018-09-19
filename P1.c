/* P1.c */
/* iasmin */
/* 11811EBI003 */
#include <stdio.h>
int main(){
	int est = 0, i = 0;
	char bits[256];
	printf("Entre com um numero binario: ");
	scanf("%s", &bits[0]);
	while(bits[i] != '\0'){
		if(est == 0 && bits[i] == '0'){
			est = 0;
		}
		else if(est == 0 && bits[i] == '1'){
			est = 1;
		}
		else if(est == 1 && bits[i] == '0'){
			est = 2;
		}
		else if(est == 1 && bits[i] == '1'){
			est = 0;
		}
		else if(est == 2 && bits[i] == '0'){
			est = 1;
		}
		else{
			est = 2;
		}
		i++;
	}
	printf("\nO estado eh: %d\nA sequencia original eh: %s\n", est, bits);
	if(est == 0){
		printf("\nEh multiplo de 3");
	}
	else{
		printf("\nNao eh");
	}
	return 0;
}
