/*
 * @Autor: zcshen
 * @Date: 2021-01-05 13:53:32
 * @Description: 进制转换 - 支持16进制内
 */

#include "my_stack.h"

using namespace std;
using namespace zcshen;

void BaseConvert(Stack< char >& result, int n, int base) {
    static char Base[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

    while (n > 0) {
        result.Push(Base[n % base]);
        n /= base;
    }
}

void PrintStack(Stack< char >& s) {
    while (!s.Empty()) {
        cout << s.Pop();
    }
    cout << endl;
}

int main(int argc, char** argv) {
    Stack< char > result;

    int n1 = 0;
    BaseConvert(result, n1, 2);
    PrintStack(result);
    BaseConvert(result, n1, 5);
    PrintStack(result);
    BaseConvert(result, n1, 16);
    PrintStack(result);

    n1 = 5;
    BaseConvert(result, n1, 2);
    PrintStack(result);
    BaseConvert(result, n1, 5);
    PrintStack(result);
    BaseConvert(result, n1, 16);
    PrintStack(result);

    n1 = 100;
    BaseConvert(result, n1, 2);
    PrintStack(result);
    BaseConvert(result, n1, 5);
    PrintStack(result);
    BaseConvert(result, n1, 16);
    PrintStack(result);

    return 0;
}
