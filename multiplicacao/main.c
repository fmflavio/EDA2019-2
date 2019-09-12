#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
int passos=0;

/** Function to calculate length or number of digits in a number **/
int getSize(long num){
    passos=passos+2;
    int ctr = 0;
    while (num != 0){
        ctr++;
        num /= 10;
        passos=passos+2;
    }
    return ctr;
}
/** Function to multiply two numbers **/
unsigned long Karatsuba(unsigned long x, unsigned long y, int base){
    passos=passos+14;
    int size1 = getSize(x);
    int size2 = getSize(y);
    /** Maximum of lengths of number **/
    int N = MAX(size1, size2);
    /** for small values directly Karatsuba **/
    if (N < base)
        return x * y;
    /** max length divided, rounded up **/
    N = (N / 2) + (N % 2);
    /** multiplier **/
    unsigned long m = (unsigned long)pow(base, N);
    /** compute sub expressions **/
    unsigned long b = x / m;
    unsigned long a = x - (b * m);
    unsigned long d = y / m;
    unsigned long c = y - (d * N);
    /** compute sub expressions **/
    unsigned long z0 = Karatsuba(a, c, base);
    unsigned long z1 = Karatsuba(a + b, c + d, base);
    unsigned long z2 = Karatsuba(b, d, base);
    return z0+((z1-z0-z2)*m)+(z2*(unsigned long)(pow(base,2*N)));
}

long **geraMat(int l,int c,int val1,int val2,int base){
    passos=passos+5;
    int i,j;
    //alocação dinamica
    int **mat=(int**)malloc(sizeof(int*)*l);
    for(i=0;i<l;i++){
        passos++;
        mat[i]=(int*)malloc(sizeof(int)*c);
    }
    printf("\nMatriz a ser multiplicada\n");
    //gera matriz
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            passos++;
            if(i==0 && j==0)
                mat[i][j]=(val1/base)*base;
            else
                if(i==0 && j==1)
                    mat[i][j]=val1%base;
                else
                    if(i==1 && j==0)
                        mat[i][j]=(val2/base)*base;
                    else
                        if(i==1 && j==1)
                            mat[i][j]=val2%base;
            //imprime a primeira matriz
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    return mat;
}
long **multMat(int **mat,int l,int c){
    passos=passos+4;
    int i,j,resp[l][c],total=0;
    printf("\nMatriz antes da soma\n");
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            passos=passos+2;
            //multiplica os valores da matriz
            // original geranto a seundária
            resp[i][j]=mat[0][i]*mat[1][j];
            printf("%d ",resp[i][j]);
            //após exibir a matriz secundaria
            //soma os valores em um inteiro
            total+=resp[i][j];
        }
        printf("\n");
    }
    free(resp);
    return total;
}
int contadigitos(int valor, int base){
    passos=passos+3;
    int contaDigitos = 0;
    if (valor == 0)
        contaDigitos = 1;
    else
        while (valor != 0){
            passos=passos+2;
            contaDigitos++;
            valor = valor / base;
        }
    return contaDigitos;
}
long multiplicacao(int val1,int val2,int base){
    passos=passos+3;
    //multiplicação usando matrizes
    int i,j,l=contadigitos(val1,base),c=contadigitos(val2,base);//valores
    long **mat=geraMat(l,c,val1,val2,base);
    return multMat(mat,l,c);
}

long * somaVet(char *s1, char *s2, int t1, int t2,int base){
    passos=passos+10;
    int i,vaium=0,*sf=(int*)malloc(sizeof(int)*t1);
    char *string=(char*)malloc(sizeof(char)*t1+1);
    for(i=0;i<t1;i++){//insere o maior vetor no final
        passos++;
        sf[i]=(s1[i]-48);
    }
    for(i=0;i<t1;i++){//soma do vetor menor com o vetor final
        passos++;
        sf[i+(t1-t2)]=sf[i+(t1-t2)]+(s2[i]-48);
    }
    printf("\nString inter(char[]): ");
    for(i=0;i<t1;i++)
        printf("%d ",sf[i]);
    //converte o vetor bruto para o final
    for(i=t1-1;i>=0;i--){
        passos++;
        if(sf[i]>=base){
            passos=passos+3;
            int div=sf[i]/base,mod=sf[i]%base+1;
            sf[i]=mod;
            if(i>0)
                sf[i-1]+=div;
            else
                vaium=div;
        }
    }
    printf("\nString Final(char[]): ");
    if(vaium!=0){
        printf("%d ",vaium);
        string[0]=vaium+48;
    }
    for(i=0;i<t1;i++){
        printf("%d ",sf[i]);
        if(vaium!=0)
            string[i+1]=sf[i]+48;
        else
            string[i]=sf[i]+48;
    }
	free(sf);
	return atol(string);
}

int main(){
    printf("Trabalho de ASA 2019-2\nFlavio Miranda de Farias\n");
    while(1){
        clock_t begin,end;//relacionado ao cronometro
        double time_spent=0.0;//relacionado ao cronometro
        long si1=0,si2=0;
        fflush(stdin);
        int tipo,base,t1,t2,i;
        printf("\nDigite\n1-Soma(Proprio)\n2-Multiplicacao(Karatsuba)\n3-Multiplicacao(Proprio):\n--> ");
        scanf(" %d",&tipo);
        printf("\nDigite a Base: ");
        scanf(" %d",&base);
        if(tipo!=3){
            printf("Tamanho da string 1: ");
            scanf(" %d",&t1);
            printf("Tamanho da string 2: ");
            scanf(" %d",&t2);
        } else
            t1=t2=2;
        char *s1=(char*)malloc(sizeof(char)*t1),
            *s2=(char*)malloc(sizeof(char)*t2);
        printf("\nString 1(char[]): ");
        for(i=0;i<t1;i++){
            s1[i]=(rand()%base)+48;
            printf("%c ",s1[i]);
        }
        printf("\nString 2(char[]): ");
        for(i=0;i<t2;i++){
            s2[i]=(rand()%base)+48;
            printf("%c ",s2[i]);
        }
        si1=atol(s1);
        si2=atol(s2);
        printf("\n");
        begin=clock();//inicio do cronometro
        switch(tipo){
            case 1:
                if(t1>=t2)
                    printf("\nResultado(long): %lu",somaVet(s1,s2,t1,t2,base));
                else
                    printf("\nResultado(long): %lu",somaVet(s2,s1,t2,t1,base));
            break;
            case 2:
                printf("\nResultado(long): %lu",Karatsuba(si1,si2,base));
            break;
            case 3:
                printf("\nResultado(long): %lu",multiplicacao(si1,si2,base));
            break;
            default:
            break;
        }
        end=clock();//fim do cronometro
        //exibe cronometro
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
        printf("\n\nTempo de execucao: %lf segundos", time_spent);
        printf("\nPara as strings com valor %d e %d, foram realizados %d passos\n",si1,si2,passos);
        passos=0;
        free(s1);
        free(s2);
        printf("\nNovamente? (s/n): ");
        char c;
        scanf(" %c",&c);
        system("cls");
        if(c!='s')
            return 0;
    }
    return 0;
}
