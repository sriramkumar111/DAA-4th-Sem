#include <iostream>
#include <cstring>
using namespace std;
#define INT_MAX 2147483647
int arr[] = {2, 3, 5, 2, 4};
int dp[10][10] = {0};
int parenthesis[10][10] = {0};
int n = sizeof(arr) / sizeof(int) - 1;
void showParenthesis(int i, int j)
{
    if (i == j)
    {
        cout << char('A' + i);
    }
    else
    {
        cout << "(";
        showParenthesis(i, parenthesis[i][j]);
        showParenthesis(parenthesis[i][j] + 1, j);
        cout << ")";
    }
}
void matrixChain(){
	for(int len = 2; len <= n; len++){
		for(int i = 1; i <= n-len+1; i++){
			int j = i + len - 1;
			dp[i][j] = INT_MAX;
			for(int k = i; k < j; k++){
				int cost = dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
				if(cost < dp[i][j]){
					dp[i][j] = cost;
					parenthesis[i][j] = k;
				}
			}
		}
	}
	cout << "Minimum operations required is: " << dp[1][n] << endl;
	showParenthesis(0,n);
}

int main(){
	matrixChain();
	return 0;
}
