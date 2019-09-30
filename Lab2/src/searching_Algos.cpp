////
//// Created by jakeb on 9/22/2019.
////
//
//#include "searching_Algos.h"
//std::vector<std::vector<Node<int>>>& searching_Algos::DFS_Iterative(int src, int dest,AdjList<Node<int>> adj_Graph) {
//    std::stack<Node<int>>searching;
//    std::vector<std::vector<Node<int>*>>paths;
//    int curr_index=src-1;
//     Node<int>* current;
//    current=&adj_Graph.getList()[src].getEdges()[adj_Graph.Find(src,dest)];
//    searching.push(current);
//while(!searching.empty())
//{
//    for(int i=0;i<adj_Graph.getSize();i++)
//    {
//        if(adj_Graph.getList()[curr_index].getEdges().operator[](i).isVisited()==false)
//        {
//            Node<int>* temp;
//            temp->setData()=adj_Graph.getList()[src].getEdges().operator[](i).getData();
//            searching.push(temp);
//        }
//    }
//    current->setVisited(true);
//    searching.pop();
//    paths[current].push_back(searching.top());
//    current=&searching.top();
//    if(current->getData()==dest)
//        break;
//    curr_index=current->getData()-1;
//
//}
//
//
//    return paths;
//}