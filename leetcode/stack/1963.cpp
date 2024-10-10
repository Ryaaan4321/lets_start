#include <bits/stdc++.h>

// #define MAIN_ACTIVE
// #define IO_ON_FILE

using namespace std;
#define int64_t wadwafesfesfes21321300242142104210321
using int64_t = long long;
using pii = pair<int, int>;
using pil = pair<int, int64_t>;
using pli = pair<int64_t, int>;
using pll = pair<int64_t, int64_t>;
#define umap unordered_map
#define uset unordered_set
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define emp_back emplace_back
#define bitcount(x) __builtin_popcount((x))
#define mbin(val, cap) bitset<64>(val).to_string().substr(64 - cap)
#define PQ(x, y) priority_queue<x, vector<x>, y<x>>
// #define PQD(x, y) priority_queue<x, vector<x>, decltype(y)>
#define print(x) cout << "[ " << #x << " ]: " << x << "\n";
#define printc(x) cout << "[ " << #x << " ]: [", show(all(x), ", ", false), cout << "]\n";
#define e_ cout << "\n";
constexpr int dx[9] = {0, 1, 0, -1, -1, 1, 1, -1, 0};
constexpr int dy[9] = {1, 0, -1, 0, -1, 1, -1, 1, 0};

class Solution
{
public:
    int minSwaps(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ']' && st.empty())
            {
                continue;
            }
            else if (s[i] == ']' && st.top() == '[')
            {
                st.pop();
            }
            else
            {
                st.push('[');
            }
        }
        return (st.size() + 1) / 2;
    }
    int minSwaps(string s) {
        int cnt=0;
        int mxcnt=0;
        int _=0;
        for(;_<s.length();_++){
            if(s[_]=='['){
                cnt--;
                mxcnt=max(cnt,mxcnt);
            }else if(s[_]==']'){
                cnt++;
                mxcnt=max(cnt,mxcnt);
            }
        }
        return (mxcnt+1)/2;
        
    }
};

#ifdef MAIN_ACTIVE

void solve()
{
}

int main()
{

#ifdef IO_ON_FILE
    const string FILENAME = "user";
    freopen((FILENAME + ".in").c_str(), "r", stdin);
    freopen((FILENAME + ".out").c_str(), "w", stdout);
#endif

    int test_count = 1;
    // cin >> test_count;
    while (test_count--)
        solve();

    return EXIT_SUCCESS;
}
#endif