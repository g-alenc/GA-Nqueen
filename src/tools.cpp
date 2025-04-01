#include <random>
#include <iostream>
using namespace::std;

// Generate a random number between 'min' and 'max'
double random(double min, double max){
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_real_distribution<double> dis(min, max); 

    return dis(gen); 
}

// Generate a random integer number between 'min' and 'max'
int randint(double min, double max){
    std::random_device rd; 
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(min, max);

    return dis(gen);
}

void draw_separator_line(int size) {
    cout << "+";
    for (int i = 0; i < size; ++i) {
        cout << "---+";
    }
    cout << "\n";
}





