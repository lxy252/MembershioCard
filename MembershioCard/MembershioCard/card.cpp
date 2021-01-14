#include"stdafx.h"
#include"head.h"
#include<string.h>
#include<locale.h>

Cardinfo *cardhead;	//会员卡信息链表的头结点

void initcard()	//初始化，从文件中取出会员卡信息
{
	FILE *fp = freopen("card.txt", "r", stdin);
	if (fp == NULL)
	{
		fp = freopen("card.txt", "w+", stdin);
	}
	cardhead = NULL;
	Cardinfo *newcard,*cardtail=NULL;
	TCHAR id[30];
	//char sid[30];
	while (wscanf(L"%ls", id) == 1)
	{
		newcard = (Cardinfo *)malloc(sizeof(Cardinfo));
		wcscpy(newcard->CardId, id);
		scanf("%d%d%d", &newcard->integral, &newcard->discount, &newcard->disamount);
		getwchar();	//吃掉换行符
		setlocale(LC_ALL, "chs");
		fgetws(newcard->cname, 20, stdin);
		//wcscpy(newcard->cname, L"蔡昊");

		if (cardhead==NULL)
		{
			cardhead = newcard;
		}
		else
		{
			cardtail->next = newcard;
		}
		cardtail = newcard;
		cardtail->next = NULL;
	}

	fclose(fp);
}

void endcard()		//将会员卡信息写回文件并销毁链表
{
	if (cardhead == NULL)
		return;

	FILE *fp = freopen("card.txt", "w", stdout);
	Cardinfo *tem = cardhead;
	while (tem != NULL)
	{
		wprintf(L"%ls ", tem->CardId);
		printf("%d %d %d\n", tem->integral, tem->discount, tem->disamount);
		setlocale(LC_ALL, "chs");
		wprintf(L"%ls", tem->cname);
		tem = tem->next;
	}

	Cardinfo *p = cardhead;
	while (p != NULL)
	{
		tem = p->next;
		free(p);
		p = tem;
	}

	fclose(fp);
}

Cardinfo *FindId(TCHAR *id)		//查找会员，不存在时返回空
{
	Cardinfo *tem = cardhead;
	while (tem != NULL)
	{
		if (wcscmp(tem->CardId, id) == 0)
			return tem;
		tem = tem->next;
	}
	
	return NULL;
}