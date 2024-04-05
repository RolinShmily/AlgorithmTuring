//bitset
//数的种类：输入n个数字，问使用这些数字做加法（也可都不选），最多得到几种不同的数字？
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e3 + 9;
const int M = 5e5 + 9;
int a[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    bitset<M> bs;
    bs[0] = 1;
    for (int i = 1; i <= n;++i)
    {
        bs |= bs << a[i];
    }
    cout << bs.count() << '\n';
    return 0;
}
//bitset类型：类二进制数，M表示位数，count表示其中数字1的个数。
//题目解析，如果写一个二维数组dp[i][j]表示到a[i]为止，能否组成j，如果能，则为1，反之为0。可以得到一个只有1，0的序列，而每当a[i]读入一个数字，因为只遵循加法，相当于原来能够组成j的，现在可以组成j+a[i]，相应的，这些位置也要填入1；如果将其视作位运算，相当于这个数列，朝着j增大的方向，移动了a[i]位。而bitset是逆序的类二进制数序列，对他来讲是进行左移，同时用或运算，将原来位置的'1'copy下来，接着读出这些1的个数，就是能够构成不同种数字j的个数。