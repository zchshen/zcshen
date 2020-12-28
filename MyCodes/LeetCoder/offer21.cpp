/*
 * @Autor: zcshen
 * @Date: 2020-12-27 15:38:34
 * @Description: 将所有偶数移动到数组的后缀, 奇数移动到前缀
 */

// 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。

//  

// 示例：

// 输入：nums = [1,2,3,4]
// 输出：[1,3,2,4] 
// 注：[3,1,2,4] 也是正确的答案之一。
//  

// 提示：

// 1 <= nums.length <= 50000
// 1 <= nums[i] <= 10000

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


#include <iostream>
#include <vector>
#include "common_function.h"

using namespace std;
using namespace zcshen;

vector< int > exchange(vector< int >& nums) {
    int size = nums.size();
    int rank1 = 0;
    int rank2 = size - 1;
    while (rank1 < rank2) {
        while (rank1 < rank2 && 0 != (nums[rank1] & 1)) {
            rank1++;
        }

        while (rank1 < rank2 && 0 == (nums[rank2] & 1)) {
            rank2--;
        }

        if (rank1 < rank2) {
            swap(nums[rank1], nums[rank2]);
        }
    }

    return nums;
}

int main(int argc, char** argv) {
    vector< int > nums{ 1, 2, 3, 4, 5, 5, 6, 6, 6, 7 };

    ShowElememts(exchange(nums));

    return 0;
}