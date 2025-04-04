#include "./include/genetic_algorithm.hpp"
#include <iostream>
using namespace::std;

int main() {
    int pop_size = 100;
    int chromo_size = 12;
    double mut_rate = 0.9;
    int gens = 200;
    double elite_rate = 0.1;

    cout << "Tamanho do tablueiro (NxN): ";
    cin >> chromo_size;
    cout << endl;

    GeneticAlgorithm ga = GeneticAlgorithm(chromo_size, pop_size, mut_rate, elite_rate);

    ga.run(gens, true);
    Individual* best_individual = &ga.best_solution;

    cout << "Best solution: "<< "\n";
    best_individual->show_solution();

    return 0;
}