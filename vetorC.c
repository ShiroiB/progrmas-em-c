#include <stdio.h>

typedef struct {
    int num1,num2,num3;
    double vet1[1000], vet2[1000],copy[1000],soma,multi,sub,div;
}conj;

void limpar()
{
   #ifdef _WIN32
   system("cls");
   #else
   system("clear");
   #endif
}




int pop (const void *x, const void *y)
{
   const double *A = x, *B = y;
   return (*A > *B) - (*A < *B);
}

void ler(conj *a)
{
    int k,f,p;
    printf("digite numeros (max=1000), digite 0 para sair\n");
    for(k=0;k<1000;k++)
    {

        scanf("%lf", &(*a).vet1[k]);
        if((*a).vet1[k]==0)break;
        (*a).num1=(*a).num1+1;
        
        
    }
}

void soma(conj *a)
{
    int k,f;
    double p=0;
    for(k=0;k<(*a).num1;k++)
    {
        p=p+(*a).vet1[k];  
    }
    (*a).soma=p;

}


void mult(conj *a)
{
    int k,f;
    double p=1;
    qsort((*a).vet1,(*a).num1, sizeof(double), pop);
    for(k=0;k<(*a).num1;k++)
    {
        p=p*(*a).vet1[k];  
    }
    (*a).multi=p;

}

void sub(conj *a)
{
    int k,f;
    double p;
    for(k=0;k<(*a).num1;k++)
    {
        if(k==0)p=(*a).vet1[k];
        else p=p-(*a).vet1[k];  
    }
    (*a).sub=p;

}

void div(conj *a)
{
    int k,f;
    double p;
    for(k=0;k<(*a).num1;k++)
    {
        if(k==0)p=(*a).vet1[k];
        else p=p/(*a).vet1[k];  
    }
    (*a).div=p;

}


void mostrar(conj a)
{
    int k;
    printf("numeros digitados\n");
    printf("(");
    for(k=0;k<a.num1;k++)
    {
        if(k+1>=a.num1)
		{
			printf("%0.2lf", a.vet1[k]);	
			break;
		}
		else printf("%0.2lf,", a.vet1[k]);	
    } 
    printf(")\n");
    printf("soma= %0.2lf\n", a.soma);
    printf("multiplicacao= %0.2lf\n", a.multi);
    printf("subtracao= %0.2lf\n", a.sub);
    printf("divisao= %lf\n", a.div);
    
    
}
void t2(char o[], conj a)
{
    int k;
	FILE *arq;
    arq = fopen(o, "a");
    if (arq!=NULL)
    {
        fprintf(arq, "--------------------------------------------------------------\n");
        fprintf(arq, "__________CALCULADORA SIMPLES DE ELEMENTOS DE UM VETOR_______\n");
        fprintf(arq,"numeros digitados: (");
        for(k=0;k<a.num1;k++)
        {
        if(k+1>=a.num1)
		{
			fprintf(arq, "%0.2lf", a.vet1[k]);	
			break;
		}
	   	else fprintf(arq,"%0.2lf,", a.vet1[k]);	
    } 
        fprintf(arq,")\n");
		
	    fprintf(arq,"soma= %0.2lf\n", a.soma);
        fprintf(arq,"subtracao= %0.2lf\n", a.sub);
        fprintf(arq,"multipicacao= %0.2lf\n", a.multi);
        fprintf(arq,"divisao= %lf\n", a.div);
        fprintf(arq, "--------------------------------------------------------------\n");
        fclose(arq);
    }	

}


void pro(conj a)
{
    printf("__________CALCULADORA SIMPLES DE ELEMENTOS DE UM VETOR_______\n");
    ler(&a);
    soma(&a);
    mult(&a);
    sub(&a);
    div(&a);
    mostrar(a);
    t2("resultado.txt",a);
}
 
 void tryagain(conj a)
 {
     int y=0;
     char n[10];
     pro(a);
     while(y==0)
     {
     printf("Deseja continuar(digite sim ou nao)?\n");
     scanf("%s", n);
     if(n[0]=='S' || n[0]=='s')
     {
         limpar();
         printf("Entendido\n");
         pro(a);
     } 
     if(n[0]=='N' || n[0]=='n')
     {
         printf("Volte sempre\n");
         y=1;
     }
     
 }

 }
int main()
{
    conj a;
    tryagain(a);
    return 0;
}