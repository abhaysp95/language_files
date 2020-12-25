#include "../inc/phase_util.hpp"
#include <climits>
#include <iostream>

namespace Algo {
	Simple_Demo_Ga::Simple_Demo_Ga(size_t count):_population(count), _generation_count(0) {}
	void Simple_Demo_Ga::set_generation_count(size_t count) {
		this->_generation_count = count;
	}
	Population Simple_Demo_Ga::get_population() const {
		return this->_population;
	}
	int Simple_Demo_Ga::get_generation_count() const {
		return this->_generation_count;
	}
	void Simple_Demo_Ga::selection() {
		// select the most fittest individual
		this->_fittest = this->_population.get_fittest();
		// select the second most fittest individual
		this->_second_fittest = this->_population.get_second_fittest();
	}
	void Simple_Demo_Ga::crossover() {
		// select random crossover point
		int cross_over_point = rand() % this->_population.get_individual(0).get_gene_length();

		for (int i = 0; i < cross_over_point; ++i) {
			int temp = this->_fittest.get_genes(i);
			this->_fittest.set_genes(i, this->_second_fittest.get_genes(i));
			this->_second_fittest.set_genes(i, temp);
		}
	}
	void Simple_Demo_Ga::mutation() {
		int mutation_point = rand() % this->get_population().get_individual(0).get_gene_length();
		// flip the values at the mutation point
		if (this->_fittest.get_genes(mutation_point) == 0) {
			this->_fittest.set_genes(mutation_point, 1);
		}
		else {
			this->_fittest.set_genes(mutation_point, 0);
		}
		mutation_point = rand() % this->get_population().get_individual(0).get_gene_length();
		if (this->_second_fittest.get_genes(mutation_point) == 0) {
			this->_second_fittest.set_genes(mutation_point, 1);
		}
	}
	// get fittest offspring
	Individual Simple_Demo_Ga::get_fittest_offspring() {
		if (this->_fittest.get_fitness() > this->_second_fittest.get_fitness()) {
			return this->_fittest;
		}
		else {
			return this->_second_fittest;
		}
	}
	// replace least fittest individual from most fittest offspring
	void Simple_Demo_Ga::add_fittest_offspring() {
		// update fitness value offspring
		this->_fittest.calc_fitness();
		this->_second_fittest.calc_fitness();
		// get index of least fit individual
		int least_fittest_index = this->_population.get_least_fittest_index();
		// replace least fittest individual from most fittest offspring
		this->_population.set_individual(least_fittest_index, this->get_fittest_offspring());
	}

	Individual::Individual() {
		this->_fitness = 0;
		for (int i = 0; i < this->_genes.size(); ++i) {
			_genes[i] = rand() % 2;
		}
	}
	void Individual::set_genes(int index, int value) {
		this->_genes[index] = value;
	}
	int Individual::get_fitness() const { return this->_fitness; }
	int Individual::get_genes(size_t index) const {
		return this->_genes[index];
	}
	size_t Individual::get_gene_length() const { return this->_genes.size(); }
	void Individual::calc_fitness() {
		this->_fitness = 0;
		for (int i = 0; i < this->_genes.size(); ++i) {
			if (this->_genes[i] == 1) {
				++this->_fitness;
			}
		}
	}

	//std::vector<individual> individual::_individuals(10);
	Population::Population(size_t size):_individuals(size), _fittest(0) {}
	// set individual
	void Population::set_individual(size_t index, Individual new_individual) {
		this->_individuals.at(index) = new_individual;
	}
	// set fittest
	void Population::set_fittest(int value) {
		this->_fittest = value;
	}
	int Population::get_fittest_value() const { return this->_fittest; }
	Individual Population::get_individual(size_t index) const {
		return this->_individuals.at(index);
	}
	// get the fittest individual
	Individual Population::get_fittest() {
		int max_fit = INT_MIN;
		int max_fit_index = 0;
		for (int i = 0; i < this->_individuals.size(); ++i) {
			if (max_fit <= this->_individuals.at(i).get_fitness()) {
				max_fit = this->_individuals.at(i).get_fitness();
				max_fit_index = i;
			}
		}
		this->_fittest = this->_individuals.at(max_fit_index).get_fitness();
		return this->_individuals.at(max_fit_index);
	}
	// get second fittest individual
	Individual Population::get_second_fittest() const {
		int first_max_fit = 0;
		int second_max_fit = 0;
		for (int i = 0; i < this->_individuals.size(); ++i) {
			if (this->_individuals.at(i).get_fitness() > this->_individuals.at(first_max_fit).get_fitness()) {
				second_max_fit = first_max_fit;
				first_max_fit = i;
			}
			else if (this->_individuals.at(i).get_fitness() > this->_individuals.at(second_max_fit).get_fitness()) {
				second_max_fit = i;
			}
		}
		return this->_individuals.at(second_max_fit);
	}
	// get least fittest individual index
	size_t Population::get_least_fittest_index() const {
		int min_fit_value = INT_MAX;
		int min_fit_index = 0;
		for (int i = 0; i < this->_individuals.size(); ++i) {
			if (min_fit_value >= this->_individuals.at(i).get_fitness()) {
				min_fit_value = this->_individuals.at(i).get_fitness();
				min_fit_index = i;
			}
		}
		return min_fit_index;
	}
	// calculate fitness for each individual
	void Population::calculate_fitness() {
		for (int i = 0; i < this->_individuals.size(); ++i) {
			this->_individuals.at(i).calc_fitness();
		}
		this->get_fittest();
		//this->set_fittest(this->get_fittest_value());
	}
};