#pragma once
#include<stdio.h>
#include<stdlib.h>

//����1Ԫ����1����
//1000-5000���֣�	9.5��	�ȼ�1
//5000-10000���֣�	9��		�ȼ�2
//10000-50000���֣�	8.5��	�ȼ�3
//50000-150000���֣�8��		�ȼ�4
//150000�������ϣ�	7��		�ȼ�5

typedef struct node {
	TCHAR CardId[30];	//����
	int integral;		//����
	int discount;		//�ۿ۵ȼ�
	int disamount;	//�ۼ��ۿ۽��
	TCHAR cname[20];		//�ֿ�������
	struct node *next;
}Cardinfo;

void initcard();	//��ʼ�������ļ���ȡ����Ա����Ϣ
void endcard();		//����Ա����Ϣд���ļ�����������
Cardinfo *FindId(TCHAR *id);		//���һ�Ա��������ʱ���ؿ�
