#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    unsigned char mangled_result[18] = {0xCC, 0xD4, 0xD7, 0xC9, 0xD9, 0xD9, 0xD9, 0xCD, 0xCD, 0xDF, 0xD2, 0xCD, 0xD1, 0xDA, 0xD9, 0xCE, 0xD9, 0xD6};
    char key = 0xBB;
    char original_input[18]; // Adjust the size of the array to 18 to match mangled_result
    for (int i = 0; i < 18; i++) {
        original_input[i] = mangled_result[i] ^ key;
    }
    for (int i = 0; i < 18; i++) {
        cout << original_input[i];
    }
    cout << endl;
    reverse(original_input, original_input + 9);
    reverse(original_input, original_input + 9);
    for (int i = 0; i < 18; i++) {
        cout << original_input[i];
    }
    cout << endl;

}
