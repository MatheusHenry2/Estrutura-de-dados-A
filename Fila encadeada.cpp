#include <iostream>
#include <time.h>
using namespace std;

struct no
{
    int codigo;
    time_t horario, after;
    struct no *prox;
};

void insere(no **fila, no **fim, int *qtd)
{
    (*qtd) = (*qtd) + 1;
    no *aux = (no *)malloc(sizeof(no));
    struct tm data;

    if (aux != NULL)
    {
        cout << "\n Informe um numero :";
        cin >> aux->codigo;
        aux->prox = NULL;
        aux->horario = time(NULL);
        data = *localtime(&aux->horario);
        cout << " \n\nData de insercao: " << data.tm_mday << "/" << data.tm_mon + 1 << "/" << data.tm_year + 1900 << endl;
        cout << "Hora de insercao:  " << data.tm_hour << ":" << data.tm_min << ":" << data.tm_sec << endl;
    }

    if ((*fila) == NULL)
    {
        (*fila) = aux;
        (*fim) = aux;
    }
    else
    {
        (*fim)->prox = aux;
        (*fim) = aux;
    }
}

int remover(no **fila, int *soma, int *qtd)
{
    no *lixo;
    struct tm data;
    int media = 0;

    if ((*fila) == NULL)
        cout << "\n Fila ja vazia ! " << endl;

    else
    {
        lixo = (*fila);
        lixo->after = time(NULL);
        (*fila) = (*fila)->prox;
        cout << "\n\n O elemento que esta sendo removido e : " << lixo->codigo << endl;
        data = *localtime(&lixo->horario);
        cout << " \n\nData de insercao: " << data.tm_mday << "/" << data.tm_mon + 1 << "/" << data.tm_year + 1900 << endl;
        cout << "Hora de insercao:  " << data.tm_hour << ":" << data.tm_min << ":" << data.tm_sec << endl;
        data = *localtime(&lixo->after);
        cout << " \nData de remocao: " << data.tm_mday << "/" << data.tm_mon + 1 << "/" << data.tm_year + 1900 << endl;
        cout << "Hora de de remocao:  " << data.tm_hour << ":" << data.tm_min << ":" << data.tm_sec << endl;
        cout << "\n Tempo na fila : " << (difftime(lixo->after, lixo->horario)) << " Segundos" << endl;
        (*soma) += (difftime(lixo->after, lixo->horario));
        media = (*soma) / (*qtd);
        cout << "\n Tempo medio dos elementos na fila :" << media<<endl;
        free(lixo);
    }
}

void imprimir(no *fila)
{
    while (fila != NULL)
    {
        cout << fila->codigo;
        fila = fila->prox;
    }
}

int main()
{
    no *fila = NULL;
    no *fim = NULL;
    int soma = 0;
    int qtd = 0;

    int opcao;

    do
    {
        cout << "\n 1 Para inserir na Fila !";
        cout << "\n 2 para Remover da Fila !";
        cout << "\n 3 Para imprimir a Fila !";
        cout << "\n Informe sua opcao : ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            insere(&fila, &fim, &qtd);
            break;
        case 2:
            remover(&fila, &soma, &qtd);
            break;
        case 3:
            imprimir(fila);
            break;
        }

    } while (opcao != 0);

    return 0;
}
