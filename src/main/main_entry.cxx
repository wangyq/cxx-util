/*
 * main_entry.cxx
 *
 *  Created on: 2016年1月12日
 *      Author: wang
 */
#include <memory>
#include <iostream>
#include <iomanip>

#include "util.h"
using namespace std;
/**
 *
 */
void printFullArrayTree(int depth,int gap){
    if( depth <=0 ) return;
    string strSpan;
    int i,j;
    int span =1; //, gap=4;

    strSpan.append(((1<<(depth-1))-1)*gap,' ');

    int index = 0;                 //first value of index
    for(i=1;i<=depth;i++){
        cout<<strSpan;          //print span first.
        strSpan.erase(0,span*gap);                     //erase the last space
        span*=2;
        for(j=0;j<span;j++,index++){
            cout<<setw(gap)<<index;          //print index
        }
        cout<<endl;

    }
}


void hello_world() {
    printFullArrayTree(4,3);
    //printFullArrayTree(8,4);
    cout << "Hello, world!" << endl;
}


/**
 *
 */
void module_run() {

    hello_world();
}
