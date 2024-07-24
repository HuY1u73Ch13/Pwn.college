/*#include <iostream>
#include <iomanip>

int main() {
     char mangled_result[5] = {0x67, 0x69, 0x60, 0x61, 0x60};
     char key = 0x05;
    char original_input[5];

    // Áp dụng phép toán XOR để đảo ngược mã hóa
    for (int i = 0; i < 5; i++) {
        original_input[i] = mangled_result[i] ^ key;
    }

    // In kết quả
    std::cout << "Original input:\n";
    for (int i = 0; i < 5; i++) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)original_input[i] << " ";
    }
    std::cout << std::dec << std::endl; // Quay lại hệ thập phân

    return 0;
}*/
#include<bits/stdc++.h>
#define ll long long
using namespace std ;
int main ()
{
    char mangled_result[5] = {0x67, 0x69, 0x60, 0x61, 0x60};
    char key = 0x05;
    char original_input[5];
    for (int i = 0; i < 5; i++)
    {
        original_input[i] = mangled_result[i] ^ key;
    }
    for (int i = 0; i < 5; i++)
    {
        cout<<original_input[i]<<" ";
    }
}
