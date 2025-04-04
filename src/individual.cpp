#include "../include/tools.hpp"
#include "../include/individual.hpp"
#include <cmath>
#include <iostream>

using namespace std;

Individual::Individual(int chromosome_size){
    chromosome_size_ = chromosome_size;
    chromosome.reserve(chromosome_size);

    //Initialize the 'chromosome' with random values
    for(int i = 0; i < chromosome_size; i++){
        chromosome.push_back(randint(1, chromosome_size));
    }
}   

void Individual::evaluate_fitness(){
    fitness = 0;

    for(int i=0; i < chromosome_size_; i++){
        for(int j = i+1; j < chromosome_size_; j++){
            
            bool is_in_same_row = chromosome[i] == chromosome[j];
            bool is_in_same_diagonal = abs(i-j) == abs(chromosome[i]-chromosome[j]);

            if(is_in_same_row or is_in_same_diagonal){
                fitness += 1;
                errors.push_back(penality{i, j, is_in_same_diagonal});
            }
        }
    }
}

void Individual::show_solution(){
    for (int row = 0; row < chromosome_size_; ++row) {
        draw_separator_line(chromosome_size_);
        
        cout << "|";
        for (int col = 0; col < chromosome_size_; ++col) {
            bool is_penalized = false;
            for (const auto& penalty : errors) {
                if (penalty.first == row || penalty.second == row) {
                    is_penalized = true;
                    break;
                }
            }

            if (chromosome[row] == col + 1) {
                if (is_penalized) {
                    cout << "\033[31m ♛ \033[0m|"; // Vermelho (penalizada)
                } else {
                    cout << "\033[32m ♛ \033[0m|"; // Verde (legítima)
                }
            } else {
                cout << " . |";
            }
        }
        cout << "\n";
    }

    draw_separator_line(chromosome_size_);

    cout << "Sequence: {";
    for (size_t i = 0; i < chromosome.size(); ++i) {
        cout << chromosome[i];
        if (i < chromosome.size() - 1) cout << ", ";
    }
    cout << "}\n";

    cout << "Fitness: " << fitness << endl;
}

