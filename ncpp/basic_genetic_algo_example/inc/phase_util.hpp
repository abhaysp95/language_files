#pragma once

#include <array>
#include <cstdlib>
#include <ctime>
#include <vector>

namespace Algo {
	class Individual {
		private:
			int _fitness;
			std::array<int, 5> _genes;
		public:
			Individual();
			void set_genes(int index, int value);
			int get_fitness() const;
			int get_genes(size_t index) const;
			size_t get_gene_length() const;
			void calc_fitness();
	};

	class Population {
		private:
			std::vector<Individual> _individuals;
			int _fittest;
		public:
			Population(size_t size);
			//void initialize_population(int size);
			void set_individual(size_t index, const Individual& new_individual);
			void set_fittest(int value);
			int get_fittest_value() const;
			Individual get_individual(size_t index) const;
			Individual get_fittest();
			Individual get_second_fittest() const;
			size_t get_least_fittest_index() const;
			void calculate_fitness();
	};

	class Simple_Demo_Ga {
		private:
			Population _population;
			Individual _fittest;
			Individual _second_fittest;
			int _generation_count;

		public:
			Simple_Demo_Ga(size_t count);;
			void set_generation_count(size_t count);
			Population get_population() const;
			int get_generation_count() const;
			void selection();
			void crossover();
			void mutation();
			Individual get_fittest_offspring();
			void add_fittest_offspring();
	};
};