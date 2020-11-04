//static int s_variable = 5;
int s_variable = 5;

// let's make this static, otherwise error for duplicate declaration as main.cpp also have it
static void function() {

}


// this is only visible to one translation unit or to say, private for one translation unit, no other class/file will see it if it has static prefixed to it
