/*
 * test_main.cxx
 *
 *  Created on: 2016年1月9日
 *      Author: wang
 */

#include <memory>
#include <iostream>

#include "util.h"
#include "Stack.h"

using namespace std;


void test_endian(){
	cout<<"BigEndian is : "<<is_bigendian()<<endl;
}
void test_stack(){
	Stack<int> st;
	int i = 0;
	for(i=10;i<200;i++){
		st.Push(i);
	}

	while(!st.isEmpty() ){
		cout<<st.Pop()<<",";
	}
	cout<<endl;
}

void test_run(){
	test_endian();
	test_stack();
}
