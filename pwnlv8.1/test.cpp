#include<bits/stdc++.h>
using namespace std;

using BYTE = unsigned char;

void swap_bytes(BYTE* buf, int idx1, int idx2) {
    BYTE temp = buf[idx1];
    buf[idx1] = buf[idx2];
    buf[idx2] = temp;
}

void reverse_buf(BYTE* buf) {
    for (int n = 0; n <= 16; ++n) {
        swap_bytes(buf, n, 34 - n);
    }
}

void reverse_xor(BYTE* buf)
{
    for (int m = 0; m <= 34; ++m)
    {
        int v3 = m % 4;
        if (m % 4 == 3)
        {
            buf[m] ^= 0x1B;
        }
        else if (v3 <= 3)
        {
            if(v3 == 2)
            {
                buf[m] ^= 0x06;
            }
            else if (v3 <= 2)
            {
                if (v3 == 1)
                {
                    buf[m] ^= 0xD6;
                }
                else
                {
                    buf[m] ^= 0x1D;
                }
            }

        }
    }
}

void reverse_sort(BYTE* buf)
{
    for (int j = 0; j <= 33; ++j)
    {
        for (int k = 0; k < 34 - j; ++k)
        {
            if (buf[k] > buf[k + 1])
            {
                swap_bytes(buf, k, k + 1);
            }
        }
    }
}

void reverse_xor_66(BYTE* buf) {
    for (int i = 0; i <= 34; ++i) {
        buf[i] ^= 0x66;
    }
}

int main() {
    BYTE buf[35] = {
        0x1C, 0xD7, 0x07, 0x1A, 0x1E, 0xD5, 0x03, 0x1E, 0x1A,
        0xD1, 0x0E, 0x11, 0x16, 0xDD, 0x0D, 0x17, 0x10, 0xDB, 0x08,
        0x0A, 0x0F, 0xC5, 0x15, 0x0F, 0x09, 0xC2, 0x13, 0x0E, 0x0B,
        0xC1, 0x18, 0x05, 0x03, 0xC9, 0x19
    };

    // Reverse steps
    reverse_buf(buf);            // Reverse the final swap
    swap_bytes(buf, 26, 31);       // Swap the first and second byte
    reverse_buf(buf);            // Reverse the first swap again
    reverse_xor(buf);            // Reverse the xor operations
    reverse_sort(buf);           // Reverse the sorting
    swap_bytes(buf, 7, 14);       // Swap the first and sixth byte
    reverse_xor_66(buf);         // Reverse the initial xor with 0x66

    cout << "Original input: ";
    for (int i = 0; i <= 36 ; ++i) {
        cout << hex << setw(2) << setfill('0') << static_cast<int>(buf[i]) << ' ';
    }
    cout << endl;

    return 0;
}
