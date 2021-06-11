#include <iostream>
using namespace std;

struct dados
{
    int codigo;
};

void altera(float x, struct dados *reg, int v[])
{
    for (int i = 0; i < 5; i++)
    {
        v[i] = i * 3;
    }
    x = 15;

    (*reg).codigo = 100;

    cout << "\n\n\nImpressao dos valores dentro da funcao : " << endl;
    cout << " \n Impressao do vetor : ";

    for (int i = 0; i < 5; i++)
    {
        cout << v[i] << " ";
    }
    cout << " \n Impressao do valor de X : " << x;
    cout << " \n Impressao do valor do registro : " << reg->codigo;
}

int main()
{
    struct dados reg, *regis;
    float x, *px;
    int v[10];

    for (int i = 0; i < 5; i++)
    {
        v[i] = i;
    }

    px = &x;
    regis = &reg;

    *px = 10;
    regis->codigo = 5;

    cout << " \n Valores antes da chamada da funcao : " << endl;
    cout << " \n Valor do Vetor : ";

    for (int i = 0; i < 5; i++)
    {
        cout << v[i] << " ";
    }
    cout << " \n Valor do X : " << x;
    cout << "\n Valor do registro : " << reg.codigo;

    altera(x, &reg, v);

    cout << " \n\n\n Valor apos alteracoes MAIN " << endl;
    cout << " \n new  valor do vetor :";

    for (int i = 0; i < 5; i++)
    {
        cout << v[i] << " ";
    }
    cout << " \n new Valor do X : " << x;
    cout << " \n new Valor do registro " << reg.codigo;

    return 0;
}