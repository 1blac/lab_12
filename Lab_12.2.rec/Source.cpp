#include <iostream>
#include <Windows.h>

using namespace std;

typedef int inform;

struct Elem
{
    Elem* link1;
    inform inf;
};

int Enqueue(Elem*& first, Elem*& last, int index, int x);
int Print(Elem*& K, inform inf, int x, int index);
int Process(Elem*& K, int z, inform inf);
int main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Elem* first = NULL;
    Elem* last = NULL;
    Elem* K;
    inform inf, N;

    do
    {
        cout << "Введіть кількість елементів списку: "; cin >> N;
    } while (N < 0);

    for (int i = 0; i < N; i++)
    {
        cout << "Введіть елементи: "; cin >> inf;
        Enqueue(first, last, inf, 0);
    }

    int index = 0, x = 0;
    Enqueue(first, last, index, x);


    K = first;
    cout << "Вивід інформації про створені елементи: " << endl << endl;
    Print(K, 0, x, index);
    cout << endl << endl;

    int z;
    cout << "Введіть певне значення, для вилучення інформаційного поля кожного елемента: ";
    cin >> z;

    K = first;
    cout << endl;
    cout << "Вивід інформації про модифікований елемент" << endl << endl;
    Process(K, z, 0);
    cout << endl;

    return 0;
}

int Enqueue(Elem*& first, Elem*& last, int index, int x)
{
    Elem* tmp = new Elem;

    tmp->inf = index;
    tmp->link1 = NULL;
    if (first == NULL)
        first = tmp;
    else
        last->link1 = tmp;
    last = tmp;

    if (index < x - 1)
        return Enqueue(first, last, index + 1, x);
    else
        return 0;
}

int Print(Elem*& K, inform inf, int x, int index)
{
    if (K != NULL)
    {
        inf = K->inf;
        cout << inf << "   ";
    }

    if (K != NULL)
        return Print(K->link1, inf, x, index + 1);
    else
        return 0;
}

int Process(Elem*& K, int z, inform inf)
{
    if (K != NULL)
    {
        inf = K->inf;
        K->inf = inf + z;
        cout << K->inf << "   ";
    }
    if (K != NULL)
        return Process(K->link1, z, inf);
    else
        return 0;
}
