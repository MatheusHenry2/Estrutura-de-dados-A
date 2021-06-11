#include <iostream>
#include <math.h>
using namespace std;

int global1;
float global2;

int  main()
{
    int i,*pi;
    char j,*pc;
    float t,*pf;
    double x,*pd;
    int u;
    int *pa;

    cout << " \n O Tamanho em bytes INT "<<sizeof(i);
    cout << " \n O Tamanho em bytes Char "<<sizeof(j);
    cout << " \n O Tamanho em bytes FLOAT "<<sizeof(t);
    cout << " \n O Tamanho em bytes DOUBLE "<<sizeof(x);

    cout << " \n\n tamanho dos ponteiros inteiro : "<<sizeof(pi);
    cout << " \n tamanho dos ponteiros char : "<<sizeof(pc);
    cout << " \n tamanho dos ponteiros float : "<<sizeof(pf);
    cout << " \n tamanho dos ponteiros double : "<<sizeof(pd);


    cout << " \n\n O endereco da 1 variavel global e : "<<&global1;
    cout << " \n O endereco da 2 variavel global e : "<<&global2;

    cout << " \n\n O endereco da 1 variavel local e : "<<&i;
    cout << " \n O endereco da 2 variavel local e : "<<&t;

    cout << "\n\n Endereco da funcao main : "<<main;

    pa = (int *)malloc(sizeof(int));
    cout << " \n\n Endereco heap : "<<&pa;

    pc = (char *)malloc(sizeof(char));
    cout << " \n Endereco heap 2 : "<<&pc;






    return 0;
}