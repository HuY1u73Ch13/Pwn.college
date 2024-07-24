/*#include<bits/stdc++.h>
#define ll long long
using namespace std ;
int main ()
{
    BYTE expected_result[40] = {
        0x0D9, 0x0A5, 0x0CB, 0x4A, 0x0FA, 0x4B, 0x41, 0x5F, 0x54, 0x48,
        0x73, 0x0D5, 0x0C5, 0x7D, 0x0A6, 0x0A4, 0x06, 0x2F, 0x47, 0x57,
        0x98, 0x54, 0x93, 0x26, 0x0C5, 0x0CE, 0x0AB, 0x72, 0x6B, 0x0BA,
        0x0A2, 0x0F1, 0x3C, 0x4F, 0x4C, 0x4B, 0x35, 0x2E, 0x0B8
    };
    BYTE buf[39];
    memcpy(buf, expected_result, 39);
    reverse_mangler(buf, 0, 18);
}*/
#include <iostream>
#include <iomanip>
#include <cstdint>
#include <cstring>

using namespace std;

using BYTE = unsigned char;

void reverse_reverse_mangler(BYTE* buf) {
    for (int i = 0; i <= 18; ++i) {
        BYTE temp = buf[i];
        buf[i] = buf[38 - i];
        buf[38 - i] = temp;
    }
}

void reverse_swap(BYTE* buf, int idx1, int idx2) {
    BYTE temp = buf[idx1];
    buf[idx1] = buf[idx2];
    buf[idx2] = temp;
}

void reverse_xor_mangler(BYTE* buf, const BYTE* key, int key_len) {
    for (int jj = 0; jj <= 38; ++jj) {
        buf[jj] ^= key[jj % key_len];
    }
}

void reverse_sort_mangler(BYTE* buf) {
    for (int i = 1; i <= 38; ++i) {
        for (int j = 0; j < 38 - i + 1; ++j) {
            if (buf[j] < buf[j + 1]) {
                BYTE temp = buf[j];
                buf[j] = buf[j + 1];
                buf[j + 1] = temp;
            }
        }
    }
}

int main() {
    BYTE buf[39] = {0x0D9, 0x0A5, 0x0CB, 0x4A, 0x0FA, 0x4B, 0x41, 0x5F, 0x54, 0x48, 0x73, 0x0D5, 0x0C5, 0x7D, 0x0A6, 0x0A4, 0x06, 0x2F, 0x47, 0x57, 0x98, 0x54, 0x93, 0x26, 0x0C5, 0x0CE, 0x0AB, 0x72, 0x6B, 0x0BA, 0x0A2, 0x0F1, 0x3C, 0x4F, 0x4C, 0x4B, 0x35, 0x2E, 0x0B8};

    // Reverse last reverse mangler
    reverse_reverse_mangler(buf);

    // Reverse swap mangler for indexes 7 and 32
    //reverse_swap(buf, 0, 7);
    reverse_swap(buf, 32, 7);

    // Reverse swap mangler for indexes 21 and 29
    reverse_swap(buf, 21, 29);

    // Reverse xor mangler with key 0xbc42c9426755
    BYTE key1[] = {0xBC, 0x42, 0xC9, 0x42, 0x67, 0x55};
    reverse_xor_mangler(buf, key1, 6);

    // Reverse xor mangler with key 0x660e9e6a4f7ee5
    BYTE key2[] = {0x66, 0x0E, 0x9E, 0x6A, 0x4F, 0x7E, 0xE5};
    reverse_xor_mangler(buf, key2, 7);

    // Reverse sort mangler
    reverse_sort_mangler(buf);

    // Reverse first reverse mangler
    reverse_reverse_mangler(buf);

    cout << "Original input: ";
    for (int i = 0; i <= 38; ++i) {
        cout << hex << setw(2) << setfill('0') << static_cast<int>(buf[i]) << ' ';
    }
    cout << endl;

    return 0;
}
