//
// Created by jakeb on 9/4/2019.
//

#ifndef SORTING_ALGORITHMS_PROJECT_SORT_ALGOS_H
#define SORTING_ALGORITHMS_PROJECT_SORT_ALGOS_H



class Sort_Algos {
public:
   template <typename T>
   static void bubble_Sort (T &data) {
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
    template <typename T>
    static void insertion_Sort(T &data)
    {
        
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
