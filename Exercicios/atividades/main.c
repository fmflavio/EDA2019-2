#include <stdio.h>

int **geraMat(int l,int c,int val1,int val2,int base){
    int i,j;
    //alocação dinamica
    int **mat=(int**)malloc(sizeof(int*)*l);
    for(i=0;i<l;i++)
        mat[i]=(int*)malloc(sizeof(int)*c);
    //gera matriz
    for(i=0;i<l;i++)
        for(j=0;j<c;j++){
            if(i==0 && j==0)
                mat[i][j]=(val1/base)*base;
            else
                if(i==0 && j==1)
                    mat[i][j]=val1%base;
                else
                    if(i==1 && j==0)
                        mat[i][j]=(val2/base)*base;
                    else
                        if(i==1 && j==1)
                            mat[i][j]=val2%base;
            //imprime a primeira matriz
            printf("%d ",mat[i][j]);
        }
    printf("\n");
    return mat;
}
void **multMat(int **mat,int l,int c){
    int i,j,resp[l][c],total=0;
    for(i=0;i<l;i++)
        for(j=0;j<c;j++){
            //multiplica os valores da matriz
            // original geranto a seundária
            resp[i][j]=mat[0][i]*mat[1][j];
            printf("%d ",resp[i][j]);
            //após exibir a matriz secundaria
            //soma os valores em um inteiro
            total+=resp[i][j];
        }
    printf("\n%d ",total);
    return resp;
}
void multiplicacao(){
    //multiplicação usando matrizes
    int i,j,l=2,c=2,base=10,
        val1=34,val2=13;//valores
    int **mat=geraMat(l,c,val1,val2,base);
    multMat(mat,l,c);
}

void selectionSort(int *vet,int n){
    int i,j,menor,aux;
    for(i=0;i<n-1;i++){
        menor=i;
        for(j=i+1;j<n;j++)
            if(vet[menor]>vet[j])
                menor=j;
        if(menor!=i){
            aux=vet[menor];
            vet[menor]=vet[i];
            vet[i]=aux;
        }
    }
}
void ordena(){
    int i,n=10,vet[]={9,0,1,3,2,5,4,8,6,7};
    selectionSort(vet,n);
    for(i=0;i<n;i++)
        printf("%d ",vet[i]);
}

int fibo3(int n){
    if(n<=1)
        return 1;
    else
        return fibo3(n-1)+fibo3(n-2);
}

int fibo2(int n){
    int a=1,b=2,c,i;
    for(i=3;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}

void fibo(){
    int n;
    printf("Digite o n fibonascci: ");
    scanf("%d",&n);
    if(n<=0)
        return;
    printf("\n%d",fibo2(n));
}

int fatorial2(int n){
    if(n<=1)
        return 1;
    else
        return n*fatorial2(n-1);
}
void fatorial(){
    int n;
    printf("Digite o n fatorial: ");
    scanf("%d",&n);
    if(n<=0)
        return;
    printf("\n%d",fatorial2(n));
}

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
int mdc2(int x, int y){
    if (y==0) //if(x%y==0)
        return x; //return y
    else
        return mdc(y,x % y);
}
void mdc(){
    int x,y,i,menor,div;
    while(1){
        printf("Digite dois numeros: ");
        scanf("%d %d",&x,&y);
        if(x<=0 && y<=0)
            break;
        if(x>y)
            menor=y;
        else
            menor=x;
        for(i=1;i<menor;i++)
            if(x%i==0 && y%i==0)
                div=i;
        printf("%d\n",div);
    }
}

void sec_dec(){
    int n,cont=0,contfinal=0,ant=0,i,x;
    while(1){
        printf("Digite o Tamanho: ");
        scanf("%d",&n);
        if(n<=0)
            break;
        for(i=0;i<n;i++){
            printf("Digite valor %d: ",i+1);
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

int main(){
    int i;
    printf("Digite o valor do menu: \n");
    printf("1 - Para execicio: \n");
    printf("2 - Para execicio: \n");
    printf("3 - Para execicio: \n");
    printf("4 - Para execicio: \n");
    printf("5 - Para execicio: \n");
    printf("6 - Para execicio: \n");
    printf("7 - Para execicio: \n");
    printf("8 - Para execicio: \n");
    printf("9 - Para execicio: \n");
    printf("--> ");
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
        case 6:
            fatorial();
            break;
        case 7:
            fibo();
            break;
        case 8:
            ordena();
            break;
        case 9:
            multiplicacao();
            break;
        default:
            break;
    }
    return 0;
}
