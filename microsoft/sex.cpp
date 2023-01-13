// kk #include <algorithm>

#include <bits/stdc++.h>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// int solution(vector<Point2D> &A) {
// write your code in C++14 (g++ 6.2.0)
// } }} }} } }


struct pair_hash
{
    size_t operator()(const pair<int, int> &pair) const
    {
        return hash<int>()(pair.first) ^ hash<int>()(pair.second);
    }
};

int gcd(pair<int, int> &frac)
{
    int a = frac.first;
    int b = frac.second;
    int t;
    while (b != 0)
    {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}
pair<int, int> simp_frac(pair<int, int> &frac) {

    int gcdR = gcd(frac);
    return make_pair((int)unsimp_frac.first / gcdR, (int)unsimp_frac.second / gcdR);

}
pair<int, int> getSlope(Point2D &p1, Point2D &p2)
{
    int denom = p1.x - p2.x;
    int num = p1.y - p2.y;
    pair<int, int> x = make_pair(abs(num), abs(denom));
    x = simp_frac(ret);
    if (num < 0)
    {
        x.first *= -1;
        x.second *= -1;
    }
    return x;
}
int solution(vector<Point2D> &A)
{
    int colls = 0;
    for (int i = 0; i < A.size(); ++i)
    {
        unordered_map<pair<int, int>, vector<int>, pair_hash> pivot_map;
        for (int j = i + 1; j < A.size(); ++j)
        {
            unordered_map<pair<int, int>, vector<int>, pair_hash>::iterator slope_iterator = pivot_map.find(getSlope(A[i], A[j]));
            if (slope_iterator == pivot_map.end())
            {
                pivot_map.insert(make_pair(getSlope(A[i], A[j]), vector<int>{j}));
            }
            else
            {
                (slope_iterator->second).push_back(j);
            }
        }
        for (unordered_map<pair<int, int>, vector<int>, pair_hash>::iterator iter = pivot_map.begin(); iter != pivot_map.end(); ++iter)
        {
            colls += (iter->second).size() * ((iter->second).size() - 1) / 2;
        }
    }
    return colls;
}
