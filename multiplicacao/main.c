#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void * multVet(char *s1, char *s2, int t1, int t2,int base){
    clock_t begin,end;//relacionado ao cronometro
    double time_spent=0.0;//relacionado ao cronometro
    int i,j,cont=0,vaium=0,*sf=(int*)malloc(sizeof(int)*(t1*t2));
    begin =clock();//inicio do cronometro
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
    end =clock();//fim do cronometro
    printf("\nString Final: ");
    if(vaium!=0)
        printf("%d ",vaium);
    for(i=0;i<cont;i++)
        printf("%d ",sf[i]);
    //exibe cronometro
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n\nTime elpased is %lf seconds\n", time_spent);
	free(sf);
}

void * somaVet(char *s1, char *s2, int t1, int t2,int base){
    clock_t begin,end;//relacionado ao cronometro
    double time_spent=0.0;//relacionado ao cronometro
    int i,vaium=0,*sf=(int*)malloc(sizeof(int)*t1);
    begin =clock();//inicio do cronometro
    for(i=0;i<t1;i++)//insere o maior vetor no final
        sf[i]=(s1[i]-48);
    for(i=0;i<t1;i++)//soma do vetor menor com o vetor final
        sf[i+(t1-t2)]=sf[i+(t1-t2)]+(s2[i]-48);
    printf("\nString combinada: ");
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
    end =clock();//fim do cronometro
    printf("\nString Final: ");
    if(vaium!=0)
        printf("%d ",vaium);
    for(i=0;i<t1;i++)
        printf("%d ",sf[i]);
    //exibe cronometro
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n\nTime elpased is %lf seconds\n", time_spent);
	free(sf);
}

int main(){
    while(1){
        fflush(stdin);
        int tipo,base,t1,t2,i;
        printf("\nDigite 1-Soma ou 2-Multiplicacao: ");
        scanf(" %d",&tipo);
        printf("Digite a Base: ");
        scanf(" %d",&base);
        printf("Tamanho da string 1: ");
        scanf(" %d",&t1);
        printf("Tamanho da string 2: ");
        scanf(" %d",&t2);
        char *s1=(char*)malloc(sizeof(char)*t1),
            *s2=(char*)malloc(sizeof(char)*t2);
        printf("\nString 1: ");
        for(i=0;i<t1;i++){
            s1[i]=(rand()%base)+48;
            printf("%c ",s1[i]);
        }
        printf("\nString 2: ");
        for(i=0;i<t2;i++){
            s2[i]=(rand()%base)+48;
            printf("%c ",s2[i]);
        }
        printf("\n");
        if(tipo==1){
             if(t1>=t2)
                somaVet(s1,s2,t1,t2,base);
            else
                somaVet(s2,s1,t2,t1,base);

        } else {
            if(t1>=t2)
                multVet(s1,s2,t1,t2,base);
            else
                multVet(s2,s1,t2,t1,base);
        }
        free(s1);
        free(s2);
        printf("\nNovamente? (s/n): ");
        char c;
        scanf(" %c",&c);
        if(c!='s')
            return 0;
    }
    return 0;
}
