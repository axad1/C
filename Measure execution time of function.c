#include <stdio.h>
#include <time.h>

void function()
{
	int result = 0;
	for (int i = 0; i < 400000000; i++)
		result = i + 1;
}

int main()
{
	clock_t start, end;
	double time;

	puts("start");
	start = clock();

	function();

	end = clock();
	puts("end");

	time = (end - time) / CLOCKS_PER_SEC;
	printf("Execution Time: %fs\n", time);
}
