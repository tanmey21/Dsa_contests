#include "bits/stdc++.h"
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
typedef long long ll;

#ifndef ONLINE_JUDGE
#include "debug.h"
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

class GoldGrid {
    private:
        int n, m;
        vector<vector<int>> prefix;
    
    public:
        GoldGrid(int rows, int cols, const vector<string>& gridInput) {
            n = rows;
            m = cols;
            prefix.assign(n + 1, vector<int>(m + 1, 0));
    
            vector<string> grid(n + 1);
            for (int i = 1; i <= n; i++) {
                grid[i] = "#" + gridInput[i - 1]; // pad for 1-based
            }
    
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    prefix[i][j] = (grid[i][j] == 'g' ? 1 : 0)
                                 + prefix[i - 1][j]
                                 + prefix[i][j - 1]
                                 - prefix[i - 1][j - 1];
                }
            }
        }
    
        // 1-based inclusive query
        int query(int x1, int y1, int x2, int y2) {
            return prefix[x2][y2]
                 - prefix[x1 - 1][y2]
                 - prefix[x2][y1 - 1]
                 + prefix[x1 - 1][y1 - 1];
        }
    };

int main() {
fastio();
int tc;cin>>tc;
while(tc--){
  int n,m,k;cin>>n>>m>>k;int total=0;
   vector<string> a(n);
   for(int i=0;i<n;i++){
    string s;
    for(int j=0;j<m;j++){
        char c;cin>>c;
        if(c=='g')total++;
        s+=c;
    }
    a[i]=s;
   }
   GoldGrid goldGrid(n, m, a);

   int fa=0;

   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(a[i][j]=='.'){
            int i1=i-(k-1);i1=max(i1,0);
            int i2=j-(k-1);i2=max(i2,0);

            int j1=i+(k-1);j1=min(j1,n-1);
            int j2=j+(k-1);j2=min(j2,m-1);

            i1++;i2++;j1++;j2++;

            int count=goldGrid.query(i1,i2,j1,j2);
            int ans=total-count;
            fa=max(fa,ans);
        }
    }
   }
   cout<<fa<<endl;
  }
}