#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int test_cases;
    cin >> test_cases; // Number of test cases

    for (int t = 0; t < test_cases; t++) {
        int length;
        cin >> length; // Length of the list arr
        vector<int> arr(length); // List of integers

        for (int i = 0; i < length; i++) {
            cin >> arr[i];
        }

        map<int, int> counts;
        for (int x : arr) {
            counts[x]++;
        }

        vector<int> frequent_elements;
        for (const auto& pair : counts) {
            if (pair.second >= 2) {
                frequent_elements.push_back(pair.first);
            }
        }

        if (frequent_elements.size() < 2) {
            cout << -1 << endl;
        } else {
            vector<int> result;
            bool first_occurred = false, second_occurred = false;
            for (int x : arr) {
                if (x == frequent_elements[0]) {
                    result.push_back(first_occurred ? 2 : 1);
                    first_occurred = true;
                } else if (x == frequent_elements[1]) {
                    result.push_back(second_occurred ? 3 : 1);
                    second_occurred = true;
                } else {
                    result.push_back(1);
                }
            }

            for (int x : result) {
                cout << x << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}
