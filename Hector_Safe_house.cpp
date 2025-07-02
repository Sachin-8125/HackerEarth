#include<iostream>
#include<cmath>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        cout << (int)dist << endl;
    }
    return 0;
}