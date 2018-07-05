/*
 * day03_StaticLinkList.c
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
#include <stdio.h>

#define  OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define ElemType int
#define Status int
#define MAXSIZE 1000

typedef struct 
{
	ElemType data;
	int cur;
}Component,StaticLinkList[MAXSIZE];

Status InitLisk(StaticLinkList space)
{
	int i;
	for(i = 0;i < MAXSIZE - 1;i++) //数组各个元素游标赋值
		space[i].cur = i+1;
	space[MAXSIZE].cur = 0; //指向数组首元素
	return OK ;
}

Status Malloc_SLL(StaticLinkList space)
{
	if(space[0].cur) //如果静态链表不为空
	{
		space[0].cur = space[space[0].cur].cur;
	}
	return space[0].cur;//返回申请成功的数组元素下标位置
}

Status ListInsert(StaticLinkList L,int i,ElemType e)
{
	int j = Malloc_SLL(L); //j是新分配的元素位置【在备用链表位置】。给新分配的元素分配空间
	int l,k;
	if(j)
	{	
		L[j].data = e;//赋值
		for(l=1;l<=i-1;l++)
		{
			k = L[k].cur; //k为插入位置的前一个元素索引，i为插入的位置【以下标索引为准】
		}
		L[j].cur = L[k].cur; 
		L[k].cur = j;
		return OK;
	}
	return ERROR;
}

void Free_SLL(StaticLinkList space,int k)
{
	//删除位置的cur指向原数组的space[0].cur位置，即优先以刚删除的位置作为备份链表，该链表指向原备份链表。
	space[k].cur = space[0].cur; //第二备份链表【原第一备份链表】
	space[0].cur = k; //第一备用链表，也就是说下次来新元素优先存储到这个位置
}

Status ListLength(StaticLinkList L)
{
	int j = 0;
	int i = L[MAXSIZE-1].cur; //i为数组头元素下标0
	while(i)
	{
		i = L[i].cur;
		j++; //判断游标是否为0，用j值计数
	}
	return j;
}

Status ListDelete(StaticLinkList L,int i)
{
	int k = L[MAXSIZE-1].cur;
	int j;
	for(j=1;j<=i-1;j++)
	{
		k = L[k].cur;
	}
	L[k].cur = L[L[k].cur].cur;//即删除了L[k].cur这个元素，即第i个位置的元素
	Free_SLL(L,j);
	return OK;
}



int main(int argc, char **argv)
{
	
	return 0;
}

