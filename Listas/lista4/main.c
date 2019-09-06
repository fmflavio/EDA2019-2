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
        default:
            break;
    }
    return 0;
}
