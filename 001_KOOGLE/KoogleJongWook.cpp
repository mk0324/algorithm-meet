#include<iostream>
#include<string>
using namespace std;

int main() {
  int cases;
  cin >> cases;

  // log(26)
  const long double conversion = 1.41497334797081796442024405266682145759791906984917681311161843612466128;

  while(cases--) {
    int N;
    cin >> N;

    long double maxVal = 0;
    string maxText;
    long double curVal;
    string curText;

    while(N--) {
      cin >> curText;
      curVal = 0;

      // Calculate the log(strength)
      for (char& c : curText) {
        if ('0' <= c && c <= '9') {
          curVal = curVal + 1;
        } else {
          curVal = curVal + conversion;
        }
      }

      // Update the max value
      if (curVal > maxVal) {
        maxVal = curVal;
        maxText = curText;
      } else if (curVal == maxVal) {
        // The dictionary order rule
        if (curText < maxText) {
            maxText = curText;
        }
      }
    }

    cout << maxText << endl;
  }

  return 0;
}

