/*
 * @Autor: zcshen
 * @Date: 2020-12-14 14:53:04
 * @Description: 字符串匹配, KMP算法原始版本
 */

#include <iostream>

using namespace std;

int* BuildNextTable(const string& pattern) {
    size_t pattern_len = pattern.size();
    size_t offset = 0;

    int* next_table = new int[pattern_len];
    next_table[0] = -1;
    int t = next_table[0];

    while (offset < pattern_len - 1) {
        if (0 > t || pattern[offset] == pattern[t]) {
            next_table[++offset] = ++t;
        }
        else {
            t = next_table[t];
        }
    }

    return next_table;
}

int Match(const string& text, const string& pattern) {
    // 构造next表
    int* next_table = BuildNextTable(pattern);

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
            pattern_offset = next_table[pattern_offset];
        }
    }

    delete[] next_table;

    return (text_offset - pattern_offset);
}

int main(int argc, char** argv) {
    string pattern;
    string text;

    cin >> pattern >> text;

    if (Match(text, pattern) > (text.size() - pattern.size())) {
        cout << "false" << endl;
    }
    else {
        cout << "true" << endl;
    }

    return 0;
}
