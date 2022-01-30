#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[10];
	int height;
	int weight;
}PERSON;

//이름 오름차순
int name_cmp(const PERSON* a, const PERSON* b)
{
	return strcmp(a->name, b->name);
}

// 키 오름차순
int height_cmp(const PERSON* a, const PERSON* b)
{
	return a->height < b->height ? -1 : a->height > b->height ? 1 : 0;
}

// 몸무게 내림차순
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

	puts("정렬전");
	print_person(x, nx);

	//이름 오름차순으로 정렬
	qsort(x, nx, sizeof(PERSON), (int(*)(const void*, const void*))name_cmp);
	puts("\n이름 오름차순 정렬 후");
	print_person(x, nx);

	//키 오름차순으로 정렬
	qsort(x, nx, sizeof(PERSON), (int(*)(const void*, const void*))height_cmp);
	puts("\n키 오름차순 정렬 후");
	print_person(x, nx);

	//몸무게 내림차순으로 정렬
	qsort(x, nx, sizeof(PERSON), (int(*)(const void*, const void*))weight_cmp);
	puts("\n몸무게 내림차순 정렬 후");
	print_person(x, nx);

}