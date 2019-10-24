//
// Created by jakeb on 10/22/2019.
//

#ifndef SRC_MAPHANDLER_H
#define SRC_MAPHANDLER_H

#include <vector>
#include <map>
#include "StructureHandler.h"
#include <sstream>
class MapHandler: public StructureHandler {
public:
 virtual void addLine(std::string s);

private:
    std::map<int,std::vector<float>>node_map;
};


#endif //SRC_MAPHANDLER_H
