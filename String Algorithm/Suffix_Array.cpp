#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Tuple {
    int first, second, index;
};

const int MAXN = 1000000; // Maximum length of the string

int P[31][MAXN]; // P[i][j] denotes rank of suffix at position 'j' when sorted by first 2^i characters
Tuple L[MAXN]; // Array of Tuples
int POWER[31]; // Array of powers of 2
int SA[MAXN]; // Suffix Array
string str; // Input string
int N; // Length of the string

void buildSuffixArray() {
    N = str.length();
    
    // Initialize P for step 0
    for (int i = 1; i <= N; i++) {
        P[0][i] = str[i - 1] - 'a';
    }
    
    int step = 1;
    
    // Calculate powers of 2
    for (int i = 0; (1 << i) < N; i++) {
        POWER[i] = (1 << i);
        step++;
    }
    
    for (int i = 1; i <= step; i++) {
        for (int j = 1; j <= N; j++) {
            L[j].index = j;
            L[j].first = P[i - 1][j];
            L[j].second = (j + POWER[i - 1] <= N) ? P[i - 1][j + POWER[i - 1]] : -1;
        }
        
        sort(L + 1, L + N + 1, [](const Tuple& a, const Tuple& b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });
        
        for (int j = 1; j <= N; j++) {
            P[i][L[j].index] = (j > 1 && L[j].first == L[j - 1].first && L[j].second == L[j - 1].second)
                               ? P[i][L[j - 1].index]
                               : j;
        }
    }
    
    step = step - 1;
    
    for (int i = 1; i <= N; i++) {
        SA[P[step][i]] = i; // Fill the suffix array
    }
}

int main() {
    cin >> str; // Input the string
    if(str.length()==1){
        cout<<str;
        return 0;
    }
    int n = str.length();
    // string k = str;
    // k.pop_back();
    // str+=k;
    buildSuffixArray(); // Build the suffix array
    
    // Display the suffix array
    int minSA = 10000000;
    minSA = SA[1];
        for (int j = minSA-1; j < n; j++)
        {
            cout<<str[j];
        }
        for (int j = 0; j < (minSA-1); j++)
        {
            cout<<str[j];
        }
        return 0;
     
}
