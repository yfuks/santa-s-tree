#include <stdio.h>

#define HauteurSapin 25

int main(void)
{
	int espaces;
	int r;
	int line;

	line = 0;
	while (line < HauteurSapin)
	{
		espaces = (HauteurSapin * 3) / 2;
		while (espaces > (line * 2 + 1 - 4 * (line / 4)) / 2)
		{
			printf(" ");
			espaces--;
		}
		r = 0;
		while (r < (line * 2 + 1 - 4 * (line / 4))) 
		{
			printf("#");
			r++;
		}
		printf("\n");
		line++;
	}
	return 0;
}
