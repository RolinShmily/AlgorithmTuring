// 求和：给定一个大小为n的整数序列a_i（下标从1开始），你需要求出该序列所有子区间最小值的和。
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll a[N], l[N], r[N];
int stk[N],top;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        while (top &&a[stk[top]] >= a[i] )
            top--;
        if (!top)
            l[i] = 0;
        else
            l[i] = stk[top];
        stk[++top]=i;
    }
    top=0;
    for (int i = n; i >= 1; --i)
    {
        while (top &&a[stk[top]] > a[i])
            top--;
        if (!top)
            r[i] = n + 1;
        else
            r[i] = stk[top];
        stk[++top]=i;
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += a[i] * (i - l[i]) * (r[i] - i);
    cout << ans << '\n';
    return 0;
}
//单调栈思想，用stk存入枚举的下标，通过top调用，直到找到左端第一个比被比较元素大或相等的元素的位置，存入l，同样，找到右端第一个比被比较元素大的元素的位置，存入r，通过l与r的可选次数，相乘，得到没一个被比较元素对答案的贡献值。