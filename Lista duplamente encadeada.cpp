#include <iostream>
using namespace std;

struct no
{
    int codigo;
    struct no *prox;
    struct no *ant;
};

void insere(no **lista)
{
    no *aux = (*lista);
    aux = (no *)malloc(sizeof(no));
    if (aux != NULL)
    {
        cout << " \n Informe seu codigo :";
        cin >> aux->codigo;
        aux->prox = (*lista);
        (*lista) = aux;
        aux->ant = NULL;
    }
    if ((*lista) != NULL)
    {
        (*lista)->ant = aux;
        (*lista) = aux;
    }
}

void inserefim(no **lista)
{
    no *aux;
    no *aux2;
    aux = (no *)malloc(sizeof(no));

    if (aux != NULL)
    {
        cout << "\n Informe seu codigo :";
        cin >> aux->codigo;
        aux->prox = NULL;
    }

    if ((*lista) == NULL)
    {
        aux->ant = NULL;
        (*lista) = aux;
    }

    else
    {
        aux2 = (*lista);
        while (aux2->prox != NULL)
        {
            aux2 = aux2->prox;
        }
        aux2->prox = aux;
        aux->ant = aux2;
    }
}

void insereordenado(no **lista)
{
    no *aux;
    aux = (no *)malloc(sizeof(no));

    if (aux != NULL)
    {
        cout << " \n Informe o numero :";
        cin >> aux->codigo;
    }

    if ((*lista) == NULL)
    {
        aux->prox = NULL;
        aux->ant = NULL;
        (*lista) = aux;
    }

    else
    {
        no *ante, *atual = (*lista);
        while (atual != NULL && atual->codigo < aux->codigo)
        {
            ante = atual;
            atual = atual->prox;
        }

        if (atual == (*lista))
        {
            aux->ant = NULL;
            (*lista)->ant = aux;
            aux->prox = (*lista);
            (*lista) = aux;
        }
        else
        {

            aux->prox = ante->prox;
            aux->ant = ante;
            ante->prox = aux;
            if (atual != NULL)
            {
                atual->ant = aux;
            }
        }
    }
}
void imprime(no *lista)
{
    int contador = 0;
    while (lista != NULL)
    {
        cout << lista->codigo;
        lista = lista->prox;
        contador++;
    }
    cout << " \n O tamanho da lista ligada e : " << contador;
}

int main()
{

    int opcao;
    no *lista = NULL;

    do
    {
        cout << " \n 1 para inserir : ";
        cout << " \n 2 para imrpimir :";
        cout << "  \n 3 Para inserir Fim :";
        cout << " \n 4 para ordenado ! ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            insere(&lista);
            break;
        case 2:
            imprime(lista);
            break;
        case 3:
            inserefim(&lista);
            break;
        case 4:
            insereordenado(&lista);
            break;
        }
    } while (opcao != 0);

    return 0;
}