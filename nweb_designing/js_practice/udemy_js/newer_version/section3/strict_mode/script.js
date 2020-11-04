/* script mode should be the first line of the file or else it will not work, comments are exception. You can have script mode for individual functions too */

/* helps us in getting error when we do mistake */

'use strict';

let hasDriversLicense = false;
const passTest = true;

if (passTest) { hasDriversLicense = true; }
if (hasDriversLicense) { console.log("I can drive"); }

/* js reserved words for future is also detected by script mode, like */

//const interface = 'Audio';
//const private = SSH;
