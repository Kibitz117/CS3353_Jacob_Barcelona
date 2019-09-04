//
// Created by jakeb on 9/3/2019.
//

#ifndef SRC_DATASETCREATOR_H
#define SRC_DATASETCREATOR_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>
#include <fstream>
class DataSetCreator {
public:
    std::vector<int> random(int);
    std::vector<int>reverse(int);
    std::vector<int>partiallyRandom(int);
    std::vector<int>TwentyPercentUnique(int);
    void dataFile(std::vector<int>);
private:
};


#endif //SRC_DATASETCREATOR_H
