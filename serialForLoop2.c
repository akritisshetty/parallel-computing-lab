// Serially printing n iterations

#include <stdio.h>
int main(void) {
	int n;

	printf("Enter n: ");
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		printf("Thread %d executed.\n", i);
	}

	return 0;
}
