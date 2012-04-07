#include <stdio.h>
#include <stdlib.h>


#include "util.h"


void test_endian()
{
	if( is_bigendian() ){
		printf(" system is bigendian \n");
	} else {
		printf(" system is little endian \n");
	}
}
int main()
{
	test_endian();
	return 0;
}
