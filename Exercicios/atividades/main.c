#include <stdio.h>

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
    mdc();
    //sec_dec();
    //sec_cre();
    return 0;
}
