#include <iostream>
#include <Windows.h>

using namespace std;

typedef int inform;

struct Elem
{
    Elem* link1;
    inform inf;
};

void Enqueue(Elem*& first, Elem*& last, inform inf);
void Print(Elem*& K);
void Process(Elem*& K, int z);

int main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Elem* first = NULL;
    Elem* last = NULL;
    inform inf, N;

    do
    {
        cout << "Введіть кількість елементів списку: "; cin >> N;
    } while (N < 0);

    for (int i = 0; i < N; i++)
    {
        cout << "Введіть елементи: "; cin >> inf;
        Enqueue(first, last, inf);
    }

    

    Elem* K = first;
    Print(K);
    K = first;

    int z;
    cout << "Введіть значення, для вилучення інформаційного поля: ";


    cin >> z;
    Process(K, z);

    return 0;
}

void Enqueue(Elem*& first, Elem*& last, inform inf)
{
    Elem* tmp = new Elem;

    tmp->inf = inf;
    tmp->link1 = NULL;
    if (first == NULL)
        first = tmp;
    else
        last->link1 = tmp;
    last = tmp;
}

void Print(Elem*& K)
{
    inform inf;

    cout << "Вивід інформації про створені елементи: " << endl << endl;
    while (K != NULL)
    {
        inf = K->inf;
        cout << inf << "   ";
        K = K->link1;
    }
    cout << endl << endl;
}

void Process(Elem*& K, int z)
{
    inform inf;

    cout << endl;
    cout << "модифікований список елементів " << endl << endl;
    while (K != NULL)
    {
        inf = K->inf;

        K->inf = inf + z;
        cout << K->inf << "   ";
        K = K->link1;

    }
    cout << endl;
}