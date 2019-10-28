//
// Created by jakeb on 10/23/2019.
//

#ifndef SRC_STRUCTUREFACTORY_H
#define SRC_STRUCTUREFACTORY_H

#include "MapHandler.h"
#include "StructureHandler.h"

class StructureFactory {
public:
    enum structure_type{
        MAP=0,
        VECTOR
    };
    static StructureHandler* Create(int i);
};


#endif //SRC_STRUCTUREFACTORY_H
