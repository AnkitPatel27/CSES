#include <bits/stdc++.h>
using namespace std;

int main() {
    vector <vector <int>> v = {{1,2,3}};
    v.push_back(v[0]);
    v[0][0] = 5;
    cout<<v[1][0]<<endl;

    return 0;
}
