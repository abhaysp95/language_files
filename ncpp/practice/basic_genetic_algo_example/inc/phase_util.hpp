#pragma once

#include <cstdlib>
#include <ctime>
#include <vector>

namespace algo {
	class individual {
		private:
			int _fitness;
			int* _genes;
			int _gene_length;
		public:
			individual();
			void set_genes(int index, int value);
			int get_fitness() const;
			int get_genes(int index) const;
			int get_gene_length() const;
			void calc_fitness();
			void delete_genes();
	};

	class population {
		private:
			int _popSize;
			std::vector<individual*> _individuals;
			int _fittest;
		public:
			population();
			void initialize_population(int size);
			void set_individual(int index, individual* new_individual);
			void set_fittest(int value);
			int get_fittest_value() const;
			individual* get_individual(int index) const;
			individual* get_fittest();
			individual* get_second_fittest() const;
			int get_least_fittest_index() const;
			void calculate_fitness();
			void delete_individuals();
	};

	class simple_demo_ga {
		private:
			population* _population;
			individual* _fittest;
			individual* _second_fittest;
			int _generation_count = 0;

		public:
			simple_demo_ga();
			void set_generation_count(int count);
			population* get_population() const;
			int get_generation_count() const;
			void selection();
			void crossover();
			void mutation();
			individual* get_fittest_offspring();
			void add_fittest_offspring();
	};
};