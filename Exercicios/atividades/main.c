#include <stdio.h>

void divisores(){
    int n,i;
    while(1){
        printf("Digite o valor: ");
        scanf("%d",&n);
        if(n<=1)
            break;
        for(i=1;i<=n;i++)
            if(n%i==0)
                printf("%d\n",i);
    }
}

void fibonascci(){
    int n,ant=1,antant=1,cont=2,atual;
    while(1){
        printf("Digite o valor de fibonascci: ");
        scanf("%d",&n);
        if(n<=0)
            break;
        if((n==0)||(n==1)){
            printf("1\n");
            continue;
        }
        while(cont<=n){
            atual=ant+antant;
            antant=ant;
            ant=atual;
            cont++;
        }
        printf("%d\n",atual);
        ant=1,antant=1,cont=2;
    }
}

void mdc(){
    int x,y,i,menor,maior,div;
    while(1){
        printf("Digite dois numeros: ");
        scanf("%d %d",&x,&y);
        if(x<=0 && y<=0)
            break;
        if(x>y){
            maior=x;
            menor=y;
        } else {
            maior=y;
            menor=x;
        }
        for(i=1;i<menor;i++)
            if(x%i==0 && y%i==0)
                div=i;
        printf("%d\n",div);
    }
}

void sec_cre(){
    int x,ant=0,seq=0,maior=0;
    while(1){
        printf("Digite um inteiro positivo: ");
        scanf("%d",&x);
        if(x<=0)
            break;
        if(x>ant)
            seq++;
        else
            seq = 1;
        if(seq>=maior)
            maior=seq;
        ant=x;
    }
    printf("Esta e a maior sequencia: %d\n",maior);
}
void sec_dec(){
    int n,cont=0,contfinal=0,ant,i,x;
    while(1){
        printf("Digite o Tamanho: ");
        scanf("%d",&n);
        if(n<=0)
            break;
        for(i=0;i<n;i++){
            scanf("%d",&x);
            if(ant>x)
                cont++;
            else
                cont = 1;
            if(cont>contfinal)
                contfinal=cont;
            ant=x;
        }
        printf("Tamanho: %d\n",contfinal);
        cont=contfinal=0;
    }
}

int main(){
    int i;
    printf("Digite o valor do menu: \n");
    printf("1 - Para execicio: \n");
    printf("2 - Para execicio: \n");
    printf("3 - Para execicio: \n");
    printf("4 - Para execicio: \n");
    scanf("%d",&i);
    switch(i){
        case 1:
            sec_cre();
            break;
        case 2:
            sec_dec();
            break;
        case 3:
            mdc();
            break;
        case 4:
            fibonascci();
            break;
        case 5:
            divisores();
            break;
        default:
            break;
    }
    return 0;
}
