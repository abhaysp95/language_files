/* ---- ifdef/infndef(header) guards --------- */
#ifndef UTIL_H
#define UTIL_H
/* --------------------------- */

/* ---- extern "C" --------- */
#ifdef __cplusplus  // it'll be defined if we use C++ compiler
// C++ does name mangling while C doesn't
extern "C" {
#endif
/* --------------------------- */

	typedef struct {
		int age;
		char name[256];
	} person;

	double getmean(double *values, int length);

	void print_person_info(person *p);

/* ---- extern "C" --------- */
#ifdef __cplusplus
}
#endif
/* --------------------------- */

/* ---- ifdef guards --------- */
#endif  // UTIL_H
/* --------------------------- */
