#include <math.h>
#include <stdio.h>

#include "cma.h"

int main(int argc, char * argv[]) {
	
	double power = 1;
	int size = 1;
	double output = 0;
	double total = 0;

	if (argc != 2)
	{
		printf("Enter this size of memory to be allocated.\n");	
		return 0;
	}
	
	int mSize = atoi(argv[1]);
	//unsigned char mem[mSize];

	unsigned char* pointer = malloc(mSize);
	
	if (pointer)
	{
		class_memory(pointer, mSize);

		while (class_malloc(size)) 
		{
			size = (int)pow(2.0,power);
			power++;
		} 
	}

	class_stats();

	return 0;
}
