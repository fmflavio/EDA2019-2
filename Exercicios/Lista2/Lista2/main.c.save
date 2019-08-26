#include <stdio.h>

int mdc(int x, int y){
    int i,menor,maior,div;
    if(x<=0 && y<=0)
        return -1;
    if(x>y)
        maior=x;
    else
        maior=y;
    for(i=1;i<maior;i++)
        if(x%i==0 && y%i==0)
            div=i;
    return div;
}

void figurinhas(){
    int n,f1,f2,i;
    printf("\nDigite o tamanho da sequencia: ");
    scanf("%d",&n);
    if(n<1 || n>3000)
        return;
    for(i=0;i<n;i++){
        printf("\nDigite F1: ");
        scanf("%d",&f1);
        if(f1<1 || f1>1000)
            return;
        printf("\nDigite F2: ");
        scanf("%d",&f2);
        if(f2<1 || f2>1000)
            return;
        printf("%d\n",mdc(f1,f2));
    }
}

int tempo(int H1, int M1, int H2, int M2){
    if(H2>H1)
        return ((H2*60)+M2)-((H1*60)+M1);
    if(H2==H1 && M1<M2)
        return ((H2*60)+M2)-((H1*60)+M1);
    if(H2<H1)
        return ((H2*60)+M2)-((H1*60)+M1)+(24*60);
    if(H2==H1 && M1>M2)
        return ((H2*60)+M2)-((H1*60)+M1)+(24*60);
}
void tempoSono(){
    int H1, M1, H2, M2;
    while(1){
        scanf("%d %d %d %d",&H1,&M1,&H2,&M2);
        if(H1==0, M1==0, H2==0, M2==0)
            break;
        printf("%d\n",tempo(H1, M1, H2, M2));
    }
}

int isPrimo(int val){
    int i,cont=0;
    for(i=1;i<=val;i++)
        if(val%i==0)
            cont++;
    if(cont==2)
        return 1;
    else
        return 0;
}
void sec_pos_primos(){
    int n,i,cont;
    while(1){
        printf("\nDigite o tamanho da sequencia de pos primos: ");
        scanf("%d",&n);
        if(n<=0)
            break;
        i=n+1;
        cont=0;
        while(cont<n){
            if(isPrimo(i)){
               printf("%d ",i);
               cont++;
            }
            i++;
        }
    }
}
void sec_primos(){
    int n,i;
    while(1){
        printf("\nDigite o tamanho da sequencia de primos: ");
        scanf("%d",&n);
        if(n<=0)
            break;
        for(i=1;i<=n;i++){
            if(i==1 || isPrimo(i))
               printf("%d ",i);
        }
    }
}

int main(){
    int i;
    printf("Digite o valor do menu: \n");
    printf("1 - Para execicio 1 \n");
    printf("2 - Para execicio 2 \n");
    printf("3 - Para execicio 3 \n");
    printf("4 - Para execicio 4 \n");
    printf("Outro valor para sair \n");
    printf("---> ");
    scanf("%d",&i);
    switch(i){
        case 1:
            sec_primos();
            break;
        case 2:
            sec_pos_primos();
            break;
        case 3:
            tempoSono();
            break;
        case 4:
            figurinhas();
            break;
        default:
            break;
    }
    return 0;
}
