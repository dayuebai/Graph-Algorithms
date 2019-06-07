#ifndef RANDOM_GENERATION_SAMPLE_CPP
#define RANDOM_GENERATION_SAMPLE_CPP
#include <iostream>
#include <chrono>
#include <random>
#include <vector>

using namespace std;

mt19937 get_mersenne_twister_generator_with_current_time_seed()
{
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    return mt19937(seed);
}

uniform_int_distribution<int> get_uniform_int_generator(int lb, int ub)
{
    return uniform_int_distribution<int>(lb, ub);
}

int randint(mt19937 mt, int lb, int ub)
{
    return uniform_int_distribution<int>(lb, ub)(mt);
}

# endif // RANDOM_GENERATION_SAMPLE_CPP
