--
-- EPITECH PROJECT, 2022
-- B-PDG-300-BER-3-1-PDGRUSH1-luca.paulekat
-- File description:
-- pushswap_checker
--

import System.Environment
import System.Exit
import Data.Char
import Distribution.Simple.Program.HcPkg (list)

convert :: [String] -> [Int]
convert = map read

checkSorted :: Ord a => [a] -> Bool
checkSorted [] = True
checkSorted [x] = True
checkSorted (a:b:as) = a <= b && checkSorted (b:as)

sa :: ([Int], [Int]) -> ([Int], [Int])
sa ([], y) = ([], y)
sa (x, y) | length x <= 1 = (x, y)
sa (x:xs, y) = (head xs:x:tail xs, y)

sb :: ([Int], [Int]) -> ([Int], [Int])
sb (x, []) = (x, [])
sb (x, y) | length y <= 1 = (x, y)
sb (x, y:ys) = (head ys:y:tail ys, x)

pa :: ([Int], [Int]) -> ([Int], [Int])
pa (x, []) = (x, [])
pa (x, y:ys) = (y:x, ys)

pb :: ([Int], [Int]) -> ([Int], [Int])
pb ([], y) = ([], y)
pb (x:xs, y) = (xs, x:y)

ra :: ([Int], [Int]) -> ([Int], [Int])
ra ([], y) = ([], y)
ra (x, y) | length x == 1 = (x, y)
ra (x:xs, y) = (xs <> [x], y)

rb :: ([Int], [Int])-> ([Int], [Int])
rb (x, []) = (x, [])
rb (x, y) | length y == 1 = (x, y)
rb (x, y:ys) = (x, ys <> [y])

rr :: ([Int], [Int]) -> ([Int], [Int])
rr ([], []) = ([], [])
rr (x, y) | length y == 1 && length x == 1 = (x, y)
rr ([], y:ys) = ([], ys <> [y])
rr (x:xs, []) = (xs <> [x], [])
rr (x:xs, y:ys) = (xs <> [x], ys <> [y])

myLast :: [a] -> [a]
myLast [] = []
myLast (a:b) | length b == 0 = [a]
    | otherwise = myLast b

remLast :: [a] -> [a]
remLast [] = []
remLast x | length x == 2 = [head x]
remLast (x:xs) = x:remLast xs

rra :: ([Int], [Int]) -> ([Int], [Int])
rra ([],y) = ([], y)
rra (x, y) | length x == 1 = (x, y)
rra (x, y) = (myLast x <> remLast x, y)

rrb :: ([Int], [Int]) -> ([Int], [Int])
rrb (x, []) = (x, [])
rrb (x, y) | length y == 1 = (x, y)
rrb (x, y) = (x, myLast y <> remLast y)

rrr :: ([Int], [Int]) -> ([Int], [Int])
rrr ([], []) = ([], [])
rrr (x, y) | length y == 1 && length x == 1 = (x, y)
rrr (x, y) | length y == 1 = (myLast x <> remLast x, y)
rrr (x, y) | length x == 1 = (x, myLast y <> remLast y)
rrr ([], y) | length y <= 1 = ([], y)
    | otherwise = ([], myLast y <> remLast y)
rrr (x, []) | length x <= 1 = ([], x)
    | otherwise = (myLast x <> remLast x, [])
rrr (x, y) = (myLast x <> remLast x, myLast y <> remLast y)

executeOp :: [String] -> ([Int], [Int]) -> Bool
executeOp [] ([], _) = False
executeOp [] (list1, _) = checkSorted list1
executeOp (x:xs) (list1, list2) = case x of
    "sa" -> executeOp xs (sa (list1, list2))
    "sb" -> executeOp xs (sb (list1, list2))
    "pa" -> executeOp xs (pa (list1, list2))
    "pb" -> executeOp xs (pb (list1, list2))
    _ -> executeRot (x:xs) (list1, list2)

executeRot :: [String] -> ([Int], [Int]) -> Bool
executeRot(x:xs) (list1, list2) = case x of
    "ra" -> executeOp xs (ra (list1, list2))
    "rb" -> executeOp xs (rb (list1, list2))
    "rr" -> executeOp xs (rr (list1, list2))
    "rra" -> executeOp xs (rra (list1, list2))
    "rrb" -> executeOp xs (rrb (list1, list2))
    "rrr" -> executeOp xs (rrr (list1, list2))
    _ -> executeOp xs (list1, list2)
executeRot [] (list1, _) = checkSorted list1

checkInput :: [String] -> Bool
checkInput [] = True
checkInput (x:xs) = case x of
    "sa" -> checkInput xs
    "sb" -> checkInput xs
    "pa" -> checkInput xs
    "pb" -> checkInput xs
    _ -> checkInputRot (x:xs)

checkInputRot :: [String] -> Bool
checkInputRot (x:xs) = case x of
    "ra" -> checkInput xs
    "rb" -> checkInput xs
    "rr" -> checkInput xs
    "rra" -> checkInput xs
    "rrb" -> checkInput xs
    "rrr" -> checkInput xs
    _ -> False
checkInputRot [] = True

isInt :: [Char] -> Bool
isInt [] = True
isInt ('-':x) = isInt x
isInt (xs:x) | isDigit xs = isInt x
isInt x = False

checkArgs :: [String] -> Bool
checkArgs [] = True
checkArgs (x:xs) = 
    if isInt x
        then checkArgs xs
        else False

result :: [String] -> [Int] -> IO ()
result op list = 
    if (executeOp op (list, []))
    then putStrLn "OK"
    else putStrLn "KO"

errorCheck :: [String] -> IO ()
errorCheck op =
    if checkInput op
    then pure ()
    else exitWith (ExitFailure 84)

main :: IO ()
main = do
    args <- getArgs
    operations <- getLine
    let op = words operations
    errorCheck op
    if checkArgs args
    then pure ()
    else exitWith (ExitFailure 84)
    let list = convert args
    result op list