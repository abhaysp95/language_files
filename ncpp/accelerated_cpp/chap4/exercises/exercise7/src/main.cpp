// main file

#include <iostream>
#include <vector>
#include <numeric>  // std::accumulate
#include <algorithm>  // std::for_each
#include <type_traits>  // std::remove_reference

double avg_method1(std::vector<double>& vec) {
	double sum{0.0};
	// says error when taking vec as const
	for (std::vector<double>::iterator it = vec.begin(); it != vec.end(); ++it) {
		sum += *it;
	}
	std::cout << "sum is: " << sum << std::endl;
	return sum / vec.size();
}

double avg_method2(const std::vector<double>& vec) {
	double sum{0.0};
	for (std::vector<double>::size_type i = 0; i < vec.size(); ++i) {
		sum += vec.at(i);
	}
	std::cout << "sum is: " << sum << std::endl;
	return sum / vec.size();
}

// before C++11
double avg_method3(const std::vector<double>& vec) {
	double sum{0.0};
	// last argument's type is used not just for the intial value, but for the
	// type of the results as well. For int, you give 0(it'll change float to
	// int to), for float give 0.0f(or 0.0 for double)
	sum = std::accumulate(vec.begin(), vec.end(), 0.0);
	std::cout << "sum is: " << sum << std::endl;
	return sum / vec.size();
}

// since C++11
double avg_method4(std::vector<double> vec) {
	double sum{0.0};
	// decltype takes declaration of class, namespace or enums etc. so you
	// can't give reference to it, that's why no
	// 'const std::vector<double> & vec'
	sum = std::accumulate(vec.begin(), vec.end(), decltype(vec)::value_type(0));
	std::cout << "sum is: " << sum << std::endl;
	return sum / vec.size();
}

double avg_method5(const std::vector<double> vec) {
	double sum{0.0};
	// for_each loop(using lambda expression)
	std::for_each(vec.begin(), vec.end(), [&](int n) { sum += n; });
	std::cout << "sum is: " << sum << std::endl;
	return sum / vec.size();
}

double avg_method6(const std::vector<double> vec) {
	double sum{0.0};
	// you can use auto since C++11(I think)
	for (auto& n: vec) {
		sum += n;
	}
	std::cout << "sum is: " << sum << std::endl;
	return sum / vec.size();
}

double avg_method7(const std::vector<double>& vec) {
	double sum{0.0};
	// const_iterator doesn't mean that you can't change the iterator(or
	// whether iterator is constant) but you can't change the item that
	// iterator refers to
	for (std::vector<double>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
		sum += *it;
	}
	std::cout << "sum is: " << sum << std::endl;
	return sum / vec.size();
}

int main(int argc, char **argv) {
	double number{0.0};
	std::cout << "Enter the numbers[press Ctrl-d to cancel]: " << std::endl;
	std::vector<double> vector_for_question;
	while (std::cin >> number) {
		vector_for_question.push_back(number);
	}
	double got_avg_method1 = avg_method1(vector_for_question);
	std::cout << "Avg[method1]: " << got_avg_method1 << std::endl;
	std::cout << "----------------------------" << std::endl;
	double got_avg_method2 = avg_method2(vector_for_question);
	std::cout << "Avg[method2]: " << got_avg_method2 << std::endl;
	std::cout << "----------------------------" << std::endl;
	double got_avg_method3 = avg_method3(vector_for_question);
	std::cout << "Avg[method3]: " << got_avg_method3 << std::endl;
	std::cout << "----------------------------" << std::endl;
	double got_avg_method4 = avg_method4(vector_for_question);
	std::cout << "Avg[method4]: " << got_avg_method4 << std::endl;
	std::cout << "----------------------------" << std::endl;
	double got_avg_method5 = avg_method5(vector_for_question);
	std::cout << "Avg[method5]: " << got_avg_method5 << std::endl;
	std::cout << "----------------------------" << std::endl;
	double got_avg_method6 = avg_method6(vector_for_question);
	std::cout << "Avg[method6]: " << got_avg_method6 << std::endl;
	return 0;
}


/** look more for decltype and std::remove_reference() */