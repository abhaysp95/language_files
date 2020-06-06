import Data.List
import System.IO

-- single line comments
{-multiline comment
another line-}

maxInt = maxBound :: Int
minInt = minBound :: Int

bigfloat = 89.09309048 + 0.30498092

always5 :: Int  -- permanent
always5 = 10

sumNums = sum [1..1000]

-- all four mathematical operations are normal
modIs = mod 7 5  -- prefix operator
modIs2 = 8 `mod` 5  -- infix operator


-- since sqrt works with floating numbers, else gives error variable not in scope
num9 = 9 :: Int
sqrtOf9 = sqrt (fromIntegral num9)

-- other built-in math functions
piVal = pi
ePow9 = exp 9
logOf9 = log 9
squared9 = 9 ** 2
truncateVal = truncate 9.99999
roundVal = round 9.99000999
ceilingVal =ceiling 9.99000999
floorVal = floor 77.7889

-- Also sin, cos, tan, asin, acos, atan, sinh, tanh,
-- cosh, atanh, acosh

trueAndFalse = True && False
trueOrFalse = True || False
notTrue = not(True)


-- List
primeNumbers = [3,5,6,7,11]
morePrime = primeNumbers ++ [13, 17]
favNums = 2 : 7 : 21 : 66 : []  -- end of list
multiList = [[3, 5, 7], [11, 13, 17]]
morePrimes2 = 2 : morePrime
-- length
lenPrime = length morePrimes2
-- reverse
revPrime = reverse morePrimes2
-- check if list empty
isListEmpty = null morePrimes2
-- slicing list (no -ve)
secondPrime = morePrimes2 !! 1
-- fisrt value
firstPrime = head morePrimes2
-- last value
lastPrime = last morePrimes2
-- everything except last
primeInit = init morePrimes2
-- first 3 primes
first3Primes = take 3 morePrimes2
-- remove
removedPrimes = drop 3 morePrimes2
-- check if in list
is7InList = 7 `elem` morePrimes2
-- is7InList2 = `elem` 7 morePrimes2  (not right)
-- max & min
maxPrime = maximum morePrimes2
minPrime = minimum morePrimes2
-- sum of list
sumPrime = sum morePrimes2
-- product
productPrime = product morePrimes2
-- list gernerate
zeroToTen = [0..10]
-- even list
evenList = [2,4..20]
-- letter list
letterList = ['A', 'C'..'Z']
-- infinite list
infinPow10 = [10,20..]
is200inList = 200 `elem` infinPow10
-- repeat values
many2s = take 10 (repeat 2)
many3s = replicate 20 3
cycleList = take 40 (cycle [1, 2, 3, 4, 5])
