/*
 * @Autor: zcshen
 * @Date: 2021-01-05 15:22:40
 * @Description: 利用栈结构判断括号成对情况
 */

#include "my_stack.h"

using namespace std;
using namespace zcshen;

// 支持 () [] {}
void ParenMatch(const char exp[], int lo, int hi) {
    Stack<char> s;

    for (int i=lo; i<hi; i++) {
        if ('(' == exp[i] || '[' == exp[i] || '{' == exp[i]) {
            s.Push(exp[i]);
        }
        else if (!s.Empty()) {
            char pop = s.Pop();
            if ((')' == exp[i] && '(' != pop) || (']' == exp[i] && '[' != pop) || ('}' == exp[i] && '{' != pop)) {
                cout << "NO Matched" << endl;
                return;
            }
        }
        else {
            cout <<"No Matched" << endl;
            return;
        }
    }

    cout << "Matched" << endl;
}

int main (int argc, char** argv) {
    string input1 = "(((())))";
    ParenMatch(input1.c_str(), 0, input1.length());

    string input2 = "((())))";
    ParenMatch(input2.c_str(), 0, input2.length());

    string input3 = "((()))";
    ParenMatch(input3.c_str(), 0, input3.length());

    string input4 = "()))";
    ParenMatch(input4.c_str(), 0, input4.length());

    string input5 = "{([])}";
    ParenMatch(input5.c_str(), 0, input5.length());

    string input6 = "{[(])}";
    ParenMatch(input6.c_str(), 0, input6.length());

    string input7 = "{(])}";
    ParenMatch(input7.c_str(), 0, input7.length());

    return 0;
}
