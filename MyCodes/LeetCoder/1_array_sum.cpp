/*
 * @Autor: zcshen
 * @Date: 2020-12-14 12:22:56
 * @Description: 数组元素求和
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
 * 示例:
 * 给定 nums = [2, 7, 11, 15], target = 9
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector< int > TwoSum(const vector< int >& nums, int target) {
    vector< int > sum_index;
    auto input_size = nums.size();

    // <data,position>
    unordered_map< int, int > data_map;
    unordered_map< int, int >::iterator find_iter;
    for (auto index = 0; index < input_size; ++index) {
        find_iter = data_map.find(nums[index]);
        if (data_map.end() == find_iter) {
            // 插入当前元素
            data_map.insert(make_pair(nums[index], index));
        }

        // 进一步查找
        find_iter = data_map.find(target - nums[index]);
        if (data_map.end() != find_iter && index != find_iter->second) {
            // 找到
            index < find_iter->second ? sum_index.push_back(index),
                sum_index.push_back(find_iter->second) : sum_index.push_back(find_iter->second), sum_index.push_back(index);
        }
    }

    return sum_index;
}

int main(int argc, char** argv) {
    vector< int > input;
    int target_sum = 0;

    int element = 0;

    int counter = 0;
    // 数组总元素的数量
    cin >> counter;
    while (counter--) {
        cin >> element;
        input.push_back(element);
    }

    cin >> target_sum;

    for (auto data : input) {
        cout << data << " ";
    }
    cout << endl;
    cout << "target sum: " << target_sum << endl;

    vector< int > sum_index = TwoSum(input, target_sum);

    cout << "[" << sum_index[0] << "," << sum_index[1] << "]" << endl;
    return 0;
}
