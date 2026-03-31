#include<bits/stdc++.h>
using namespace std;

long long solve (int N, int start, int finish, vector<int> Ticket_cost) {
   // Write your code here
    if(start>finish) swap(start, finish);
    long long direct_cost = 0;
    start--; finish--;
    for(int i=start; i<finish; ++i){
        direct_cost += Ticket_cost[i];
    }
    long long total_cost = 0;
    for(int i=0;i<N;++i){
        total_cost += Ticket_cost[i];
    }
    long long circular_cost = total_cost-direct_cost;
    return min(direct_cost, circular_cost);
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int start;
    cin >> start;
    int finish;
    cin >> finish;
    vector<int> Ticket_cost(N);
    for(int i_Ticket_cost = 0; i_Ticket_cost < N; i_Ticket_cost++)
    {
    	cin >> Ticket_cost[i_Ticket_cost];
    }

    long long out_;
    out_ = solve(N, start, finish, Ticket_cost);
    cout << out_;
}