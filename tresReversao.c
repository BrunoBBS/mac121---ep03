#include "pilha.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>

/*A funcao recebe um vetor circular, seu tamanho e um indice e executa a
 * 3-reversao nesse indice.*/
void rev(int v[], int n, int ind)
{
    int aux;
    aux = v[ind % n];
    v[ind % n] = v[(ind + 2) % n];
    v[(ind + 2) % n] = aux;
}

/*A funcao recebe um vetor circular e sua quantidade de items e retorna 1 se
 * ele está ordenado ou 0 se não está.*/
int isSorted(int v[], int n)
{
    int j;
    for (j = 0; j < n - 1; j++)
        if (v[j] > v[j + 1])
            return 0;
    return 1;
}

/*A funcao recebe um vetor, seu tamanho, um indice e retorna o tipo de
 * movimento a ser utilizado para o numero desse indice, sendo 0 para
 * nenhum,  1 para uma tres reversao nesse indice e 2 para uma serie de
 * tres reversoes para trocar com o numero do indice sucessor.*/
int movType(int v[], int n, int ind)
{
    int a, b, c;
    a = ind;
    b = ind + 1;
    c = ind + 2;

    if (c < n && v[a] > v[c])
        return 1; /*Troca tres-reversao normal*/
    else if (b < n && v[a] > v[b])
        return 2; /*Troca com o vizinho*/
    return 0;     /*Nao troca com ninguem*/
}

/*A funcao recebe um vetor, seu tamanho e um indice e faz uma sequencia de
 * tres-reversoes para trocar o elemento do indice indicado com o do indice
 * sucessor.*/
void swNeighbor(int v[], int n, int ind)
{
    int i, bsteps, fsteps;
    bsteps = (n - 1) / 2;
    fsteps = (n - 3) / 2;
    for (i = 0; i < bsteps; i++)
    {
        ind = (ind - 2) % n;
        if (ind < 0)
            ind += n;
        rev(v, n, ind);
        printf("%d\n", ind);
    }

    for (i = 0; i < fsteps; i++)
    {
        ind = (ind + 2) % n;
        rev(v, n, ind);
        printf("%d\n", ind);
    }
}

/*Recebe um vetor circular, seu tamanho, e o indice inicial e o ordena
 * utilizando 3-reversao.*/
void revSortOdd(int v[], int n, int ind)
{
    int i, j, move, count = 1;
    if (isSorted(v, n))
        return;
    for (i = n - 1; count && i > 0; i--)
    {
        count = 0;
        for (j = 0; j < i; j++)
        {
            move = movType(v, n, j);
            if (move == 2)
            {
                swNeighbor(v, n, j);
                i = n - 1;
                j = 0;
                count++;
            }
            else if (move == 1)
            {
                rev(v, n, j);
                count++;
                printf("%d\n", j);
            }
        }
    }
}

/* Recebe o vetor, seu tamanho, e um vetor para guardar os passos e retorna o
 * numero de passos.*/
int revSortEven(int v[], int n, pilha *p)
{
    int j, i, mov = 1, k = 0;

    /*Realiza uma especie de bubble sort usado tres-reversoes.*/
    for (i = n - 2; mov && i > 0; i--)
    {
        mov = 0;
        for (j = 0; j < i; j++)
        {
            if (v[j] > v[j + 2])
            {
                rev(v, n, j);
                empilha(p, j);
                k++;
                mov++;
            }
        }
    }
    return k;
}

/*A funcao recebe as entradas do usuario e ordena o vetor caso seja possivel*/
int main()
{
    int *v, n, i;
    scanf("%d", &n);
    v = malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", &v[i]);

    if (!(n % 2))
    {
        pilha *p;
        p = criaPilha(n);
        revSortEven(v, n, p);
        if (isSorted(v, n))
            for (i = 0; i < p->topo; i++)
                printf("%d\n", p->v[i]);
        else
            printf("Nao e possivel\n");
    }
    else
        revSortOdd(v, n, 0);
    return 0;
}
