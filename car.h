#include<iostream>
#include <string.h>
using namespace std;
typedef struct
{
    char num[10];
    int time;
}car;
void Getn(car &e){//���복�� 
    printf("         �����복�ƺ�:");
    gets(e.num);
	if(strlen(e.num)!=8){
		printf("         ������������ԡ�\n");
		printf("  ----------------------------------------------------------------------------\n");
		Getn(e);
	}
}
void Gett(car &e){//����ʱ�� 
	int i;
    printf("         �밴��ʽ�������ں�ʱ�䣨12��31��03ʱ33��Ϊ12310333��:");
    scanf("%d",&e.time);
	i=e.time;
	if(i%100>=60 && (i%10000)/100>=24 &&(i%1000000)/10000>31 && i/1000000>12){
		printf("         ������������ԡ�\n");
		printf("  ----------------------------------------------------------------------------\n");
		Getn(e);
    }

}
void Out1(car &e)
{
    printf("       ���ƺţ�%s��ͣ��ʱ�䣺%d",e.num,e.time);
}

void Get1(car &e){
	;
    Getn(e);
    Gett(e);
}