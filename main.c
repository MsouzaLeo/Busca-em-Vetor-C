/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo Martins Souza
 *
 * Created on 22 de Maio de 2020, 15:42
 */

#include <stdio.h>
#include <stdlib.h>

/*busca Sequencial Padrao
 * recebe o vetor, o valor a procurar e o tamanho deste vetor
 */
int buscaSeqP(int *vet, int e, int n)
{
    for (int i = 0; i < n; i++)
    { //visita casa a casa do vetor procurando o elemento "e", em ordem sequencial da esquerda para a direita
        if (vet[i] == e)
        {
            return i;
        }
    }
    return -1;
}

/*busca Sequencial Ordenada
 * recebe o vetor, o valor a procurar e o tamanho deste vetor
 */
int buscaSeqOrd(int *vet, int e, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (vet[i] == e)
        {
            return i;
        }
        else if (vet[i] > e)
        { //A diferença esta no "else if", como o vetor é ordenado, se o elemento q esta sendo procurado é menor que o q esta sendo visitado no momento e ele nao foi encontrado, entao nao esta no vetor
            return -1;
        }
    }
    return -1;
}

/*busca binaria
 * recebe o vetor, o valor a procurar e o tamanho deste vetor
 */
int buscaBin(int *vet, int e, int n)
{
    int inicio, meio, fim;
    inicio = 0;
    fim = n - 1;
    if (inicio >= fim)
        return -1;
    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        if (vet[meio] > e)
            fim = meio - 1; //se o valor q esta procurando for menor q o meio calculado, entao muda o final para meio-1 e procura na "primeira" parte do vetor
        else if (e > vet[meio])
            inicio = meio + 1; //se o valor q esta procurando for maior q o meio calculado, entao muda o inicio para meio+1 e procura na "segunda" parte do vetor
        else
            return meio; //se o valor q esta procurando nao for menor e nem maior q o meio entao ele é igual, entao já é retornado o indice do meio do vetor
    }
    return -1;
}

int main(int argc, char **argv)
{

    int n, e;
    //leitura do numero de elementos do vetor
    scanf("%d", &n);

    //cria vetor do tamanho de n
    int *vet = (int *)malloc(n * sizeof(int));

    //ler os valores do vetor
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vet[i]);
    }

    //leitura do valor a ser encontrado
    scanf("%d\n", &e);

    //leitura do modo de busca
    char x;
    scanf("%c", &x);

    if (x == 's')
    {
        printf("%d", buscaSeqP(vet, e, n));
    }
    else if (x == 'S')
    {
        printf("%d", buscaSeqOrd(vet, e, n));
    }
    else if (x == 'B')
    {
        printf("%d", buscaBin(vet, e, n));
    }
    return (0);
}
