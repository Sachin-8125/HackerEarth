#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for(int i = 0; i < n; ++i)
        cin >> a[i];
    
    for(int i = 0; i < n; ++i)
        cin >> b[i];

    int count = 0;
    int mi = *min_element(a.begin(), a.end());
    int i = 0;

    while(i < n) {
        if(a[i] >= b[i]) {
            while(a[i] > mi) {
                a[i] -= b[i];
                count++;
            }
        }
        if(a[i] < mi) {
            mi = a[i];
            i = 0;
            continue;
        }
        if(a[i] != mi) {
            count = -1;
            break;
        }
        i++;
    }

    cout << count << endl;
    return 0;
}


