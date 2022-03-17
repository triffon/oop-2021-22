#include <iostream>
using namespace std;
#define MAXN 128
#define MAX 999999

// currentX and currentY are out current place in the 2d array
// int fromX, int fromY are the original place we start from
// int toX, int toY are the final place where we want to go
void solve(int a[MAXN][MAXN], int currentX, int currentY, int fromX, int fromY,
                int toX, int toY, int x, int y, int sum, int minSum, int maxSum, bool isGoBack, bool &finalSolution) {
    if (currentX < 0 || currentY < 0 || currentX >= x || currentY >= y) return;
    if (finalSolution) return;
    if (currentX == toX && currentY == toY && isGoBack) {
        finalSolution = true;
    }
    if (currentX == toX && currentY == toY) {
        solve(a, currentX,  currentY, toX, toY, fromX, fromY, x, y, sum, minSum, maxSum, true, finalSolution);
    }
    int currentSum;
    if (currentX - 1 < 0 && a[currentX - 1][currentY] + sum > minSum && a[currentX - 1][currentY] + sum < maxSum)  {
        currentSum = a[currentX - 1][currentY];
        a[currentX - 1][currentY] = MAX;
        solve( a, currentX - 1, currentY,  fromX, fromY,
                 toX, toY, x, y, sum + a[currentX - 1][currentY] , 0, maxSum,  isGoBack, finalSolution);
        a[currentX - 1][currentY] = currentSum;
    }
    if (currentX + 1 < x && a[currentX + 1][currentY] + sum > minSum && a[currentX - 1][currentY] + sum < maxSum)  {
        currentSum = a[currentX + 1][currentY];
        a[currentX + 1][currentY] = MAX;
        solve(a, currentX + 1, currentY,  fromX, fromY,
              toX, toY, x, y, sum + a[currentX + 1][currentY], minSum, maxSum, isGoBack, finalSolution);
        a[currentX - 1][currentY] = currentSum;
    }
    if (currentY - 1 < 0 && a[currentX][currentY - 1] + sum > minSum && a[currentX][currentY - 1] + sum < maxSum)  {
        currentSum = a[currentX][currentY-1];
        a[currentX - 1][currentY] = MAX;
        solve( a, currentX, currentY-1,  fromX, fromY,
               toX, toY, x, y, sum + a[currentX - 1][currentY] , 0, maxSum,  isGoBack, finalSolution);
        a[currentX][currentY - 1] = currentSum;
    }
    if (currentY + 1 < y && a[currentX][currentY + 1] + sum > minSum && a[currentX][currentY + 1] + sum < maxSum)  {
        currentSum = a[currentX][currentY-1];
        a[currentX - 1][currentY] = MAX;
        solve( a, currentX, currentY-1,  fromX, fromY,
               toX, toY, x, y, sum + a[currentX - 1][currentY] , 0, maxSum,  isGoBack, finalSolution);
        a[currentX][currentY - 1] = currentSum;
    }

    return;
}

inline int maxValue (int a, int b) {
    return a > b ? a : b;
}
int main() {
    int n,m;
    int minSum, maxSum;
    int fromX,fromY,toX,toY;
    int a[MAXN][MAXN];

    cin>>n>>m;
    for (int i = 0;i<n;i++)
        for (int t =0;t<m;t++)
            cin>>a[i][t];

    cin>>fromX>>fromY>>toX>>toY;
        // 0
    cin>>minSum>>maxSum;
    bool finalSolution = false;
    solve(a, fromX, fromY, fromX, fromX, toX,toY, n, m,/*currentSum*/ 0,minSum, maxSum, false,finalSolution);

    cout<<finalSolution<<endl;
    return 0;

}
