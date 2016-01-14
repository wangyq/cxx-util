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
    typedef struct tagTreeNode {
        T data;
        struct tagTreeNode* left, *right;
        tagTreeNode(T data) {
            this->data = data;
            this->left = this->right = 0;
        }
    } TreeNode, *PTreeNode;

    TreeNode* pRoot;  //the root node.

    /**
     *
     */
    void destroyTree(TreeNode* pNode) {
        if (pNode == 0)
            return;
        destroyTree(pNode->left);
        destroyTree(pNode->right);
        delete pNode;
    }

    TreeNode* createPreOrderInternal(T* val, int len, int& index,
            const T& nulVal) {
        TreeNode* pNode = 0;

        if (index < len) {
            T data = val[index];
            index++;

            if (data != nulVal) {
                pNode = new TreeNode(data);
                pNode->left = createPreOrderInternal(val, len, index, nulVal);
                pNode->right = createPreOrderInternal(val, len, index, nulVal);
            }
        }

        return pNode;
    }

    void printInOrderInternal(TreeNode* pNode,
            void (*pPrintFunc)(const T& val)) {
        if (pNode != 0) {  //not null
            printInOrderInternal(pNode->left, pPrintFunc);
            pPrintFunc(pNode->data);
            printInOrderInternal(pNode->right, pPrintFunc);
        }
    }
    void printPreOrderInternal(TreeNode* pNode,
            void (*pPrintFunc)(const T& val)) {
        if (pNode != 0) {  //not null
            pPrintFunc(pNode->data);
            printPreOrderInternal(pNode->left, pPrintFunc);
            printPreOrderInternal(pNode->right, pPrintFunc);
        }
    }
    void printPostOrderInternal(TreeNode* pNode,
            void (*pPrintFunc)(const T& val)) {
        if (pNode != 0) {  //not null
            printPostOrderInternal(pNode->left, pPrintFunc);
            printPostOrderInternal(pNode->right, pPrintFunc);
            pPrintFunc(pNode->data);
        }
    }
    void travelPreOrder(void (*pPrintFunc)(const T& val)) {
        Stack<TreeNode*> st;

        TreeNode* pNode = pRoot;

        do {
            if (pNode != 0) {
                pPrintFunc(pNode->data); //visit current node.
                st.Push(pNode->right);
                pNode = pNode->left;  //next node.
            } else if (!st.isEmpty()) {
                pNode = st.Pop();
            } else {
                break;  //finished!
            }
        } while (true);

//#define VISIT_CUR_NODE_PREORDER(pNode,stack,pfunc)  \
//		do{                                           \
//		pfunc(pNode->data);                           \
//		if (pNode->right != 0) {                      \
//			stack.Push(pNode->right);                  \
//		}                                                            \
//		pNode = pNode->left;}while(0)
//
//		TreeNode* pNode = pRoot;
//
//		do {
//			if (pNode != 0) {
//				VISIT_CUR_NODE_PREORDER(pNode,st,pPrintFunc)
//				;
//			} else if (!st.isEmpty()) {
//				pNode = st.Pop();
//				VISIT_CUR_NODE_PREORDER(pNode,st,pPrintFunc)
//				;
//			} else {
//				break;  //finished!
//			}
//		} while (true);

//		do {
//			if (pNode != 0) {
//				pPrintFunc(pNode->data); //visit current node.
//				if (pNode->right != 0) {
//					st.Push(pNode->right);
//				}
//				pNode = pNode->left;  //next node.
//			} else if (!st.isEmpty()) {
//				pNode = st.Pop();
//				pPrintFunc(pNode->data); //visit current node.
//				if (pNode->right != 0) {
//					st.Push(pNode->right);
//				}
//				pNode = pNode->left;  //next node.
//			} else {
//				break;
//			}
//
//		} while (true);

    }
    void travelPreOrder_one(void (*pPrintFunc)(const T& val)) {
        Stack<TreeNode*> st;

        if (pRoot == 0)
            return;
        TreeNode* pNode = pRoot;

        while (true) {

            pPrintFunc(pNode->data); //visit current node.

            if (pNode->left != 0) { //left node is not null!
                if (pNode->right != 0) {
                    st.Push(pNode->right);
                }
                pNode = pNode->left;  //next node.
            } else if (pNode->right != 0) {
                pNode = pNode->right;
            } else { //left and right child is null. so visit it.

                if (st.isEmpty()) {
                    break;  //end
                }
                pNode = st.Pop();
            } //end of if

        }

    }

    void travelInOrder(void (*pPrintFunc)(const T& val)) {
        Stack<TreeNode*> st;

        TreeNode* pNode = pRoot;
        do {
            if (pNode != 0) {
                st.Push(pNode);
                pNode = pNode->left;
            } else if (!st.isEmpty()) {
                pNode = st.Pop();
                pPrintFunc(pNode->data);
                pNode = pNode->right;
            } else {
                break;  //finished!
            }
        } while (true);
    }
    void travelInOrder_one(void (*pPrintFunc)(const T& val)) {
        Stack<TreeNode*> st;
        bool bFinished = false;

        if (pRoot == 0)
            return;
        TreeNode* pNode = pRoot;

        while (true) {
            if (pNode->left != 0) { //left node is not null!
                st.Push(pNode);  //current node push into stack
                pNode = pNode->left;  //next node.
            } else {
                //visit this node.
                pPrintFunc(pNode->data);

                if (pNode->right != 0)
                    pNode = pNode->right;
                else {
                    bFinished = true;
                    while (!st.isEmpty()) {
                        //
                        pNode = st.Pop();
                        pPrintFunc(pNode->data);
                        if (pNode->right != 0) {
                            pNode = pNode->right;
                            bFinished = false;
                            break;

                        }
                    }  //end of while
                    if (bFinished)
                        break;
                }

            }  //end of else

        }

    }
    void travelPostOrder(void (*pPrintFunc)(const T& val)) {
        Stack<TreeNode*> st;

        TreeNode* pNode = pRoot;
        do {
            if (pNode != 0) {
                st.Push(pNode);
                pNode = pNode->left;
            } else {  //pNode == 0
                while (!st.isEmpty()) {
                    if (st.Top()->right == pNode) { //equal 0 or last visited node.
                        pNode = st.Pop();
                        pPrintFunc(pNode->data);
                    } else {
                        pNode = st.Top()->right;
                        break;
                    }
                }  //end of while.
                if (st.isEmpty())
                    break;     //end of all travel.
            }
        } while (true);
    }
    void travelPostOrder_one(void (*pPrintFunc)(const T& val)) {
        Stack<TreeNode*> st;
        bool bFinished = false;

        if (pRoot == 0)
            return;
        TreeNode* pNode = pRoot;

        while (true) {
            if (pNode->left != 0) { //left node is not null!
                st.Push(pNode);  //current node push into stack
                pNode = pNode->left;  //next node.
            } else if (pNode->right != 0) {
                st.Push(pNode);  //current node push into stack
                pNode = pNode->right;
            } else { //left and right child is null. so visit it.
                //visit this node.
                pPrintFunc(pNode->data);

                bFinished = true;
                while (!st.isEmpty()) {
                    if ((pNode == st.Top()->right) || (st.Top()->right == 0)) {
                        //
                        pNode = st.Pop();
                        pPrintFunc(pNode->data);
                    } else { //st.Top()->right is not null.
                        pNode = st.Top()->right;
                        bFinished = false;
                        break;
                    }
                } //end of while
                if (bFinished)
                    break;
            } //end of if

        }

    }
    //====================================
public:
    BinTree() {
        pRoot = 0;
    }

    virtual ~BinTree() {
        destroyTree(pRoot);
        pRoot = 0;
    }

    void createPreOrder(T* val, int len, const T& nulVal) {
        if (val == 0)
            return;
        int index = 0;
        pRoot = createPreOrderInternal(val, len, index, nulVal);
    }

    void printInOrder(void (*pPrintFunc)(const T& val)) {
        printInOrderInternal(pRoot, pPrintFunc);
        travelInOrder(pPrintFunc);
    }
    void printPreOrder(void (*pPrintFunc)(const T& val)) {
        printPreOrderInternal(pRoot, pPrintFunc);
        travelPreOrder(pPrintFunc);
    }
    void printPostOrder(void (*pPrintFunc)(const T& val)) {
        printPostOrderInternal(pRoot, pPrintFunc);

        travelPostOrder(pPrintFunc);
    }
};

#endif /* SRC_INCLUDE_BINTREE_H_ */
