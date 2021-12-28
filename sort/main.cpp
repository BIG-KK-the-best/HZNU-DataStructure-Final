#include"stdio.h"
#include"Public.h"


#define leftChild(i) (2*(i)+1)


void precDown(int* A,int n,int i) {
	int child;
	int t;
	for (t = A[i]; leftChild(i)< n; i = child) {
		child = leftChild(i);
		if (child != n - 1 && A[child + 1] > A[child]) {
			child++;
		}
		if (A[child] > t) {
			A[i] = A[child];
		}
		else {
			break;
		}
	}
	A[i] = t;
}

void heapSort(int* A, int n) {
	int t;
	for (int i = n / 2 - 1; i >= 0; i--) {
		precDown(A, n, i);
	}
	for (int i = n - 1; i >0; i--) {
		SWAP(A[0], A[i],t);
		precDown(A, i, 0);
	}
}


void quickSort(int* A, int left, int right) {
	int i = left;
	int j = right + 1;
	int prov = A[left];
	int t;
	if(i<j){
		do{
			do i++; while (A[i] < prov);
			do j--; while (A[j] > prov);
			if (i < j) {
				SWAP(A[i], A[j], t);
			}
		} while (i < j);
		SWAP(A[left], A[j], t);
		quickSort(A, left, j - 1);
		quickSort(A, j + 1, right);
	}
}


int main() {
	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");

	int* A;
	MALLOC(A, sizeof(int) * 1000, int*);

	int n;
	int caseId = 0;
	while (fscanf(fin,"%d", &n),n != -1) {
		for (int i = 0; i < n; i++) {
			fscanf(fin, "%d", &A[i]);
		}
		quickSort(A, 0,n-1);
		fprintf(fout, "Case %d:%d\n", ++caseId,n);
		for (int i = 0; i < n; i++) {
			fprintf(fout, "%d ", A[i]);
		}
		fprintf(fout, "\n");
	}

	fclose(fin);
	fclose(fout);
}