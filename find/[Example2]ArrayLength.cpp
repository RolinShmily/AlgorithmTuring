// 二分查找 : 元素不重复情况下的数组最大长度
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int a[N], c[N];
bool check(int mid, int n)
{
    ll cnt = 0;
    for (int i = 1; i <= n; ++i)
        c[a[i]] = 0;
    for (int i = 1; i <= mid; ++i)
    {
        c[a[i]]++;
        if (c[a[i]] == 1)
            cnt++;
        else if (c[a[i]] == 2)
            cnt--;
        if (cnt == mid)
            return true;
    }
    for (int i = 1, j = mid; j < n; ++i, ++j)
    {
        c[a[i]]--;
        if (c[a[i]] == 1)
            cnt++;
        else if (c[a[i]] == 0)
            cnt--;
        c[a[j + 1]]++;
        if (c[a[j + 1]] == 1)
            cnt++;
        if (c[a[j + 1]] == 2)
            cnt--;
        if (cnt == mid)
            return true;
    }
    return false;
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int l = 0, r = n + 1;
    while (l + 1 != r)
    {
        int mid = (l + r) >> 1;
        if (check(mid, n))
            l = mid;
        else
            r = mid;
    }
    cout << l << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
//暴力枚举：假设答案（长度）从0开始递增到n推算，总会存在一个ans再[0，n]之间，使得数组中有元素重复，因此再[0,ans]是不重复，即符合题意，[ans,n]不符合题意，我们只需找到这个ans即可，ans就是答案。
//二分查找：基础的二分写法，做一个check函数检查该mid值是否合理，用cnt表示计数数组c（记录a中数字出现次数）中1的数量，也即存在的数量，对其进行实时维护，mid此时代表枚举的答案也就是数组的长度，当cnt==mid时意味着，数组中只有mid个元素出现，且均出现一次，也就找到了ans，也即mid合理。
//双指针思想：check函数中，对从i到mid的数字进行计数1次，令ptr1（i）指向1，ptr2（j）指向mid（当前查找对象），只需在数组中走动双指针，也即对j+1进行判断查重，同时对i进行抛值，跑完一圈，若未能实现cnt==mid，则mid值不合理，也即推断的ans不正确，进行再次枚举。