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
