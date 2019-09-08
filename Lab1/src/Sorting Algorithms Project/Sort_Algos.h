//
// Created by jakeb on 9/4/2019.
//

#ifndef SORTING_ALGORITHMS_PROJECT_SORT_ALGOS_H
#define SORTING_ALGORITHMS_PROJECT_SORT_ALGOS_H


#include <vector>
class Sort_Algos {
public:
    Sort_Algos();
   static void bubble_Sort (std::vector<int> &data);

    template <typename T>
    static void insertion_Sort(T &data)
    {
        for(int i=1;i<data.size();i++)
        {
            int x=data[i];
            int a=i-1;
            while(a>=0&&data[a]>x)
            {
                data[a+1]=data[a];
                a--;
            }
            data[a+1]=x;
        }
    }

private:
    template<typename T>
//swaps the elements specified
    static void swap(T *a, T *b)
    {
        T temp=*a;
        *a=*b;
        *b=temp;
    }
};


#endif //SORTING_ALGORITHMS_PROJECT_SORT_ALGOS_H
