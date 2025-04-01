#ifndef INDIVIDUAL_HPP
#define INDIVIDUAL_HPP
#include <vector>
using namespace::std;

class Individual{
    private:
        


    public:
        vector<int> chromosome;
        int chromosome_size_;
        int fitness;

        Individual(int chromosome_size);
        void evaluate_fitness();
        void show_solution();
};


#endif  