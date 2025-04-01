#include "../include/genetic_algorithm.hpp"
#include "../include/tools.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace::std;

GeneticAlgorithm::GeneticAlgorithm(int chromosome_size, int pop_size, double mutation_rate, double elitism_rate)
    : population(pop_size, chromosome_size), mutation_rate(mutation_rate),  population_size(pop_size), elitism_rate(elitism_rate),
    elitism_length(round(population_size*elitism_rate)) {}

void GeneticAlgorithm::mutation(Individual& individual){
    // Change the position of a queen from a random column
    individual.chromosome[randint(0, individual.chromosome_size_)] = randint(0, individual.chromosome_size_);
}

pair<Individual, Individual> GeneticAlgorithm::crossover(const Individual& father, const Individual& mother){
    int cut_index = randint(1, father.chromosome_size_-1);

    Individual son1 = Individual(father.chromosome_size_);
    Individual son2 = Individual(father.chromosome_size_);

    // Subistitui o valor do cromossomo dos filhos alternando entre o da mãe e do pai a partir do 'cut_index'
    for (int i = 0; i < father.chromosome_size_; i++){
        if (i < cut_index){
            son1.chromosome[i] = father.chromosome[i];
            son2.chromosome[i] = mother.chromosome[i];
        }
        else{
            son1.chromosome[i] = mother.chromosome[i];
            son2.chromosome[i] = father.chromosome[i];
        }
    }
    return make_pair(son1, son2);
}

void GeneticAlgorithm::evaluate_all_fitness(){
    for (int i = 0; i < population_size; i++){
        population.individuals[i].evaluate_fitness();
        population.mean_fitness += population.individuals[i].fitness;
    }
    population.mean_fitness /= population_size;
}

pair<Individual, Individual> GeneticAlgorithm::select_parents(){
    sorted_indices = calculate_sort_indices();
    return make_pair(population.individuals[sorted_indices[0]], population.individuals[sorted_indices[1]]);

}

vector<int> GeneticAlgorithm::calculate_sort_indices(){
    vector<int> indices(population_size);

    for (int i = 0; i < population_size; ++i) {
        indices[i] = i;
    }

    for (int i = 0; i < population_size - 1; ++i) {
        int maxIdx = i;
        for (int j = i + 1; j < population_size; ++j) {
            if (population.individuals[indices[j]].fitness > population.individuals[indices[maxIdx]].fitness) {
                maxIdx = j;
            }
        }
        // Troca os índices
        swap(indices[i], indices[maxIdx]);
    }

    return indices;  // Retorna os índices ordenados
}

Population GeneticAlgorithm::new_population(){
    Population new_population = Population(population_size, population.individuals[0].chromosome_size_);

    for (int i= 0; i < elitism_length; i++){
        new_population.individuals[i] = population.individuals[sorted_indices[i]];
    }

    for (int i = elitism_length; i < (population_size/2); i++){

        auto parents = select_parents(); 
        auto sons = crossover(parents.first, parents.second);
        mutation(sons.first);
        mutation(sons.second);

        new_population.individuals[i] = sons.first;
        new_population.individuals[i+(population_size/2)] = sons.first;
    }
    return new_population;
}

void GeneticAlgorithm::run(int generations){
    for (int g = 0; g < generations; g++){
        evaluate_all_fitness();

        cout << "Generation:" << g << "\n";
        cout << "Mean fitness:" << population.mean_fitness << "\n";
        cout << "---------------------\n";

        population = new_population();
    }
}