#include <bits/stdc++.h>
using namespace std;

static inline int char_to_val(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    if (c >= 'a' && c <= 'z') return c - 'a' + 10;
    return -1;
}

static inline char val_to_char(int v) {
    if (v >= 0 && v <= 9) return char('0' + v);
    return char('A' + (v - 10));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n, B;
    if (!(cin >> m >> n >> B)) return 0;
    string s1, s2;
    s1.reserve(max(0, m - 1));
    s2.reserve(max(0, n - 1));
    cin >> s1 >> s2;

    // lengths without terminator
    int len1 = (int)s1.size();
    int len2 = (int)s2.size();
    int L = max(len1, len2);

    // Normalize to uppercase for safety when outputting
    // but we only need to ensure output uppercase
    // We'll compute from the least significant end

    string res(L, '0');
    int carry = 0;
    for (int i = 0; i < L; ++i) {
        int p1 = len1 - 1 - i;
        int p2 = len2 - 1 - i;
        int v1 = 0, v2 = 0;
        if (p1 >= 0) {
            int t = char_to_val(s1[p1]);
            v1 = (t >= 0) ? t : 0;
        }
        if (p2 >= 0) {
            int t = char_to_val(s2[p2]);
            v2 = (t >= 0) ? t : 0;
        }
        int sum = v1 + v2 + carry;
        int digit = sum % B;
        carry = sum / B;
        res[L - 1 - i] = val_to_char(digit);
    }

    // Fixed width: ignore overflow carry
    // Ensure uppercase (val_to_char already returns uppercase for >=10)
    for (char &c : res) {
        if (c >= 'a' && c <= 'z') c = char(toupper(c));
    }

    cout << res << '\n';
    return 0;
}

