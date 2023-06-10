#include <bits/stdc++.h>
using namespace std;
 
bool compar(pair<long long,long long> &a,pair<long long,long long> &b){
        return a.first<b.first;
}

int main(){
    long long n;
    cin >> n;
    vector <pair<long long,long long>> task;
    for(int i = 0; i < n; i++){
        long long x, y;
        cin >> x >> y;
        task.push_back({x,y});
    }
    sort(task.begin(), task.end(),compar);
    long long time = 0;
    long long prof = 0;
    for (long long i = 0; i < n; i++)
    {   
        prof += task[i].second;
        prof -= task[i].first*(n-i);
    }
    cout<<prof<<endl;    
    return 0;
}