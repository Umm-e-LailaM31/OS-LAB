#include <iostream>
#include <thread>
#include <vector>
using namespace std;
int main() {
    int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int vec[3] = {1,2,3}, result[3] = {};
    vector<thread> workers;
    for (int r=0; r<3; ++r)
        workers.emplace_back([&, r] {
            for (int c=0; c<3; ++c) result[r] += matrix[r][c] * vec[c];
        });
    for (auto &t : workers) t.join();
    cout << "Result Vector: [";
    for (int i=0; i<3; ++i) cout << result[i] << (i<2 ? ", " : "");
    cout << "]" << endl;
}
