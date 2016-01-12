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
#include "ArrayQueue.h"

using namespace std;

void test_endian() {
	cout << "BigEndian is : " << is_bigendian() << endl;
}
void test_stack() {
	Stack<int> st;
	int i = 0;
	for (i = 10; i < 100; i++) {
		st.Push(i);
	}

	while (!st.isEmpty()) {
		cout << st.Pop() << ",";
	}
	cout << endl;
}

void test_queue() {
	ArrayQueue<int> queue;
	for (int i = 10; i < 100; i++) {
		queue.EnQueue(i);
	}
	while (!queue.isEmpty()) {
		cout << queue.Dequeue() << ",";
	}
	cout << endl;
}
void test_run() {
	test_endian();
	test_stack();
	test_queue();
}
