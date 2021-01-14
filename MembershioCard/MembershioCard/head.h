#pragma once
#include<stdio.h>
#include<stdlib.h>

//消费1元——1积分
//1000-5000积分：	9.5折	等级1
//5000-10000积分：	9折		等级2
//10000-50000积分：	8.5折	等级3
//50000-150000积分：8折		等级4
//150000积分以上：	7折		等级5

typedef struct node {
	TCHAR CardId[30];	//卡号
	int integral;		//积分
	int discount;		//折扣等级
	int disamount;	//累计折扣金额
	TCHAR cname[20];		//持卡人姓名
	struct node *next;
}Cardinfo;

void initcard();	//初始化，从文件中取出会员卡信息
void endcard();		//将会员卡信息写回文件并销毁链表
Cardinfo *FindId(TCHAR *id);		//查找会员，不存在时返回空
