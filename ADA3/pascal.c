#include<stdio.h>
#include<stdlib.h>
int factorial (int numero);
int main() {
    int n, i,j=1,k=1;  
    puts("Escribe el valor de n: ");
    scanf("%d", &n);
    for (i=0; i<=n;i++) {
        for (j=1;j<=n-i;j++){
        	printf("   ");
        }
        for (k=0; k<=i; k++) {
        	printf ("%6d",(factorial(i))/(factorial(k)*(factorial(i-k))));//numeros combinatorios
        }
        printf ("\n");
    }
    system("pause");
    return 0;
}
int factorial(int numero){
    int i=numero;
    int facto=1;
    for(i=numero;i>1;i--){
        facto*=i;
    }
    return facto;
}

