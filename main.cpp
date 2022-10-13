#include<bits/stdc++.h> 
//priority_queue next_permutation 
#define ll long long 
#define int ll 
// #define double long double 
#define flot(n) cout << setprecision(n) << setiosflags(ios::fixed) << setiosflags(ios::showpoint) 
#define all(a) a.begin() , a.end() 
#define allr(a) a.rbegin() , a.rend() 
#define pb push_back 
#define mp make_pair 
#define pii pair<int,int> 
#define pll pair<ll,ll> 
#define piii pair<pii,int> 
#define plll pair<ll,pll> 
#define R return 
#define B break 
#define C continue 
#define SET(n , i) memset(n , i , sizeof(n)) 
#define SD ios::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
#define rep(i , n) for(int i = 0 ; i < n ; i++) 
#define repn(i , j , n) for(int i = j ; i < n ; i++) 
#define repr(i,n,j) for(int i=n;i>=j;i--)
#define positive(x) (x%mod+mod)%mod
#define YES(f)cout<<(f?"YES":"NO")<<endl
#define F first 
#define S second 
#define endl '\n' 
using namespace std; 
void MAX(int32_t &x,int32_t y){x=max(x,y);} 
void MAX(ll &x,ll y){x=max(x,y);} 
void MIN(int32_t &x,int32_t y){x=min(x,y);} 
void MIN(ll &x,ll y){x=min(x,y);} 
const int INF = 0x3f3f3f3f; 
const ll INFLL = 0x3f3f3f3f3f3f3f3f; 
const double EPS = 1e-7; 
const double pi = 3.14159265358979323846;
const int mod = 1e9+7; 
const int N = 1e5+7; 
ll Mul(ll x,ll y){R((x%mod)*(y%mod))%mod;}
ll Add(ll x,ll y){R((x%mod)+(y%mod)+2ll*mod)%mod;} 
int n,m,a[N];
struct node {
    int sum , lazy ;
    node *left,*right ;
    node (int _sum = 0 ,int _lazy = 0 , node *_left = NULL , node *_right = NULL) {
        sum = _sum ;
        lazy = _lazy ;
        left = _left ;
        right = _right ;
    }
    node *build(int l,int r)
    {
        if(l==r) {
            sum = a[l] ;
            return this ;
        }
        int mid = (l+r)/2 ;
        left = new node() ;
        right = new node () ;
        left = left->build(l,mid) ;
        right = right->build(mid+1,r) ;
        sum = left->sum + right->sum ;
        return this ;
    }
    node *update(int l,int r,int ql,int qr,int val) {
        if(l > qr || r < ql) {
            return this ;
        }
        if(l>=ql && r<=qr) {
            return new node(sum,lazy+val,left,right) ;
        }
        int mid = (l+r)/2 ;
        return new node(sum + val * (min(r,qr) - max(l,ql) + 1),lazy , left->update(l,mid,ql,qr,val) , right->update(mid+1,r,ql,qr,val)) ;
    }
    int query(int l,int r,int ql,int qr,int val)
    {
        if(l > qr || r < ql) {
            return 0 ;
        }
        val += lazy ;
        if(l>=ql && r<=qr) {
            return sum + val * (r-l+1) ;
        }
        int mid = (l+r)/2 ;
        return left->query(l,mid,ql,qr,val) + right->query(mid+1,r,ql,qr,val) ;
    }
};
node *version[N];
void solve() {
    cin >> n >> m;
    repn(i,1,n+1)cin>>a[i];
    version[0] = new node();
    version[0] = version[0] -> build(1,n);
    int cur=0;
    while(m--) {
        char x;cin>>x;
        if(x == 'C') {
            cur++;
            int l,r,d;cin>>l>>r>>d;
            version[cur] = version[cur-1] -> update(1,n,l,r,d);
        }else if(x == 'Q') {
            int l,r;cin>>l>>r;
            cout << version[cur]->query(1,n,l,r,0) << endl;
        }else if(x == 'H') {
            int l,r,t;cin>>l>>r>>t;
            cout << version[t]->query(1,n,l,r,0) << endl;
        }else {
            int t;cin>>t;cur=t;
        }
    }
}
void sett(){ 
} 
int32_t main() { 
    SD; 
    int t = 1; 
    // cin >> t; 
    // scanf("%d" , &t); 
    while(t--){
        solve(); 
        sett(); 
    } 
}
