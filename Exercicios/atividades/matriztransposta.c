//dada uma matriz qualquer,retorne uma matriz transposta

#include <stdio.h>

int **transposta(int **mat, int l, int c){
    if(l<=0||c<=0)
        exit(1);
    int i,j,**resp=(int**)malloc(sizeof(int*)*c);
    for(i=0;i<l;i++)
        resp[i]=(int*)malloc(sizeof(int)*l);
    for(i=0;i<l;i++)
        for(j=0;j<l;j++)
            resp[j][i]=mat[i][j];
    return resp;
}

int main(){
    int i,j,l=3,c=3,cont=0;
    int **mat=(int**)malloc(sizeof(int*)*l);
    for(i=0;i<l;i++)
        mat[i]=(int*)malloc(sizeof(int)*c);
    for(i=0;i<l;i++)
        for(j=0;j<l;j++)
            mat[i][j]=cont++;
    for(i=0;i<l;i++){
        for(j=0;j<l;j++)
            printf("%d ",mat[i][j]);
        printf("\n");
    }
    printf("\n");
    mat=transposta(mat,l,c);
    for(i=0;i<l;i++){
        for(j=0;j<l;j++)
            printf("%d ",mat[i][j]);
        printf("\n");
    }
    for(i=0;i<l;i++)
        free(mat[i]);
    free(mat);
}
