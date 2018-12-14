/* P4.c */
/* Iasmin Martins */
/* 11811EBI003 */

#include <stdio.h>

double funcao(float, float);

int main()
{
	float m, n;
	printf("Entre com dois numeros: ");
	scanf ("%f%f", &m, &n);
	printf("%g + %g = %g", m, n, funcao(m,n));
	return 0;
}

double funcao(float m, float n)
{
	if(m == 0) 
		return n + 1;
	else if(m > 0 && n == 0) 
		return funcao(m - 1, 1);
	else if(m > 0 && n > 0) 
		return funcao(m - 1, funcao(m, n - 1));
}
