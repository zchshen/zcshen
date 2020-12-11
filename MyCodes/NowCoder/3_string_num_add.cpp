/*
 * @Autor: zcshen
 * @Date: 2020-12-11 12:57:15
 * @Description: 字符串形式两个大数相加
 */

#include <iostream>
#include <string.h>

using namespace std;

static const uint8_t MAX_LEN = 31;

uint8_t CharAdd (const char& c1, const char& c2, uint8_t carry, char& out_char) {
    out_char = ((c1 - '0' + c2 - '0' + carry) % 10) + '0';
    return (c1 - '0' + c2 - '0' + carry) / 10;
}

void StringNumAdd (
    const char* input1, uint8_t len1, const char* input2, uint8_t len2) {
    uint8_t max_len = 0;
    char *max_input = nullptr;
    uint8_t min_len = 0;
    char *min_input = nullptr;
    (len1 > len2) ? (max_len = len1, max_input = const_cast< char* > (input1), min_len = len2,
                    min_input = const_cast< char* > (input2)) : (max_len = len2, max_input = const_cast< char* > (input2),
                    min_len = len1, min_input = const_cast< char* > (input1));

    // 进位标识符
    uint8_t carry_flag = 0;

    // 处理结果
    char result[MAX_LEN] = { '\0' };
    uint8_t output_len = 0;

    while (max_len--) {
        carry_flag = min_len > 0 ? CharAdd (max_input[max_len], min_input[--min_len], carry_flag, result[output_len++]) :
                                   CharAdd (max_input[max_len], '0', carry_flag, result[output_len++]);
    }
    // 最后处理进位情况
    if (1 == carry_flag) {
        result[output_len++] = '1';
    }

    // 倒序输出
    while (output_len--) {
        cout << result[output_len];
    }
    cout << endl;
}

int main (int argc, char** argv) {
    uint8_t ctrl = 2;
    char strnum1[MAX_LEN] = { '\0' };
    char strnum2[MAX_LEN] = { '\0' };
    char output[MAX_LEN] = { '\0' };

    while (ctrl--) {
        cin >> strnum1;
        cin >> strnum2;
        cout << strnum1 << " len: " << strlen(strnum1) << endl;
        cout << strnum2 << " len: " << strlen(strnum2) << endl;

       StringNumAdd(strnum1, strlen(strnum1), strnum2, strlen(strnum2));
    }

    return 0;
}