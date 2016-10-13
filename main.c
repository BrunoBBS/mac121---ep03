#include <stdio.h>
#include <stdlib.h>

/*A funcao recebe um vetor circular, seu tamanho e um indice e executa a 3-reversao nesse
 * indice.*/
void ret(int v[], int n, int ind)
{
    int aux;
    aux = v[ind % n];
    v[ind%n] = v[(ind + 2)%n];
    v[(ind + 2)%n] = aux;
}


int isOrd(int v[], int n)
{
    int i, max = 0;
    for (i = 0; i < n; i++)
        if(v[i] > v[max])
            max = i;
    return (max == (n-1));
}

void retSort(int v[], int n)
{

}

int main()
{
    int *v, n, i;
    scanf("%d", &n);
    v = malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", &v[i]);

    if (!(n%2))
    
    else
        retSort(v, n);
}
