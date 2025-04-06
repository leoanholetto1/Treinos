#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define maxN 1e6 
using namespace std;

int c(int i){
    int sum=0;
    while(i){
        sum+=(i%10);
        i/=10;
    }
    return sum;
}

int main(){
    IOS
    int n,k,x;
    vector<int> v(maxN+1);
    cin>>n>>k;
    while(n--){
        cin>>x;
        v[x]++;
    }
    for(int i=maxN;i>=0;i--){
        if(k<=v[i]){
            cout<<c(i) <<endl;
            return 0;
        }
        v[i-c(i)]+=v[i];
        k-=v[i];
    }
    cout<<0<<endl;
    return 0;
}