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
char e1[10];//����
typedef struct 
{
	int mon;
	int day;
	int hour;
	int min;
} ptime;//����ͣ��ʱ��ṹ�� Ӧ�ü���ģ�ʧ��
void money(int etime,int ltime){//��Ǯ
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
		printf("�ܱ�Ǹ����������Χ,�޷���ʾ�۸�\n");
	}
	else{
	pday=pday+31*(lt.mon-et.mon);
	}
	if(pmin+60*phour+60*24*pday<t)
		total=0;
	else
		total=((((pmin+60*phour+60*24*pday)-t)/60)+1)*p;
	printf("         ͣ��%d��%dʱ%d�֣���ɷ�%dԪ\n",pday,phour,pmin,total);	
}
void InfoMenu(){
	int inum;
imenu:printf("         ====================ͣ������Ϣ��ѯ�˵�====================\n");
	  printf("         **********************************************************\n");
	  printf("         ***************1.��ѯ���г�����Ϣ>>>>>>>>>>>>>>***********\n");
	  printf("         ***************2.��ѯͣ�����շ���Ϣ>>>>>>>>>>>>***********\n");
	  printf("         ***************3.�������˵�>>>>>>>>>>>>>>>>>>>>***********\n");
	  printf("         **********************************************************\n");
	  printf("         ==========================================================\n");
	  printf("         ��������ѡ��Ĳ�������(�س�ȷ��)��");
	  scanf("%d",&inum);
	  system("cls");
	  
	  switch(inum)
	  {
	  case 1:
		  if(L->length==0)
			  printf("     ͣ������û�г�����\n");
		  else
			  DispList(L);
		  break;
	  case 2:printf("��ͣ����%d������ͣ����ѣ�%d���Ӻ�ÿСʱ%dԪ��\n",t,t,p);break;
	  case 3:return;
	  default:printf("         ����������������롣\n");printf("  ----------------------------------------------------------------------------\n");
	  }
	  goto imenu;
}


int main(int argc, const char * argv[]){
	system("color f6");
	
    printf("\n");
	printf("                          ��ӭʹ��ͣ��������ϵͳ���԰�\n");	
	printf("         **********************************************************\n");
start:printf("                  ��ʼ���У�������ͣ������λ����1~100��:");
	  scanf("%d",&MaxSize);
	  if(MaxSize>100 || MaxSize<=0){
		  printf("����������������롣\n"); 
		  goto start;   
	  }
start2:printf("                       ������ͣ�����Ⱥ�����������0~10��:");
	  scanf("%d",&MaxWait);
	  if(MaxWait>10 || MaxWait<=0){
		  printf("����������������롣\n"); 
		  goto start2;   
	  }

	  InitQueue(q);
	  InitList(L);

	  printf("         **********************************************************\n");
	  printf("                             ������ͣ�����շѱ�׼\n");
	  printf("         ���ʱ�������ӣ�:");scanf("%d",&t);
	  printf("         ��λ�۸�Ԫ/Сʱ��:");scanf("%d",&p);
	  InitList(L);
	  printf("         **********************************************************\n");
menu:printf("         ======================���������˵�========================\n");
	 printf("         **********************************************************\n");
	 printf("         ***************1.��������>>>>>>>>>>>>>>>>>>>>>>***********\n");
	 printf("         ***************2.�����뿪>>>>>>>>>>>>>>>>>>>>>>***********\n");
	 printf("         ***************3.��ѯͣ������Ϣ>>>>>>>>>>>>>>>>***********\n");
	 printf("         ***************4.���³�ʼ��>>>>>>>>>>>>>>>>>>>>***********\n");
	 printf("         ***************5.�˳�����>>>>>>>>>>>>>>>>>>>>>>***********\n");
	 printf("         **********************************************************\n");
	 printf("         ==========================================================\n");
	 printf("             ������ͣ�������г�λ%d,ͣ�복����%d,ʣ�೵λ%d������\n",MaxSize,L->length,MaxSize-L->length);
	 printf("            ������ͣ�����ɵȴ�%d��,%d���ȴ���,ʣ��ȴ�λ��%d������\n",MaxWait,QueueLength(q),MaxWait-QueueLength(q));
	 printf("         ==========================================================\n");
	 printf("         ��������ѡ��Ĳ�������(�س�ȷ��)��");
	 flag=0;
	 scanf("%d",&flag);
	 system("cls");
	 
	 switch(flag){
	 case 1:
		 rewind(stdin);
		 if(L->length==MaxSize){
			 if(QueueLength(q)==MaxWait)
				 printf("�ܱ�Ǹ��ͣ�����޿���λ���ҵȺ������������뿪��\n");
			 else if(QueueLength(q)!=MaxWait){
				 printf("ͣ������������Ⱥ�\n");
		         printf("         ====================¼��ȴ���������======================\n\n");
				 Getn(e);//���� 
				 strcpy(e1,e.num);
				 EnQueue(q,e1);//���ӵ�
			 }
		 }
		 else{
			 printf("         ======================¼�복����Ϣ========================\n\n");
			 Get1(e);
			 ListInsert(L,ListLength(L)+1,e);
		 }
		 break;
		 
	 case 2:	
		 rewind(stdin);
		 if(ListEmpty(L))
			 printf("ͣ����Ϊ�գ���������\n");
		 else{
			 printf("�������뿪�����ĳ��ƺţ�");
			 ElemType i1;
			 gets(i1.num);
			 if(ListDelete(L,LocateElem(L,i1),e)){
				 printf("�������뿪ʱ�䣺");
				 scanf("%d",&leave);
				 money(e.time,leave);
				 if(!QueueEmpty(q)){//�����зǿ�
					 DeQueue(q,e1);//���ӣ�����
					 strcpy(e.num,e1);
					 printf("���ƺ�%s�ĳ����ֿɽ���ͣ������\n",e.num);
					 Gett(e);//����ʱ��
					 ListInsert(L,ListLength(L)+1,e);//���� 
				 }
				 
			 }
			 else{
				 printf("ͣ��������ƥ��ĳ��ƺš�\n");
			 }
		 }
		 break;
	 case 3:InfoMenu();break;
	 case 4:
		 printf("������������������г�����Ϣ����ͬ���������������Ƿ����³�ʼ����0��1�ǣ���");
		 scanf("%d",&flag);
		 if(flag==0)
			 break;
		 else
			 goto start;
	 case 5:printf("ллʹ�ã�\n");DestroyList(L);DestroyQueue(q);return 0;
	 default:printf("         ����������������롣\n");printf("  ----------------------------------------------------------------------------\n");
	 }
	 goto menu;
}
