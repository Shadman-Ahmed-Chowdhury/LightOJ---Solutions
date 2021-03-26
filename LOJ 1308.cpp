#include <bits/stdc++.h>

using namespace std;

int upperBound(int arr[], int n, int x) {

    int lo = 0, hi = n;

    while(lo < hi) {
        int mid = (lo + hi) / 2;
        if(x >= arr[mid]) lo = mid + 1;
        else hi = mid;
    }

    return hi;
}

int main() 
{
    int T; 
    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        int n;
        scanf("%d", &n);
        int A[n]; 
        for(int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
        }
        sort(A, A+n);
        printf("Case %d: ", t);
        int cnt= 0;
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n - 1; j++) {
                int sum = A[i] + A[j] - 1;
                int upper = upperBound(A, n, sum) - 1;
                //cout << A[i] << " " << A[j] << " " << upper << endl;
                if(A[i] + A[j] > A[upper] && (upper != i) && (upper != j)) {
                    cnt += (upper - j);
                    //cout << A[i] << "+" << A[j] << " > " << A[upper] <<  endl;
                }
            }
        }
        cout << cnt << endl;
        
    }

    return 0;
}