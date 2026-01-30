#include <bits/stdc++.h>
using namespace std;

bool canDivide(vector<int> &A, int N, int M, int maxOR)
{
    int segments = 1;
    int currOR = 0;

    for (int i = 0; i < N; i++)
    {
        if ((currOR | A[i]) <= maxOR)
        {
            currOR |= A[i];
        }
        else
        {
            segments++;
            currOR = A[i];
        }
    }
    return segments <= M;
}

int minimizeMaxOR(vector<int> &A, int N, int M)
{
    int low = 0, high = 0;

    for (int x : A)
    {
        low = max(low, x);
        high |= x;
    }

    int ans = high;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (canDivide(A, N, M, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    cout << minimizeMaxOR(A, N, M);
    return 0;
}
