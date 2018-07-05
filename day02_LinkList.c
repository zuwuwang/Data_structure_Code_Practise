/*
 * day2_ChainList.c
 * 
 * Copyright 2018 nvidia <nvidia@asus>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdlib.h>
#include <stdio.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node;
typedef struct Node *LinkList; //定义LinkList

Status GetElem(LinkList L,int i,ElemType* e)
{
	int j = 1; //用于遍历节点
	LinkList p; //定义一个节点P
	p = L->next; 
	while( p && j < i )  //寻找第i个节点
	{
		p = p->next;
		++j;
	}
	if( !p || j>i)  //当超出索引，报错
	{
		return ERROR;
	}
	*e = p->data;
	return OK;
}

Status ListInsert(LinkList* L,int i,ElemType e)  //插入操作，必须是地址传递，修改原单链表
{
	int j = 1;
	LinkList p,s;
	p = *L; //获取第一个节点
	while(p && j<i) // 获取第i个节点
	{
		p = p->next;
		++j;
	}
	if( !p || j>i)
		return ERROR;
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

Status ListDelete(LinkList* L,int i,ElemType* e)
{
	int j = 1;
	LinkList p,q;
	p = *L;
	while( p && j<i)
	{
		p = p->next;
		++j;
	}
	if( !p || j>i)
		return ERROR;
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free( q ); //系统回收一个节点，释放内存，否则带来内存泄漏
	return OK;
}

Status CreateListHead(LinkList *L,int n)
{
	LinkList p;
	int i = 1;
	srand(time(0));
	*L = (LinkList)malloc(sizeof (Node));
	(*L)->next = NULL;
	for(i =0; i<n; i++)
	{
		p =(LinkList)malloc(sizeof(Node));
		p->data = rand()%100+1;
		p->next = (*L)->next;
	}
	return OK;
}

Status CreateListTail(LinkList* L,int n) //n为指定线性表的长度
{
	LinkList p,r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;
	for(i=0; i<n;i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100+1;
		r->next = p;
		r = p;
	} 
	r->next = NULL;
	return OK;
}

Status ClearList(LinkList *L)
{
	LinkList p,q;
	p =(*L)->next; // 指向L第一个元素
	while( p )
	{
		q = p->next;
		free(p); // 循环删除
		p=q;
	}
	(*L)->next =NULL;
	return OK;
}

int main(int argc,char** argv)
{
	return OK;
}
