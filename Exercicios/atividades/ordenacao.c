#include <stdio.h>

void * quicksort(int *vet,int n){
    if(n<=1)
        return -1;
    int pivo=vet[0],a=1,b=n-1;
    do{
        while((a<n)&&(vet[a]<=pivo))
            a++;
        while(vet[b]>pivo)
            b--;
        if(a<=b){
            int temp=vet[a];
            vet[a]=vet[b];
            vet[b]=temp;
        }
    }while(a<=b);
    vet[0]=vet[b];
    vet[b]=pivo;
    quicksort(vet,b);
    quicksort(&vet[b-1],n-b-1);
}

int * selectionsort(int *vet,int n){
    int i,j,menor,temp;
    for(i=0;i<n;i++){
        menor=i;
        for(j=i+1;j<n;j++)
            if(vet[j]<vet[menor])
                menor=j;
        if(vet[i]!=vet[menor]){
            temp=vet[i];
            vet[i]=vet[menor];
            vet[menor]=temp;
        }
    }
    return vet;
}

int main(){
    int i,n=3,*vet=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        scanf(" %d",&vet[i]);
    //vet = selectionsort(vet,n);
    quicksort(vet,n);
    for(i=0;i<n;i++)
        printf("%d ",vet[i]);
}
