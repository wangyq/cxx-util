/*
 * test_main.cxx
 *
 *  Created on: 2016年1月9日
 *      Author: wang
 */

#include <memory>
#include <iostream>

#include "util.h"
using namespace std;


void test_endian(){
	cout<<"BigEndian is : "<<is_bigendian()<<endl;
}

void test_run(){
	test_endian();
}
