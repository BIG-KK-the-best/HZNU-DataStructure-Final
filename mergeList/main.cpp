#include"Public.h"


int FRead(FILE* fin, int* a, int &n) {
	int t;
	fscanf(fin,"%d", &t);
	if (t == -1) {
		return -1;
	}
	else {
		n = t;
		for (int i = 0; i < n; i++) {
			fscanf(fin,"%d", &a[i]);
		}
	}
	return OK;
}

void FWrite(FILE* fout, int* c,int n,int caseId) {
	fprintf(fout, "CaseId %d:%d\n", caseId,n);
	for (int i = 0; i < n; i++) {
		fprintf(fout,"%d ",c[i]);
	}
	fprintf(fout, "\n");
}

void MergeList(int* a, int an, int* b, int bn,int *c,int& cn) {
	cn = an + bn;
	int a1=0;
	int b1=0;
	int c1=0;
	while (a1<an && b1<bn) {
		if (a[a1] < b[b1]) {
			c[c1++] = a[a1++];
		}
		else {
			c[c1++] = b[b1++];
		}
	}
	while (a1 < an) {
		c[c1++] = a[a1++];
	}
	while (b1 < bn) {
		c[c1++] = b[b1++];
	}
}

int main() {
	int an = 0;
	int bn = 0;
	int cn = 0;
	FILE* fin = fopen("input.txt","r");
	FILE* fout = fopen("output.txt","w");
	int* a;
	int* b;
	int* c;
	MALLOC(a, sizeof(int) * 2000, int*);
	MALLOC(b, sizeof(int) * 2000, int*);
	MALLOC(c, sizeof(int) * 2000, int*);
	
	int caseId = 0;
	while (FRead(fin, a, an) != -1) {
		caseId++;
		FRead(fin, b, bn);
		MergeList(a, an, b, bn, c, cn);
		FWrite(fout,c, cn,caseId);
	}
	fclose(fin);
	fclose(fout);
}