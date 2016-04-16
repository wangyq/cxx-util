/*
 * func_map.h
 *
 *  Created on: 2016年1月9日
 *      Author: wang
 */

#ifndef SRC_INCLUDE_FUNC_MAP_H_
#define SRC_INCLUDE_FUNC_MAP_H_

typedef void (*PFUNC_VAR)(...);
typedef void (*PFUNC_VOID)();

#define BEGIN_FUNC_MAP() static void call_module_func_FUNC_MAP() {
#define CALL_FUNC_MAP() do{ call_module_func_FUNC_MAP(); } while(0)

#define FUNC_ITEM(func) {extern void func(); func();}
#define FUNC_ITEM1(func,type1,arg1) {extern void func(type1 ); func((arg1));}
#define FUNC_ITEM2(func,type1,arg1,type2,arg2) {extern void func(type1 ,type2 ); func((arg1),(arg2));}
#define FUNC_ITEM3(func,type1,arg1,type2,arg2,type3,arg3) {extern void func(type1 ,type2 ,type3 ); func((arg1),(arg2),(arg3));}
#define FUNC_ITEM4(func,type1,arg1,type2,arg2,type3,arg3,type4,arg4) {extern void func(type1 ,type2 ,type3 ,type4 ); func((arg1),(arg2),(arg3),(arg4));}

//whether call the function!
#define RUN_FUNC_IF(bRun,func) {extern void func(); if(bRun) func();}
#define FUNC_ITEM1_IF(bRun,func,type1,arg1) {extern void func(type1 ); if(bRun) func((arg1));}
#define FUNC_ITEM2_IF(bRun,func,type1,arg1,type2,arg2) {extern void func(type1 ,type2 ); if(bRun) func((arg1),(arg2));}
#define FUNC_ITEM3_IF(bRun,func,type1,arg1,type2,arg2,type3,arg3) {extern void func(type1 ,type2 ,type3 ); if(bRun) func((arg1),(arg2),(arg3));}
#define FUNC_ITEM4_IF(bRun,func,type1,arg1,type2,arg2,type3,arg3,type4,arg4) {extern void func(type1 ,type2 ,type3 ,type4 ); if(bRun) func((arg1),(arg2),(arg3),(arg4));}

#define END_FUNC_MAP() }

#endif /* SRC_INCLUDE_FUNC_MAP_H_ */
