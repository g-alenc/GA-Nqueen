#include "../include/population.hpp"

Population::Population(int population_size, int chromosome_size){
    population_size_ = population_size;

    // Initialize the 'individuals' with 'Individual's
    for(int i = 0; i < population_size; i++){
        individuals.push_back(Individual(chromosome_size));
    }
}

