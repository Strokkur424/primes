#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//				            b  m  k
const unsigned int amount = 1000000000;
const int bufferSize = 5761455; // precalculated for 1b

int main()
{
	char* a = malloc(amount / 2 + 1);

	int* out = malloc(bufferSize * 4);
	int* current = out;

	// 2 is the first prime num
	*current = 2;
	current++;

	printf("Starting...\n");

	int max = (int) sqrt((double) amount);
	for (int n = 3; n < amount; n += 2)
	{
		int i = (n / 2) - 1;
		if (*(a + i))
		{
			continue;
		}

		*current = n;
		current++;
		if (n > max)
		{
			continue;
		}

		for (int j = n * n; j < amount; j += n + n)
		{
			*(a + (j / 2 - 1)) = 1;
		}
	}

	printf("\nDone!\n");

	int amountFound = current - out;
	printf("Found %i primes.\n\n", amountFound);

	free(out);
	free(a);
}
