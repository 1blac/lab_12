#include <iostream>

struct Elem
{
    Elem* link1,
        * link2;
    int info;
};

Elem* p;


void Create()
{
    p = new Elem;                              //1     
    p->info = 1;                               //2
    p->link1 = new Elem;                       //3
    p->link1->info = 2;                        //4
    p->link2 = new Elem;                       //5
    p->link2->info = 3;                        //6 
    p->link2->link2->link1;                    //7
    p->link2->link1 = p->link2;                //8
    p->link1->link2 = new Elem;                //9             
    p->link1->link2->info = 4;                 //10
    p->link1->link2->link2 = p->link2->link2;  //11
    p->link1->link2->link1 = p;                //12
    p->link1 = NULL;                           //13







}
void Delete()
{

    delete p->link1->link2;             //14 - видалення четвертого елемента
    delete p->link2;                    //15 - видалення третього елемента
    delete p->link1;                    //16 - видалення другого елемента
    delete p;                           //17 - видалення першого елемента

}
int main()
{

    Create();
    Delete();

    return 0;
}