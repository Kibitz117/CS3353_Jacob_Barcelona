//
// Created by jakeb on 10/20/2019.
//

#include "FileLoader.h"

void FileLoader::load(const std::string &path,int structure) {
std::map<int,std::vector<float>>node_map;
std::fstream dataFile;
dataFile.open(path);
std::string line;
    while(getline(dataFile,line))
    {
//        std::stringstream tokenize(line);
//        std::string s;
//        std::vector<std::string>tokens;
//        while (getline(tokenize,s,','))
//            tokens.push_back(s);
//        int node=atoi(tokens[0].c_str());
//        int x=atoi(tokens[1].c_str());
//        int y=atoi(tokens[2].c_str());
//        int z=atoi(tokens[3].c_str());
//        node_map[node].push_back(x);
//        node_map[node].push_back(y);
//        node_map[node].push_back(z);
//        tokens.clear();
//Create a StuctureHandler pointer from the factory based on the users input of a structure
    structure_type=StructureFactory::Create(StructureFactory::structure_type(structure));
    structure_type->addLine(line);

    }
    dataFile.close();
}
void FileLoader::output(std::vector<int>&path,std::string&filepath) {
    std::ofstream out;
    out.open(filepath);
    for(int i=0;i<path.size();i++)
    {
        out<<path[i]<<std::endl;
    }
    out.close();
}