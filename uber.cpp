#include <bits/stdc++.h>

using namespace std;
int solution(vector<int> costs, int uberCredits) {
    sort(costs.begin(),costs.end());
    int sum,i;
    for(i=0; i<costs.size(); sum<=uberCredits,i++){
        sum=costs.at(i);
    }
    return i;
    
}

int main(){
    vector<int> costs;
    int ubercredits,len;
    cin>> len>> ubercredits;
    for(int i=0;i<len;i++){
        int cost;
        cin<<cost;
        costs.pushback(cost);
    }
    cout<< solution(costs, ubercredits);
}
