#include <stdio.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int * ordena(int *vet, int n){
    int i,*resp = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        resp[i]=vet[i];
    qsort(resp,n,sizeof(int),cmpfunc);
    return resp;
}

int main(){
    int i,n,*vet;
    scanf("%d",&n);
    vet=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        scanf("%d",&vet[i]);
    int *resp = ordena(vet,n);
    for(i=0;i<n;i++)
        printf("%d ",resp[i]);
    free(vet);
}
