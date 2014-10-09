#ifndef MFIFO_H
#define MFIFO_H
namespace FIFO
{

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class Item
{
    public:

        Item();
        int &getData();
        Item *&getPrev();
        Item *&getNext();

    private:
        int data;
        Item *prev;
        Item *next;
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class MFifo
{
    public:
        MFifo();
        ~MFifo();
        void PutItem(const int data);
        int GetItem();
        int PeekItem(const  int index = 0);
        int GetItems();
        void Clear() ;
        void massItems(int items);
        void Repair(int *a, int items, int i);
        void Build(int *a, int items);
        void Sort(int *a, int items);
    private:
        int items;
        Item *begin;
        Item *end;
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~




/*void RepairV(class Item *item1, int i,int items, int (*fp)( Item, Item));
void BuildV(class Item  *item1,int items, int (*fp)( Item, Item));
void sortV(class Item  *item1,int items, int (*fp)( Item, Item));
void RepairY(class Item  *item1, int i,int items, int (*fp)( Item, Item));
void BuildY(class Item  *item1,int items, int (*fp)( Item, Item));
void sortY(class Item  *item1,int items, int (*fp)( Item, Item));
*/
}

#endif // MFIFO_H

