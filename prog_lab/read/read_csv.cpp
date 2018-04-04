#include "read_csv.hpp"


data *read_from_file(string file_name) {
    data *result = new data();
    ifstream file(file_name);
    
    string line, buff, name;
    vector<int> v;
    
    getline(file, line);
    while (getline(file, line)) {
        buff = "";
        name = "";
        v.clear();
        
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == ',') {
                if (name.empty()) name = buff; else {
                    v.push_back(stoi(buff));
                }
                buff = "";
            } else buff += line[i];
        }
        
        result->name.push_back(name);
        result->score.push_back(v);
    }
    
    file.close();
    
    return result;
}
