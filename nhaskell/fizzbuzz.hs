import Data.List
import System.IO

range = [1 .. 10]
square = map(\x -> x * x) [1..10]
fizzBuzz num
  | num `mod` 15 == 0 = "FizzBuzz"
  | num `mod` 5 == 0 = "Buzz"
  | num `mod` 3 == 0 = "Fizz"
  | otherwise = show num

full_fizzbuzz = map(fizzBuzz) [1..100]
