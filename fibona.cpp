#include <iostream>
#include <map>

using namespace std;

int step_rec = 0;
int step_it = 0;

int fib_rec(int n) {
    step_rec += 1;
    if (n <= 1) {
        return n;
    } else {
        return fib_rec(n-1) + fib_rec(n-2);
    }
}

int fib_it(int n) {
    step_it += 1;

    if (n <= 1){
        return n;
    }

    int fib;
    int pre = 1;
    int post = 2;
    
    for (int i=0; i<n-2; i++) {
        fib = pre+post;
        pre = post;
        post = fib;
        step_it += 1;
    }

    return pre;
}

int main() {
    int n;
    cin >> n;
    cout << "Term " << n << " using recursion is " << fib_rec(n) << " in " << step_rec << " steps\n";
    cout << "Term " << n << " using iteration is " << fib_it(n) << " in " << step_it << " steps\n";

    return 0;
}

