/*
 * @Autor: zcshen
 * @Date: 2020-12-27 09:33:00
 * @Description:
 */

int solution(string& S, vector< int >& C) {
    // write your code in C++14 (g++ 6.2.0)
    size_t len = s.size();
    if (len < 2) {
        return 0;
    }

    int min_sum = 0;
    for (auto i = 1; i < len; i++) {
        if (s[i - 1] == s[i]) {
            // 相邻且相等
            min_sum += min(C[i - 1], C[i]);
        }
    }

    return min_sum;
}

vector< int > solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    vector< int > uniq_vec;
    if (1 == N) {
        uniq_vec.push_back(0);
        return uniq_vec;
    }

    int pre_sum = 0;
    for (int i = 0; i < N - 1; i++) {
        uniq_vec.push_back(i + 1);
        pre_sum += i + 1;
    }

    uniq_vec.push_back(-pre_sum);

    return uniq_vec;
}