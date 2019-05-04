#include <bits/stdc++.h>

using namespace std;

int n, k, arr[1001];

bool BinarySearch(int mid)
{
    int sum = 0, cnt = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(sum > mid)
        {
            cnt++;
            sum = arr[i];
        }

    }
    cnt++;

    return cnt <= k;

}

int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        cin >> n >> k;
        n++, k++;
        int sum = 0, mid;
        int mx = -1;
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]), sum += arr[i], mx = max(arr[i], mx);
        int lo = mx, hi = sum;
        int best = hi;
        while(lo <= hi)
        {
            mid = (lo + hi) / 2;
            if(BinarySearch(mid))
            {
                best = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        printf("Case %d: %d\n", t, best);
        int cnt = k;
        sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += arr[i];
            if(sum > best || n - i + 1 == cnt)
            {
                cnt--;
                sum -= arr[i];
                printf("%d\n", sum);
                sum = arr[i];
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}

