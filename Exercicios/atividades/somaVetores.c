#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char vet1[]="241987258",vet2[]="14977701863";
    int i,t1=strlen(vet1),t2=strlen(vet2),tmaior,tmenor;
    if(t1>=t2){
        tmaior=t1;
        tmenor=t2;

    } else {
        tmaior=t2;
        tmenor=t1;
    }
    int vet3[tmaior];
    if(t1>=t2){
        for(i=0;i<tmaior;i++)
            vet3[i]=vet1[i]-48;
        for(i=0;i<(tmaior-tmenor);i++)
            vet3[i+(tmaior-tmenor)]=vet2[i]+vet3[i+(tmaior-tmenor)]-48;
    } else {
        for(i=0;i<tmaior;i++)
            vet3[i]=vet2[i]-48;
        for(i=0;i<tmaior;i++)
            vet3[i+(tmaior-tmenor)]=vet1[i]+vet3[i+(tmaior-tmenor)]-48;
    }
    printf("\nVetor 1 = ");
    for(i=0;i<t1;i++)
        printf("%d ",vet1[i]-48);
    printf("\nVetor 2 = ");
    for(i=0;i<t2;i++)
        printf("%d ",vet2[i]-48);
    printf("\nVetor 3 = ");
    for(i=0;i<tmaior;i++)
        printf("%d ",vet3[i]);

    for(i=tmaior;i>=0;i--){
        if(vet3[i]>9){
            vet3[i]=vet3[i]-9;
            vet3[i-1]++;
        }
    }
    printf("\nVetor 3 = ");
    for(i=0;i<tmaior;i++)
        printf("%d ",vet3[i]);
    return 0;
}
