#include <iostream>
using namespace std;

struct no
{
    int codigo;
    struct no *prox;
};

void imprime(no *lista)
{
    while (lista != NULL)
    {
        cout << lista->codigo;
        lista = lista->prox;
    }
}

int insere(no **lista, int *tam)
{
    no *aux = (no *)malloc(sizeof(no));

    if (aux != NULL)
    {
        (*tam) = (*tam) + 1;
        cout << "\n Informe o codigo:";
        cin >> aux->codigo;
        aux->prox = (*lista);
        (*lista) = aux;
    }
    return (*tam);
}

void print(no *aux)
{
    if (aux != NULL)
    {
        print(aux->prox);
        cout << aux->codigo;
    }
}

int main()
{
    int opcao, tam = 0, retorno;
    ;
    no *lista = NULL;

    do
    {
        cout << "\n 1 Insert";
        cout << "\n 2 print";
        cout << "\n 3 impressao recursiva";
        cout << "\n Informe sua opcao:";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            retorno = insere(&lista, &tam);
            if (retorno)
                cout << "\n O tamanho da lista ligada: " << tam << endl;
            else
                cout << "\n Vazia " << endl;
            break;
        case 2:
            imprime(lista);
            break;

        case 3:
            print(lista);
            break;
        }

    } while (opcao != 0);

    return 0;
}