#include <limits.h>
#include <vector>
#include <iostream>

using namespace std;

/**
    \brief Given a complete, undirected, weighted graph in the form of an adjacency matrix,
           returns the smallest tour that visits all nodes and starts and ends at the same
           node. This dynamic programming solution runs in O(n * 2^n).
    \return the minimum cost to complete the tour
*/
float tsp(const vector<vector<float>>& cities, int pos, int visited, vector<vector<float>>& state)
{
    if(visited == ((1 << cities.size()) - 1))
        return cities[pos][0]; // return to starting city

    if(state[pos][visited] != INT_MAX)
        return state[pos][visited];

    for(int i = 0; i < cities.size(); ++i)
    {
        // can't visit ourselves unless we're ending & skip if already visited
        if(i == pos || (visited & (1 << i)))
            continue;

        float distance = cities[pos][i] + tsp(cities, i, visited | (1 << i), state);
        if(distance < state[pos][visited])
            state[pos][visited] = distance;
    }

    return state[pos][visited];
}

int main()
{
    vector<vector<float>> cities = { { 0, 1, 2, 3 },
                                   { 1, 0, 1, 2 },
                                   { 2, 1, 0, 1 },
                                   { 3, 2, 1, 0 }
    };

    vector<vector<float>> state(cities.size());
    for(auto& neighbors : state)
        neighbors = vector<float>((1 << cities.size()) - 1, INT_MAX);

    cout << "minimum: " << tsp(cities, 0, 1, state) << endl;

    return 0;
}