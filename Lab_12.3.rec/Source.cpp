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

int Enqueue(Elem*& first, Elem*& last, int index, int N, int i);
int Print(Elem*& K, inform inf, int N, int index);
void Process(Elem*& K, inform L1, Elem*& last);

int main(void)
{
    srand((unsigned)time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Elem* first = NULL;
    Elem* last = NULL;

    int index = rand() % 6, N = 4, i = 0;
    Enqueue(first, last, index, N, i);

    Elem* K = first;
    cout << "L2: " << endl << endl;
    Print(K, 0, N, index);
    cout << endl << endl;

    int L1;

    cout << "¬вед≥ть L1: ";  cin >> L1;
    cout << endl;


    K = first;
    Process(K, L1, last);
    K = first;
   Print(K, 0, N, index);

    return 0;
}

  int Enqueue(Elem*& first, Elem*& last, int index, int N, int i)
{
      Elem* tmp = new Elem;

    tmp->inf = index;
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

    if (i < N - 1)
        return Enqueue(first, last, rand() % 6, N, i + 1);
    else
        return 0;
}

int Print(Elem*& K, inform inf, int N, int index)
{
    if (K != NULL)
    {
        inf = K->inf;
        cout << inf << "   ";
    }

    if (K != NULL)
        return Print(K->link1, inf, N, index + 1);
    else
        return 0;
}

void Process(Elem*& K, inform L1, Elem*& last)
{
    if (K != NULL)
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
            return Process(K->link1->link1, L1, last);
        }
        else
            return Process(K->link1, L1, last);
    }
}