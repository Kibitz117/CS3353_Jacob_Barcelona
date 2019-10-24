//
// Created by jakeb on 10/23/2019.
//

#include "StructureFactory.h"
StructureHandler* StructureFactory::Create(StructureFactory::structure_type) {
    StructureHandler* pStruct;
    int i;
    switch (i)
    {
        case StructureFactory::MAP:
            pStruct=new MapHandler();
            break;

        default:
            pStruct=nullptr;
    }
    return pStruct;
}