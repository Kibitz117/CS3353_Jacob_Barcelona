//
// Created by jakeb on 11/14/2019.
//

#ifndef SRC_TSPINTERFACE_H
#define SRC_TSPINTERFACE_H


class TSPInterface {
//This class will use the strategy pattern to dynamically switch between GA techniques or Tabu techniques depending on the current
//algorithm
virtual void Run(int)=0;
};


#endif //SRC_TSPINTERFACE_H
