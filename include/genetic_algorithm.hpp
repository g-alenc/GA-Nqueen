#ifndef GENETIC_ALGORITHM_HPP
#define GENETIC_ALGORITHM_HPP
#include "population.hpp"
#include <utility>
#include <vector> 


class GeneticAlgorithm{
    private:
        void mutation(Individual& individual);
        Individual& tournament_selection(int tournament_size);
        Population new_population();
        void evaluate_all_fitness();
        pair<Individual, Individual>crossover(const Individual& father, const Individual& mother);
        int elitism_length;

    public: 
        Population population;
        double mutation_rate;
        int population_size;
        int elitism_rate;
        Individual best_solution;

        GeneticAlgorithm( int chromosome_size, int population_size, double mutation_rate, double elitism_rate);
        void run(int generations, bool verbose);
};

#endif