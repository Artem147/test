#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <malloc.h>


typedef struct list {
	float info;
	struct list *next;
	struct list *prev;
}list;

list*CreateF(list* F) {
	float temp;
	if (scanf("%f", &temp) < 1) return NULL;
	F = (list*)malloc(sizeof(list));
	if (!F) return NULL;
	F->info = temp;
	F->next = NULL;
	F->prev = NULL;
	return F;
}
list*yeshchyo(list*pred) {
	list*T = NULL;
	float temp;
	if (scanf("%f", &temp) < 1) return NULL;
	T = (list*)malloc(sizeof(list));
	if (!T) return NULL;
	T->info = temp;
	T->next = NULL;
	T->prev = pred;
	return T;
}


list* Create(list*F, list*T, list*P) {
	int a;
	float temp;
	if (scanf("%f", &temp) < 1) return 0;
	T = (list*)malloc(sizeof(list));
	if (!T) return 0;
	F->next = T;
	T->prev = F;
	T->info = temp;
	T->next = NULL;
	while (1) {
		printf("Dobavit yeshchyo? 1/0");
		if (scanf("%d", &a) < 1 || a != 0 && a != 1) return NULL;
		if (a == 1)
			T->next = yeshchyo(T);
		else break;
		if (T->next == NULL) return NULL;
		T = T->next;
	}
	return T;
}

int DeletePred(list* T)
{
	list*P, *S;
	P = T->prev;
	S = T->next;
	S->prev = T->prev;
	P->next = T->next;
	free(T);
	return 1;
}

int main()
{
	list *F, *T, *P;
	int a;
	float k;
	P = T = F = NULL;
	printf("Sozdat spisok? 1/0");
	if (scanf("%d", &a) < 1 || a != 1) return 0;
	else {
		F = CreateF(F);
		P = F;
	}
	if (F == NULL) return 0;
	printf("Dobavit yeshchyo? 1/0");
	if (scanf("%d", &a) < 1 || a != 0 && a != 1) return 0;
	if (a == 1) {
		P = Create(F, T, P);
		if (P == NULL) return 0;
	}
	for (T = F; T != NULL; T = T->next)
		printf("%.2f ", T->info);

	printf("\npozhaluista vvedite kakoe-nibud' k, pered kotorym nuzhno udalit' element ");
	if (scanf("%f", &k) < 1) return 0;
	for (T = P; T != F; T = T->prev)
		if (T->info == k)
			DeletePred(T->prev);

	for (T = F; T != NULL; T = T->next)
		printf("%.2f ", T->info);

	for (T = F; P != NULL; T = P)
	{
		P = T->next;
		free(T);
	}
	printf("\n");
	system("pause");
}