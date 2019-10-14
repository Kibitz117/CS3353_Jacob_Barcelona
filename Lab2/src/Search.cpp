//
// Created by jakeb on 9/22/2019.
//
#include "Search.h"
//Loads in nodes,weights,and positions
void Search::Load(std::string fileName,std::string weights,std::string positions) {
    std::fstream dataFile;
    dataFile.open(weights);
    std::string edge;
    std::string line;
    std::map<std::pair<int,int>,int>weight_values;
    while(getline(dataFile,line)) {
        std::stringstream tokenize(line);
        std::string s;
        std::vector<std::string> tokens;
        while (getline(tokenize, s, ',')) {
            tokens.push_back(s);
        }
        int src = atoi(tokens[0].c_str());
        int dest = atoi(tokens[1].c_str());
        int weight = atoi(tokens[2].c_str());
        weight_values[std::make_pair(src, dest)] = weight;
        tokens.clear();
    }
        dataFile.close();
    dataFile.open(fileName);
    int count=0;
std::vector<std::string> streams;
    while(getline(dataFile,line))
    {
        streams.push_back(line);
        count++;

    }
    AdjList list_Graph(count);
    list=&list_Graph;
    for(int i=0;i<streams.size();i++)
    {
        std::string node;
        int count2=0;
        std::stringstream stream(streams[i]);
        while(getline((stream),node,','))
        {
            if(count2==0)
            {

            }
            else{
                int temp=atoi(node.c_str());
                int weight=weight_values[std::make_pair(i+1,temp)];
                list->addNode(i+1,temp,weight);
            }
            count2++;

        }
    }
    dataFile.close();

//        list->Find(src-1,dest-1)->setWeight(weight);
//        list->Find(dest-1,src-1)->setWeight(weight);


list_Graph.toString();
searching_Algos s;
    Graph* g=&list_Graph;
   // s.DFS_Iterative(2,8,g);
   // s.DFS_Recursive(2,8,g);
// s.BFS_Iterative(3,9,g);
 // s.BFS_Recursive(3,9,g);//WRONG
  s.Djkstra(2,12,g,weight_values);//WRONG




    //Read line tokenize commas
    //First number is adjacency nodes
    //Following are the adjacency nodes children in Linked List
    //Find way to abstract with AdjMatrix
}
void Search::Execute(){
    auto start_time = std::chrono::high_resolution_clock::now();
    (SearchAlgo)(src,dest,list);
    auto end_time = std::chrono::high_resolution_clock::now();
    time=std::chrono::duration_cast<std::chrono::nanoseconds>(end_time-start_time).count();
}//Running switch statement
void Search::Display(){
//Output tree or vector
//Make Tree a parameter by reference
}
void Search::Stats(int algo){

}
void Search::Select(int i){
//    if(i==DFS_ITER)
//    {
//        //Why isn't this line working?
//        SearchAlgo= &searching_Algos::DFS_Iterative;
//        std::cout<<"DFS Iterative"<<std::endl;
//        Execute();
//    }
//    else if(i==DFS_RECUR)
//    {
//        SearchAlgo= &searching_Algos::DFS_Recursive;
//        std::cout<<"Insertion Sort"<<std::endl;
//        Execute();
//    }
//    else if(i==BFS_ITER)
//    {
//        SearchAlgo=&searching_Algos::BFS_Iterative;
//        std::cout<<"Merge Sort"<<std::endl;
//        Execute();
//    }
//    else if(i==BFS_RECUR)
//    {
//        SearchAlgo=&searching_Algos::BFS_Recursive;
//        std::cout<<"BFS Recursive"<<std::endl;
//        Execute();
//    }
//    else
//    {
//        std::cout<<"ERROR No Sort Selected"<<std::endl;
//    }
}//Select active algorithm
void Search::Save(std::string,int,std::string){
//Change searches to return vector so just save vector path
}
void Search::Configure(){

}
void Search::Clear()
{
    //Tree and vector clear
}
