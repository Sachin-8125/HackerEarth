#include <bits/stdc++.h>
using namespace std;

int occurrence(const vector<int>& a, int digit) {
    int count = 0;
    for (const int& num : a) {
        int temp = abs(num);  // Handle negatives if needed

        // Remove trailing zeros
        while (temp > 0 && temp % 10 == 0)
            temp /= 10;

        bool found = false;
        int current = temp;
        while (current > 0) {
            if (current % 10 == digit) {
                found = true;
                break;
            }
            current /= 10;
        }
        if (found)
            count++;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& num : a)
        cin >> num;

    vector<int> digit_counts(10, 0);
    for (int d = 0; d < 10; ++d)
        digit_counts[d] = occurrence(a, d);

    int max_count = *max_element(digit_counts.begin(), digit_counts.end());
    cout << max_count << "\n";
    return 0;
}

 

count[i] = occurence(a,n,i);


 

}

int max = count[0];

for(int i = 1; i < 10; i++)

{

if(count[i] > max)

{

max = count[i];

}

}

cout << max << "\n";

}