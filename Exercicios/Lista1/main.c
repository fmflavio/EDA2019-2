#include <stdio.h>

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

            break;
        case 4:

            break;
        case 5:

            break;
        default:
            break;
    }
    return 0;
}
