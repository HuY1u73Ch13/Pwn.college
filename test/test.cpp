#include <iostream>
#include <iomanip> // Để sử dụng std::setw và std::setfill
#include <cstring>

typedef unsigned char BYTE;

void reverseTransform(BYTE* buf) {
    // Undo XOR with 0x2F and 0x2
    for (int n = 0; n <= 28; ++n) {
        if (n % 2) {
            if (n % 2 == 1) {
                buf[n] ^= 0x2F;
            }
        } else {
            buf[n] ^= 2u;
        }
    }

    // Undo XOR in the m loop
    for (int m = 0; m <= 28; ++m) {
        int v4 = m % 4;
        if (m % 4 == 3) {
            buf[m] ^= 0xF9u;
        } else if (v4 <= 3) {
            if (v4 == 2) {
                buf[m] ^= 0xB4u;
            } else if (v4 <= 2) {
                if (v4) {
                    if (v4 == 1) {
                        buf[m] ^= 0xC7u;
                    }
                } else {
                    buf[m] ^= 0x4Du;
                }
            }
        }
    }

    // Undo XOR with values based on switch cases
    for (int k = 0; k <= 28; ++k) {
        switch (k % 5) {
            case 0:
                buf[k] ^= 0x45u;
                break;
            case 1:
                buf[k] ^= 0xC3u;
                break;
            case 2:
                buf[k] ^= 0xD8u;
                break;
            case 3:
                buf[k] ^= 0xD8u;
                break;
            case 4:
                buf[k] ^= 0xB2u;
                break;
        }
    }

    // Undo XOR with 0xDF
    for (int j = 0; j <= 28; ++j) {
        buf[j] ^= 0xDFu;
    }

    // Undo XOR based on i % 3
    for (int i = 0; i <= 28; ++i) {
        int v3 = i % 3;
        if (i % 3 == 2) {
            buf[i] ^= 0xD7u;
        } else if (v3 <= 2) {
            if (v3) {
                if (v3 == 1) {
                    buf[i] ^= 0xFCu;
                }
            } else {
                buf[i] ^= 0x44u;
            }
        }
    }
}

int main() {
    // Khai báo các giá trị hợp lệ cho kiểu BYTE
    BYTE buf[29] = {0xF7, 0x7F, 0x01, 0xE5, 0xB5, 0xCF, 0x8F, 0x49, 0xFC, 0xAA, 0xB4, 0x70, 0x7E, 0x7B, 0x69, 0x70, 0xC4, 0x56, 0x90, 0x36, 0x74, 0xC9, 0x21, 0x7C, 0x09, 0xF8, 0x1E, 0xEC, 0xDE};

    reverseTransform(buf);

    std::cout << "Reversed output:\n";
    for (int i = 0; i <= 28; ++i) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(buf[i]) << ' ';
    }
    std::cout << std::endl;

    return 0;
}
