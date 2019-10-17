//
// Created by jakeb on 9/22/2019.
//
#include "Search.h"
//Loads in nodes,weights,and positions
float Search::avg_time=0;
int Search::avg_nodes_explored=0;
int Search::avg_path_nodes=0;
int Search::count=0;
double Search::avg_cost=0.0;
double Search::avg_distance=0.0;
void Search::Load(std::string fileName,std::string weights,std::string positions,int graph) {
    std::fstream dataFile;
    dataFile.open(weights);
    std::string edge;
    std::string line;
    std::map<std::pair<int,int>,double>weight_values;
    while(getline(dataFile,line)) {
        std::stringstream tokenize(line);
        std::string s;
        std::vector<std::string> tokens;
        while (getline(tokenize, s, ',')) {
            tokens.push_back(s);
        }
        int src = atoi(tokens[0].c_str());
        int dest = atoi(tokens[1].c_str());
        double weight = atof(tokens[2].c_str());
        weight_values[std::make_pair(src, dest)] = weight;
        tokens.clear();
    }
        dataFile.close();
    dataFile.open(positions);
    while(getline(dataFile,line))
    {
        std::stringstream tokenize(line);
        std::string s;
        std::vector<std::string>tokens;
        while (getline(tokenize,s,','))
            tokens.push_back(s);
        int node=atoi(tokens[0].c_str());
        int x=atoi(tokens[1].c_str());
        int y=atoi(tokens[2].c_str());
        int z=atoi(tokens[3].c_str());
        node_positions[node].push_back(x);
        node_positions[node].push_back(y);
        node_positions[node].push_back(z);
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
    if(graph==0)
    {
        AdjList *list_Graph=new AdjList(count);
        list=list_Graph;
    }
    else
    {
        AdjMatrix *list_Graph=new AdjMatrix(count);
        list=list_Graph;
    }

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
    this->weight_values=weight_values;
}
void Search::Execute(int src,int dest){
    auto start_time = std::chrono::high_resolution_clock::now();
    path=(SearchAlgo)(src,dest,list,weight_values,node_positions);
    auto end_time = std::chrono::high_resolution_clock::now();
    time=std::chrono::duration_cast<std::chrono::nanoseconds>(end_time-start_time).count();
}//Running switch statement
void Search::Display(){
//Output tree or vector
//Make Tree a parameter by reference
}
void Search::Stats(int algo){
    if(algo==DFS_ITER)
    {
        std::cout<<"DFS Iterative"<<std::endl;
        //Output path
        for(int i=0;i<path.size()-1;i++)
        {
            std::cout<<path[i]<<" ";
        }
        std::cout<<std::endl;
        //Vector size
        std::cout<<"Number of nodes in path:"<<path.size()<<std::endl;
        Search::avg_path_nodes+=path.size();
        //this->avg_path.push_back(path.size());
        //Tree Size
        Search::avg_time+=time;
        std::cout<<"Time of execution: "<<time<<" ns"<<std::endl;
       // times.push_back(time);
        //Nodes Explored
        Search::avg_nodes_explored+=path[path.size()-1];
        std::cout<<"Nodes explored: "<<path[path.size()-1]<<std::endl;
        //this->avg_nodes.push_back(path[path.size()-1]);
        Search::count++;
    }
    else if(algo==DFS_RECUR)
    {
        std::cout<<"DFS Recursive"<<std::endl;
        //Output path
        for(int i=0;i<path.size();i++)
        {
            std::cout<<path[i]<<" ";
        }
        std::cout<<std::endl;
        //Vector size
        std::cout<<"Number of nodes in path:"<<path.size()<<std::endl;
        //Not sure for nodes explored
        std::cout<<"Time of execution: "<<time<<" ns"<<std::endl;

        Search::avg_path_nodes+=path.size();
        Search::avg_time+=time;
        Search::avg_nodes_explored+=path[path.size()-1];
        Search::count++;
    }
    else if(algo==BFS_ITER)
    {
        std::cout<<"BFS Iterative"<<std::endl;
        //Output path
        for(int i=0;i<path.size()-1;i++)
        {
            std::cout<<path[i]<<" ";
        }
        std::cout<<std::endl;
        //Vector size
        std::cout<<"Number of nodes in path:"<<path.size()<<std::endl;
        //Tree Size
        std::cout<<"Time of execution: "<<time<<" ns"<<std::endl;
        //Nodes Explored
        std::cout<<"Nodes explored: "<<path[path.size()-1]<<std::endl;
        Search::avg_path_nodes+=path.size();
        Search::avg_time+=time;
        Search::avg_nodes_explored+=path[path.size()-1];
        Search::count++;

    }
    else if(algo==BFS_RECUR)
    {
        std::cout<<"BFS Recursive"<<std::endl;
        //Output path
        for(int i=0;i<path.size();i++)
        {
            std::cout<<path[i]<<" ";
        }
        std::cout<<std::endl;
        std::cout<<"Number of nodes in path:"<<path.size()<<std::endl;
        //Vector size
        //Not sure for nodes explored
        std::cout<<"Time of execution: "<<time<<" ns"<<std::endl;
        Search::avg_path_nodes+=path.size();
        Search::avg_time+=time;
        Search::avg_nodes_explored+=path[path.size()-1];
        Search::count++;


    }
    else if(algo==DJKSTRA)
    {
        std::cout<<"Djkstra"<<std::endl;
        //Output path
        for(int i=0;i<path.size()-1;i++)
        {
            std::cout<<path[i]<<" ";
        }
        std::cout<<std::endl;
        //Vector size
        std::cout<<"Number of nodes in path:"<<path.size()<<std::endl;
        //Cost
        std::cout<<"Cost: "<<weight_values[std::make_pair(path[0],path[path.size()-2])]<<std::endl;
        //TREE POINTER SAME AS VECTOR THINGY
        //Tree Size
        std::cout<<"Time of execution: "<<time<<" ns"<<std::endl;
        //Nodes Explored
        std::cout<<"Nodes explored: "<<path[path.size()-1]<<std::endl;
        Search::avg_path_nodes+=path.size();
        Search::avg_time+=time;
        Search::avg_nodes_explored+=path[path.size()-1];
        Search::count++;
        Search::avg_cost+=weight_values[std::make_pair(path[0],path[path.size()-1])];
    }
    else if(algo==A_STAR)
    {
        std::cout<<"A*"<<std::endl;
        //Output path
        for(int i=0;i<path.size()-1;i++)
        {
            std::cout<<path[i]<<" ";
        }
        std::cout<<std::endl;
        //Vector size
        std::cout<<"Number of nodes in path:"<<path.size()<<std::endl;
        //Cost
        std::cout<<"Cost: "<<weight_values[std::make_pair(path[0],path[path.size()-2])]<<std::endl;
        //TREE POINTER SAME AS VECTOR THINGY
        std::cout<<"Distance: "<<weight_values[std::make_pair(path[path.size()-2],path[0])]<<std::endl;
        //Tree Size
        std::cout<<"Time of execution: "<<time<<" ns"<<std::endl;
        //Nodes Explored
        std::cout<<"Nodes explored: "<<path[path.size()-1]<<std::endl;
        Search::avg_path_nodes+=path.size();
        Search::avg_time+=time;
        Search::avg_nodes_explored+=path[path.size()-1];
        Search::count++;
        Search::avg_cost+=weight_values[std::make_pair(path[0],path[path.size()-1])];
        Search::avg_distance+=weight_values[std::make_pair(path[path.size()-2],path[0])];
    }
    else
    {
        std::cout<<"ERROR No Sort Selected"<<std::endl;
    }
    //Next steps: change output from void to vector path, load in other graphs, figure out nodes explored for recursive
}
void Search::Select(int i){
    if(i==DFS_ITER)
    {
        SearchAlgo= &searching_Algos::DFS_Iterative;
    }
    else if(i==DFS_RECUR)
    {
        SearchAlgo= &searching_Algos::DFS_Recursive;
    }
    else if(i==BFS_ITER)
    {
        SearchAlgo=&searching_Algos::BFS_Iterative;
    }
    else if(i==BFS_RECUR)
    {
        SearchAlgo=&searching_Algos::BFS_Recursive;
    }
    else if(i==DJKSTRA)
    {
       SearchAlgo=&searching_Algos::Djkstra;
    }
    else if(i==A_STAR)
    {
        SearchAlgo=&searching_Algos::A_Star;
    }
    else
    {
        std::cout<<"ERROR No Sort Selected"<<std::endl;
    }
}//Select active algorithm
void Search::Save(std::string path,int i,std::string filename){
    std::ofstream out;
    path+=filename;
    //Save vector path to file also name file based on algo and graph size
}
void Search::Configure(){

}
void Search::Clear()
{
    //Tree and vector clear
    path.clear();
    //Tree private data member clear
}
void Search::load_Test_Nodes(std::string fileName) {
    std::fstream dataFile;
    dataFile.open(fileName);
    std::string line;
    while(getline(dataFile,line))
    {
        std::stringstream tokenize(line);
        std::string s;
        std::vector<std::string>tokens;
        while(getline(tokenize,s,' '))
        {
            tokens.push_back(s);
        }
        int src=atoi(tokens[0].c_str());
        int dest=atoi(tokens[1].c_str());
        test_Nodes[src]=dest;

    }
    dataFile.close();
}
std::map<int,int>& Search::get_Test_Nodes() {
    return test_Nodes;
}
void Search::printAverages() {
//    for(int i=0;i<avg_path.size();i++)
//    {
//        avg_path_nodes+=avg_path[i];
//    }
//    for(int i=0;i<avg_nodes.size();i++)
//    {
//        avg_nodes_explored+=avg_nodes[i];
//    }
//    for(int i=0;i<times.size();i++)
//    {
//       avg_time+=times[i];
//    }
    std::cout<<"Average path size: "<<Search::avg_path_nodes/Search::count<<std::endl;
    std::cout<<"Average nodes explored: "<<Search::avg_nodes_explored/Search::count<<std::endl;
    std::cout<<"Average time "<<Search::time/Search::count<<std::endl;
    std::cout<<"Average distance "<<Search::avg_distance/Search::count<<std::endl;
    std::cout<<"Average cost "<<Search::avg_cost/Search::count<<std::endl;
    Search::avg_nodes_explored=0;
    Search::avg_path_nodes=0;
    Search::time=0;
    Search::count=0;
    Search::avg_cost=0;
    Search::avg_distance=0;
}