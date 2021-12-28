#include"Public.h"
#include"AScack.h"
#include"LStack.h"

int main() {
	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");
	int n;
	LStack stack = createLStack();
	while (1) {
		fscanf(fin, "%d", &n);
		if (n== - 1) {
			break;
		}
		fprintf(fout, "%d--->", n);
		while (n > 0) {
			Push(stack, n % 2);
			n /= 2;
		}
		while (!isEmpty(stack)) {
			fprintf(fout, "%d", Pop(stack));
		}
		fprintf(fout, "\n");
	}

	fclose(fin);
	fclose(fout);
}