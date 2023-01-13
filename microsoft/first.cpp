#include<bits/stdc++.h>

using namespace std;

struct pairingHash {
    size_t operator()(const pair<int, int> &pair) const {
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
pair<int, int> simp_frac(pair<int, int> &unsimp_frac)
{
    int gcd_p = gcd(unsimp_frac);
    return make_pair((int)unsimp_frac.first / gcd_p, (int)unsimp_frac.second / gcd_p);
}
pair<int, int> get_slope(Point2D &p1, Point2D &p2)
{
    int num = p1.y - p2.y;
    int denom = p1.x - p2.x;
    pair<int, int> ret = make_pair(abs(num), abs(denom));
    ret = simp_frac(ret);
    if (num < 0)
    {
        ret.first *= -1;
        ret.second *= -1;
    }
    return ret;
}
int solution(vector<Point2D> &A)
{
    int colls = 0;
    for (int i = 0; i < A.size(); ++i)
    {
        unordered_map<pair<int, int>, vector<int>, pairingHash> pivot_map;
        for (int j = i + 1; j < A.size(); ++j)
        { //
            unordered_map<pair<int, int>, vector<int>, pairingHash>::iterator slope_iterator = pivot_map.find(get_slope(A[i], A[j]));
            if (slope_iterator == pivot_map.end())
            {
                pivot_map.insert(make_pair(get_slope(A[i], A[j]), vector<int>{j}));
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