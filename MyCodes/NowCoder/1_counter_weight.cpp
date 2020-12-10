/*
 * @Autor: zcshen
 * @Date: 2020-12-08 14:28:44
 * @Description: 砝码称重: n种重量的砝码，重量为m1的砝码有x1个，
 * 砝码为mn的砝码有xn个
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

uint32_t count_weight (const vector< uint32_t >& input, uint32_t size) {
    set< uint32_t > counter{ 0 };
    for (auto i = 0; i < size; i++) {
        set< uint32_t > temp_counter (counter);
        for (const auto iter : temp_counter) {
            counter.insert (input[i] + iter);
        }
    }

    return counter.size ();
}

int main (int argc, char** argv) {
    // 输入砝码不同砝码重量的类型数
    uint32_t weight_type = 0;
    // 每种砝码的重量
    uint32_t weight[10] = { 0 };
    // 各种重量砝码集合
    vector< uint32_t > weight_vec;
    uint32_t counter = 0;
    while (cin >> weight_type) {
        weight_vec.clear ();
        for (auto i = 0; i < weight_type; i++) {
            cin >> weight[i];
        }

        for (auto i = 0; i < weight_type; i++) {
            cin >> counter;
            for (auto j = 0; j < counter; j++) {
                weight_vec.push_back (weight[i]);
            }
        }

        cout << count_weight (weight_vec, weight_vec.size ()) << endl;
    }
    return 0;
}