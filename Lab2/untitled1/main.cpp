#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
int main() {
    std::ofstream out;
    std::string path="Data_Point_Nodes(2).txt";
    std::vector<int>nodes;
    std::map<std::pair<int,int>,bool>node_pairs;
    nodes.reserve(16);
    for(int i=1;i<=16;i++)
    {
        nodes.push_back(i);
    }
    while(node_pairs.size()<100)
    {
       std::random_shuffle(nodes.begin(),nodes.end());
       int src=nodes[0];
       int dest=nodes[1];
       if(!node_pairs[std::make_pair(src,dest)])
        node_pairs[std::make_pair(src,dest)]=true;
    }
    out.open(path);
    for(std::map<std::pair<int,int>,bool>::iterator it=node_pairs.begin();it!=node_pairs.end();++it)
    {
        out<<it->first.first<<" "<<it->first.second<<std::endl;
    }
}