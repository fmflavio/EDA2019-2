// C++ implementation of Karatsuba algorithm for bit string multiplication.
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;
int passos=0;

// FOLLOWING TWO FUNCTIONS ARE COPIED FROM http://goo.gl/q0OhZ
// Helper method: given two unequal sized bit strings, converts them to
// same length by adding leading 0s in the smaller string. Returns the
// the new length
int makeEqualLength(string &str1, string &str2){
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 < len2){
        for (int i = 0 ; i < len2 - len1 ; i++)
            str1 = '0' + str1;
        return len2;
    }
    else if (len1 > len2)    {
        for (int i = 0 ; i < len1 - len2 ; i++)
            str2 = '0' + str2;
    }
    return len1; // If len1 >= len2
}

// The main function that adds two bit sequences and returns the addition
string addBitStrings( string first, string second ){
    string result;  // To store the sum bits
    // make the lengths same before adding
    int length = makeEqualLength(first, second);
    int carry = 0;  // Initialize carry
    // Add all bits one by one
    for (int i = length-1 ; i >= 0 ; i--)    {
        int firstBit = first.at(i) - '0';
        int secondBit = second.at(i) - '0';
        // boolean expression for sum of 3 bits
        int sum = (firstBit ^ secondBit ^ carry)+'0';
        result = (char)sum + result;
        // boolean expression for 3-bit addition
        carry = (firstBit&secondBit) | (secondBit&carry) | (firstBit&carry);
    }
    // if overflow, then add a leading 1
    if (carry)  result = '1' + result;
    return result;
}

// A utility function to multiply single bits of strings a and b
int multiplyiSingleBit(string a, string b)
{  return (a[0] - '0')*(b[0] - '0');  }

// The main function that multiplies two bit strings X and Y and returns
// result as long integer
long int multiply(string X, string Y)
{
    // Find the maximum of lengths of x and Y and make length
    // of smaller string same as that of larger string
    int n = makeEqualLength(X, Y);

    // Base cases
    if (n == 0) return 0;
    if (n == 1) return multiplyiSingleBit(X, Y);

    int fh = n/2;   // First half of string, floor(n/2)
    int sh = (n-fh); // Second half of string, ceil(n/2)

    // Find the first half and second half of first string.
    // Refer http://goo.gl/lLmgn for substr method
    string Xl = X.substr(0, fh);
    string Xr = X.substr(fh, sh);

    // Find the first half and second half of second string
    string Yl = Y.substr(0, fh);
    string Yr = Y.substr(fh, sh);

    // Recursively calculate the three products of inputs of size n/2
    long int P1 = multiply(Xl, Yl);
    long int P2 = multiply(Xr, Yr);
    long int P3 = multiply(addBitStrings(Xl, Xr), addBitStrings(Yl, Yr));

    // Combine the three products to get the final result.
    return P1*(1<<(2*sh)) + (P3 - P1 - P2)*(1<<sh) + P2;
}

// Driver program to test above functions
int main(){
    printf("Trabalho de ASA 2019-2\nFlavio Miranda de Farias\n");
    while(1){
        clock_t begin,end;//relacionado ao cronometro
        double time_spent=0.0;//relacionado ao cronometro
        long si1=0,si2=0;
        fflush(stdin);
        int tipo,base,t1,t2,i;
        printf("\nDigite\n1-Soma(Proprio)\n2-Multiplicacao(Karatsuba)\n3-Multiplicacao(Proprio)\n4-teste:\n--> ");
        scanf(" %d",&tipo);
        printf("\nDigite a Base: ");
        scanf(" %d",&base);
        if(tipo!=3){
            printf("Tamanho da string 1: ");
            scanf(" %d",&t1);
            printf("Tamanho da string 2: ");
            scanf(" %d",&t2);
        } else
            t1=t2=2;
        char *s1=(char*)malloc(sizeof(char)*t1),
            *s2=(char*)malloc(sizeof(char)*t2);
        printf("\nString 1(char[]): ");
        for(i=0;i<t1;i++){
            s1[i]=(rand()%base)+48;
            printf("%c ",s1[i]);
        }
        printf("\nString 2(char[]): ");
        for(i=0;i<t2;i++){
            s2[i]=(rand()%base)+48;
            printf("%c ",s2[i]);
        }
        si1=atol(s1);
        si2=atol(s2);
        printf("\n");
        begin=clock();//inicio do cronometro
        switch(tipo){
            case 1:
                //if(t1>=t2)
                    //printf("\nResultado(long): %lu",somaVet(s1,s2,t1,t2,base));
                //else
                    //printf("\nResultado(long): %lu",somaVet(s2,s1,t2,t1,base));
            break;
            case 2:
                //printf("\nResultado(long): %lu",Karatsuba(si1,si2,base));
            break;
            case 3:
                //printf("\nResultado(long): %lu",multiplicacao(si1,si2,base));
            break;
            case 4:
                int c;
                //scanf("%d %d",&a,&b);
                char v1[100],v2[100],v3[100];
                itoa(si1,v1,base);
                itoa(si2,v2,base);
                //c=(int);
                //itoa(c,v3,10);
                printf("\nResultado(long): %ld",multiply(v1,v2));
            break;
            default:
            break;
        }
        end=clock();//fim do cronometro
        //exibe cronometro
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
        printf("\n\nTempo de execucao: %lf segundos", time_spent);
        printf("\nPara as strings com valor %d e %d, foram realizados %d passos\n",si1,si2,passos);
        passos=0;
        free(s1);
        free(s2);
        printf("\nNovamente? (s/n): ");
        char c;
        scanf(" %c",&c);
        system("cls");
        if(c!='s')
            return 0;
    }
    return 0;
    /*
    int i1=10,i2=9;
    char v1[100],v2[100];
    itoa(i1,v1,2);
    itoa(i2,v2,2);
    printf("%s %s\n",v1,v2);

    printf ("%ld\n", multiply(v1, v2));
    */
}
