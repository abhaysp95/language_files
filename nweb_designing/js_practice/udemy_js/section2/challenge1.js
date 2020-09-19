// compare the BMI


var markHeight = 1.79;
var markWeight = 78;
var johnHeight = 1.82;
var johnWeight = 86;

markBMI = markWeight / (markHeight * markHeight);
johnBMI = johnWeight / (johnWeight * johnWeight);

isMarksBMIgreater = markBMI > johnBMI;

console.log("Is Marks BMI greater than John: " + isMarksBMIgreater);
