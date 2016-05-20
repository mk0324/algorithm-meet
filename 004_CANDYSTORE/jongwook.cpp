#include <iostream>
#include <map>
using namespace std;

int main() {
    while(true) {
        int n, intM;
        double m;
        cin >> n;
        cin >> m;
        intM = (int) (100 * m + 0.5);
        if (n == 0 && m == 0.00)
            break;

        // Maximum calories for each money
        int* money;
        money = new (nothrow) int [intM + 1];
        for (int i = 0; i <= intM; i++) {
            money[i] = 0;
        }

        // Get the inputs and store a map of possible candies
        map<int, int> value_map;
        value_map[1] = 0;
        while (n--) {
            int cal;
            float price;
            cin >> cal;
            cin >> price;
            int intPrice = (int) (100 * price + 0.5);

            if (value_map.count(intPrice) > 0) {
                if (cal > value_map.at(intPrice)) {
                    value_map.at(intPrice) = cal;
                }
            } else {
                value_map[intPrice] = cal;
            }
        }



        // find maximum for each value now
        for (int i = 1; i<= intM; i++) {
            int curMax = 0;
            for (map<int,int>::iterator it=value_map.begin(); it!=value_map.end(); ++it) {
                int p = it->first;
                int c = it->second;
                if (p <= i) {
                    int curVal = c + money[i - p];
                    if (curVal > curMax) {
                        curMax = curVal;
                    }
                }
            }
            money[i] = curMax;
        }
        cout << money[intM] << endl;
    }
}
