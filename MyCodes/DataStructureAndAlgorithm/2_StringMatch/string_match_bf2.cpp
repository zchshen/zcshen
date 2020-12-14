/*
 * @Autor: zcshen
 * @Date: 2020-12-13 12:22:33
 * @Description: 字符串匹配, 暴力解法2
 */
#include <iostream>

using namespace std;

int Match(const char* text, uint8_t text_len, const char* pattern, uint8_t pattern_len) {
    size_t text_pos = 0;
    size_t pattern_pos = 0;

    for (text_pos = 0; text_pos < text_len - pattern_len +1; text_pos++) {
        for (pattern_pos = 0; pattern_pos < pattern_len; pattern_pos++) {
            if (text[text_pos+pattern_pos] != pattern[pattern_pos]) {
                break;
            }
        }

        if (pattern_pos == pattern_len) {
            break;
        }
    }

    cout << "index: " << text_pos << endl;
    return text_pos;
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