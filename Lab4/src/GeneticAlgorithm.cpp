//
// Created by jakeb on 11/14/2019.
//

//SOMEWHERE VALUES AREN'T GETTING INTIALIZED MAYBE NEW OPERATOR
//Something with erasing from vector maybe pair of bool and tour so can't get repeats
//TRY IF tour[pos]==null fill with leftover value
//Roulette wheel returning empty tours maybe?
//Check if population empty tour
//Tomorrow do tabu search then come back to Genetic
#include "GeneticAlgorithm.h"
//
GeneticAlgorithm::GeneticAlgorithm(int src,int size,std::vector<int>path,std::map<int,std::vector<float>>&node_map) {
    //Set global best and update it
    global_best.setCost(9999999);
    setMap(node_map);
    this->src=src;
    for(int i=0;i<size;i++)
    {
        Tour t;
        t.generateTour(path);
        t.calcFitness(src,this->node_map);
        if(t.getCost()<global_best.getCost())
        {
            global_best=t;
        }
        population.push_back(t);
    }
}
void GeneticAlgorithm::rouletteWheel(Tour&parent) {
    float total_fitness=0.0;
    //Calculate the total fitness
    for(int i=0;i<population.size();i++)
    {
        total_fitness+=population[i].getFitness();
    }
    //Set each tour's(chromosome) probability
    for(int i=0;i<population.size();i++)
    {
        population[i].setProbability(total_fitness);
    }
   // float randNum = (0 + 1) + (((float) rand()) / (float) RAND_MAX) * (total_fitness - (0 + 1));
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = total_fitness - 0;
    float r = random * diff;
    float randNum= 0 + r;
    int count=0;
    while(randNum<total_fitness)
    {
        randNum+=population[count].getFitness();
        count++;
    }
    parent=population[count-1];
    //population.erase(population.begin()+count);

}
void GeneticAlgorithm::elitism(Tour&parent) {
    double high=0;
    int high_index;
    for(int i=0;i<population.size();i++)
    {
        double to_compare=population[i].getFitness();
        if(to_compare>high)
        {
            parent=population[i];
            high=to_compare;
            high_index=i;
        }
    }
    //population.erase(population.begin()+high_index);
}

Tour GeneticAlgorithm::one_Point_Crossover(Tour &parent1,Tour& parent2) {
    Tour child;
    srand(time(NULL));
    int cross_index=(rand() % parent1.getTour().size()-2);
    std::vector<int>new_parent1(parent1.getTour().size());
    std::vector<int> new_parent2(parent1.getTour().size());
    int p1_count=0;
    int p2_count=0;
    //Fills new_parent1 with first half of parent1
    for(int i=0;i<cross_index;i++)
    {
       // new_parent1.push_back(parent1.getTour()[i]);
       new_parent1[p1_count]=parent1.getTour()[i];
       p1_count++;
    }
    //Fills new_parent1 with second half of parent2
    for(int i=cross_index;i<parent1.getTour().size();i++)
    {
        if(std::find(new_parent1.begin(),new_parent1.end(),parent2.getTour()[i])!=new_parent1.end())
        {

        }
        else
        {
            new_parent1[p1_count]=parent2.getTour()[i];
            p1_count++;
        }
        //new_parent1.push_back(parent2.getTour()[i]);
    }
    //Fills new_parent2 with first half of parent2
    for(int i=0;i<cross_index;i++)
    {
        //new_parent2.push_back(parent2.getTour()[i]);
        new_parent2[p2_count]=parent2.getTour()[i];
        p2_count++;
    }
    //Fills new_parent2 with second half of parent1
    for(int i=cross_index;i<parent2.getTour().size();i++)
    {
        if(std::find(new_parent2.begin(),new_parent2.end(),parent1.getTour()[i])!=new_parent2.end())
        {

        }
        else
        {
            new_parent2[p2_count]=parent1.getTour()[i];
            p2_count++;
        }
            //new_parent2.push_back(parent1.getTour()[i]);
    }
    //Fill in rest of nodes
    for(int i=2;i<=parent1.getTour().size()+1;i++)
    {
        if(find(new_parent1.begin(),new_parent1.end(),i)!=new_parent1.end())
        {

        }
        else{
            //new_parent1.push_back(i);
            new_parent1[p1_count]=i;
            p1_count++;
        }
        if(find(new_parent2.begin(),new_parent2.end(),i)!=new_parent2.end())
        {

        }
        else{
            //new_parent2.push_back(i);
            new_parent2[p2_count]=i;
            p2_count++;
        }

    }
    child.setTour(new_parent1);
    child.calcFitness(src,node_map);
    parent1.setTour(new_parent1);
    parent2.setTour(new_parent2);
    parent1.calcFitness(src,node_map);
    if(parent1.getCost()<global_best.getCost())
    {
        global_best=parent1;
    }
    parent2.calcFitness(src,node_map);
    if(parent2.getCost()<global_best.getCost())
    {
        global_best=parent2;
    }
    return child;
}
Tour GeneticAlgorithm::multi_Point_Crossover(Tour &parent1, Tour &parent2) {
    Tour child;
    srand(time(NULL));
    int cross_index=(rand() % parent1.getTour().size()-2);
    int cross_index2=(rand() % cross_index)+cross_index;
    std::vector<int>new_parent1(parent1.getTour().size());
    std::vector<int> new_parent2(parent1.getTour().size());
    int p1_count=0;
    int p2_count=0;
    //Fills new_parent1 with first half of parent1
    for(int i=0;i<cross_index;i++)
    {
        // new_parent1.push_back(parent1.getTour()[i]);
        new_parent1[p1_count]=parent1.getTour()[i];
        p1_count++;
    }
    //Fills new_parent1 with second half of parent2
    for(int i=cross_index;i<cross_index2;i++)
    {
        if(std::find(new_parent1.begin(),new_parent1.end(),parent2.getTour()[i])!=new_parent1.end())
        {

        }
        else
        {
            new_parent1[p1_count]=parent2.getTour()[i];
            p1_count++;
        }
        //new_parent1.push_back(parent2.getTour()[i]);
    }
    for(int i=cross_index2;i<parent1.getTour().size();i++)
    {
        if(std::find(new_parent1.begin(),new_parent1.end(),parent1.getTour()[i])!=new_parent1.end())
        {

        }
        else
        {
            new_parent1[p1_count]=parent1.getTour()[i];
            p1_count++;
        }
        //new_parent1.push_back(parent2.getTour()[i]);
    }
    for(int i=2;i<=parent1.getTour().size()+1;i++)
    {
        if(find(new_parent1.begin(),new_parent1.end(),i)!=new_parent1.end())
        {

        }
        else{
            //new_parent1.push_back(i);
            new_parent1[p1_count]=i;
            p1_count++;
        }
        if(find(new_parent2.begin(),new_parent2.end(),i)!=new_parent2.end())
        {

        }
        else{
            //new_parent2.push_back(i);
            new_parent2[p2_count]=i;
            p2_count++;
        }

    }
    child.setTour(new_parent1);
    child.calcFitness(src,node_map);
    parent1.setTour(new_parent1);
    parent2.setTour(new_parent2);
    parent1.calcFitness(src,node_map);
    if(parent1.getCost()<global_best.getCost())
    {
        global_best=parent1;
    }
    parent2.calcFitness(src,node_map);
    if(parent2.getCost()<global_best.getCost())
    {
        global_best=parent2;
    }
    return child;
}
void GeneticAlgorithm::swap_Mutation(Tour &child) {
    int to_swap1=(rand() % child.getTour().size());
    int to_swap2=(rand() % child.getTour().size());
//   std::swap(parent1.getTour()[to_swap1],parent1.getTour()[to_swap2]);
//    std::swap(parent2.getTour()[to_swap1],parent1.getTour()[to_swap2]);
std::iter_swap(child.getTour().begin()+to_swap1,child.getTour().begin()+to_swap2);
}
void GeneticAlgorithm::Run(int num_times) {
    //Update global best to see if getting better paths
    //Also make tours save cost so you can see evolution
    int run=0;
    while(run<num_times)
    {
        for(int i=0;i<global_best.getTour().size();i++)
        {
            std::cout<<global_best.getTour()[i]<<" ";
        }
        std::cout<<"    "<<global_best.getCost()<<std::endl;
        std::vector<Tour>new_pop;
        new_pop.reserve(population.size());
        for(int i=0;i<population.size();i++)
        {
            Tour parent1;
            Tour parent2;
            this->rouletteWheel(parent1);
            this->elitism(parent2);
            //Crossover to create children
            Tour child;
            //child=this->one_Point_Crossover(parent1,parent2);
            child=this->multi_Point_Crossover(parent1,parent2);
            //HIGH MUTATION RATE
            if(i%25==0)
            {
                this->swap_Mutation(child);
            }
            //Add the children to new parents
            new_pop.push_back(child);
        }
        population.clear();
//    for(int i=0;i<population.size();i++)
//    {
//        population.push_back(new_pop[i]);
//    }
        population=new_pop;

//    for(int i=0;i<new_pop.size();i++)
//    {
//        for(int z=0;z<new_pop[i].getTour().size();z++)
//        {
//            std::cout<<new_pop[i].getTour()[z]<<" ";
//        }
//        std::cout<<new_pop[i].getFitness()<<std::endl;
//    }
    }



}
void GeneticAlgorithm::setMap(std::map<int, std::vector<float>> &node_map) {
    this->node_map=node_map;
}