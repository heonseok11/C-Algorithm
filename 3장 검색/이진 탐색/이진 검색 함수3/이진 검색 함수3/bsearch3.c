#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[10];
	int height;
	int weight;
}Person;

int cmp(const Person *x, const Person *y)
{
	return strcmp(x->name, y->name);
}

void main()
{
	Person x[] = {
		{"�迵��", 179, 79},
		{"������", 172, 63},
		{"�̼���", 176, 52},
		{"������", 165, 51},
		{"������", 181, 73},
		{"ȫ����", 172, 84},
	};

	int nx = sizeof(x) / sizeof(x[0]);

	int retry;
	puts("�̸����� �˻�");
	do {
		Person temp, * p;
		printf("�̸� : ");
		scanf_s("%s", temp.name,10); // Ű��
		p = bsearch(&temp, x, nx, sizeof(Person), (int(*)(const void*, const void*))cmp);
		if (NULL == p) puts("�˻� ����");
		else {
			puts("�˻� ����!");
			printf("x[%d] : %s %dcm %dkg\n", (int)(p - x), p->name, p->height, p->weight);
		}
		printf("�ٽ� �˻� ? (1)�� / (2)�ƴϿ� : ");
		scanf_s("%d", &retry);
	} while (retry == 1);
}