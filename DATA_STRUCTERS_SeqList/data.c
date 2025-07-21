#define _CRT_SECURE_NO_WARNINGS 1
#define MAXSIZE 100
#include <stdio.h>
#include <stdlib.h> 
typedef int ElemType;


/*typedef struct {
	ElemType* data1;
	int length1;
}SeqList1;*/



SeqList1* initList1() {
	SeqList1* L = (SeqList1*)malloc(sizeof(SeqList1));
	L->data1 = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	L->length1 = 0;
	return L;
}//动态内存分配初始化



typedef struct {
	ElemType data[MAXSIZE];
	int length;
}SeqList;//这就是一个顺序表



void initList(SeqList* L) {
	L->length = 0;
}//顺序表的初始化



int append(SeqList* L, ElemType e) {
	if (L->length >= MAXSIZE) {
		printf("顺序表已满\n");
		return 0;
	}
	L->data[L->length] = e;
	L->length++;
	return 1;
}//尾部添加元素


void listElem(SeqList* L) {
	for (int i = 0; i < L->length; i++) {
		printf("%d\n", L->data[i]);
	}
}//遍历



void insertElem(SeqList* L, int pos, ElemType e) {
	if (pos <= L->length) {
		for (int i = L->length - 1; i >= pos - 1; i--) {
			L->data[i + 1] = L->data[i];
		}
		L->data[pos - 1] = e;
		L->length++;
	}
	else
		printf("请输入正确的插入位置");
}//插入元素，从后往前复制



void deleteElem(SeqList* L, int pos) {
	for (int i = pos - 1; i < L->length; i++) {
		L->data[i] = L->data[i + 1];
	}
	L->length--;
}//删除元素


int findElem(SeqList* L, int e) {
	for (int i = 0; i < L->length; i++) {
		if (L->data[i] == e) {
			return i + 1;
		}
	}
	return -1;
}//查找元素



int main() {
	SeqList s;
	initList(&s);
	append(&s, 10);
	append(&s, 20);
	append(&s, 30);
	append(&s, 40);
	insertElem(&s, 2, 15);
	listElem(&s);
	printf("删后的\n");
	deleteElem(&s, 4);
	listElem(&s);
	printf("%d\n", findElem(&s, 25));
	printf("%d\n", findElem(&s, 20));
	SeqList1* s1 = initList1();
	printf("完成");
}
