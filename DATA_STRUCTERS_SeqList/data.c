#define _CRT_SECURE_NO_WARNINGS 1
#define MAXSIZE 100
#include <stdio.h>
#include <stdlib.h> 
typedef int ElemType;


typedef struct {
	ElemType* data1;
	int length1;
}SeqList1;



SeqList1* initList1() {
	SeqList1* L = (SeqList1*)malloc(sizeof(SeqList1));
	L->data1 = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	L->length1 = 0;
	return L;
}//��̬�ڴ�����ʼ��



typedef struct {
	ElemType data[MAXSIZE];
	int length;
}SeqList;//�����һ��˳���



void initList(SeqList* L) {
	L->length = 0;
}//˳���ĳ�ʼ��



int append(SeqList* L, ElemType e) {
	if (L->length >= MAXSIZE) {
		printf("˳�������\n");
		return 0;
	}
	L->data[L->length] = e;
	L->length++;
	return 1;
}//β�����Ԫ��


void listElem(SeqList* L) {
	for (int i = 0; i < L->length; i++) {
		printf("%d\n", L->data[i]);
	}
}//����



void insertElem(SeqList* L, int pos, ElemType e) {
	if (pos <= L->length) {
		for (int i = L->length - 1; i >= pos - 1; i--) {
			L->data[i + 1] = L->data[i];
		}
		L->data[pos - 1] = e;
		L->length++;
	}
	else
		printf("��������ȷ�Ĳ���λ��");
}//����Ԫ�أ��Ӻ���ǰ����



void deleteElem(SeqList* L, int pos) {
	for (int i = pos - 1; i < L->length; i++) {
		L->data[i] = L->data[i + 1];
	}
	L->length--;
}//ɾ��Ԫ��


int findElem(SeqList* L, int e) {
	for (int i = 0; i < L->length; i++) {
		if (L->data[i] == e) {
			return i + 1;
		}
	}
	return -1;
}//����Ԫ��



int main() {
	SeqList s;
	initList(&s);
	append(&s, 10);
	append(&s, 20);
	append(&s, 30);
	append(&s, 40);
	insertElem(&s, 2, 15);
	listElem(&s);
	printf("ɾ���\n");
	deleteElem(&s, 4);
	listElem(&s);
	printf("%d\n", findElem(&s, 25));
	printf("%d\n", findElem(&s, 20));
	SeqList1* s1 = initList1();
	printf("���");
}
#define _CRT_SECURE_NO_WARNINGS 1