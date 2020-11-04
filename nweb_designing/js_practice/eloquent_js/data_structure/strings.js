let kim = "Kim";
kim.age = 88;
console.log(kim.age);

/* Values of type string, number and Boolean are not objects(just like above kim.age) */

console.log("coconuts".slice(4, 7));
console.log("coconut".indexOf("u"));
console.log("one two three".indexOf("ee"));
console.log("   okay  \n".trim());
console.log(String(6).padStart(3, "0"));
console.log("6".padStart(3, "1"));

let sentence = "Secratorybirds specialize in stomping";
let words = sentence.split(" ");
console.log(words);
console.log(words.join("-"));
console.log("LA".repeat(3));
console.log(sentence.length);
console.log(sentence[2]);
