#include <bits/stdc++.h>

using namespace std;

int minCost(string S, vector<int> &C) {

    int output = 0;
    int sizest = S.size();

    for (int i = 0; i + 1 < sizest; ++i){
        if (S[i] != S[i + 1]){
            continue;
        }
        if (C[i] > C[i + 1]) {

            swap(C[i], C[i + 1]);
        }

        output += C[i];
    }

    return output;
}

int main()
{   
    string s = "abccbd";

    vector<int> ar = {0, 1, 2, 3, 4, 5};

    cout << minCost(s, ar);

    return 0;
}
