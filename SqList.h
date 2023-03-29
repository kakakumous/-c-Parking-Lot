#include<malloc.h>
#include<stdio.h>  
#include <stdlib.h>
#include <string.h>
#include"car.h" 
extern int MaxSize;
typedef car ElemType;
typedef struct 
{    
	int length;
    ElemType data[0];

}SqList;    //˳�������

void CreateList(SqList*&L,ElemType a[],int n)//���� 
{
    int i;
    L=(SqList*)malloc(sizeof(SqList));
    for(i=0;i<n;i++)
        L->data[i]=a[i];
    L->length=n;
}

void InitList(SqList *&L)//��ʼ�� 
{
    L=(SqList*)malloc(sizeof(SqList)+sizeof(ElemType)*MaxSize);
    L->length=0;

}
void DestroyList(SqList *&L)//���� 
{
    free(L);
}
bool ListEmpty(SqList *L)//���� 
{
    return(L->length==0);
}
int ListLength(SqList *L)//���� 
{
    return(L->length);
}
void DispList(SqList *L)//��� 
{
    int i;
    if(ListEmpty(L)){
        printf("ͣ���������޳�����\n");
        return;
    }
    for(i=0;i<L->length;i++)  Out1(L->data[i]);//stu���� 
    printf("\n");
} 
bool GetElem(SqList *L,int i,ElemType &e)//��ֵ 
{
    if (i<1 || i>L->length)  return false;
    e=L->data[i-1];
    return true;
}
int LocateElem(SqList *L,ElemType e)//���� 
{
    int i=0;
    while (i<L->length && strcmp(L->data[i].num,e.num)!=0)   i++;
    if(i>=L->length)  return 0;
    else  return i+1;
}
bool ListInsert(SqList *&L,int i,ElemType e)//���� 
{  
    int j;
    if(i<1||i>L->length+1)  return false;
    i--;
    for(j=L->length;j>i;j--)  L->data[j]=L->data[j-1];
    L->data[i]=e;
    L->length++;
    return true;
}
bool ListDelete(SqList *&L,int i,ElemType &e)//ɾ�� 
{  
    int j;
    if(i<1||i>L->length)  return false;
    i--;
    e=L->data[i];
    for(j=i;j<L->length-1;j++)  L->data[j]=L->data[j+1];
    L->length--;
    return true;
}
