#include "List.h"
#include <cstddef>
#include <cstdlib>
#include <iostream>
using namespace std;

int IsEmpty(List L)
{
    return L->Next == NULL;
}


int IsLast(Position P, List L)
{
    return P->Next == NULL;
}

Position Find(ElementType x, List L)
{
    Position P;
    P = L->Next;
    while (P != NULL && P->Element != x)
    {
        P = L->Next;/* code */
    }
    return P;
}

void Delete(ElementType x, List L)
{
    Position P, TmpCell;
    P = FindPrevious(x, L);
    if(!IsLast(P, L))
    {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }

}


Position FindPrevious(ElementType x, List L)
{
    Position P;
    P = L;
    while (P->Next != NULL && P->Next->Element != x)
    {
        P = P->Next;/* code */
    }
    return P;
}


void Insert(ElementType x, List L, Position P)
{
    Position TmpCell;
    TmpCell = (Position)malloc( sizeof( struct Node ) );
    if(TmpCell == NULL)
    {
        cout << "Out of Space!" << endl;
    }
    TmpCell->Element = x;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}


void DeleteList(List L)
{
    Position P, Tmp;
    P = L->Next;
    L->Next = NULL;
    while (P != NULL)
    {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
    
}

void InitLinkedList()
{
    Node * L;
    L = (Node *)malloc( sizeof( struct Node ) );
    if(L == NULL)
    {
        cout << "Out of Space!" << endl;
    }
    L->Next = NULL;
}


List createList(int n)
{
    List L;
    L = (List)malloc( sizeof( struct Node ) );
    L->Next = NULL;

    for(int i = 0; i < n; i++)
    {
        Insert(i, L, L);
    }
    return L;
}

void Print(List L)
{
    Position Tmp;
    Tmp = L->Next;
    cout << "Linked List:";
    while (Tmp !=NULL)
    {
       cout << Tmp->Element << " --> " ;
       Tmp = Tmp->Next;
    }
    cout << " NULL" << endl;
    
}

int main()
{
    List L = createList(50);
    Print(L);
    Position P;
    P = L->Next;
    cout << P << ", " << L->Next << endl;
    L->Next = NULL;
    cout << P << ", " << L->Next << endl;
    return 0;
}