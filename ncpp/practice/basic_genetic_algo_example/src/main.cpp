// main file

#include <iostream>

#include "../inc/phase_util.hpp"

int main(int argc, char **argv) {
	srand((unsigned) time(0));
	Algo::Simple_Demo_Ga demo(10);  // initialized population too

	// calculate fitness of each individual
	demo.get_population().calculate_fitness();

	std::cout << "Generation: " << demo.get_generation_count() <<
		" Fittest: " << demo.get_population().get_fittest_value() << std::endl;

	// while population gets an individual with maximum fitness
	while (demo.get_population().get_fittest_value() < 5) {
		demo.set_generation_count(demo.get_generation_count() + 1);

		// do selection
		demo.selection();

		// do crossover
		demo.crossover();

		// do mutation under a random probability
		if (rand() % 7 < 5) {
			demo.mutation();
		}

		// add fittest offspring to population
		demo.add_fittest_offspring();

		// calculate new fitness value
		demo.get_population().calculate_fitness();

		std::cout << "Generation: " << demo.get_generation_count() <<
			" Fittest: " << demo.get_population().get_fittest_value() << std::endl;
	}

	std::cout << "\nSolution found in generation " << demo.get_generation_count();
	std::cout << "\nFitness: " << demo.get_population().get_fittest().get_fitness();
	std::cout << "\nGenes: ";

	for (int i = 0; i < 5; ++i) {
		std::cout << demo.get_population().get_fittest().get_genes(i);
	}
	std::cout << std::endl;
	return 0;
}