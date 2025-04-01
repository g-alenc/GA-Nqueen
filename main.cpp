#include "./include/genetic_algorithm.hpp"
#include <iostream>
using namespace::std;

int main() {
    int pop_size = 10;
    int chromo_size = 5;
    double mut_rate = 1;
    int gens = 100;
    int elite_rate = 0.1;

    GeneticAlgorithm ga = GeneticAlgorithm(chromo_size, pop_size, mut_rate, elite_rate);
    //ga.run(gens);

    // Individual* pai = &ga.population.individuals[0];
    // Individual* mae = &ga.population.individuals[1];

    // cout << "Mae:" << "\n";
    // mae->show_solution();

    // mae->evaluate_fitness();
    // cout << mae->fitness << "\n";

    ga.run(gens);

    return 0;
}

