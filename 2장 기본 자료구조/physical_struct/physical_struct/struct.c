#include <stdio.h>
#define VMAX 21 // �÷��� �ִ� 2.1 * 10

typedef struct {
	char name[20];
	int height;
	double vision;
}PER;

void dist_vision(const PER dat[], int n, int vdist[])
{
	for (int i = 0; i < n; i++) {
		if (dat[i].vision >= 0.0 && dat[i].vision <= VMAX / 10.0)
			vdist[(int)(dat[i].vision * 10)]++;
	}
}

double ave_height(const PER dat[], int n)
{
	int i;
	double sum = 0;
	for (i = 0; i < n; i++) {
		sum += dat[i].height;
	}
	return sum / n;
}

void main()
{
	int i;
	PER x[] = {
		{"������", 162, 0.3},
		{"������", 173, 0.7},
		{"������", 175, 2.0},
		{"ȫ����", 171, 0.4},
		{"�̼���", 168, 0.4},
		{"�迵��", 174, 1.2},
		{"�ڿ��", 169, 0.8},
	};

	int nx = sizeof(x) / sizeof(x[0]);
	int vdist[VMAX] = { 0, }; // VMAX / 10.0 �� �÷��� ���� ������� ����� ������
	puts("------ ��ü�˻�ǥ ------");
	puts(" �̸�              Ű  �÷�");
	puts("--------------------------");
	for (i = 0; i < nx; i++) {
		printf("%-18s%3d%5.1f\n", x[i].name, x[i].height, x[i].vision);
	}

	printf("\n ��� Ű : %5.1f cm\n", ave_height(x, nx));
	dist_vision(x, nx, vdist);
	printf("\n �÷º��� \n");
	for (i = 0; i < VMAX; i++) {
		printf("%3.1f ~ : ", i / 10.0);
		for (int j = 0; j < vdist[i]; j++) putchar('*');
		printf("\n");
	}
}