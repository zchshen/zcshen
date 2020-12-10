/*
 * @Autor: zcshen
 * @Date: 2020-12-10 14:20:00
 * @Description: 根据先序与中序遍历顺序，重建二叉树
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 定义树节点
struct BinaryNode {
    int value{ 0 };
    BinaryNode* lchild{ nullptr };
    BinaryNode* rchild{ nullptr };
};

// 根据先序遍历序列和后续遍历序列重建二叉树
BinaryNode* BuildBinaryTree (const int* preorder, const int* inorder, int element_size) {
    if (nullptr == preorder || nullptr == inorder || element_size <= 0) {
        // 空树
        return nullptr;
    }

    BinaryNode* root_node = nullptr;
    try {
        root_node = new BinaryNode ();
    }
    catch (std::bad_alloc&) {
        return nullptr;
    }

    // 构建根节点
    root_node->value = preorder[0];
    
    // 在中序序列中查找根节点位置
    int index = 0;
    while (index < element_size && root_node->value != *(inorder+index)) {
        ++index;
    }

    // 递归的构建左子树
    root_node->lchild = BuildBinaryTree(preorder+1, inorder, index);
    // 递归构建右子树
    root_node->rchild = BuildBinaryTree(preorder+1+index, inorder+index+1, element_size-index-1);

    return root_node;
}

// 利用层次遍历验证结果
void TravLevel (const BinaryNode* bin_tree) {
    if (nullptr == bin_tree) {
        return;
    }

    queue<BinaryNode*> trav_que;
    trav_que.push (const_cast< BinaryNode* > (bin_tree));

    BinaryNode *visit_node = nullptr;
    while (!trav_que.empty()) {
        // 打印
        visit_node = trav_que.front();
        cout << visit_node->value << " ";
        // 出队列
        trav_que.pop();
        // 左孩子入队列
        if (nullptr != visit_node->lchild) {
            trav_que.push (visit_node->lchild);
        }

        if (nullptr != visit_node->rchild) {
            trav_que.push (visit_node->rchild);
        }
    }

    cout << endl;
}

int main (int argc, char** argv) {
    int preorder[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
    int inorder[] = { 4, 7, 2, 1, 5, 3, 8, 6 };

   TravLevel(BuildBinaryTree(preorder, inorder, sizeof(preorder)/sizeof(int)));

    return 0;
}
