#include <stdio.h>

int Q07(){
    while(1){
        int n,i,v,resp;
        scanf("\n%d",&n);
        if(n<=0 || n<2 || n>1000)
            break;
        int vet[n];
        for(i=0;i<n;i++){
            scanf("%d",&vet[n]);
        }

        printf("%d\n",resp);
    }
}

int Q06(){
    while(1){
        int n,m,i,j,cont=0,contf=0;
        printf("\nDigite N e M: ");
        scanf("%d %d",&n, &m);
        if(n>10000 || m>20000 || n<1 && m<1)
            break;
        int vet1[m],vet2[m],vet3[m];
        for(i=0;i<m;i++){
            printf("%Digite %d de %d: ",i,m);
            scanf("%d",&vet1[i]);
            //vet2[i]=vet1[i];
        }
        for(i=0;i<m;i++){
            for(j=0;j<m;j++){
                if(vet1[i]==vet1[j]){
                    vet2[i]=vet1[i];

                }
            }
        }

        /*
        for(i=0;i<m;i++){
            for(j=0;j<m;j++){
                if(vet1[i]==vet2[j]){
                    vet2[j]=-1;
                    cont++;
                }
            }
            if(cont>1)
                contf++;
            cont=0;
        }
        */
        printf("%d\n",contf);
    }
}

int Q05(){
    while(1){
        int n,i=0,j;
        printf("\n\nDigite um numero inteiro e positivo para n\n---> ");
        scanf(" %d",&n);
        if(n<0)
            return 0;
        int vet[n];
        printf("\nEstes e o equivalente binario pra %d: ",n);
        if(n==0 || n==1)
            printf("%d ",n);
        else{
            do{
                vet[i]=n%2;
                i++;
                n=n/2;
            }while(n>=1);
            for(j=i-1;j>=0;j--)
                printf("%d",vet[j]);
        }
    }
    return 0;
}

int Q04(){
    while(1){
        char nome[10];
        int i,j,tamanho,cont=0;
        printf("\nDigite um valor para palindrome\n---> ");
        scanf(" %s",&nome);
        if(nome[0]=='-')
            return 0;
        tamanho=strlen(nome);
        for(i=0,j=tamanho-1;i<(tamanho/2)-1;i++,j--)
            if(nome[i]!=nome[j])
                cont++;
        if(cont>0)
            printf("\nFALSO\n");
        else
            printf("\nVERDADEIRO\n");
    }
    return 0;
}

int Q03(){
    char a[10],b[10],i,j;
    printf("\nDigite o valor de a\n---> ");
    scanf("%s",&a);
    printf("\nDigite o valor de b\n---> ");
    scanf("%s",&b);
    for(i=0;a[i]!='\0';i++)
        if(a[i]=='0')
            return 0;
    for(i=0;b[i]!='\0';i++)
        if(b[i]=='0')
            return 0;
    if(strlen(a)!=strlen(b))
        return 0;
    for(i=0;a[i]!='\0';i++)
        for(j=0;b[j]!='\0';j++)
            if(a[i]==b[j]){
                a[i]='x';
                b[j]='x';
                break;
            }
    if(strcmp(a,b)==0)
        printf("\nOs valores sao permutacoes\n");
    else
        printf("\nOs valores nao sao permutacoes\n");
    return 0;
}

int Q02(){
    int g,i;
    while(scanf(" %d",&g) && g>0){
        g++;
        double poli[g], derivada[g-1], integral[g+1];
        for(i=0;i<g;i++)
            scanf("%1f",poli+1);
        integral[0]=0;
        for(i=1;i<g+1;i++)
            integral[i]=poli[i-1]/i;
        for(i=0;i<g-1;i++)
            derivada[i]=poli[i+1]*(i+1);
        printf("\nIntegral:\n");
        for(i=0;i<g+1;i++)
            printf("%.1f ",integral[i]);
        printf("\nDerivada:\n");
        for(i=0;i<g-1;i++)
            printf("%.1f ",derivada[i]);
        printf("\n\n");
    }
    return 0;
}

int Q01(){
    int n,i,j,x,mult;
    printf("\nDigite o valor de n\n---> ");
    scanf(" %d",&n);
    if(n<=1)
        return 0;
    int vet[n];
    for(i=2;i<=n;i++)
        vet[i]=i;
    for(mult=2;mult<=5;mult++)
        for(j=mult;j<=n;j+=mult)
            if(vet[j]!=mult)
                vet[j]=0;
    for(x=2;x<=n;x++)
        if(vet[x]!=0)
            printf("%d ",vet[x]);
    printf("\n");
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
    printf("7 - Para execicio 7 \n");
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
        default:
            break;
    }
    return 0;
}
