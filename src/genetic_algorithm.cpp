#include "../include/genetic_algorithm.hpp"
#include "../include/tools.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_set>
using namespace::std;

GeneticAlgorithm::GeneticAlgorithm(int chromosome_size, int pop_size, double mutation_rate, double elitism_rate)
    : mutation_rate(mutation_rate),
      population_size(pop_size),
      elitism_rate(elitism_rate),
      elitism_length(round(pop_size * elitism_rate)),
      population(pop_size, chromosome_size)
{}

void GeneticAlgorithm::mutation(Individual& individual){
    // Change the position of n queens from  random columns
    // Seleciona duas colunas diferentes aleatoriamente

    int i = randint(0, individual.chromosome_size_ - 1);
    int j = randint(0, individual.chromosome_size_ - 1);
    while (i == j) {
        j = randint(0, individual.chromosome_size_ - 1);
    }

    // Troca as posições das rainhas entre essas colunas
    std::swap(individual.chromosome[i], individual.chromosome[j]);
    // individual.chromosome[randint(0, individual.chromosome_size_ - 1)] = randint(1, individual.chromosome_size_ - 1);
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
    population.mean_fitness = 0.0;
    for (int i = 0; i < population_size; i++){
        population.individuals[i].evaluate_fitness();
        population.mean_fitness += population.individuals[i].fitness;
    }
    population.mean_fitness /= population_size;
}
Individual& GeneticAlgorithm::tournament_selection(int tournament_size = 5) {
    int best = randint(0, population_size - 1);
    for (int i = 1; i < tournament_size; ++i) {
        int competitor = randint(0, population_size - 1);
        if (population.individuals[competitor].fitness < population.individuals[best].fitness) {
            best = competitor;
        }
    }
    return population.individuals[best];
}

Population GeneticAlgorithm::new_population(){
    Population new_population = Population(population_size, population.individuals[0].chromosome_size_);

    for (int i= 0; i < elitism_length; i++){
        new_population.individuals[i] = population.individuals[population.sorted_indices[i]];
    }

    for (int i = elitism_length; i < population_size; i += 2){

        Individual father = tournament_selection(8); 
        Individual mother = tournament_selection(8); 

        auto sons = crossover(father, mother);
        mutation(sons.first);
        mutation(sons.second);

        if (i < population_size) {
            new_population.individuals[i] = sons.first;
        }
        if (i + 1 < population_size) {
            new_population.individuals[i + 1] = sons.second;
        }
    }
    return new_population;
}

void GeneticAlgorithm::run(int generations, bool verbose){
    for (int g = 1; g < generations+1; g++){
        evaluate_all_fitness();
        population.calculate_sort_indices();
        best_solution = population.individuals[population.sorted_indices[0]];
        

        if (verbose){
        cout << "Generation:" << g << "\n";
        cout << "Mean fitness:" << population.mean_fitness << "\n";
        cout << "Best fitness:" << best_solution.fitness << "\n";
        cout << "---------------------\n";

        if (best_solution.fitness == 0){
            break;
        }
}
        population = new_population();
    }
}