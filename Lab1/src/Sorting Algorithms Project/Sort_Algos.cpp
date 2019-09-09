//
// Created by jakeb on 9/4/2019.
//

#include "Sort_Algos.h"
static void Sort_Algos::bubble_Sort(std::vector<int> &data) {
        bool sorted;

        for(int i=0;i<data.size();i++)
        {
            sorted=false;
            for(int x=0;x<data.size()-1;x++)
            {
                //Checks if the current is bigger than the next element
                if(data[x]>data[x+1])
                {
                    swap(&data[x],&data[x+1]);
                    sorted=true;
                }
            }
            if(!sorted)
                break;

        }

}