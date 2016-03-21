#include <stdio.h>

#define DATA_MAX 255

typedef int ListData;
typedef struct __arrayList
{
    ListData data[DATA_MAX];
    int size; // number of data
    int pos; // position
}arrayList;

typedef arrayList List;
void ListInit(List *plist)
{
    plist->size = 0;
    plist->pos = 0;
}

bool LInsert(List *plist, ListData data)
{
    if (plist->size > DATA_MAX)
        return false;

    plist->data[plist->size++] = data;
    return true;
}

bool LFirst(List *plist, ListData *data)
{
    if (!plist->size)
        return false;

    plist->pos = 0;
    *data = plist->data[plist->pos];
    return true;
}

bool LNext(List *plist, ListData *data)
{
    if (plist->pos < plist->size)
    {
        *data = plist->data[plist->pos++];
        return true;
    }
    return false;
}

bool LDelete(List *plist)
{
    if (plist->size)
    {
        plist->size--;
        return true;
    }
    return false;
}

int LCount(List *plist)
{
    return plist->size;
}

int main()
{
    List list;
    ListData data;

    ListInit(&list);
    LInsert(&list, 11);
    LInsert(&list, 7);
    LInsert(&list, 22);
    LInsert(&list, 35);

    printf("데이터의 갯수 : %d\n", LCount(&list));
    if (LFirst(&list, &data))
    {
        printf("%d ", data);
        while(LNext(&list, &data))
        {
            printf("%d ", data);
        }
        printf("\n");
    }
}
