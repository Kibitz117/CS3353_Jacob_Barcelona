//
// Created by jakeb on 10/20/2019.
//

#ifndef SRC_FILELOADER_H
#define SRC_FILELOADER_H

#include <fstream>
#include <map>
#include <vector>
#include <sstream>
#include "StructureFactory.h"
class FileLoader {
public:
void load(const std::string& path,int select_structure,StructureHandler*&);
 void output(std::vector<int>&path,std::string& filepath);
private:
};


#endif //SRC_FILELOADER_H
