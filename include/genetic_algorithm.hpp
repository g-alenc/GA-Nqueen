#ifndef GENETIC_ALGORITHM_HPP
#define GENETIC_ALGORITHM_HPP
#include "population.hpp"
#include <utility>
#include <vector> 


class GeneticAlgorithm{
    private:
        void mutation(Individual& individual);
        pair<Individual, Individual> select_parents();
        Population new_population();
        void evaluate_all_fitness();
        vector<int> calculate_sort_indices();
        pair<Individual, Individual> crossover(const Individual& father, const Individual& mother);
        int elitism_length;

    public: 
        Population population;
        double mutation_rate;
        int population_size;
        int elitism_rate;
        vector<int> sorted_indices;

        GeneticAlgorithm( int chromosome_size, int population_size, double mutation_rate, double elitism_rate);
        void run(int generations);
};

#endif