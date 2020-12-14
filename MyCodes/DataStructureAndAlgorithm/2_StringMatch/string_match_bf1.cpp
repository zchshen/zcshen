/*
 * @Autor: zcshen
 * @Date: 2020-12-11 15:27:05
 * @Description: 字符串匹配, 暴力匹配方法-1
 */

#include <string>
#include <iostream>

using namespace std;

int Match(const char* text, size_t text_len, const char* pattern, size_t pattern_len) {
    size_t text_pos = 0;
    size_t pattern_pos = 0;

    while (pattern_pos < pattern_len && text_pos < text_len) {
        if (pattern[pattern_pos] == text[text_pos]) {
            ++pattern_pos;
            ++text_pos;
        }
        else {
            text_pos -= pattern_pos - 1;
            pattern_pos = 0;
        }
    }

    cout << "position: " << text_pos - pattern_pos << endl;
    return (text_pos - pattern_pos);
}

int main(int argc, char** agrv) {
    string pattern;
    string text;

    cin >> pattern >> text;

    size_t text_len = text.size();
    size_t pattern_len = pattern.size();
    if (Match(text.c_str(), text_len, pattern.c_str(), pattern_len) > (text_len - pattern_len)) {
        cout << "false" << endl;
    }
    else {
        cout << "true" << endl;
    }

    return 0;
}
