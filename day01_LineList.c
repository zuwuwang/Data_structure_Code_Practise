/*
 * ListInert.c
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
#include <malloc.h>
#define TRUE 1
#define FALSE 0
#define ERROR -1
#define SIZE 100

typedef struct {
	int data[SIZE]; //线性的数据结构，可以声明一个一维数组
	int length;
} sq_list;

void init_list(sq_list* list)
{
	//分配存储线性表的空间
	list->data = (sq_list*)malloc(sizeof(sq_list));
	list->length = 0;
}

void destory_list(sq_list* list)
{
	free(list);
}

bool list_empty(sq_list* list)
{
	//若为空，则返回1，反之返回0
	return (list->length == 0);
}

int list_length(sq_list* list)
{
	return list->length;
}

void disp_list(sq_list* list)
{
	int i;
	for(i=0;i<list->length;i++)
	{
		printf("%d",list->data[i]);
	}
	printf("\n");
}

int get_elem(sq_list* list,int key)
{
	//对list进行操作时，先判断相关操作哦是否合法
	int n = ERROR;
	if(key > -1 && key < list->length)
		n = list->data[key];
	return n
}

int locate_list(sq_list* list,int value)
{
	int key = -1;
	for(int i = 0;i <list->length;i++)
		{
			if(value == list->data[i])
			{
				key = i;
				break;
			}
		}
	lreturn key;
}

bool list_insert(sq_list* list,int value,int key)
{
	// 表未满， 位置合法，才可插入
	// key及其后面的元素依次后移一位，先挪最后一个元素
	bool n = FALSE;
	if( （list->length < SIZE ）&&（key > -1 && key  <list->length）)
	{
		for(int i =list->length;i!=key;i--)
		{
			list->data[i+1] = list->data[i];
		}
		list->data[key] = value;
		n = true;
		list->length ++;
	}
	return n;
}

bool list_delete(sq_list* list,int key)
{
	bool n = FALSE;
	if(key > -1 && key<list->length)
	{
		for(int i = key;i<list->length-1;i++)  //将后一个挪到key处
		{
			list->data[i] = list->data[i+1];
		}
		n = TRUE;
	}
	return n;
}

bool list_append(sq_list* list,int value)
{
	bool n = FALSE;
	if(list->length < SIZE )
	{
		//data以下标0开始，是0-length -1;data[length]位置就代表append的位置
		list->data[length] = value;
		list->length++;
		n = TRUE;
	}
}

bool list_pop(sq_list* list_length)
{
	bool n = FALSE;
	if(list->length !=0)
		{
			list->length --;
			n = TRUE;
		}
}
		

int main(int argc, char **argv)
{

	sq_list List;
	
	return 0;
}

