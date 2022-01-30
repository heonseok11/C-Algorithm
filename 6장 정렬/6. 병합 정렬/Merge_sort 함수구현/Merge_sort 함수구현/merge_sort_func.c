#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static char* buff;

int int_cmp(int* a, int* b)
{
	return (*a < *b) ? -1 : (*a > *b) ? 1 : 0;
}

void __m_sort(char* a, size_t left, size_t right, size_t size, int(*compar)(const void*, const void*))
{	
	if (left < right) {
		size_t i;
		size_t p = 0;
		size_t j = 0;
		size_t k = left;
		size_t center = (left + right) / 2;

		__m_sort(a, left, center, size, compar);
		__m_sort(a, center + 1, right,  size, compar);

		for (i = left; i <= center; i++)
			memcpy(&buff[p++ * size], &a[i * size], size); //a배열에서 옮겨진 요소의 개수 + 1 저장
		while (i <= right && j < p) 
			memcpy(&a[k++ * size], (compar((const void*)&buff[j * size], (const void*)&a[i * size]) <= 0) ? 
				&buff[j++ * size] : &a[i++ * size], size);
		while (j < p) 
			memcpy(&a[k++ * size], &buff[j++ * size], size);
		
	}
	
}

int m_sort(void* base, size_t nmemb, size_t size, int(*compar)(const void*, const void*)) {

	if (nmemb > 0) {
		buff = (char*)calloc(nmemb, size);
		__m_sort(base, 0, nmemb - 1, size, compar);
		free(buff);
	}
}

void main()
{
	int i, nx;
	puts("병합 정렬");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);

	int* x = (int*)calloc(nx, sizeof(int));
	

	srand((unsigned int)time(NULL));
	for (i = 0; i < nx; i++) {
		x[i] = rand() % 15 + 1;
		printf("x[%d] : %d\n", i, x[i]);
	}

	m_sort(x, nx, sizeof(x[0]),(int(*)(const void*, const void*))int_cmp);

	puts("정렬 완료");
	for (i = 0; i < nx; i++) {
		printf("x[%d] : %d\n", i, x[i]);
	}

	
	free(x);
}