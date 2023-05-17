#include <bits/stdc++.h>
using namespace std;

bool comp(pair <int ,int> &a,pair <int ,int> &b){
    return a.second<b.second;
} 

int main(){
    int n;
    cin>>n;
    //start end
    vector <pair<int,int>> movie(n);
    for(int i=0;i<n;i++){
        cin>>movie[i].first>>movie[i].second;
    }

    sort(movie.begin(),movie.end(),comp);

    if(n==0 || n==1){
        cout<<n<<endl;
        return 0;
    }
    int ans=1;
    int time = movie[0].second;
    for (int i = 1; i < n; i++)
    {
        if(time<=movie[i].first){
            ans++;
            time = movie[i].second;
        }
    }
    cout<<ans<<endl;
    return 0;
}