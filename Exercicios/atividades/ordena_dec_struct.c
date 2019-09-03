#include <stdio.h>
#include <stdlib.h>

typedef struct fig{
    float area;
    int cod;
}Tfig;

void ordena(Tfig *vet, int n){
    int i;
    for(i=0;i<n;i++){
        int prim=i,j;
        for(j=i+1;j<n;j++)
        if((vet[j].area>vet[prim].area) ||
           (vet[j].area==vet[prim].area) &&
           (vet[j].cod<vet[prim].cod))
            prim=j;
        if(prim!=i){
            Tfig t;
            t.cod=vet[i].cod;
            t.area=vet[i].area;
            vet[i].cod=vet[prim].cod;
            vet[i].area=vet[prim].area;
            vet[prim].area=t.area;
            vet[prim].cod=t.cod;
        }
    }
}

int main(){
    int i,n=5;
    Tfig *vet=(Tfig*)malloc(sizeof(Tfig)*n);
    for(i=0;i<n;i++){
        vet[i].cod=i;
        printf("\nDigite o tamanho da area: ");
        scanf("%f",&vet[i].area);
    }
    ordena(vet,n);
    for(i=0;i<n;i++){
        printf("\nCod: %d",vet[i].cod);
        printf("\nArea: %.1f",vet[i].area);
    }
    return 0;
}
