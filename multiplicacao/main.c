#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define MAX(a,b) (((a)>(b))?(a):(b))

/** Function to calculate length or number of digits in a number **/
int getSize(long num){
    int ctr = 0;
    while (num != 0){
        ctr++;
        num /= 10;
    }
    return ctr;
}
/** Function to multiply two numbers **/
unsigned long multiply(unsigned long x, unsigned long y, int base){
    int size1 = getSize(x);
    int size2 = getSize(y);
    /** Maximum of lengths of number **/
    int N = MAX(size1, size2);
    /** for small values directly multiply **/
    //if (x < base || y < base)
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
    unsigned long z0 = multiply(a, c, base);
    unsigned long z1 = multiply(a + b, c + d, base);
    unsigned long z2 = multiply(b, d, base);

    //return (z2*pow(base,2*(N/2))+((z1-z2-z0*pow(base,(N/2)))+z0));
    return z0+((z1-z0-z2)*m)+(z2*(unsigned long)(pow(base,2*N)));
}

int **geraMat(int l,int c,int val1,int val2,int base){
    int i,j;
    //alocação dinamica
    int **mat=(int**)malloc(sizeof(int*)*l);
    for(i=0;i<l;i++)
        mat[i]=(int*)malloc(sizeof(int)*c);
    //gera matriz
    for(i=0;i<l;i++)
        for(j=0;j<c;j++){
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
    return mat;
}
void **multMat(int **mat,int l,int c){
    int i,j,resp[l][c],total=0;
    for(i=0;i<l;i++)
        for(j=0;j<c;j++){
            //multiplica os valores da matriz
            // original geranto a seundária
            resp[i][j]=mat[0][i]*mat[1][j];
            printf("%d ",resp[i][j]);
            //após exibir a matriz secundaria
            //soma os valores em um inteiro
            total+=resp[i][j];
        }
    printf("\n%d ",total);
    return resp;
}
void multiplicacao(int base){
    //multiplicação usando matrizes
    int i,j,l=2,c=2,val1=34,val2=13;//valores
    int **mat=geraMat(l,c,val1,val2,base);
    multMat(mat,l,c);
}

void * multVet(char *s1, char *s2, int t1, int t2,int base){
    int i,j,cont=0,vaium=0,*sf=(int*)malloc(sizeof(int)*(t1*t2));
    for(i=0;i<t1;i++)
        for(j=0;j<t2;j++){
            sf[cont]=(s1[i]-48)*(s2[j]-48);
            cont++;
        }
    printf("\nString combinada: ");
    for(i=0;i<cont;i++)
        printf("%d ",sf[i]);
    //converte o vetor bruto para o final
    for(i=cont-1;i>=0;i--)
        if(sf[i]>=base){
            int div=sf[i]/base,mod=sf[i]%base+1;
            //printf("\ni:%d sf[i]:%d div: %d mod: %d",i,sf[i],div,mod);
            if(i==cont)
                sf[i]=mod;
            else{
                if(i==0){
                    break;
                }
                sf[i]=mod;
                sf[i-1]=sf[i-1]+div;
            }
            if(i>0)
                sf[i-1]+=div;
            else
                vaium=div;
        }
    printf("\nString Final: ");
    if(vaium!=0)
        printf("%d ",vaium);
    for(i=0;i<cont;i++)
        printf("%d ",sf[i]);
	free(sf);
}

void * somaVet(char *s1, char *s2, int t1, int t2,int base){
    int i,vaium=0,*sf=(int*)malloc(sizeof(int)*t1);
    for(i=0;i<t1;i++)//insere o maior vetor no final
        sf[i]=(s1[i]-48);
    for(i=0;i<t1;i++)//soma do vetor menor com o vetor final
        sf[i+(t1-t2)]=sf[i+(t1-t2)]+(s2[i]-48);
    printf("\nString inter(char[]): ");
    for(i=0;i<t1;i++)
        printf("%d ",sf[i]);
    //converte o vetor bruto para o final
    for(i=t1-1;i>=0;i--)
        if(sf[i]>=base){
            int div=sf[i]/base,mod=sf[i]%base+1;
            sf[i]=mod;
            if(i>0)
                sf[i-1]+=div;
            else
                vaium=div;
        }
    printf("\nString Final(char[]): ");
    if(vaium!=0)
        printf("%d ",vaium);
    for(i=0;i<t1;i++)
        printf("%d ",sf[i]);
	free(sf);
}

int main(){
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
        printf("Tamanho da string 1: ");
        scanf(" %d",&t1);
        printf("Tamanho da string 2: ");
        scanf(" %d",&t2);
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
        printf("\n");
        begin=clock();//inicio do cronometro
        switch(tipo){
            case 1:
                if(t1>=t2)
                    somaVet(s1,s2,t1,t2,base);
                else
                    somaVet(s2,s1,t2,t1,base);
            break;
            case 2:
                si1=atol(s1);
                si2=atol(s2);
                printf("\nResultado: %lu",multiply(si1,si2,base));
            break;
            case 3:
                multiplicacao(base);
            break;
            default:
            break;
        }
            /*
            if(t1>=t2)
                multVet(s1,s2,t1,t2,base);
            else
                multVet(s2,s1,t2,t1,base);
            */
        end=clock();//fim do cronometro
        //exibe cronometro
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
        printf("\n\nTime elpased is %lf seconds\n", time_spent);
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
