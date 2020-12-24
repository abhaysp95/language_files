#include "../inc/phase_util.hpp"
#include <climits>

namespace algo {
	simple_demo_ga::simple_demo_ga() {
		// define population
		this->_population = new population();
		this->_generation_count = 0;
	}
	void simple_demo_ga::set_generation_count(int count) {
		this->_generation_count = count;
	}
	population* simple_demo_ga::get_population() const {
		return this->_population;
	}
	int simple_demo_ga::get_generation_count() const {
		return this->_generation_count;
	}
	void simple_demo_ga::selection() {
		// select the most fittest individual
		this->_fittest = this->_population->get_fittest();
		// select the second most fittest individual
		this->_second_fittest = this->_population->get_second_fittest();
	}
	void simple_demo_ga::crossover() {
		srand((unsigned) time(0));
		// select random crossover point
		int cross_over_point = rand() % this->_population->get_individual(0)->get_gene_length();

		for (int i = 0; i < cross_over_point; ++i) {
			int temp = this->_fittest->get_genes(i);
			this->_fittest->set_genes(i, this->_second_fittest->get_genes(i));
			this->_second_fittest->set_genes(i, temp);
		}
	}
	void simple_demo_ga::mutation() {
		srand((unsigned) time(0));
		int mutation_point = rand() % this->get_population()->get_individual(0)->get_gene_length();
		// flip the values at the mutation point
		if (this->_fittest->get_genes(mutation_point) == 0) {
			this->_fittest->set_genes(mutation_point, 1);
		}
		else {
			this->_fittest->set_genes(mutation_point, 0);
		}
		mutation_point = rand() % this->get_population()->get_individual(0)->get_gene_length();
		if (this->_second_fittest->get_genes(mutation_point) == 0) {
			this->_second_fittest->set_genes(mutation_point, 1);
		}
	}
	// get fittest offspring
	individual* simple_demo_ga::get_fittest_offspring() {
		if (this->_fittest->get_fitness() > this->_second_fittest->get_fitness()) {
			return this->_fittest;
		}
		else {
			return this->_second_fittest;
		}
	}
	// replace least fittest individual from most fittest offspring
	void simple_demo_ga::add_fittest_offspring() {
		// update fitness value offspring
		this->_fittest->calc_fitness();
		this->_second_fittest->calc_fitness();
		// get index of least fit individual
		int least_fittest_index = this->_population->get_least_fittest_index();
		// replace least fittest individual from most fittest offspring
		this->_population->set_individual(least_fittest_index, this->get_fittest_offspring());
	}

	individual::individual() {
		this->_genes = new int[5];
		this->_gene_length = 5;
		this->_fitness = 0;
		srand((unsigned) time(0));
		for (int i = 0; i < this->_gene_length; ++i) {
			_genes[i] = rand() % 2;
		}
	}
	void individual::set_genes(int index, int value) {
		this->_genes[index] = value;
	}
	int individual::get_fitness() const { return this->_fitness; }
	int individual::get_genes(int index) const {
		return this->_genes[index];
	}
	int individual::get_gene_length() const { return this->_gene_length; }
	void individual::calc_fitness() {
		this->_fitness = 0;
		for (int i = 0; i < this->_gene_length; ++i) {
			if (this->_genes[i] == 1) {
				++this->_fitness;
			}
		}
	}
	void individual::delete_genes() {
		delete this->_genes;
	}

	//std::vector<individual> individual::_individuals(10);
	population::population():_individuals(10) {
		this->_popSize = 10;
		this->_fittest = 0;
	}
	void population::initialize_population(int size) {
		for (int i = 0; i < size; ++i) {
			this->_individuals.at(i) = new individual();
		}
	}
	// set individual
	void population::set_individual(int index, individual *new_individual) {
		this->_individuals.at(index) = new_individual;
	}
	// set fittest
	void population::set_fittest(int value) {
		this->_fittest = value;
	}
	int population::get_fittest_value() const { return this->_fittest; }
	individual* population::get_individual(int index) const {
		return this->_individuals.at(index);
	}
	// get the fittest individual
	individual* population::get_fittest() {
		int max_fit = INT_MIN;
		int max_fit_index = 0;
		for (int i = 0; i < this->_individuals.size(); ++i) {
			if (max_fit <= this->_individuals.at(i)->get_fitness()) {
				max_fit = this->_individuals.at(i)->get_fitness();
				max_fit_index = i;
			}
		}
		this->_fittest = this->_individuals.at(max_fit_index)->get_fitness();
		return this->_individuals.at(max_fit_index);
	}
	// get second fittest individual
	individual* population::get_second_fittest() const {
		int first_max_fit = 0;
		int second_max_fit = 0;
		for (int i = 0; i < this->_individuals.size(); ++i) {
			if (this->_individuals.at(i)->get_fitness() > this->_individuals.at(first_max_fit)->get_fitness()) {
				second_max_fit = first_max_fit;
				first_max_fit = i;
			}
			else if (this->_individuals.at(i)->get_fitness() > this->_individuals.at(second_max_fit)->get_fitness()) {
				second_max_fit = i;
			}
		}
		return this->_individuals.at(second_max_fit);
	}
	// get least fittest individual index
	int population::get_least_fittest_index() const {
		int min_fit_value = INT_MAX;
		int min_fit_index = 0;
		for (int i = 0; i < this->_individuals.size(); ++i) {
			if (min_fit_value >= this->_individuals.at(i)->get_fitness()) {
				min_fit_value = this->_individuals.at(i)->get_fitness();
				min_fit_index = i;
			}
		}
		return min_fit_index;
	}
	// calculate fitness for each individual
	void population::calculate_fitness() {
		for (int i = 0; i < this->_individuals.size(); ++i) {
			this->_individuals.at(i)->calc_fitness();
		}
		this->get_fittest();
		//this->set_fittest(this->get_fittest_value());
	}
	// free the memory
	void population::delete_individuals() {
		for (int i = 0; i < this->_individuals.size(); ++i) {
			this->_individuals.at(i)->delete_genes();
			delete this->_individuals.at(i);
		}
		this->_individuals.clear();
	}
};