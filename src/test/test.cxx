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
#include "BinTree.h"


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
		queue.EnQueue(i+1);
		queue.Dequeue();
	}
	while (!queue.isEmpty()) {
		cout << queue.Dequeue() << ",";
	}
	cout << endl;
}

void printInt(const int& val){
	cout<<val<<" ";
}
void test_bintree(){
	BinTree<int> tree;
	int val[] = {1,2,0,0,3,4,0,5};
	tree.createPreOrder(val,sizeof(val)/sizeof(int), 0);

	cout<<"InOrder: ";
	tree.printInOrder(printInt); cout<<endl;
	cout<<"PreOrder: ";
	tree.printPreOrder(printInt); cout<<endl;
	cout<<"PostOrder: ";
	tree.printPostOrder(printInt); cout<<endl;

}

/**
 * test run entry
 */
void test_run() {
	test_endian();
	//test_stack();
	test_queue();
	test_bintree();
}
