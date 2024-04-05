// set
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    set<int> st;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        st.insert(x);
    }
    for (auto &i : st)
        cout << i << '\n';
    return 0;
}
// set中value默认升序，且value唯一(直接去重)（非线性结构）