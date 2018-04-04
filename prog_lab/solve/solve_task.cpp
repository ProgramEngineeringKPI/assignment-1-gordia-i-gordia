#include "solve_task.hpp"
#include <map>

vector< pair<int, string> > *solve(data* dt) {
    vector< pair<int, string> > *result = new vector< pair<int, string> >();
    map<string, int> pos;
    
    for (int i = 0; i < dt->name.size(); i++) {
        pos[dt->name[i]] = i;
        result->push_back(make_pair(0, dt->name[i]));
    }
    
    for (int i = 0; i < dt->score[0].size(); i++) {
        vector< pair<int, string> > v;
        for (int j = 0; j < dt->name.size(); i++)
            v.push_back(make_pair(dt->score[j][i], dt->name[j]));
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());

        (*result)[ pos[v[0].second] ].first += 12;
        (*result)[ pos[v[1].second] ].first += 10;
        for (int j = 3; j < 11; j++)
            (*result)[ pos[v[j].second] ].first += (11 - j);
    }
    
    sort(result->begin(), result->end());
    
    return result;
}
