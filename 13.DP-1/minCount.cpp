/*
Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force approach
int minCount(int n)
{
    // Base Case
    if (n <= 1) {
        return n;
    }
    
    int rem, ans = n;
    
    for (int i = 1; i <= sqrt(n); i++) {
        rem = n - (i*i);
        int temp = minCount(rem) + 1;
        if (temp < ans) {
            ans = temp;
        }
    }
    
    return ans;
}

// Memoization approach
int minCountHelper(int n, int *arr) {
    // Base Case
    if (n <= 1) {
        arr[n] = n;
        return n;
    }
    
    // Check if the output has already been computed
    if (arr[n] != -1) {
        return arr[n];
    }
    
    // Calculate
    int rem, ans = n;
    for (int i = 1; i <= sqrt(n); i++) {
        rem = n - (i*i);
        int temp = minCountHelper(rem, arr) + 1;
        if (temp < ans) {
            ans = temp;
        }
    }
    
    arr[n] = ans;
    
    return arr[n];
}

int minCount_2(int n) {
    int *arr = new int[n+1];
    
    for (int i = 0; i <= n; i++) {
        arr[i] = -1;
    }
    
    return minCountHelper(n, arr);
}

// DP approach
int minCount_3(int n) {
    int *arr = new int[n+1];
    
    arr[0] = 0;
    arr[1] = 1;
    
    for (int j = 2; j <= n; j++) {
        int rem, ans = j;
        for (int i = 1; i <= sqrt(j); i++) {
            rem = j - (i*i);
            int temp = arr[rem] + 1;
            if (temp < ans) {
                ans = temp;
            }
        }
        arr[j] = ans;
    }
    
    return arr[n];
}

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}