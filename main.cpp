// Arbitrary-base fixed-width string addition
// Reads m, n, B; then two strings of lengths m-1 and n-1; outputs sum with width max(m-1, n-1)

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

namespace {

int char_to_val(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    if (c >= 'a' && c <= 'z') return c - 'a' + 10;
    return -1;
}

char val_to_char(int v) {
    if (v >= 0 && v <= 9) return static_cast<char>('0' + v);
    return static_cast<char>('A' + (v - 10));
}

}  // namespace

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m, n, B;
    if (!(std::cin >> m >> n >> B)) return 0;
    std::string s1, s2;
    s1.reserve(std::max(0, m - 1));
    s2.reserve(std::max(0, n - 1));
    std::cin >> s1 >> s2;

    const int len1 = static_cast<int>(s1.size());
    const int len2 = static_cast<int>(s2.size());
    const int L = std::max(len1, len2);

    std::string res(L, '0');
    int carry = 0;
    for (int i = 0; i < L; ++i) {
        const int p1 = len1 - 1 - i;
        const int p2 = len2 - 1 - i;
        int v1 = 0, v2 = 0;
        if (p1 >= 0) {
            const int t = char_to_val(s1[p1]);
            v1 = (t >= 0) ? t : 0;
        }
        if (p2 >= 0) {
            const int t = char_to_val(s2[p2]);
            v2 = (t >= 0) ? t : 0;
        }
        const int sum = v1 + v2 + carry;
        const int digit = sum % B;
        carry = sum / B;
        res[L - 1 - i] = val_to_char(digit);
    }

    // Ensure uppercase output
    for (char &c : res) {
        if (c >= 'a' && c <= 'z') c = static_cast<char>(std::toupper(c));
    }

    std::cout << res << '\n';
    return 0;
}
