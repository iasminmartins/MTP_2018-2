/* P7.c */
/* Iasmin Martins */
/* 11811EBI003 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ponto{
  	double x, y;
};

struct ponto *criar(int num){

	struct ponto *p = (struct ponto*) malloc(num*sizeof(struct ponto));
	int i;

	for(i = 0; i < num; i++){
		p[i].x = cos(i * 2.0 * M_PI / (num - 1));
	    p[i].y = sin(i * 2.0 * M_PI / (num - 1));
  	}

  	return p;
}

void salvar(struct ponto *p, int num){
  
	FILE *arq;
	arq = fopen("pontos.dat", "w");
	int i, j;
	  
	for(i = 0; i < num; i++){
	    for(j = 0; j < 20; j++){
	        fprintf(arq, "%d\t%d\t\t", p[i].x, p[i].y);
	    }    
	    fprintf(arq, "\n");
	} 
	fclose(arq);
}

void abin(struct ponto *p, int num){
  
    FILE * arq;
    arq = fopen("pontos.dat", "wb");
    fwrite(p, num, sizeof(struct ponto), arq);
    fclose(arq);
}

struct ponto *ler(unsigned int *pn){
  
    struct ponto *p = (struct ponto *) malloc(sizeof(struct ponto));
    unsigned int num = 0;
    FILE *arq;
    arq = fopen("pontos.dat", "rb");
    
    while(1){
        fread(p, 1, sizeof(struct ponto), arq);
        if(feof(arq)) 
      		break;
        num++;
    }
    
    rewind(arq);
    p = (struct ponto *) realloc(p, num*sizeof(struct ponto));
    fread(p, num, sizeof(struct ponto), arq);
    fclose(arq);
    *pn = num;
    return p;
}

void mostrar(struct ponto *p, struct ponto *pf){
	
    if(p < pf){
    	printf("(%.3lf, %.3lf)\n", (*p).x, (*p).y);
    	mostrar(p + 1, pf);
  	}
}

int main(){
  struct ponto *p;
  int num, opc;

  do{
    system ("cls");
    printf("-----MENU----- \n[1]- Gerar arquivo com pontos. \n[2]- Recuperar pontos de arquivo.\n[3]- Sair do programa.\n\n");
    scanf("%d", &opc);
    
    switch(opc){
        case 1:
          
        printf("\nEntre com o numero de pontos que deseja encontrar: ");
        scanf("%d", &num);
        getchar();
        p = criar(num);
        salvar(p, num);
        abin(p, num);
        printf("\nArquivo gravado!");
        getch();
        
      break;
      
        case 2:
          
        p = ler(&num);
        mostrar(p, p + num);
        getch();
        
      break;
      
        default:
          
        if (opc != 3)
            printf("\nOpcao invalida!");
        getch();
        
      break;
    }
  }while(opc != 3);

  printf ("\nAdeus! :)");
  free(p);
  return 0;
}

