#include <fstream>
#include <random>

const int iterations = 1e6;
const int steps = 100;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main() {
    int amount[steps + 1];
    for (int i = 0; i <= steps; i++) amount[i] = 0;
    
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, 3);

    for (int i = 0; i < iterations; i++) {
        int x = 0, y = 0;
        for (int j = 0; j < steps; j++) {
            int val = distribution(generator);
            x += dx[val];
            y += dy[val];
        }
        int dist = abs(x) + abs(y);
        amount[dist]++;
    }

    std::ofstream out("res.txt");
    for (int i = 0; i <= steps; i += 2) {
        out << amount[i] << '\n';
    }
}