#include <bits/stdc++.h>

using namespace std;

int n, m, arr[1001];

bool tryCapacity(int mid)
{
    int total = 0, cur = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > mid)
            return false;
        if(cur + arr[i] > mid)
            cur = 0;
        if(cur == 0)
            total++;
        cur += arr[i];
        if(total > m)
            return false;
    }
    return true;
}

int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        cin >> n >> m;
        int sum = 0, mid;
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]), sum += arr[i];
        int lo = 1, hi = sum;
        int best = hi + 1;
        while(lo <= hi)
        {
            mid = (lo + hi) / 2;
            if(tryCapacity(mid))
            {
                best = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        printf("Case %d: %d\n", t, best);
    }

    return 0;
}
