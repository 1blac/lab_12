#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

typedef int inform;

struct Elem
{
    Elem* link1,
        * link2;
    inform inf;
};

void Enqueue(Elem*& first, Elem*& last, inform inf);
void Print(Elem*& K);
void Process(Elem*& K, inform L1, Elem*& last);

int main(void)
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Elem* first = NULL;
    Elem* last = NULL;

    int x = 0;
    for (int i = 0; i < 4; i++)
    {
        x = rand() % 6;
        Enqueue(first, last, x);
    }

    Elem* K = first;
    Print(K);


    int L1;

    cout << "¬вед≥ть L1: ";  cin >> L1;
    cout << endl;


    K = first;
    Process(K, L1, last);
    K = first;
    Print(K);

    return 0;
}

void Enqueue(Elem*& first, Elem*& last, inform inf)
{
    Elem* tmp = new Elem;

    tmp->inf = inf;
    tmp->link1 = NULL;
    tmp->link2 = NULL;
    if (first == NULL)
        first = tmp;
    else
    {
        last->link1 = tmp;
        tmp->link2 = last;
    }
    last = tmp;
}

void Print(Elem*& K)
{

    inform inf;
    cout << "L2: " << endl;
    while (K != NULL)
    {
        inf = K->inf;
        cout << inf << "   ";
        K = K->link1;
    }
    cout << endl;
}

void Process(Elem*& K, inform L1, Elem*& last)
{
    while (K != NULL)
    {
        if (K->inf == L1)
        {
            Elem* tmp = new Elem;
            tmp->inf = L1;
            tmp->link1 = K->link1;
            if (K->link1 != NULL)
                K->link1->link2 = tmp;
            else
                last = tmp;
            K->link1 = tmp;
            tmp->link2 = K;
            K = K->link1->link1;
        }
        else
            K = K->link1;
    }
}