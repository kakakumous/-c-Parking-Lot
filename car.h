#include<iostream>
#include <string.h>
using namespace std;
typedef struct
{
    char num[10];
    int time;
}car;
void Getn(car &e){//输入车牌 
    printf("         请输入车牌号:");
    gets(e.num);
	if(strlen(e.num)!=8){
		printf("         输入错误，请重试。\n");
		printf("  ----------------------------------------------------------------------------\n");
		Getn(e);
	}
}
void Gett(car &e){//输入时间 
	int i;
    printf("         请按格式输入日期和时间（12月31日03时33分为12310333）:");
    scanf("%d",&e.time);
	i=e.time;
	if(i%100>=60 && (i%10000)/100>=24 &&(i%1000000)/10000>31 && i/1000000>12){
		printf("         输入错误，请重试。\n");
		printf("  ----------------------------------------------------------------------------\n");
		Getn(e);
    }

}
void Out1(car &e)
{
    printf("       车牌号：%s，停入时间：%d",e.num,e.time);
}

void Get1(car &e){
	;
    Getn(e);
    Gett(e);
}