#include <iostream>
#include <string>

using namespace std;

int main() {
    // ...
    ios::sync_with_stdio(false);
    int n;
    string a;
    cin >> a >> n;

    while (n--) {
        string s;
        cin >> s;

        int sum(0);
        for (auto i : s)
            sum += (i - 48);

        while (sum > 9) {

            int temp(0);
            while (sum) {
                temp += sum % 10;
                sum /= 10;
            }

            sum = temp;
        }

        cout << a[sum];
    }

    return 0;
}