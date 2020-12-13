/*
 * @Autor: zcshen
 * @Date: 2020-12-12 18:46:55
 * @Description: 
 */

#include <iostream>

static const uint8_t kMAX_LEN = 100;

using namespace std;

void DoJob(const char *p, uint8_t p_len, const char* s, uint8_t s_len, const char* t, uint8_t t_len) {

}

int main(int argc, char** argv) {
    uint32_t num = 0;
    cin >> num;

    char str_p [kMAX_LEN] = {'\0'};
    char str_s [kMAX_LEN] = {'\0'};
    char str_t [kMAX_LEN] = {'\0'};
    
    while (num--) {
        cin >> str_s >> str_t >> str_p;
    }
        
    return 0;
}
