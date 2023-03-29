#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include"LinkQueue.h"
#include"SqList.h"
int MaxSize,MaxWait;
SqList *L;
LinkQuNode *q;
ElemType e;
int flag,t,p,leave;
char e1[10];//车牌
typedef struct 
{
	int mon;
	int day;
	int hour;
	int min;
} ptime;//定义停车时间结构体 应该加年的，失策
void money(int etime,int ltime){//算钱
	int pmin=0,phour=0,pday=0,total=0;
	ptime et={etime/1000000,(etime%1000000)/10000,(etime%10000)/100,etime%100};
	ptime lt={ltime/1000000,(ltime%1000000)/10000,(ltime%10000)/100,ltime%100};
	if(et.min>lt.min){
		pmin=lt.min+60-et.min;
		lt.hour--;
	}
	else{
	pmin=lt.min-et.min;
	}
	if(et.hour>lt.hour){
		phour=lt.hour+24-et.hour;
		lt.day--;
	}
	else{
	phour=lt.hour-et.hour;
	}
	if(et.day>lt.day){
		pday=lt.day+31-et.day;
		lt.mon--;
	}
	else{
	pday=lt.day-et.day;
	}
	if(et.mon>lt.mon){
		printf("很抱歉，超出处理范围,无法显示价格。\n");
	}
	else{
	pday=pday+31*(lt.mon-et.mon);
	}
	if(pmin+60*phour+60*24*pday<t)
		total=0;
	else
		total=((((pmin+60*phour+60*24*pday)-t)/60)+1)*p;
	printf("         停车%d天%d时%d分，需缴费%d元\n",pday,phour,pmin,total);	
}
void InfoMenu(){
	int inum;
imenu:printf("         ====================停车场信息查询菜单====================\n");
	  printf("         **********************************************************\n");
	  printf("         ***************1.查询所有车辆信息>>>>>>>>>>>>>>***********\n");
	  printf("         ***************2.查询停车场收费信息>>>>>>>>>>>>***********\n");
	  printf("         ***************3.返回主菜单>>>>>>>>>>>>>>>>>>>>***********\n");
	  printf("         **********************************************************\n");
	  printf("         ==========================================================\n");
	  printf("         请输入您选择的操作代号(回车确认)：");
	  scanf("%d",&inum);
	  system("cls");
	  
	  switch(inum)
	  {
	  case 1:
		  if(L->length==0)
			  printf("     停车场内没有车辆。\n");
		  else
			  DispList(L);
		  break;
	  case 2:printf("本停车场%d分钟内停车免费，%d分钟后每小时%d元。\n",t,t,p);break;
	  case 3:return;
	  default:printf("         输入错误！请重新输入。\n");printf("  ----------------------------------------------------------------------------\n");
	  }
	  goto imenu;
}


int main(int argc, const char * argv[]){
	system("color f6");
	
    printf("\n");
	printf("                          欢迎使用停车场管理系统测试版\n");	
	printf("         **********************************************************\n");
start:printf("                  初始化中，请输入停车场车位数（1~100）:");
	  scanf("%d",&MaxSize);
	  if(MaxSize>100 || MaxSize<=0){
		  printf("输入错误！请重新输入。\n"); 
		  goto start;   
	  }
start2:printf("                       请输入停车场等候区容纳量（0~10）:");
	  scanf("%d",&MaxWait);
	  if(MaxWait>10 || MaxWait<=0){
		  printf("输入错误！请重新输入。\n"); 
		  goto start2;   
	  }

	  InitQueue(q);
	  InitList(L);

	  printf("         **********************************************************\n");
	  printf("                             请输入停车场收费标准\n");
	  printf("         免费时长（分钟）:");scanf("%d",&t);
	  printf("         单位价格（元/小时）:");scanf("%d",&p);
	  InitList(L);
	  printf("         **********************************************************\n");
menu:printf("         ======================基本操作菜单========================\n");
	 printf("         **********************************************************\n");
	 printf("         ***************1.车辆进入>>>>>>>>>>>>>>>>>>>>>>***********\n");
	 printf("         ***************2.车辆离开>>>>>>>>>>>>>>>>>>>>>>***********\n");
	 printf("         ***************3.查询停车场信息>>>>>>>>>>>>>>>>***********\n");
	 printf("         ***************4.重新初始化>>>>>>>>>>>>>>>>>>>>***********\n");
	 printf("         ***************5.退出程序>>>>>>>>>>>>>>>>>>>>>>***********\n");
	 printf("         **********************************************************\n");
	 printf("         ==========================================================\n");
	 printf("             》》》停车场现有车位%d,停入车辆数%d,剩余车位%d《《《\n",MaxSize,L->length,MaxSize-L->length);
	 printf("            》》》停车场可等待%d车,%d车等待中,剩余等待位置%d《《《\n",MaxWait,QueueLength(q),MaxWait-QueueLength(q));
	 printf("         ==========================================================\n");
	 printf("         请输入您选择的操作代号(回车确认)：");
	 flag=0;
	 scanf("%d",&flag);
	 system("cls");
	 
	 switch(flag){
	 case 1:
		 rewind(stdin);
		 if(L->length==MaxSize){
			 if(QueueLength(q)==MaxWait)
				 printf("很抱歉，停车场无空余位置且等候区已满，请离开。\n");
			 else if(QueueLength(q)!=MaxWait){
				 printf("停车场已满，请等候。\n");
		         printf("         ====================录入等待车辆车牌======================\n\n");
				 Getn(e);//车牌 
				 strcpy(e1,e.num);
				 EnQueue(q,e1);//进队等
			 }
		 }
		 else{
			 printf("         ======================录入车辆信息========================\n\n");
			 Get1(e);
			 ListInsert(L,ListLength(L)+1,e);
		 }
		 break;
		 
	 case 2:	
		 rewind(stdin);
		 if(ListEmpty(L))
			 printf("停车场为空，操作错误。\n");
		 else{
			 printf("请输入离开车辆的车牌号：");
			 ElemType i1;
			 gets(i1.num);
			 if(ListDelete(L,LocateElem(L,i1),e)){
				 printf("请输入离开时间：");
				 scanf("%d",&leave);
				 money(e.time,leave);
				 if(!QueueEmpty(q)){//进队列非空
					 DeQueue(q,e1);//出队（车牌
					 strcpy(e.num,e1);
					 printf("车牌号%s的车辆现可进入停车场。\n",e.num);
					 Gett(e);//进场时间
					 ListInsert(L,ListLength(L)+1,e);//插入 
				 }
				 
			 }
			 else{
				 printf("停车场内无匹配的车牌号。\n");
			 }
		 }
		 break;
	 case 3:InfoMenu();break;
	 case 4:
		 printf("本功能清除车库内已有车辆信息，等同于重新启动程序。是否重新初始化（0否，1是）？");
		 scanf("%d",&flag);
		 if(flag==0)
			 break;
		 else
			 goto start;
	 case 5:printf("谢谢使用！\n");DestroyList(L);DestroyQueue(q);return 0;
	 default:printf("         输入错误！请重新输入。\n");printf("  ----------------------------------------------------------------------------\n");
	 }
	 goto menu;
}
