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

uint32_t count_weight(const vector<uint32_t>& input, uint32_t size) {
    vector<uint32_t> counter{0};
    uint32_t tmp = 0;
    for (auto i = 0; i < size; i++) {
        uint32_t end_pos = counter.size();
        for (auto j=0; j<end_pos; j++) {
            counter.push_back(input[i] + counter[j]);
        }
    }

    set<uint32_t> uniq_counter;
    for (const auto iter : counter) {
        uniq_counter.insert(iter);
    }

    for (const auto iter : uniq_counter) {
        cout << iter << " ";
    }
    cout << endl;   

    return uniq_counter.size();
}

int main(int argc, char** argv) {
    // 输入砝码不同砝码重量的类型数
    cout << "Please input the counter[1,10]: ";
    uint32_t weight_type = 0;
    scanf("%u", &weight_type);

    // 每种砝码的重量
    vector<uint32_t> weight(weight_type);
    for (auto i = 0; i < weight_type; i++) {
        cout << "Input the weight[1,2000]: " << endl;
        scanf("%u", &weight[i]);
    }

    // 各种重量砝码集合
    uint32_t counter = 0;
    vector<uint32_t> weight_vec;
    for (auto i = 0; i < weight_type; i++) {
        cout << "Input the counter[1,6]: " << endl;
        scanf("%u", &counter);
        for (auto j = 0; j < counter; j++) {
            weight_vec.push_back(weight[i]);
        }
    }

    // debug info
    for (auto iter : weight_vec) {
        cout << iter << " ";
    }
    cout << endl;

    cout << "result counter is: " << count_weight(weight_vec, weight_vec.size())
         << endl;

    return 0;
}