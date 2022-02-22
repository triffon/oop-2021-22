#include <iostream>
using namespace std;

void solve(int n, int m, int* sol, const int &originalN) {
    if ( n == 0 && m == 0 ) { // We have a solution
        for (int i = originalN-1; i >= 0; i--)
            cout<<sol[i]<< " ";
        cout<<endl;
        return;
    }
    if (n == 0) {
        return; // We didn`t generate the correct sum
    }

    for (int i = 0; i <= m; i++) {
        sol[n-1] = i;
        solve(n-1, m-i , sol, originalN);
    }
    return;
}

int main() {
    int* a = new (std::nothrow) int;
//
//    try {
//        a = new int;
//    } catch (...) {
//
//    }

    if (!a) {
        cout<<"Not allocated memory"<<endl;
    }
    delete a;

    int n,m;
    cin>>n>>m;
    int* sol = new (std::nothrow) int[n];
    if (!sol) { // error
        return 0;
    }

    solve(n, m, sol, n);
    delete [] sol;

    return 0;
}
