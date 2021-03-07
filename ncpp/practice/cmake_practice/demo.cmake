#####################
### JUST PRACTICE ###
#####################

# please don't mind the below commands as they are just for practice

# to set a variable
set(MY_VARIABLE "I'm his variable")

# to print something with cmake scripting
message(STATUS "==> Started build of project ${PROJECT_NAME}, ${PROJECT_VERSION}: ${MY_VARIABLE}")

# to add sub-directory provide the name of the sub-directory relative to this file
add_subdirectory(say-hello)

add_subdirectory(hello_exec)

# let's checkout conditional statement

set(MY_BOOL FALSE)
set(MY_STR "This is a string")
set(MY_OHTER_STR "This is another string")
set(SAME_STRING "This is a string")
set(MY_VALUE 3)

# to perform math expression use MATH(EXPR <destination> <expression>)
set(COUNT 1)

if(NOT MY_BOOL)  # pass my_bool as non-quote or nothing, just the name(it'll be treated as variable)
	# although, dereferencing("${my_bool}") will not give any error though
	message(STATUS "[${COUNT}] ==> inside if")
else()
	message(STATUS "[${COUNT}] ==> inside else")
endif()

MATH(EXPR COUNT "${COUNT} + 1")
if (MY_STR)
	message(STATUS "[${COUNT}] ==> inside if")
else()
	message(STATUS "[${COUNT}] ==> inside else")
endif()

MATH(EXPR COUNT "${COUNT} + 1")
if (MY_STR STREQUAL MY_OHTER_STR)
	message(STATUS "[${COUNT}] ==> inside if")
else()
	message(STATUS "[${COUNT}] ==> inside else")
endif()

MATH(EXPR COUNT "${COUNT} + 1")
if (NOT MY_STR STREQUAL MY_OTHER_STR)
	message(STATUS "[${COUNT}] ==> inside if")
else()
	message(STATUS "[${COUNT}] ==> inside else")
endif()

MATH(EXPR COUNT "${COUNT} + 1")
if (NOT MY_STR STREQUAL "MY_OTHER_STR")  # quoted will be treated as literal string
	message(STATUS "[${COUNT}] ==> inside if")
else()
	message(STATUS "[${COUNT}] ==> inside else")
endif()

MATH(EXPR COUNT "${COUNT} + 1")
if ((NOT MY_STR STREQUAL MY_OTHER_STR) AND ("1" EQUAL MY_VALUE))
	# EQUAL does arithemtic comparision
	message(STATUS "[${COUNT}] ==> inside if")
elseif(MY_OHTER_STR MATCHES "string$")  # regex match
	message(STATUS "[${COUNT}] ==> inside elseif")
else()
	message(STATUS "[${COUNT}] ==> inside else")
endif()
# if you miss the correct variable(say for incrementing(COUNt istead of COUNT)), cmake will not give error

# let's check loop
set(LOOP_COUNT 1)
while(LOOP_COUNT LESS_EQUAL 50)
	message(STATUS "==> Value of LOOP_COUNT: ${LOOP_COUNT}")
	math(EXPR LOOP_COUNT "${LOOP_COUNT} + 1")
endwhile()
# foreach loop(with given items)
foreach(item IN ITEMS alpha bravo charlie delta)
	message(STATUS "==> Item is: ${item}")
endforeach()
# foreach(range based)
# RANGE is kinda just like python range, if one argument for RANGE then it'll start from 0 to inclusive first argument
# if provided with second argument it'll be from first to inclusive second args(I think that's the difference from python range)
# if provided third argument then it'll be step
foreach(idx RANGE 10 100 10)
	message(STATUS "==> idx is: ${idx}")
endforeach()

####################
### PRACTICE END ###
####################


