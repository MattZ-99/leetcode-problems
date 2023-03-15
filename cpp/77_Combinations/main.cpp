// 77. Combinations

// Given two integers n and k, 
// return all possible combinations of k numbers out of the range [1, n]. 
// You may return the answer in any order.

// Runtime: 9 ms, faster than 96.48% of C++ online submissions for Combinations.
// Memory Usage: 8.8 MB, less than 98.94% of C++ online submissions for Combinations.

# include <iostream>
# include <cstdio>
# include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combs; vector<int> comb;
        int end_val = 1;
        while (true) {
            while(end_val <= n-k+1 && k > 0) {comb.push_back(end_val); end_val++; k--; }

            if (k == 0) combs.push_back(comb);
            if (comb.empty()) break;
            end_val = comb.back() + 1; comb.pop_back(); k++;
        }
        return combs;
    }
};

int main() {
    printf("#%s\n\n", "77. Combinations");

    Solution s;
    int n=4, k=2;
    vector<vector<int>> combs = s.combine(n, k);

    for(vector<int> & comb : combs) {
        for (int & c :  comb) {
            cout << c << ' ';
        }
        cout << '\n';
    }

    return 1;
}