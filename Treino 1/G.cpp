#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define maxN 1e6 
using namespace std;

int sum(int n){
    int soma=0;
    while(n){
        soma+=n%10;
        n/=10;
    }
    return soma;
}


int main(){
    IOS
    int n;
    cin>>n;
    while(true){
        if(n%sum(n)==0){
            cout << n << endl;
            break ;
        }
        n++;
    }
    return 0;
}