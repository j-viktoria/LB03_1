#include "MFIFO.H"
#include <iostream>
typedef int mytype;

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

    for(unsigned int i = 0; i < index; i++)   item = item->prev;

    return item -> data;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int MFifo::GetItems()
{
    return items;
}
void MFifo:: massItems(items)
{
    mytype *curElement;
    numElements = items;
    int *a = new int[items];

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

}

