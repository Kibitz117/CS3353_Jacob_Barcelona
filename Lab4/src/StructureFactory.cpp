//
// Created by jakeb on 10/23/2019.
//

#include "StructureFactory.h"
StructureHandler* StructureFactory::Create(int i) {
    StructureHandler* pStruct;
    switch (i)
    {
        case MAP:
            pStruct=new MapHandler();
            break;

        default:
            pStruct=nullptr;
    }
    return pStruct;
}