* You can open `R` repl with `R` command in terminal
* To run a file in console, you can do `R -f temp.r`
* To make the output silent(the prologue) use `-q` flag, `R -q -f temp.r`
* You can use `Rscript` too to run the r scripts, `Rscript temp.r`
* Instead of redirecting output to stdout, you can get the output in a file, `R CMD BATCH temp.r`, it'll create a file 'temp.r.Rout', which will contain all output from the executed file
* If you want to execute your script like `./temp.r`, you have to add shebang like `#!/usr/bin/env Rscript`
* to check R library paths, use `> .libPaths()`
* you can add a custom folder to library path with `R_LIBS` env variable
* to list all packages, use `> instal.packages()`(don't give any package name)
* to install a new package, `> install.packages('packagename', "~/Rlibs", "repo url")`(the parameters are optional)
* to get more information about _install.packages()_, use `?install.packages()`
* you can see which library is available by running `> library()`
* For more details of packages, visit -> [r-packages-guide](https://www.datacamp.com/community/tutorials/r-packages-guide)

## R-data types

* character => 'a', "abc"
* numeric => 2, 15.5
* integer => 2L (L is not here for long)
* logical => TRUE,FALSE
* complex => 1+3i

You can use `typeof()` to check datatype of variable, `length()` for length

## Data structure in R

* atomic vector (for homogenous data, default type = logical)
* list (for heterogenous data)
* matrix (2d-homongenous type data storage)
* data frame (2d-heterogenous type data storage)
* factors

## Coercion in R

* when a data-type changes its mode(it's basically type-casting)
* when this is done automatically by language, it's implicit
* when we do it manually, it's explicit.
* `as` keyword can be use to explicit coercion(like `as.numeric(), as.character()`)

`Note:` indexing in R starts from 1

## data frame

* 2d-heterogenous data structure
* all the files accessed in R are in data frame
