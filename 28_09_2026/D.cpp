#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,a,b) for(int i = a;i <= b;i ++)
#define frd(i,a,b) for(int i = a;i >= b; i --)
#define pb push_back
#define fi first
#define se second
#define el '\n'
template <class X, class Y> bool minimize(X &x, const Y &y) {if (x > y) {x = y;return true;} else return false;}
template <class X, class Y> bool maximize(X &x, const Y &y) {if (x < y) {x = y;return true;} else return false;}

const int N = 505;

int n,m;
char a[N][N];

signed main(){
    ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define TASK "qn"
    if(fopen(TASK".INP","r")){
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    }

    cin >> n >> m;

    fr(i,1,n) fr(j,1,m) cin >> a[i][j];

    int ans = 0;

    if(n <= 2 and m <= 2){
        cout << 0;
        return 0;
    }

    if(n == 1 or m == 1){
        if(n == 1){
            fr(i,2,m - 1) ans += a[1][i] == '.';
        }
        else if(m == 1){
            fr(i,2,n - 1) ans += a[i][1] == '.';
        }
        cout << ans;
        return 0;
    }
    if(n == 2){
        fr(i,2,m - 1) ans+= (a[1][i] == '.' and a[2][i] == '.');
        cout << ans;
        return 0;
    }
    if(m == 2){
        fr(i,2,n - 1) ans += (a[i][1] == '.' and a[i][2] == '.');
        cout << ans;
        return 0;
    }
    bool ok = 1;
    fr(i,1,n){
        fr(j,1,m){
            bool is_border = (i == 1 or i == n or j == 1 or j == m);
            bool is_corner = ((i == 1 or i == n) and (j == 1 or j == m));
            if(!is_border) ans += a[i][j] == '.';
            else{
                if(!is_corner and a[i][j] == '#'){
                    ok = 0;
                }
            } 
        }
    }

    cout << ans + ok;
    
    return 0;
}