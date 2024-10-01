// #include <iostream>
// #include <string>
// #include <algorithm>
// #include <vector>
// #include <unordered_set>

// using namespace std;

// bool isPalindrome(const string& str, int start, int end) {
//     while (start < end) {
//         if (str[start] != str[end])
//             return false;
//         ++start;
//         --end;
//     }
//     return true;
// }

// bool containsPalindrome(const string& str, int k) {
//     int n = str.size();
//     for (int i = 0; i <= n - k; ++i) {
//         if (isPalindrome(str, i, i + k - 1))
//             return true;
//     }
//     return false;
// }

// int main() {
//     string S;
//     int K;
//     cin >> S >> K;

//     int N = S.size();
//     sort(S.begin(), S.end());

//     unordered_set<string> unique_permutations;
//     do {
//         if (!containsPalindrome(S, K)) {
//             unique_permutations.insert(S);
//         }
//     } while (next_permutation(S.begin(), S.end()));

//     cout << unique_permutations.size() << endl;
//     return 0;
// }

// #include <iostream>
// #include <string>
// #include <algorithm>
// #include <vector>
// #include <unordered_set>

// using namespace std;

// bool isPalindrome(const string& str, int start, int end) {
//     while (start < end) {
//         if (str[start] != str[end])
//             return false;
//         ++start;
//         --end;
//     }
//     return true;
// }
// bool containsPalindrome(const string& str, int k) {
//     int n = str.size();
//     for (int i = 0; i <= n - k; ++i) {
//         if (isPalindrome(str, i, i + k - 1))
//             return true;
//     }
//     return false;
// }

// int main() {
//     int n, k;
//     cin >> n >> k;
//     string s;
//     cin >> s;

//     sort(s.begin(), s.end());

//     unordered_set<string> unique_permutations;
//     do {
//         if (!containsPalindrome(s, k)) {
//             unique_permutations.insert(s);
//         }
//     } while (next_permutation(s.begin(), s.end()));

//     cout << unique_permutations.size() << endl;
//     return 0;
// }

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

bool isPalindrome(long long x) {
    std::string s = std::to_string(x);
    std::string rev_s = s;
    std::reverse(rev_s.begin(), rev_s.end());
    return s == rev_s;
}

std::vector<long long> generatePalindromes(int N) {
    std::vector<long long> palindromes;
    for (int len = 1; palindromes.size() < N; ++len) {
        long long start = (len == 1) ? 0 : std::pow(10, (len - 1) / 2);
        long long end = std::pow(10, (len + 1) / 2);
        for (long long i = start; i < end && palindromes.size() < N; ++i) {
            std::string half = std::to_string(i);
            std::string rev_half = half;
            std::reverse(rev_half.begin(), rev_half.end());
            std::string palindrome = half + rev_half.substr(len % 2);
            palindromes.push_back(std::stoll(palindrome));
        }
    }
    return palindromes;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<long long> palindromes = generatePalindromes(N);

    std::cout << palindromes[N - 1] << std::endl;
    return 0;
}

