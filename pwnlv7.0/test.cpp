#include<bits/stdc++.h>
#define ll long long
using namespace std ;
int main ()
{
    string expected_result = "ywvvvuassrrpomkkkkkjgdbddsa";
    vector<char> buf(expected_result.begin(), expected_result.end());
    reverse(buf.begin(), buf.end());
    for (size_t i = 0; i < buf.size(); ++i) {
        cout << buf[i];
    }
    cout<<endl;
    swap(buf[1], buf[20]);
    for (size_t i = 0; i < buf.size(); ++i) {
        cout << buf[i];
    }
    cout<<endl;
    swap(buf[2], buf[4]);
    for (size_t i = 0; i < buf.size(); ++i) {
        cout << buf[i];
    }
    cout<<endl;
    swap(buf[24], buf[26]);
    for (size_t i = 0; i < buf.size(); ++i) {
        cout << buf[i];
    }
    cout<<endl;
    sort(buf.begin(), buf.end());
    for (size_t i = 0; i < buf.size(); ++i) {
        cout << buf[i];
    }
    cout<<endl;
    reverse(buf.begin(), buf.end());
    for (size_t i = 0; i < buf.size(); ++i) {
        cout << buf[i];
    }

}
