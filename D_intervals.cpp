#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    if (n == 0) {
        std::cout << '\n';
        return 0;
    }
    std::vector<int> data(n);
    std::vector<int> prev(n);
    std::vector<int> length(n);
    for (size_t i = 0; i != n; ++i) {
        std::cin >> data[i];
    }
    for (size_t i = 0; i != n; ++i) {
        length[i] = 1;
        prev[i] = -1;
        for (size_t j = 0; j != n; ++j) {
            if (data[i] > data[j] && length[j] + 1 > length[i]) {
                length[i] = length[j] + 1;
                prev[i] = j;
            }
        }
    }
    int index = 0;
    int len = length[0];
    for (size_t i = 0; i != n; ++i) {
        if (length[i] > len) {
            index = i;
            len = length[i];
        }
    }
    std::vector<int> answer;
    while (index != -1) {
        answer.push_back(data[index]);
        index = prev[index];
    }
    std::reverse(answer.begin(), answer.end());
    for (size_t i = 0; i != answer.size(); ++i) {
        std::cout << answer[i] << ' ';
    }
    std::cout << '\n';
}
