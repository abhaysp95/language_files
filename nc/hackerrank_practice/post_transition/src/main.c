// main file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 6

typedef struct package {
	char* id;
	size_t weight;
} package;

typedef struct post_office {
	size_t max_weight;
	size_t min_weight;
	package* packages;
	size_t packages_count;
} post_office;

typedef struct town {
	char* name;
	post_office* post_office;
	size_t offices_count;
} town;

town* find_town(town* towns, size_t towns_count, char* town_name);
void print_all_packages(town t);
town town_with_most_packages(town* towns, size_t towns_count);
void send_all_acceptable_package(town* source, size_t source_office_index, town* target, size_t target_office_index);

int main(int argc, char **argv) {
	size_t towns_count;
	scanf("%zu", &towns_count);  // take town count for input
	town* towns = (town*)malloc(sizeof(town) * towns_count);
	// take data input
	// take inputs for town
	for (size_t i = 0; i < towns_count; ++i) {
		towns[i].name = (char*)malloc(sizeof(char) * MAX_STRING_LENGTH);
		scanf("%s %zu", towns[i].name, &towns[i].offices_count);
		towns[i].post_office = (post_office*)malloc(sizeof(post_office) * towns[i].offices_count);
		// take inputs for post office
		for (size_t j = 0; j < towns[i].offices_count; ++j) {
			scanf("%zu %zu %zu", &towns[i].post_office[j].packages_count,
					&towns[i].post_office[j].min_weight,
					&towns[i].post_office[j].max_weight);
			towns[i].post_office[j].packages = (package*)malloc(sizeof(package) * towns[i].post_office[j].packages_count);
			// take inputs for packages
			for (size_t k = 0; k < towns[i].post_office[j].packages_count; ++k) {
				towns[i].post_office[j].packages[k].id = (char*)malloc(sizeof(char) * MAX_STRING_LENGTH);
				scanf("%s %zu", towns[i].post_office[j].packages[k].id,
						&towns[i].post_office[j].packages[k].weight);
			}
		}
	}
	// let's input queries
	size_t queries;
	scanf("%zu", &queries);
	char* town_name = (char*)malloc(sizeof(char) * MAX_STRING_LENGTH);
	while (queries--) {
		size_t query_type;
		scanf("%zu", &query_type);
		switch (query_type) {
			case 1:
				{
					scanf("%s", town_name);
					town* t = find_town(towns, towns_count, town_name);
					print_all_packages(*t);
				}
				break;
			case 2:
				{
					scanf("%s", town_name);
					town* source = find_town(towns, towns_count, town_name);
					size_t source_index;
					scanf("%zu", &source_index);
					scanf("%s", town_name);
					town* target = find_town(towns, towns_count, town_name);
					size_t target_index;
					scanf("%zu", &target_index);
					send_all_acceptable_package(source, source_index, target, target_index);
				}
				break;
			case 3:
				printf("The town with most number of packages is %s\n",
						town_with_most_packages(towns, towns_count).name);
				break;
		}
	}
	return 0;
}

// a nifty way to compare two strings for equality
size_t compare_names(char* name1, char* name2) {
	while (*name1 && *name2 && *name1 == *name2 && ++name1 && ++name2);
	return *name1 == *name2;
}

town* find_town(town* towns, size_t towns_count, char* town_name) {
	for (size_t i = 0; i < towns_count; ++i) {
		/*if (strcmp(towns[i].name, town_name) == 0) {*/
		if (compare_names(towns[i].name, town_name)) {
			return towns + i;
		}
	}
	return NULL;
}

void send_all_acceptable_package(town* source, size_t source_office_index, town* target, size_t target_office_index) {
	size_t max_from_target, min_from_target, weight_from_source, count;
	max_from_target = target->post_office[target_office_index].max_weight;
	min_from_target = target->post_office[target_office_index].min_weight;

	// let's start checking and setting
	for (size_t i = 0; i < source->post_office[source_office_index].packages_count; ++i) {
		weight_from_source = source->post_office[source_office_index].packages[i].weight;

		// if the package from source is acceptable by target
		if ((weight_from_source >= min_from_target) && (weight_from_source <= max_from_target)) {
			count = target->post_office[target_office_index].packages_count;

			// increase a package block in target and put package sent by source
			target->post_office[target_office_index].packages =
				realloc(target->post_office[target_office_index].packages, sizeof(package) * (count + 1));
			target->post_office[target_office_index].packages[count] = source->post_office[source_office_index].packages[i];
			target->post_office[target_office_index].packages_count++;

			// remove that stored package from source now
			count = source->post_office[source_office_index].packages_count;
			for (size_t k = i; k < count - 1; ++k) {
				source->post_office[source_office_index].packages[k] = source->post_office[source_office_index].packages[k + 1];
			}
			// free(source->post_office[source_office_index].packages + (count - 1));
			source->post_office[source_office_index].packages =
				realloc(source->post_office[source_office_index].packages, sizeof(package) * (count - 1));
			source->post_office[source_office_index].packages_count--;
			i--;  // cause packages in source are moved one block behind
		}
	}
}


/*void send_all_acceptable_package(town* source, size_t source_office_index, town* target, size_t target_office_index) {
	char** accepted_package_ids = (char**)malloc(sizeof(char*) * source->post_office[source_office_index].packages_count);
	size_t accepted_package_counts = 0;
	char** rejected_package_ids = (char**)malloc(sizeof(char*) * source->post_office[source_office_index].packages_count);
	size_t rejected_package_counts = 0;
	for (size_t i = 0; i < source->post_office[source_office_index].packages_count; ++i) {
		size_t min_weight_from_target = target->post_office[target_office_index].min_weight;
		size_t max_weigth_from_target = target->post_office[target_office_index].max_weight;
		// if weight of package from source_office_index is in range of target_office_index
		if ((source->post_office[source_office_index].packages[i].weight >= min_weight_from_target) &&
				(source->post_office[source_office_index].packages[i].weight <= max_weigth_from_target)) {
			accepted_package_ids[accepted_package_counts++] = source->post_office[source_office_index].packages[i].id;
		}
		else {
			rejected_package_ids[rejected_package_counts++] = source->post_office[source_office_index].packages[i].id;
		}
	}
	// if any of the package accepted by target
	if (accepted_package_counts > 0) {
		// handle accepted packages first
		size_t start_from = target->post_office[target_office_index].packages_count;
		target->post_office[target_office_index].packages = realloc(target->post_office[target_office_index].packages,
				start_from + accepted_package_counts);
		while (accepted_package_counts--) {
			// find the package now
			for (size_t i = 0; i < source->post_office[source_office_index].packages_count; ++i) {
				if (strcmp(accepted_package_ids[accepted_package_counts],
							source->post_office[source_office_index].packages[i].id) == 0) {
					target->post_office[target_office_index].packages[start_from + accepted_package_counts]
						= source->post_office[source_office_index].packages[i];
					break;
				}
			}
		}
		// now handle rejected packages
		package* rejected_packages = (package*)malloc(sizeof(package) * rejected_package_counts);
		while (rejected_package_counts--) {
			for (size_t i = 0; i < source->post_office[source_office_index].packages_count; ++i) {
				if (strcmp(rejected_package_ids[rejected_package_counts],
							source->post_office[source_office_index].packages[i].id) == 0) {
					rejected_packages[rejected_package_counts] = source->post_office[source_office_index].packages[i];
					break;
				}
			}
		}
		// free up the old packages of source_office_index and put new there
		package* temp = source->post_office[source_office_index].packages;
		source->post_office[source_office_index].packages = rejected_packages;
		free(temp);
		// free others
		[>free(accepted_package_ids);<]
		[>free(rejected_package_ids);<]
	}
}*/

town town_with_most_packages(town* towns, size_t towns_count) {
	size_t most_package = 0;
	size_t town_number;
	for (size_t i = 0; i < towns_count; ++i) {
		size_t sum_of_packages = 0;
		for (size_t j = 0; j < towns[i].offices_count; ++j) {
			sum_of_packages += towns[i].post_office[j].packages_count;
		}
		if (most_package < sum_of_packages) {
			most_package = sum_of_packages;
			town_number = i;
		}
	}
	return towns[town_number];
}

void print_all_packages(town t) {
	printf("%s:\n", t.name);
	for (size_t i = 0; i < t.offices_count; ++i) {
		printf("\t%zu:\n", i);
		for (size_t j = 0; j < t.post_office[i].packages_count; ++j) {
			printf("\t\t%s\n", t.post_office[i].packages[j].id);
		}
	}
}