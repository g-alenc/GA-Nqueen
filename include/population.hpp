#ifndef POPULATION_HPP
#define POPULATION_HPP
#include "individual.hpp"
#include <vector>

class Population{
    private:
        

    public:
        vector<Individual> individuals;
        int population_size_;
        double mean_fitness = 0.0;

        Population(int population_size, int chromosome_size);

};

#endif