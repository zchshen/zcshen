/*
 * @Autor: zcshen
 * @Date: 2021-01-10 08:02:11
 * @Description: 树遍历
 */

#include <iostream>
#include "bin_tree.h"
#include "my_stack.h"
#include "my_queue.h"

using namespace std;
using namespace zcshen;

// 递归方式实现树的先序遍历
template < typename T, typename VST >
void PreTraverRecurse(BinNodePosition(T) x, VST& visit) {
    if (nullptr == x) {
        return;
    }

    visit(x->data);

    PreTraverRecurse(x->lchild, visit);
    PreTraverRecurse(x->rchild, visit);
}

// 迭代方式实现先序遍历
template < typename T, typename VST >
void PreTraverIter1(BinNodePosition(T) x, VST& visit) {
    Stack< BinNodePosition(T) > help_stack;
    if (nullptr != x) {
        help_stack.Push(x);
    }

    while (!help_stack.Empty()) {
        x = help_stack.Pop();
        visit(x->data);

        // 先入右孩子
        if (nullptr != x->rchild) {
            help_stack.Push(x->rchild);
        }

        // 后入左孩子
        if (nullptr != x->lchild) {
            help_stack.Push(x->lchild);
        }
    }
}

// 迭代方式2 实现先序遍历
template < typename T, typename VST >
void VisitAlongLeftBranch(BinNodePosition(T) x, VST& visit, Stack< BinNodePosition(T) >& help_stack) {
    while (nullptr != x) {
        visit(x->data);
        help_stack.Push(x->rchild);
        x = x->lchild;
    }
}

template < typename T, typename VST >
void PreTraverIter2(BinNodePosition(T) x, VST& visit) {
    Stack< BinNodePosition(T) > help_stack;
    while (true) {
        VisitAlongLeftBranch(x, visit, help_stack);
        if (help_stack.Empty()) {
            break;
        }

        x = help_stack.Pop();
    }
}

// 递归方式实现树的中序遍历
template < typename T, typename VST >
void InTraverRecurse(BinNodePosition(T) x, VST& visit) {
    if (nullptr == x) {
        return;
    }

    InTraverRecurse(x->lchild, visit);

    visit(x->data);

    InTraverRecurse(x->rchild, visit);
}

// 迭代方式实现中序遍历
template <typename T>
void GoAlongLeftBranch(BinNodePosition(T) x, Stack<BinNodePosition(T)>& help_stack) {
    while (nullptr != x) {
        help_stack.Push(x);
        x = x->lchild;
    }
}

template < typename T, typename VST >
void InTraverIter(BinNodePosition(T) x, VST& visit) {
    Stack< BinNodePosition(T) > help_stack;
    while (true) {
        GoAlongLeftBranch(x, help_stack);
        if (help_stack.Empty()) {
            break;
        }
        x = help_stack.Pop();
        visit(x->data);
        x = x->rchild;
    }
}

// 层次遍历
template <typename T, typename VST>
void TraverLevel(BinNodePosition(T) x, VST& visit){
    Queue<BinNodePosition(T)> help_queue;

    if (nullptr != x) {
        help_queue.Enqueue(x);
    }

    BinNodePosition(T) node = nullptr;
    while (!help_queue.Empty()) {
        node = help_queue.Dequeue();
        visit(node->data);

        if (nullptr != node->lchild) {
            help_queue.Enqueue(node->lchild);
        }

        if (nullptr != node->rchild) {
            help_queue.Enqueue(node->rchild);
        }
    }
}

int main(int argc, char** argv) {
    BinNodePosition(int) root = new BinNode< int >(1);
    BinNodePosition(int) node = nullptr;
    node = root->InsertAsLChild(2);
    node->InsertAsLChild(3);
    node->InsertAsRChild(4);
    node = root->InsertAsRChild(5);
    node->InsertAsLChild(6);
    node->InsertAsRChild(7);

    TreeVisit< int > visit;
    // 先序
    cout << "PreRecurse: " << endl;
    PreTraverRecurse(root, visit);

    cout << "PreIterator 1: " << endl;
    PreTraverIter1(root, visit);

    cout << "PreIterator 2: " << endl;
    PreTraverIter2(root, visit);

    // 中序
    cout << "InRecurse: " << endl;
    InTraverRecurse(root, visit);

    cout << "InIterator: " << endl;
    InTraverIter(root, visit);

    // 层次遍历
    cout << "Traver Level" << endl;
    TraverLevel(root, visit);

    return 0;
}
