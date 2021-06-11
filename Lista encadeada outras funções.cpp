#include <iostream>
using namespace std;

struct no
{
    int codigo;
    struct no *prox;
};

void insere(no **lista)
{
    no *aux;
    aux = (no*)malloc(sizeof(no));

    cout << " \n Informe o codigo : ";
    cin >> aux->codigo;

    if((*lista)==NULL)
    {
        aux->prox=(*lista);
        (*lista) = aux;
    }
    else
    {
        no* ant, *atual =(*lista);
        while(atual!=NULL && atual->codigo < aux->codigo)
        {
            ant = atual;
            atual = atual ->prox;
        }
        if(atual == (*lista))
        {
            aux->prox=(*lista);
            (*lista)=aux;
        }
        else
        {
            aux->prox = ant ->prox;
            ant ->prox = aux;
        }
    }
}

void remove(no **lista)
{
    no *aux = (*lista);
    no* aux2;
    int n;
    cout << " \n Informe um valor N para remover : ";
    cin >> n;

    while(aux!=NULL && aux->codigo != n)
    {
        aux2 = aux;
        aux = aux ->prox;
    }
    if(aux == NULL)
    {
        cout << "\n Lista vazia mano ! ";
    }
    else if(aux ==(*lista))
    {
        (*lista) = aux->prox;
    }
    else
    {
        aux2 -> prox = aux->prox;
    }
    free(aux);
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
    no *lista = NULL;
    int opcao;

    do
    {
        cout << " \n 1 Para Inserir ordenado! ";
        cout << " \n 2 Para Remover um valor N ! ";
        cout << " \n 3 Para imprimir a lista ! ";
        cout << " \n 0 para sair !";
        cout << " \n Informe sua opcao ! ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            insere(&lista);
            break;
        case 2:
            remove(&lista);
            break;
        case 3:
            imprime(lista);
        }
    }
    while (opcao != 0);
    return 0;
}