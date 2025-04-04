#ifndef INDIVIDUAL_HPP
#define INDIVIDUAL_HPP
#include <vector>
using namespace::std;

struct penality{
    int first;
    int second;
    bool diogonal;
};

class Individual{
    private:
        

    public:
        vector<int> chromosome;
        int chromosome_size_;
        int fitness;
        vector<penality> errors;

        Individual() : chromosome_size_(0) {}
        Individual(int chromosome_size);
        void evaluate_fitness();
        void show_solution();
};


#endif  