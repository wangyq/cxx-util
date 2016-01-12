/*
 * func_map.cxx
 *
 *  Created on: 2016年1月9日
 *      Author: wang
 */

#include <iostream>
#include <stdarg.h>

#include "func_map.h"

using namespace std;


//typedef void (*PFUNC_VAR)(...) ;

void func_map(PFUNC_VAR pfunc, ...)
{

    va_list args;
    va_start(args,pfunc);

    (*pfunc)(args);

    va_end(args);

    return ;
}


void call_module_funcs() {
	// error when compiler!
	//extern void first_prime(...);
	//extern void do_prime_test();
	//first_prime(10);

	//extern void do_prime_test();
	typedef void (*PFUNC)();
	PFUNC test_func[] = {
	//start_icpc2014,
			//do_prime_test,
			NULL //end of the signal
			};

	//for(unsigned int i=0;i<sizeof(test_func)/sizeof(PFUNC);i++)
	for (PFUNC *pfunc = test_func; *pfunc; pfunc++) {
		//test_func[i]();
		(*pfunc)();   //more efficient.
	}

	cout << "hello,world! size of (long double) is: " << sizeof(long double)
			<< endl;
}

