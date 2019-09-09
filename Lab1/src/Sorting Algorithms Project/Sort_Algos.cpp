//
// Created by jakeb on 9/4/2019.
//

#include "Sort_Algos.h"
void Sort_Algos::bubble_Sort(std::vector<int> &data) {
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
void Sort_Algos::merge_Sort(std::vector<int> &array) {
    if(array.size()==1)
    {

    }
    else{
        merge_Divide(array,1,array.size()-1);
    }
}
void Sort_Algos::merge_Divide(std::vector<int> &array, int L, int R) {
    if(L<R)
    {
        int M=((L+R))/2;
        merge_Divide(array,L,M);
        merge_Divide(array,M+1,R);
        merge_Build(array,L,M,R);
    }
}
void Sort_Algos::merge_Build(std::vector<int> &array, int L, int M, int R) {
    std::vector<int>temp;
    int k=0;
    while(L<=M&&(M+1)<=R)
    {
        if(array[L]<=array[M+1])
        {
            temp[k]=array[L];
            k++;
            M++;
        }
        else{
            temp[k]=array[M+1];
            k++;
            M++;

        }
    }

       if(array[L]<array[R])
       {
           temp.push_back(array[L]);
           L++;
       }
       else{
           temp.push_back(array[R]);
           R++;
       }
       for(int i=L;i<=R;i++)
       {
           array[i]=temp[i-L];
       }




}