#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int gpos = atoi(argv[1]);

	printf("gpos =  %d\n\n", gpos);

	while (gpos) {
		printf("%d\n", gpos);
		gpos--;
	}

	return 0;
}
