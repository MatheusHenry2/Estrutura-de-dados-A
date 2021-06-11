#include <iostream>
using namespace std;

struct no
{
    int codigo;
    struct no *prox;
};

void insere(no **lista)
{
    no *aux = (no *)malloc(sizeof(no));
    if (aux != NULL)
    {
        cout << "digite um valor:";
        cin >> aux->codigo;
        aux->prox = (*lista);
        (*lista) = aux;
    }
}

void imprime(no *lista)
{
    while (lista != NULL)
    {
        cout << lista->codigo;
        lista = lista->prox;
    }
}

int main()
{
    int n;
    no *lista = NULL;

    cout << "\n Quantos valores serao inseridos ?";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        insere(&lista);
    }

    imprime(lista);

    return 0;
}