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

    TreeNode* createPreOrderInternal(T* val, int len, int& index, const T& nulVal) {
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

    void printInOrderInternal(TreeNode* pNode, void (*pPrintFunc)(const T& val)) {
        if (pNode != 0) {  //not null
            printInOrderInternal(pNode->left, pPrintFunc);
            pPrintFunc(pNode->data);
            printInOrderInternal(pNode->right, pPrintFunc);
        }
    }
    void printPreOrderInternal(TreeNode* pNode, void (*pPrintFunc)(const T& val)) {
        if (pNode != 0) {  //not null
            pPrintFunc(pNode->data);
            printPreOrderInternal(pNode->left, pPrintFunc);
            printPreOrderInternal(pNode->right, pPrintFunc);
        }
    }
    void printPostOrderInternal(TreeNode* pNode, void (*pPrintFunc)(const T& val)) {
        if (pNode != 0) {  //not null
            printPostOrderInternal(pNode->left, pPrintFunc);
            printPostOrderInternal(pNode->right, pPrintFunc);
            pPrintFunc(pNode->data);
        }
    }
    void travelPreOrder(void (*pPrintFunc)(const T& val)) {
        Stack<TreeNode*> st;

//        TreeNode* pNode = pRoot;

//        do {
//            if (pNode != 0) {
//                pPrintFunc(pNode->data); //visit current node.
//                st.Push(pNode->right);
//                pNode = pNode->left;  //next node.
//            } else if (!st.isEmpty()) {
//                pNode = st.Pop();
//            } else {
//                break;  //finished!
//            }
//        } while (true);

        if (pRoot == 0) {
            return;
        }
        TreeNode* pNode = pRoot;
        do {
            pPrintFunc(pNode->data); //visit current node.
            if (pNode->left != 0) {
                if (pNode->right != 0) {
                    st.Push(pNode->right);
                }
                pNode = pNode->left;
            } else if (pNode->right != 0) { //pNode->left must be null
                pNode = pNode->right;
            } else if (!st.isEmpty()) { // the left and right of pNode must be null
                pNode = st.Pop();
            } else {
                break;
            }
        } while (true);

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

    void travelPostOrder(void (*pPrintFunc)(const T& val)) {
        Stack<TreeNode*> st;

//        TreeNode* pNode = pRoot;
//        do {
//            if (pNode != 0) {
//                st.Push(pNode);
//                pNode = pNode->left;
//            } else {  //pNode == 0
//                while (!st.isEmpty()) {
//                    if (st.Top()->right == pNode) { //equal 0 or last visited node.
//                        pNode = st.Pop();
//                        pPrintFunc(pNode->data);
//                    } else {
//                        pNode = st.Top()->right;
//                        break;
//                    }
//                }  //end of while.
//                if (st.isEmpty()){
//                    break;     //end of all travel.
//                }
//            }
//        } while (true);

        if (pRoot == 0)
            return;
        TreeNode* pNode = pRoot;
        do {  //make sure pNode must not be null.
            if (pNode->left != 0) {
                st.Push(pNode);
                pNode = pNode->left;
            } else if (pNode->right != 0) {  // pNode->left is null
                st.Push(pNode);
                pNode = pNode->right;
            } else { // left and right of pNode is null.

                pPrintFunc(pNode->data); //visit current node
                while (!st.isEmpty()) {
                    if ((st.Top()->right == pNode) || (st.Top()->right == 0)) { //equal 0 or last visited node.
                        pNode = st.Pop();
                        pPrintFunc(pNode->data);
                    } else { //
                        pNode = st.Top()->right;  // Here must not be null.
                        break;
                    }
                } //end of while
                if (st.isEmpty()) { // All is finished!
                    break;     //end of all travel.
                }
            }     //end of else!
        } while (true);
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
    //

};

#endif /* SRC_INCLUDE_BINTREE_H_ */
