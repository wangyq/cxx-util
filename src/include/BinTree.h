/*
 * BinTree.h
 *
 *  Created on: 2016年1月12日
 *      Author: wang
 */

#ifndef SRC_INCLUDE_BINTREE_H_
#define SRC_INCLUDE_BINTREE_H_

template<class T>
class BinTree {

protected:
	typedef struct tagTreeNode{
		T data;
		struct tagTreeNode* left,*right;
		tagTreeNode(T data){
			this->data = data;
			this->left = this->right = 0;
		}
	}TreeNode;

	TreeNode* pRoot;  //the root node.

	/**
	 *
	 */
	void destroyTree(TreeNode* pNode){
		if( pNode == 0 ) return;
		destroyTree(pNode->left);
		destroyTree(pNode->right);
		delete pNode;
	}

	TreeNode* createPreOrderInternal(T* val, int len, int& index, const T& nulVal){
		TreeNode* pNode = 0;

		if( index < len ){
			T data = val[index];
			index ++;

			if( data != nulVal ){
				pNode = new TreeNode(data);
				pNode->left = createPreOrderInternal(val,len,index,nulVal);
				pNode->right = createPreOrderInternal(val,len,index,nulVal);
			}
		}

		return pNode;
	}

	void printInOrderInternal(TreeNode* pNode, void (*pPrintFunc)(const T& val)){
		if( pNode != 0 ){//not null
			printInOrderInternal(pNode->left,pPrintFunc);
			pPrintFunc(pNode->data);
			printInOrderInternal(pNode->right,pPrintFunc);
		}
	}
	void printPreOrderInternal(TreeNode* pNode, void (*pPrintFunc)(const T& val)){
		if( pNode != 0 ){//not null
			pPrintFunc(pNode->data);
			printPreOrderInternal(pNode->left,pPrintFunc);
			printPreOrderInternal(pNode->right,pPrintFunc);
		}
	}
	void printPostOrderInternal(TreeNode* pNode, void (*pPrintFunc)(const T& val)){
		if( pNode != 0 ){//not null
			printPostOrderInternal(pNode->left,pPrintFunc);
			printPostOrderInternal(pNode->right,pPrintFunc);
			pPrintFunc(pNode->data);
		}
	}
	//====================================
public:
	BinTree(){
		pRoot = 0;
	}

	virtual ~BinTree(){
		destroyTree(pRoot);
		pRoot = 0;
	}

	void createPreOrder(T* val, int len, const T& nulVal){
		if( val == 0 ) return;
		int index = 0;
		pRoot = createPreOrderInternal(val,len,index,nulVal);
	}

	void printInOrder(void (*pPrintFunc)(const T& val)){
		printInOrderInternal(pRoot,pPrintFunc);
	}
	void printPreOrder(void (*pPrintFunc)(const T& val)){
		printPreOrderInternal(pRoot,pPrintFunc);
	}
	void printPostOrder(void (*pPrintFunc)(const T& val)){
		printPostOrderInternal(pRoot,pPrintFunc);
	}
};




#endif /* SRC_INCLUDE_BINTREE_H_ */
