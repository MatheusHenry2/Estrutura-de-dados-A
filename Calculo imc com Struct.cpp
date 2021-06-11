#include <iostream>
#include <math.h>
using namespace std;

struct ficha_aluno
{
    char nome [20];
    float altura;
    float peso;
    float imc;
};

int  main()
{
    struct   ficha_aluno alunos[5];
    int n,i;

    cout << "\n informe o tamanho da array : ";
    cin >> n;

    for(i=0; i < n; i++)
    {
        cout << "\n informe seu nome ";
        cin >>alunos[i].nome;

        cout << " \n Informe sua altura ";
        cin >> alunos[i].altura;

        cout << "\n Informe seu peso : ";
        cin >> alunos[i].peso;

        alunos[i].imc = alunos[i].peso/(alunos[i].altura*alunos[i].altura);
    }

    for(i=0; i < n; i++)
    {
        if(alunos[i].imc < 18.5)
        {
            cout << " Abaixo do peso : ";
            cout << " O "<<alunos[i].nome << " com "<<alunos[i].peso << " com "<<alunos[i].altura << " tem "<<alunos[i].imc<<endl;
        }

        else if(alunos[i].imc > 18.5 && alunos[i].imc < 25)
        {
            cout << " peso ideal ";
            cout << " O "<<alunos[i].nome << " com "<<alunos[i].peso << " com "<<alunos[i].altura << " tem "<<alunos[i].imc<<endl;
        }

        else if(alunos[i].imc >=25 && alunos[i].imc <30)
        {
            cout << " Sobrepeso ";
            cout << " O "<<alunos[i].nome << " com "<<alunos[i].peso << " com "<<alunos[i].altura << " tem "<<alunos[i].imc<<endl;
        }

        else if(alunos[i].imc >=30 && alunos[i].imc <35)
        {
            cout << " obesidade grau 1 ";
            cout << " O "<<alunos[i].nome << " com "<<alunos[i].peso << " com "<<alunos[i].altura << " tem "<<alunos[i].imc<<endl;
        }

        else if(alunos[i].imc >=35 && alunos[i].imc <40 )
        {
            cout << " Obesidade grau 2 : ";
            cout << " O "<<alunos[i].nome << " com "<<alunos[i].peso << " com "<<alunos[i].altura << " tem "<<alunos[i].imc<<endl;
        }

        else
            cout << " Obesidade grau 3 : ";
            cout << " O "<<alunos[i].nome << " com "<<alunos[i].peso << " com "<<alunos[i].altura << " tem "<<alunos[i].imc<<endl;
    }

    return 0;
}