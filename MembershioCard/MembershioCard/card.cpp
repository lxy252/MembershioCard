#include"stdafx.h"
#include"head.h"
#include<string.h>
#include<locale.h>

Cardinfo *cardhead;	//��Ա����Ϣ�����ͷ���

void initcard()	//��ʼ�������ļ���ȡ����Ա����Ϣ
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
		getwchar();	//�Ե����з�
		setlocale(LC_ALL, "chs");
		fgetws(newcard->cname, 20, stdin);
		//wcscpy(newcard->cname, L"���");

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

void endcard()		//����Ա����Ϣд���ļ�����������
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

Cardinfo *FindId(TCHAR *id)		//���һ�Ա��������ʱ���ؿ�
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