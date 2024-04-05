// deque双端，单调队列
// 长度为n的数组，存在一个长度为k的窗口，包含着数组，这个窗口会从数组的最左边，每次移动一个单位长度，直到最右边。求在当窗口中有k个元素时，窗口中的最小值及最大值，分别输出一行。
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int a[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    deque<int> dq;
    for (int i = 1; i <= n; ++i)
    {
        while (dq.size() && dq.front() <= i - k)
        {
            dq.pop_front();
        }
        while (dq.size() && a[dq.back()] <= a[i])
            dq.pop_back();
        dq.push_back(i);
        if (i >= k)
            cout << a[dq.front()] << ' ';
    }
    cout << '\n';
    dq.clear();                                  
    for (int i = 1; i <= n; ++i)
    {
        while (dq.size() && dq.front() <= i - k)
        {
            dq.pop_front();
        }
        while (dq.size() && a[dq.back()] >= a[i])
            dq.pop_back();
        dq.push_back(i);
        if (i >= k)
            cout << a[dq.front()] << ' ';
    }
    return 0;
}
// 动态窗口，求窗口中的最大最小；从队尾推入下标，经过筛选成为队头（最优下标）；筛选有两步，第一队头的合法性，首先队列不为空，然后这个下标必须在k个元素范围内，否则将其弹出。第二队尾的优越性，首先队列不为空，然后对这个下标对应元素值进行与队头的比较，如果不优越，将其弹出。
// 此时有两种情况，1队列为空，我们要推入一个新的下标，2队列不空，我们要输出队头对应元素值。然而如果先推入一个新的下标，队列为空那么这个新下标就将为队头，因此省略这种判断