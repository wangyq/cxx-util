/*
 * Stack.h
 *
 *  Created on: 2016年1月12日
 *      Author: wang
 */

#ifndef SRC_INCLUDE_STACK_H_
#define SRC_INCLUDE_STACK_H_

template<class T>
class Stack {

protected:
	enum {
		INIT_SIZE = 16,
		INC_SIZE = 16,
		ENUM_NULL
	};
	unsigned int m_iCapacity;
	unsigned int m_iIncSize;  //every time the increment size.
	unsigned int m_iCur;      //cur top of element.
	T* m_pData ;
public:
	Stack();
	Stack(unsigned int iInitialSize);
	Stack(unsigned int iInitialSize, int iIncSize);
	virtual ~Stack();

public:
	unsigned int Size();
	bool isEmpty();
	bool isFull();
	T Pop();
	bool Push(const T& );
	T& Top();
};

template<class T>
Stack<T>::Stack() {
	// TODO Auto-generated constructor stub
	//Stack<T>(INIT_SIZE,INC_SIZE);
	m_iCapacity = INIT_SIZE;
	m_iIncSize = INC_SIZE;
	m_iCur = 0;
	m_pData = new T[m_iCapacity];
	if( m_pData == 0 ) {
		m_iCapacity = 0;
	}
}

template<class T>
Stack<T>::Stack(unsigned int iInitialSize) {
	// TODO Auto-generated constructor stub
	//Stack<T>(iInitialSize,INC_SIZE);
	m_iCapacity = iInitialSize;
	m_iIncSize = INC_SIZE;
	m_iCur = 0;
	m_pData = new T[m_iCapacity];
	if( m_pData == 0 ) {
		m_iCapacity = 0;
	}
}
template<class T>
Stack<T>::Stack(unsigned int iInitialSize, int iIncSize) {
	// TODO Auto-generated constructor stub
	m_iCapacity = iInitialSize;
	m_iIncSize = iIncSize;
	m_iCur = 0;
	m_pData = new T[m_iCapacity];
	if( m_pData == 0 ) {
		m_iCapacity = 0;
	}
}
template<class T>
Stack<T>::~Stack() {
	// TODO Auto-generated destructor stub
	delete  [] m_pData;
}

template<class T>
unsigned int Stack<T>::Size() {
	// TODO Auto-generated destructor stub
	return m_iCur ;
}

template<class T>
bool Stack<T>::isEmpty() {
	// TODO Auto-generated destructor stub
	return m_iCur == 0;
}

template<class T>
bool Stack<T>::isFull() {
	// TODO Auto-generated destructor stub
	return m_iCur >= m_iCapacity;
}

//===================
template<class T>
T& Stack<T>::Top() {
	// TODO Auto-generated destructor stub
	if( isEmpty() ) return 0;
	return m_pData[m_iCur-1];
}

template<class T>
T Stack<T>::Pop() {
	// TODO Auto-generated destructor stub
	if( isEmpty() ) return 0;
	m_iCur --;
	return m_pData[m_iCur];
}

template<class T>
bool Stack<T>::Push(const T& ele) {
	// TODO Auto-generated destructor stub
	if( isFull() ) {
		T* pNew = new T[m_iCapacity+m_iIncSize];
		if( pNew == 0 ) return false;
		for(unsigned int i=0;i<m_iCur;i++){//copy data
			pNew[i] = m_pData[i];
		}
		m_iCapacity += m_iIncSize;   //new capacity
	}
	m_pData[m_iCur ++] = ele;     //add element and pointer plus one.
	return true;
}

#endif /* SRC_INCLUDE_STACK_H_ */
