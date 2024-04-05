// 优先队列(堆)（非线性）:
// 菜篮子;每次操作有两种选择:(1) 1 x(x表示要放入的菜的重量) (2) 2 (取出菜篮子中最重的菜)
// 输出:菜篮子里菜的总重量
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q;
    cin >> q;
    priority_queue<ll> pq;
    ll sum = 0;
    while (q--)
    {
        ll op;
        cin >> op;
        if(op==1)
        {
            ll x;
            cin >> x;
            pq.push(x);
            sum += x;
        }
        else if(pq.size())
        {
            sum -= pq.top();
            pq.pop();
        }
    }
        cout << sum << '\n';
        return 0;
}
//优先队列:树状结构,只关心最顶部的元素(默认更新为最大值),通过push推入值,pop去顶部值,top读顶部值,size表示元素个数.