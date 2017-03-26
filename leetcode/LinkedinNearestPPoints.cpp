
vector<pair<int, int>> getNearestKPointsOfAGivenCenter(<vector<pair<int, int>>> v, 
        pair<int, int>center, int k)
{
    multi_map<int, pair<int, int>> m;
    for(int i=0; i<v.size(); i++) {
        int distance = (v[i].first-center.first)*(v[i].first-center.first)
            + (v[i].second-center.second)*(v[i].second-center.second);
        m.insert({distance, v[i]});
    }
    vector<pair<int, int>> ret;
    for(auto it=m.begin(), int i=0; it!=m.end()&&i<k; it++, i++) {
        ret.push_back(it->second);
    }
}
