#include <iostream>
using namespace std;

int maxSubArraySum(int arr[], int n)
{
    int maxSum = arr[0];
    int currSum = arr[0];

    for (int i = 1; i < n; i++)
    {
        currSum = max(arr[i], currSum + arr[i]);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int main()
{
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    cout << maxSubArraySum(arr, 8);
    return 0;
}
