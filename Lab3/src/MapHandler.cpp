//
// Created by jakeb on 10/22/2019.
//

#include "MapHandler.h"
void MapHandler::addLine(std::string line) {
    std::stringstream tokenize(line);
    std::string s;
    std::vector<std::string>tokens;
    while (getline(tokenize,s,','))
        tokens.push_back(s);
    int node=atoi(tokens[0].c_str());
    int x=atoi(tokens[1].c_str());
    int y=atoi(tokens[2].c_str());
    int z=atoi(tokens[3].c_str());
    node_map[node].push_back(x);
    node_map[node].push_back(y);
    node_map[node].push_back(z);
    tokens.clear();
}