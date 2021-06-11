  
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
        cout << "\n Informe o valor:";
        cin >> aux->codigo;
        aux->prox = (*lista);
        (*lista) = aux;
    }
}

void inserefim(no **lista)
{
    no *aux = (no *)malloc(sizeof(no));

    if (aux != NULL)
    {
        cout << "\n Informe o valor:";
        cin >> aux->codigo;
        aux->prox = NULL;
    }

    if ((*lista) == NULL)
        (*lista) = aux;

    else
    {
        no *aux2 = (*lista);
        while (aux2->prox != NULL)
        {
            aux2 = aux2->prox;
        }
        aux2->prox = aux;
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

void remover(no **lista)
{
    if ((*lista) == NULL)
        cout << "\n lista ja vazia" << endl;

    else
    {
        no *lixo = (*lista);
        (*lista) = (*lista)->prox;
        free(lixo);
    }
}

void removerfim(no **lista)
{
    if ((*lista) == NULL)
        cout << "\n Lista ja vazia " << endl;

    else if ((*lista)->prox == NULL)
    {
        free((*lista));
        ((*lista)) = NULL;
    }
    else
    {
        no *aux2 = (*lista);
        while (aux2->prox->prox != NULL)
        {
            aux2 = aux2->prox;
        }
        free(aux2->prox);
        aux2->prox = NULL;
    }
}

void busca(no *lista)
{
    int n, qtd = 0;

    cout << "\n Informe qual valor quer ser buscado na lista : ";
    cin >> n;

    while (lista != NULL)
    {
        if (lista->codigo == n)
        {
            qtd++;
            break;
        }
        lista = lista->prox;
    }

    if (qtd != 0)
        cout << "\n Elemento " << n << " Encontrado na lista " << endl;

    else
        cout << "\n Nada encontrado ! " << endl;
}

int main()
{
    int opcao;
    no *lista = NULL;

    do
    {
        cout << "\n 1- Para inserir no inicio";
        cout << "\n 2- Para inserir no final";
        cout << "\n 3- Para imprimir";
        cout << "\n 4- Remover inicio ";
        cout << "\n 5- remover ultimo";
        cout << "\n 6-Procurar valor N";
        cout << "\n Informe sua opcao : ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            insere(&lista);
            break;
        case 2:
            inserefim(&lista);
            break;
        case 3:
            imprime(lista);
            break;
        case 4:
            remover(&lista);
            break;
        case 5:
            removerfim(&lista);
            break;
        case 6:
            busca(lista);
            break;
        }

    } while (opcao != 0);

    return 0;
}