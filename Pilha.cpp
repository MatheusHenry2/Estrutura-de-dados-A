#include <iostream>
using namespace std;

struct no
{
    int codigo;
    struct no *prox;
};

void push(no **pilha)
{

    no *aux = (no *)malloc(sizeof(no));
    if (aux != NULL)
    {
        cout << "\n Informe o codigo:";
        cin >> aux->codigo;
        aux->prox = (*pilha);
        (*pilha) = aux;
    }
}

void pop(no **pilha)
{

    if ((*pilha) == NULL)
        cout << "\n Pilha ja vazia !" << endl;

    else
    {
        no *lixo = (*pilha);
        (*pilha) = (*pilha)->prox;
        free(lixo);
    }
}

void imprime(no *pilha)
{

    while (pilha != NULL)
    {
        cout << pilha->codigo;
        pilha = pilha->prox;
    }
}

int main()
{

    int opcao;
    no *pilha = NULL;

    do
    {
        cout << "\n1- Para inserir na pilha!";
        cout << "\n2- Para remocao da pilha!";
        cout << "\n3- Listagem pilha !";
        cout << "\n Informe sua opcao:";
        cin >> opcao;

        switch (opcao)
        {

        case 1:
            push(&pilha);
            break;

        case 2:
            pop(&pilha);
            break;

        case 3:
            imprime(pilha);
            break;
        }

    } while (opcao != 0);

    return 0;
}