//
// Created by jakeb on 10/20/2019.
//

#include "FileLoader.h"

StructureHandler* FileLoader::load(const std::string &path,int structure) {
std::fstream dataFile;
dataFile.open(path);
std::string line;
    structure_type=StructureFactory::Create(StructureFactory::structure_type(structure));
    while(getline(dataFile,line))
    {
//Create a StuctureHandler pointer from the factory based on the users input of a structure
    structure_type->addLine(line);
    }
    dataFile.close();
    return structure_type;
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