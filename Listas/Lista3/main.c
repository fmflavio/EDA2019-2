#include <stdio.h>
#define N 9

int ** construir_hadamard( int ** matriz, int ordem){
    int ii, xx, yy;
    matriz[0][0]=1;
    for(ii=2; ii<=ordem; ii*=2){
        for(xx=0; xx<(ii/2); ++xx)
            for(yy=(ii/2); yy<ii; ++yy)
                matriz[xx][yy]=matriz[xx][yy-(ii/2)];
        for(yy=0; yy<(ii/2); ++yy)
            for(xx=(ii/2); xx<ii; ++xx)
                matriz[xx][yy]=matriz[xx-(ii/2)][yy];
        for(xx=(ii/2); xx<ii; ++xx)
            for(yy=(ii/2); yy<ii; ++yy){
                matriz[xx][yy]=matriz[xx-(ii/2)][yy-(ii/2)];
                if(matriz[xx][yy]==1)
                    matriz[xx][yy]=0;
                else
                    matriz[xx][yy]=1;
            }
    }
	return matriz;
}
void Q13(){
    printf("Digite a ordem da matriz de Hadamard: ");
	int n,i,j;
	scanf(" %d", &n);
	int ** matriz = (int**)malloc(sizeof(int*)*n);
	for (i = 0; i < n; i++)
		matriz[i] = (int*)malloc(sizeof(int)*n);
	int **matriz_hadamard = construir_hadamard(matriz, n);
	for( i = 0; i < n; i++){
		for( j = 0; j < n; j++)
			printf("%d", matriz[i][j]);
		printf("\n");
	}
	for (i = 0; i < n; i++)
		free(matriz[i]);
	free(matriz);
}

int contPalavras(char *str){
    int i,cont=0, tam=strlen(str)-1;
    for(i=0;i<tam;i++)
        if(str[i]=='/')
            cont++;
    if(str[0])
        cont--;
    if(str[tam])
        cont--;
    return ++cont;
}
char** s2ss(char *str){
    int palavras=contPalavras(str),i=0,j=0,k=0,p;
    char **resposta=(char**)malloc(sizeof(char*)*palavras);
    while(str[i]!='\0'){
        // achou uma barra
        if(str[i]=='/'){
            // acha a próxima barra
            for(j=i+1;str[j]!= '/' && str[j]!='\0';j++)
                resposta[k]=(char*)malloc(sizeof(char)*(j-i));
            int temp=0;
            for(p=i+1;p<j;p++){
                resposta[k][temp]=str[p];
                temp++;
            }
            k++;
        }
        i++;
    }
    return resposta;
}
void Q12(){
    char *stringOriginal="/Fla/Flu/Bota/",**stringResultante;
    printf("\nString Original: %s\n",stringOriginal);
    stringResultante=s2ss(stringOriginal);
    for(int i = 0; i < 3; i++){
        for(int j = 0; stringResultante[i][j] != '\0'; j++)
            printf("%c",stringResultante[i][j]);
        printf("\n");
    }
}

void imprimeMatriz(int **matriz, int taml, int tamc){
    int linha,coluna;
    for(linha=0;linha<taml;linha++){
        for(coluna=0;coluna<tamc;coluna++)
            printf("%d ",matriz[linha][coluna]);
        printf("\n");
    }
    printf("\n");
}
int** alocaMatriz(int **matriz, int taml, int tamc){
    int linha;
    matriz=(int**)malloc(sizeof(int*)*taml);
    for(linha=0;linha<taml;linha++)
        matriz[linha]=(int*)malloc(sizeof(int)*tamc);
    return matriz;
}
int** mult(int m1, int n1, int **mat1, int m2, int n2, int **mat2){
    int linha, coluna,**matProduto,somaprod,i;
    matProduto=alocaMatriz(matProduto,m1,n2);
    for(linha=0;linha<m1;linha++)
        for(coluna=0;coluna<m1;coluna++){
            somaprod=0;
            for(i=0; i<m1; i++)
                somaprod+=mat1[linha][i]*mat2[i][coluna];
            matProduto[linha][coluna]=somaprod;
        }
    return matProduto;
}
void Q11(){
    int m1=3,n1=3,**mat1,m2=3,n2=3,**mat2,linha,coluna,**matProduto;
    //só é possivel realizar a multiplicação de matrizes se a quantidade de coluna da primeira for igual quantidade de linhas da segunda
    if(n1!=m2){
        printf("\nNao e possivel realizar a multiplicacao de matrizes\n");
        return 0;
    }
    mat1=alocaMatriz(mat1,m1,n1);
    for(linha=0;linha<m1;linha++)
        for(coluna=0;coluna<m1;coluna++)
            mat1[linha][coluna]=linha+coluna;
    mat2=alocaMatriz(mat2,m2,n2);
    for(linha=0;linha<m2;linha++)
        for(coluna=0;coluna<m2;coluna++)
            mat2[linha][coluna]=(linha+1)*(coluna+1);
    imprimeMatriz(mat1,m1,n1);
    imprimeMatriz(mat2,m2,n2);
    printf("\nA nova Matriz e:\n");
    matProduto=alocaMatriz(matProduto,m1,n2);
    matProduto=mult(m1,n1,mat1,m2,n2,mat2);
    imprimeMatriz(matProduto,m1,n2);
}

int isSoduku(int matriz[N][N]){
    int linha,coluna,contador=0,tamanho=N;
     printf("\n");
    for(linha = 0; linha < tamanho; linha++){
        for(coluna = 0; coluna < tamanho; coluna++)
            if(matriz[linha][linha]==matriz[linha][coluna])
                 contador++;
        if(contador>1)
            return 0;
        else
            contador=0;
    }
    return 1;
}
void Q10(){
    int tamanho=N, linha,coluna;
    int matriz[N][N] = {{5, 3, 4, 6, 7, 8, 9, 1, 2},
                       {6, 7, 2, 1, 9, 5, 3, 4, 8},
                       {1, 9, 8, 3, 4, 2, 5, 6, 7},
                       {8, 5, 9, 7, 6, 1, 4, 2, 3},
                       {4, 2, 6, 8, 5, 3, 7, 9, 1},
                       {7, 1, 3, 9, 2, 4, 8, 5, 6},
                       {9, 6, 1, 5, 3, 7, 2, 8, 4},
                       {2, 8, 7, 4, 1, 9, 6, 3, 5},
                       {3, 4, 5, 2, 8, 6, 1, 7, 9}};
    for(int linha = 0; linha < tamanho; linha++){
        for(int coluna = 0; coluna < tamanho; coluna++)
             printf("%2d", matriz[linha][coluna]);
        printf("\n");
    }
    if(isSoduku(matriz)==1)
        printf("\nE Soduku!");
    else
        printf("\nNao e Soduku!");
}

int igual(char *str1, char *str2){
    int i;
    for(i=0;i<strlen(str1)-1;i++)
        if(str1[i]>=65 && str1[i]<=90)//maiusculas
            str1[i]=str1[i]+32;
    for(i=0;i<strlen(str2)-1;i++)
        if(str2[i]>=65 && str2[i]<=90)//maiusculas
            str2[i]=str2[i]+32;
    if(strcmp(str1,str2)==0)
        return 1;
    return 0;
}
int Q09(){
    char stringA[]={'F','l','a','v','i','o'};
    char stringB[]={'F','l','A','v','i','o'};
    if(igual(stringA,stringB))
        printf("\nUM\n");
    else
        printf("\nZERO\n");
}

int cic(char *str1, char *str2){
    int i,j,tamanho1=strlen(str1)-1,tamanho2=strlen(str2)-1;
    char *aux;
    if(tamanho1<tamanho2)
        return 0;
    for(i=0;i<tamanho1;i++)
        if(str1[i]>=65 && str1[i]<=90)//maiusculas
            str1[i]=str1[i]+32;
    for(i=0;i<tamanho2;i++)
        if(str2[i]>=65 && str2[i]<=90)//maiusculas
            str2[i]=str2[i]+32;
    if(strcmp(str1,str2)==0)
        return 1;
     for(j=0;j<tamanho2;j++)
        for(i=0;i<tamanho1;i++)
            if(str2[j]==str1[i]){
                aux=&str1[i];
                if(strncmp(aux,str2,tamanho2)==0)
                    return 1;
                break;
            }
    return 0;
}
void Q08(){
    char stringA[]={'F','l','a','v','i','o'};
    char stringB[]={'l','A','v','i'};
    if(cic(stringA,stringB))
        printf("\nUM\n");
    else
        printf("\nZERO\n");
}

int Q07(){
    char stringA[]={"ACCTGAACTCCCCCC"};
    char stringB[]={"ACCTAGGACCCCCC"};
    int i,j,tamanhoA=strlen(stringA)-1,tamanhoB=strlen(stringB)-1,tamanhoSub=0,contador=0;
    char stringC[tamanhoA],stringD[tamanhoA];
    for(i=0;i<tamanhoA;i++)
        for(j=0;j<tamanhoB;j++)
            if(stringA[i]==stringB[j]){
                stringC[i]=stringA[i];
                if(stringA[i+1]!=stringB[j+1]||stringA[i+1]=='\0')
                    if(strlen(stringC)>=strlen(stringD)){
                        strcpy(stringD,stringC);
                        stringC[0]='\0';
                        printf("\n%s\n",stringD);
                    }
                break;
            }
    printf("\nMaior string: %s\n",stringD);
    return 0;
}

int Q06(){
    char string[]={'F','l','@','v','1','0','M','F'};
    int i,a=0,b=0,c=0,d=0,tamanho=strlen(string)-1;
    if(tamanho>8)//tamanho
        for(i=0;i<tamanho;i++){
            if(string[i]>=48 && string[i]<=57)//numero
                a++;
            if(string[i]>=65 && string[i]<=90)//maiusculas
                b++;
            if(string[i]>=97 && string[i]<=122)//minusculas
                c++;
            if((string[i]>=32 && string[i]<=47)||
               (string[i]>=58 && string[i]<=67)||
               (string[i]>=91 && string[i]<=96)||
               (string[i]>=123 && string[i]<=126))//fora letra e numero
                d++;
        }
    if(a>0&&b>0&&c>0&&d>0)
        printf("\nboa\n");
    return 0;
}

void retira_fim_n(char *str, int n){
    int i, tamanho=strlen(str);
    if(n>tamanho){
        printf("\nerro\n");
        exit(1);
    }
    char *vetor=(char*)malloc(sizeof(char)*tamanho-n);
    if(!vetor)
        exit(1);
    for(i=0;i<tamanho-n;i++)
        vetor[i]=str[i];
    printf("\nEsta e a saida: %s\n",vetor);
}
int Q05(){
    int n=3;
    char s[]={'a','b','c','d','e','f','g','h','i'};
    retira_fim_n(s,n);
    return 0;
}

void retira_inicio_n(char *str, int n){
    int i, tamanho=strlen(str);
    if(n>tamanho){
        printf("\nerro\n");
        exit(1);
    }
    char *vetor=(char*)malloc(sizeof(char)*tamanho-n);
    if(!vetor)
        exit(1);
    for(i=n;i<tamanho;i++)
        vetor[i-n]=str[i];
    printf("\nEsta e a saida: %s\n",vetor);
}
int Q04(){
    int n=3;
    char s[]={'a','b','c','d','e','f','g','h','i'};
    retira_inicio_n(s,n);
    return 0;
}

int* transf_i_pA(int *vet, int n){
    int i,contador=0;
    int *vetor = (int*)malloc(sizeof(int)*n);
    if(!vetor)
        exit(1);
    for(i=0;i<n;i++)
        if (vet[i]%2 == 0){
            vetor[contador]=vet[i];
            contador++;
        }
    for(i=0;i<n;i++)
        if (vet[i]%2 == 1){
            vetor[contador]=vet[i];
            contador++;
        }
    return vetor;
}
void transf_i_pB(int *vet, int n){
    int i,contador=0;
    int *vetor = (int*)malloc(sizeof(int)*n);
    if(!vetor)
        exit(1);
    for(i=0;i<n;i++)
        if (vet[i]%2 == 0){
            vetor[contador]=vet[i];
            contador++;
        }
    for(i=0;i<n;i++)
        if (vet[i]%2 == 1){
            vetor[contador]=vet[i];
            contador++;
        }
    printf("\nEsta e a saida da funcao B: ");
    for(i=0;i<n;i++)
        printf("%d ",vetor[i]);
}
int Q03(){
    int tamanho=10,i;
    int vetor[] = {0,1,2,3,4,5,6,7,8,9};
    printf("\nEsta e a saida da entrada Original: ");
    for(i=0;i<tamanho;i++)
        printf("%d ",vetor[i]);
    printf("\n");
    int *vet = (int*)malloc(sizeof(int)*tamanho);
    if(!vet)
        exit(1);
    vet=transf_i_pA(vetor,tamanho);
    printf("\nEsta e a saida da funcao A: ");
    for(i=0;i<tamanho;i++)
        printf("%d ",vet[i]);
    printf("\n");
    transf_i_pB(vetor,tamanho);
    printf("\n");
    return 0;
}

char * codifica(char *str){
    int i,tamanho = strlen(str);
    char* string = (char *)malloc(sizeof(char)*tamanho);
    if(!string)
        exit(1);
    strcpy(string,str);
    for(i=0;i<tamanho;i++)
        if(string[i]>=97 && string[i]<=122)
                string[i]='?';
    return string;
}
int Q02(){
    char str[10];
    printf("\nDigite uma palavra a ser mudada\n---> ");
    scanf(" %s",&str);
    printf("\nAnterior: %s e Nova: %s\n",str,codifica(str));
    return 0;
}

void shift_troca_string (char *str){
    int i,tamanho = strlen(str);
    for(i=0;i<tamanho;i++)
        if(str[i]>=65 && str[i]<=90)//maiusculas
            if(str[i]!=65)
                str[i]=str[i]+33;
            else
                str[i]=str[i]+57;
        else
            if(str[i]>=97 && str[i]<=122)//minusculas
                if(str[i]!=97)
                    str[i]=str[i]-33;
                else
                    str[i]=str[i]-7;
            else
                str[i]='!';
    printf("\nNova String: %s\n",str);
}
int Q01(){
    char str[10];
    printf("\nDigite uma palavra a ser mudada\n---> ");
    scanf(" %s",&str);
    shift_troca_string(str);
    return 0;
}

int main(){
    int i;
    printf("Digite o valor do menu: \n");
    printf("1 - Para execicio 1 \n");
    printf("2 - Para execicio 2 \n");
    printf("3 - Para execicio 3 \n");
    printf("4 - Para execicio 4 \n");
    printf("5 - Para execicio 5 \n");
    printf("6 - Para execicio 6 \n");
    printf("8 - Para execicio 7 \n");
    printf("9 - Para execicio 8 \n");
    printf("10 - Para execicio 9 \n");
    printf("11 - Para execicio 10 \n");
    printf("11 - Para execicio 11 \n");
    printf("12 - Para execicio 12 \n");
    printf("13 - Para execicio 13 \n");
    printf("14 - Para execicio 14 \n");
    printf("Outro valor para sair \n");
    printf("---> ");
    scanf("%d",&i);
    switch(i){
        case 1:
            Q01();
            break;
        case 2:
            Q02();
            break;
        case 3:
            Q03();
            break;
        case 4:
            Q04();
            break;
        case 5:
            Q05();
            break;
        case 6:
            Q06();
            break;
        case 7:
            Q07();
            break;
        case 8:
            Q08();
            break;
        case 9:
            Q09();
            break;
        case 10:
            Q10();
            break;
        case 11:
            Q11();
            break;
        case 12:
            Q12();
            break;
        case 13:
            Q13();
            break;
        default:
            break;
    }
    return 0;
}
