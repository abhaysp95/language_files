#include <stdio.h>
#include "b_nested.h"

#include "b.h"
#include "c.h"
#include "d.h"

void b_nested() {
	b();
	c();
	d();
}

/* now when compiling through makefile, when b_nested.o is created it'll not
 * complain that it(b_nested.o) is not seeing b(), c() and d() because it just
 * needs to see declaration at compile time, which is provided by b_nested.h, so
 * at this time we're not actually linking and b() c() and d()(or a.o, b.o, c.o
 * ? (this is question)), they'll be resolved and linked together in our final
 * compilation and linking step(see Makefile) */

/* so, in nested.c when we'll(or to say compiler) realize that we are calling
 * b(), c() and d() from b_nested.o at that time, nested.c will find them
 * because the objects for them are now creating and are in now linking process
 * and that time this is resolved */
