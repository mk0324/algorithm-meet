#include<iostream>
#include<string>
using namespace std;


int main() {
    int cases;
    cin >> cases;

    while(cases--) {
        int N;
        cin >> N;

        int *price = new int[N];
        int curMax;
        long long int profit = 0;

        // Get the prices input
        for (int i = 0; i < N; i++) {
            cin >> price[i];
        }
        curMax = price[N - 1];

        // Got from the back and find optimal trades
        for (int i = N - 2; i >= 0; i--) {
            if (curMax > price[i]) {
                profit += curMax - price[i];
            } else {
                curMax = price[i];
            }
        }

        cout << profit << endl;
        delete[] price;
    }
    return 0;
}
