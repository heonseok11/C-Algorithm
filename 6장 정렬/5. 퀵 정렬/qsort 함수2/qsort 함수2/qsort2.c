#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[10];
	int height;
	int weight;
}PERSON;

//�̸� ��������
int name_cmp(const PERSON* a, const PERSON* b)
{
	return strcmp(a->name, b->name);
}

// Ű ��������
int height_cmp(const PERSON* a, const PERSON* b)
{
	return a->height < b->height ? -1 : a->height > b->height ? 1 : 0;
}

// ������ ��������
int weight_cmp(const PERSON* a, const PERSON* b)
{
	return a->weight < b->weight ? 1 : a->weight > b->weight ? -1 : 0;
}

void print_person(const PERSON x[], int n)
{
	for (int i = 0; i < n; i++) {
		printf("%-10s : %dcm %dkg\n", x[i].name, x[i].height, x[i].weight);
	}
}

void main()
{
	PERSON x[] = {
		{"sunmi",170,52},
		{"yoobin",180,70},
		{"sohee",172,63},
		{"jina",165,50},
	};

	int nx = sizeof(x) / sizeof(x[0]);

	puts("������");
	print_person(x, nx);

	//�̸� ������������ ����
	qsort(x, nx, sizeof(PERSON), (int(*)(const void*, const void*))name_cmp);
	puts("\n�̸� �������� ���� ��");
	print_person(x, nx);

	//Ű ������������ ����
	qsort(x, nx, sizeof(PERSON), (int(*)(const void*, const void*))height_cmp);
	puts("\nŰ �������� ���� ��");
	print_person(x, nx);

	//������ ������������ ����
	qsort(x, nx, sizeof(PERSON), (int(*)(const void*, const void*))weight_cmp);
	puts("\n������ �������� ���� ��");
	print_person(x, nx);

}