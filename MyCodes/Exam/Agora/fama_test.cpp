/*
 * @Autor: zcshen
 * @Date: 2020-12-12 17:50:33
 * @Description:
 */

#include <iostream>
#include <vector>

using namespace std;

bool DoJob(uint32_t max, uint32_t min, uint32_t& output) {
    if (1 == max || 1 == min) {
        cout << "YES" << endl;
        return true;
    }

    uint32_t divisor = 0;
    while (0 != min) {
        divisor = max % min;
        max = min;
        min = divisor;
    }

    if (1 == max) {
        cout << "YES" << endl;
        return true;
    }

    output = max;

    return false;
}

void IsWeightAll(const vector< uint32_t >& input) {
    size_t len = input.size();
    uint32_t divisor = 0;
    uint32_t max = input[0];
    bool flag = false;
    for (auto i = 1; i < len; ++i) {
        if (max > input[i]) {
            if (DoJob(max, input[i], divisor)) {
                flag = true;
                break;
            }
        }
        else {
            if (DoJob(input[i], max, divisor)) { 
                flag = true;
                break;
            }
        }
        max = divisor;
    }

    if (!flag) {
        cout << "NO" << endl;
    }
}

int main(int argc, char** argv) {
    uint32_t fama_type = 0;
    vector< uint32_t > fama_weight;
    uint32_t weight = 0;

    while (cin >> fama_type) {
        fama_weight.clear();

        for (auto i = 0; i < fama_type; ++i) {
            cin >> weight;
            fama_weight.push_back(weight);
        }

        IsWeightAll(fama_weight);
    }

    return 0;
}
