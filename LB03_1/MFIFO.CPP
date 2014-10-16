#include "MFIFO.H"
#include <iostream>
typedef int mytype;
using namespace std;
namespace FIFO
{

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Item::Item()
{
    data = 0;
    prev = nullptr;
    next = nullptr;
}

int &Item:: getData()
{
    return data;
}
Item *&Item::getPrev()
{
    return prev;
}
Item *&Item::getNext()
{
    return next;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
MFifo::MFifo()
{
    items = 0;
    begin = nullptr;
    end = nullptr;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
MFifo::~MFifo()
{
    Clear();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void MFifo::Clear()
{
    while(items)
    {
        Item *item = end;

        if(item -> getPrev())
        {
            item -> getPrev() -> getNext() = 0;
            end = item -> getPrev();
        }
        else
        {
            begin = 0;
            end = 0;
        }

        delete item;
        items--;

    }
}


void MFifo::PutItem(const int data)
{
    Item *item = new Item();

    item -> getData() = data;
    item -> getPrev() = 0;

    if(items)
    {
        item -> getNext() = begin;
        begin -> getPrev() = item;
    }
    else
    {
        item -> getNext() = 0;
        end = item;
    }

    begin = item;
    items ++;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int MFifo::GetItem()
{
    if(!items)  return 0;

    Item *item = end;
    return  item ->getData();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int MFifo::PeekItem(const int index)
{
    if(items <= index)  return 0;

    Item *item = end;

    for(int i = 0; i < index; i++)   item = item->getPrev();

    return item -> getData();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int MFifo::GetItems()
{
    return items;
}

void MFifo:: massItems()
{

    int numElements;
    mytype *curElement;
    //numElements = items;
    numElements = GetItems();
    int *a = new int[numElements];

    while(numElements)
    {
        int i = 0;
        //*curElement=Fifo->PeekItem((int)numElements-1);
        *curElement = PeekItem((int)numElements - 1);
        //cout<<*curElement<<endl;
        a[i] = *curElement;
        numElements--;
        i++;
    }

}




int MFifo:: massItems1()
{

    int numElements;
    mytype *curElement;
    //numElements = items;
    numElements = GetItems();
    int *a = new int[numElements];

    while(numElements)
    {
        int i = 0;
        //*curElement=Fifo->PeekItem((int)numElements-1);
        *curElement = PeekItem((int)numElements - 1);
        //cout<<*curElement<<endl;
        a[i] = *curElement;
        numElements--;
        i++;
    }
    return *a;
}





//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void vvod(int n, int *a)
{
    for(int i=0; i<n; i++)
    {
        cout<<"["<<i<<"]";
        cin>>a[i];
    }
}
void vyvod(int n, int *a)
{
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<"  ";

    }
    cout<<endl;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Repair(int*a,int items,int i)
{
    int n=items;
    int l,r,larg=i;
    l=2*i+1;
    r=2*i+2;
    if(l<n&&a[l]>a[i]) larg=l;
    if(r<n&&a[r]> a[larg]) larg=r;
    if(larg!=i)
    {
        int t=a[larg];
        a[larg]=a[i];
        a[i]=t;
        //cout<<"afterswap repair\n";
        vyvod(n,a);
        Repair(a,n,larg);
    }
}

void Build(int *a,int items)
{
    int n=items;
    for(int i=n/2; i>=0; --i)
        Repair(a,n,i);
}



void Sort(int*a,int n)
{
    int t,larg=0;
    Build( a, n);
    vyvod(n, a);
    for(int i=n-1; i>=1; --i)
    {

        t = a[larg];
        a[larg] = a[i];
        a[i] = t;
        cout<<"afrer swap\n";
        vyvod(n,a);
        //--n;
        Repair( a, i, larg);
        vyvod(n, a);
    }
}

}
