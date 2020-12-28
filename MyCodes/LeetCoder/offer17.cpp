/*
 * @Autor: zcshen
 * @Date: 2020-12-27 15:08:20
 * @Description: 剑指offer题17
 */


// 输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

// 示例 1:

// 输入: n = 1
// 输出: [1,2,3,4,5,6,7,8,9]
//  

// 说明：

// 用返回一个整数列表来代替打印
// n 为正整数

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <iostream>
#include <vector>
#include "common_function.h"

using namespace std;
using namespace zcshen;

vector< int > printNumbers(int n) {
    if (n < 1) {
        return (vector<int>());
    }

    int temp = 1;
    while ((n--) && (temp *= 10));
    temp -= 1;

    vector<int> ret;
    ret.reserve(temp);
    for (int i = 0; i<temp; i++) {
        ret.push_back(i);
    }

    return ret;
}

int main(int argc, char** argv) {

    ShowElememts(printNumbers(0));
    cout << endl;
    ShowElememts(printNumbers(1));
    cout << endl;
    ShowElememts(printNumbers(3));

    return 0;
}