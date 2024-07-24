#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main ()
{
    string expected_result = "bdehhhqjnnoirvxyz";
    vector<char> buf(expected_result.begin(), expected_result.end());
    // Bước 1: Hoán đổi lại các ký tự ở vị trí 6 và 11
    swap(buf[6], buf[11]);
    for (size_t i = 0; i < buf.size(); ++i) {
        cout << buf[i];
    }
    cout<<endl;
    // Bước 2: Sắp xếp lại chuỗi (ngược lại quá trình sắp xếp)
    sort(buf.begin(), buf.end());
    for (size_t i = 0; i < buf.size(); ++i) {
        cout << buf[i];
    }
    cout<<endl;
    // Bước 3: Đảo ngược chuỗi
    reverse(buf.begin(), buf.end());
    for (size_t i = 0; i < buf.size(); ++i) {
        cout << buf[i];
    }
}
