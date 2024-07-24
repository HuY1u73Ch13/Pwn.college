#include<bits/stdc++.h>
#define ll long long
using namespace std ;
int main ()
{
    char mangled_result[5] = {0x7E, 0x7F, 0x7D, 0x6C, 0x6B};
    char key = 0x1c;
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
