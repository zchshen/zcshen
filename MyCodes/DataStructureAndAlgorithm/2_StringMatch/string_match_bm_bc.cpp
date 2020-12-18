/*
 * @Autor: zcshen
 * @Date: 2020-12-18 13:16:42
 * @Description: 字符串匹配 - BM_BC 算法
 */

#include <iostream>

using namespace std;

// bc表的长度与 字母表等长
static const uint16_t kBC_TABLE_LEN = 256;

int* BuildBCTable(const string& pattern) {
    size_t pattern_len = pattern.size();
    size_t offset = 0;

    int* bc_table = new int[kBC_TABLE_LEN];

    // 初始化BC表为-1
    for (size_t i = 0; i < kBC_TABLE_LEN; i++) {
        bc_table[i] = -1;
    }

    for (size_t i = 0; i < pattern_len; i++) {
        bc_table[pattern[i]] = i;
    }

    return bc_table;
}

int Match(const string& text, const string& pattern) {
    // 构造next表
    int* bc_table = BuildBCTable(pattern);

    int text_len = text.size();
    int pattern_len = pattern.size();

    int text_offset = 0;
    int pattern_offset = 0;

    while (pattern_offset < pattern_len && text_offset < text_len) {
        if (0 > pattern_offset || text[text_offset] == pattern[pattern_offset]) {
            ++pattern_offset;
            ++text_offset;
        }
        else {
            pattern_offset = bc_table[pattern_offset];
        }
    }

    delete[] bc_table;

    return (text_offset - pattern_offset);
}

int main(int argc, char** argv) {
    string pattern;
    string text;

    cin >> pattern >> text;

    if (text.size() < pattern.size()) {
        cout << "false" << endl; 
        return 0;
    }

    if (Match(text, pattern) > (text.size() - pattern.size())) {
        cout << "false" << endl;
    }
    else {
        cout << "true" << endl;
    }

    return 0;
}