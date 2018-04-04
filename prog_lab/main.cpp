#include <iostream>
#include "solve/solve_task.hpp"
using namespace std;

int main() {
    data *dt = read_from_file("/Users/nikitagordia/Documents/Workspace/XCodeProjects/prog_lab/prog_lab/eurovision.csv");
    
    vector< pair<int, string> > *res = solve(dt);
    
    for (int i = 0; i < res->size(); i++)
        cout<<(*res)[i].second<<" "<<(*res)[i].first<<endl;
    
}
