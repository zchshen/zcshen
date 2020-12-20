/*
 * @Autor: zcshen
 * @Date: 2020-12-20 08:40:25
 * @Description: 通用函数集
 */

#include <iostream>

using namespace std;

namespace zcshen_common_function
{
    /**
     * @brief: 打印集合内各个元素值
     * @param: 元素集合
     * @return: void
     */
    template < typename T >
    void ShowElememts(const T& elements) {
        for (const auto& element : elements) {
            cout << element << " ";
        }
        cout << endl;
    }

}  // namespace zcshen_common_function
