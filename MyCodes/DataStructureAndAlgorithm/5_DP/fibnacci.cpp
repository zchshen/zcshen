/*
 * @Autor: zcshen
 * @Date: 2020-12-21 14:36:07
 * @Description: 斐波那契数列
 */

#include <iostream>

using namespace std;

// 递归版本
int FibnacciRecursion(int n) {
    return (n < 2 ? n : FibnacciRecursion(n - 1) + FibnacciRecursion(n - 2));
}

// 迭代版本
int FibnacciIteration(int n) {
    int f = 0;
    int g = 1;
    while (0 < n--) {
        g = f + g;
        f = g - f;
    }

    return f;
}

int main(int argc, char** argv) {
    int n = 0;
    cin >> n;

    cout << "Fib of Recursion: " << FibnacciRecursion(n) << endl;
    cout << "Fib of Iteration: " << FibnacciIteration(n) << endl;
    return 0;
}