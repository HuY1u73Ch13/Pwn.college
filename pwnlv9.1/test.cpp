#include <iostream>
#include <iomanip>
#include <cstring>
#include<bits/stdc++.h>

using namespace std;

unsigned char target_hash[16] = {
    0x89, 0xA6, 0x24, 0x9B, 0xCB, 0xC1, 0x52, 0x13, 0xBD, 0x65, 0x82, 0x35, 0xC7, 0x5B, 0x2E, 0x74
};

bool verify_license_key(unsigned char* buf) {
    unsigned char md[EVP_MAX_MD_SIZE];
    unsigned int md_len;

    EVP_MD_CTX* mdctx = EVP_MD_CTX_new();
    if (mdctx == NULL) {
        cerr << "Error creating context" << endl;
        return false;
    }

    if (1 != EVP_DigestInit_ex(mdctx, EVP_md5(), NULL)) {
        cerr << "Error initializing digest" << endl;
        EVP_MD_CTX_free(mdctx);
        return false;
    }

    if (1 != EVP_DigestUpdate(mdctx, buf, 27)) {
        cerr << "Error updating digest" << endl;
        EVP_MD_CTX_free(mdctx);
        return false;
    }

    if (1 != EVP_DigestFinal_ex(mdctx, md, &md_len)) {
        cerr << "Error finalizing digest" << endl;
        EVP_MD_CTX_free(mdctx);
        return false;
    }

    EVP_MD_CTX_free(mdctx);

    return memcmp(md, target_hash, 16) == 0;
}

void print_license_key(unsigned char* buf) {
    for (int i = 0; i < 27; ++i) {
        cout << hex << setw(2) << setfill('0') << (int)buf[i];
    }
    cout << endl;
}

int main() {
    // You would normally reverse-engineer the known input from the provided hash
    // For this example, we will start with a known input

    unsigned char buf[27] = {
        0x89, 0xA6, 0x24, 0x9B, 0xCB, 0xC1, 0x52, 0x13, 0xBD, 0x65, 0x82, 0x35, 0xC7, 0x5B, 0x2E, 0x74,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    if (verify_license_key(buf)) {
        cout << "License key is valid: ";
        print_license_key(buf);
    } else {
        cout << "License key is invalid" << endl;
    }

    return 0;
}
