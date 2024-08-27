/*
NOME: Arthur Vinícius Vieira Ventura
PERÍODO/CURSO: 3° período de Ciência da computação
DATA: 27/08/2024
HORÁRIO: 16:41
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decimalParaBinario(int num, char *binStr);
void decimalParaOctal(int num, char *octStr);
void decimalParaHexadecimal(int num, char *hexStr);
void decimalParaBCD(int num, char *BCD[][5]);

int main() {
    int num;
    char binStr[32], octStr[32], hexStr[32], BCD[10][5];

    printf("Digite um número decimal: ");
    scanf("%d", &num);

    if (num == 0) {
        printf("O binário é: 0\n");
        printf("O octal é: 0\n");
        printf("O hexadecimal é: 0\n");
        printf("O BCD é: 0\n");
    } else {
        decimalParaBinario(num, binStr);
        printf("O binário é: %s\n", binStr);
        decimalParaOctal(num, octStr);
        printf("O octal é: %s\n", octStr);
        decimalParaHexadecimal(num, hexStr);
        printf("O hexadecimal é: %s\n", hexStr);
        decimalParaBCD(num,BCD);
    }

    return 0;
}

void decimalParaBinario(int num, char *binStr) {
    int index = 0;

    while (num > 0) {
        binStr[index] = (num % 2) + '0';  
        num /= 2;
        index++;
    }

    binStr[index] = '\0';  

    for (int i = 0; i < index / 2; i++) {
        char temp = binStr[i];
        binStr[i] = binStr[index - i - 1];
        binStr[index - i - 1] = temp;
    }
}

void decimalParaOctal(int num, char *octStr) {
    int index = 0;

    while (num > 0) {
        octStr[index] = (num % 8) + '0';  
        num /= 8;
        index++;
    }

    octStr[index] = '\0';  
    
    for (int i = 0; i < index / 2; i++) {
        char temp = octStr[i];
        octStr[i] = octStr[index - i - 1];
        octStr[index - i - 1] = temp;
    }
}

void decimalParaHexadecimal(int num, char *hexStr) {
    int index = 0;
    int remainder;

    while (num > 0) {
        remainder = num % 16;

        if (remainder < 10) {
            hexStr[index] = remainder + '0';  
        } else {
            hexStr[index] = (remainder - 10) + 'A';  
        }

        num /= 16;
        index++;
    }
    hexStr[index] = '\0'; 

    for (int i = 0; i < index / 2; i++) {
        char temp = hexStr[i];
        hexStr[i] = hexStr[index - i - 1];
        hexStr[index - i - 1] = temp;
    }
}

void decimalParaBCD(int num, char *BCD[][5]) {
    int digito;
    int digitos[10];
    int i = 0;
    
    while (num != 0) {
        digito = num % 10;  
        digitos[i] = digito;    
        num /= 10;          
        i++;
    }

    printf("O BCD é: ");

    for (int j = i - 1; j >= 0; j--) {
        decimalParaBinario(digitos[j], BCD[j]);
        if (strlen(BCD[j]) == 1){
            printf("000%s ", BCD[j]);
        }

        else if (strlen(BCD[j]) == 2){
            printf("00%s ", BCD[j]);
        }

        else if (strlen(BCD[j]) == 3){
            printf("0%s ", BCD[j]);
        }

        else {
            printf("%s ", BCD[j]);
        }
    }
}

