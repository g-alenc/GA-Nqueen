#include "../include/population.hpp"
#include <iostream>
#include <algorithm>


Population::Population(int population_size, int chromosome_size)
    : individuals()
    {
    population_size_ = population_size;

    // Initialize the 'individuals' with 'Individual's
    for (int i = 0; i < population_size; i++) {
        individuals.push_back(Individual(chromosome_size)); // Chama o construtor corretamente
    }
}


void Population::calculate_sort_indices(){
    sorted_indices.resize(population_size_);
    for (int i = 0; i < population_size_; ++i) {
        sorted_indices[i] = i;
    }

    sort(sorted_indices.begin(), sorted_indices.end(), [this](int a, int b) {
        return individuals[a].fitness < individuals[b].fitness;
    });
}
