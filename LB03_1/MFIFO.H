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
    void massItems();
    int massItems1();
    //void Repair(int *a, int items, int i);
    //void Build(int *a, int items);
    //void Sort(int *a, int items);
    //friend void vvod(int n, int *a);
    //friend void vyvod(int n, int *a);
private:
    int items;
    Item *begin;
    Item *end;
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void vvod(int n, int *a);
void vyvod(int n, int *a);
void Repair(int*a,int items,int i);
void Build(int *a,int items);
void Sort(int* a,int items);


}

#endif // MFIFO_H
