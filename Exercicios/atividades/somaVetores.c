#include <stdio.h>
#include <string.h>

int main(){
    char vet1[]="241987258",vet2[]="14977701863";
    int i,t1=strlen(vet1),t2=strlen(vet2),tm,cont=0;
    if(t1>=t2){
        tm=t1;
        cont=tm-t2;
    } else {
        tm=t2;
        cont=tm-t1;
    }
    int vet3[tm];
    printf("\nVetor 1 = ");
    for(i=0;i<t1;i++)
        printf("%c ",vet1[i]);
    printf("\nVetor 2 = ");
    for(i=0;i<t2;i++)
        printf("%c ",vet2[i]);
    i=tm;
    while(i>=0){
        if(t1>=t2){

        } else {

        }
        vet3[i]=(vet1[i]-48)+(vet2[i]-48);
        i--;
    }
    /*
    for(i=tm;i>=0;i--){
        if(i)
            vet3[i]=0+(vet2[i]-48);
        else
            if(tm-t2>=0)
                vet3[i]=(vet1[i]-48)+0;
            else
                vet3[i]=(vet1[i]-48)+(vet2[i]-48);
    }
    */
    printf("\nVetor 3 = ");
    for(i=0;i<tm;i++)
        printf("%d ",vet3[i]);
    return 0;
}
