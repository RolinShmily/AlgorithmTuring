// 单调栈，求数组中每个元素对应的左边第一个比它小的值
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int a[N], l[N];
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    stack<int> st;
    for (int i = 1; i <= n; ++i)
    {
        while (st.size() && a[st.top()] >= a[i])
            st.pop();
        if (st.empty())
            l[i] = -1;
        else
            l[i] = st.top();
        st.push(i);
    }
    for (int i = 1; i <= n; ++i)
        cout << (l[i] == -1 ? -1 : a[l[i]]) << ' ';
    return 0;
}
// 单调栈思想：先进先出。推入一个下标，判断下标所对应的值，如过这个值比前边的值小，（自然的它的位置更靠右），就把前边的值拿走，将其推入，并记录。此番操作后如果栈空，则记录-1，否则记录栈顶录入的下标。最后依次读出下表对应值。