#include <iostream>
#include <vector>

int find_leave(std::vector<int>& data) {
    int index = -1;
    for (size_t i = 0; i != data.size(); ++i) {
        if (data[i] == 1) {
            index = i;
        }
    }
    return index;
}

int main() {
    int v;
    std::cin >> v;
    std::vector<std::vector<int>> data(v);
    std::vector<int> degree(v);
    int edg = 0;
    for (size_t i = 0; i != v; ++i) {
        int n;
        std::cin >> n;
        edg += n;
        degree[i] = n;
        for (size_t j = 0; j != n; ++j) {
            int to;
            std::cin >> to;
            data[i].push_back(to);
        }
    }
    edg = edg / 2;
    int answ = 0;
    std::vector<int> used(v, 0);
    while (edg != 0) {
        int index = find_leave(degree);
        if (index != -1) {
            degree[index] = 0;
            for (size_t i = 0; i != data[index].size(); ++i) {
                if (!used[data[index][i]] && degree[data[index][i]] != 0) {
                    degree[data[index][i]] -= 1;
                    if (!used[index]) {
                        used[data[index][i]] = 1;
                        ++answ;
                    }
                    --edg;
                } else if (used[data[index][i]] && degree[data[index][i]] != 0) {
                    --edg;
                    degree[data[index][i]] -= 1;
                }
            }
        } else {
            break;
        }
    }
    std::cout << answ << '\n';
}