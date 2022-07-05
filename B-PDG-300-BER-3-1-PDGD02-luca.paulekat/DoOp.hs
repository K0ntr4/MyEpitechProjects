import Data.Char ( isDigit )
import System.Exit (exitWith, exitSuccess, ExitCode (ExitFailure))
import System.Environment (getArgs)

myElem :: Eq a => a -> [a] -> Bool
myElem el [] = False
myElem el (a:b) | el == a = True
    | otherwise = myElem el b

safeDiv :: Int -> Int -> Maybe Int
safeDiv x 0  = Nothing 
safeDiv x y = Just (div x y)

safeMod :: Int -> Int -> Maybe Int
safeMod x 0  = Nothing 
safeMod x y = Just (mod x y)

safeNth :: [a] -> Int -> Maybe a
safeNth [] x = Nothing
safeNth (a:_) x | x < 0 = Nothing
safeNth (a:b) x | x <= 0 = Just a
    |otherwise = safeNth b (x-1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc Nothing = Nothing 
safeSucc (Just x) = Just (x + 1)

myLookup :: Eq a => a -> [(a,b)] -> Maybe b
myLookup x [] = Nothing
myLookup x (a:b) | x == fst a = Just (snd a)
    |otherwise = myLookup x b

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo fct Nothing b = Nothing
maybeDo fct a Nothing = Nothing 
maybeDo fct (Just a) (Just b) = Just (fct a b)

isInt :: [Char] -> Bool
isInt [] = True
isInt (xs:x) | isDigit xs = isInt x
isInt x | head x == '-' = isInt x
isInt x = False 

readInt :: [Char] -> Maybe Int
readInt str | isInt str = Just (read str)
    | otherwise = Nothing 

myLength :: [a] -> Int
myLength [] = 0
myLength (_:a) = 1 + myLength a

getLineLength :: IO Int
getLineLength = fmap length getLine 

printAndGetLength :: String -> IO Int
printAndGetLength str = putStrLn str >> pure (length str)

buildTop :: Char -> Int -> IO ()
buildTop c 1 = putChar c
buildTop c x = putChar c >> buildTop c (x-1)

printLine :: Char -> Char -> Int -> Int -> IO ()
printLine c d x 1 = putChar '+' >> buildTop '-' ((x * 2) - 2) >> 
    putChar '+' >> putChar '\n'
printLine c d x y = putChar c >> buildTop d ((x * 2) - 2) >>
    putChar c >> putChar '\n' >> printLine '|' ' ' x (y - 1)

printBox :: Int -> IO ()
printBox x | x <= 0 = putStr ""
printBox 1 = putStr "++" >> putChar '\n'
printBox x = printLine '+' '-' x x

concatLines :: Int -> IO String
concatLines x | x <= 0 = return ""
concatLines 1 = getLine
concatLines x = fmap (++) (concatLines (x - 1)) <*> getLine

getInt :: IO (Maybe Int)
getInt = readInt <$> getLine

doop :: Maybe Int -> Int -> Maybe Int -> Maybe Int
doop (Just x) 0 (Just y) = Just (x + y)
doop (Just x) 1 (Just y) = Just (x - y)
doop (Just x) 2 (Just y) = Just (x * y)
doop (Just x) 3 (Just y) = safeDiv x y
doop (Just x) 4 (Just y) = safeMod x y
doop x _ y = Nothing

getOp :: [Char] -> Int
getOp c = case c of
                "+" -> 0
                "-" -> 1
                "*" -> 2
                "/" -> 3
                "%" -> 4
                _ -> 5

exitWithErrorMessage :: String -> IO a
exitWithErrorMessage str = print str >> exitWith (ExitFailure 84)

removeJust :: Maybe a -> a
removeJust (Just a) = a

executeOp :: Maybe Int -> [Char] -> Maybe Int -> IO ()
executeOp Nothing op y = exitWithErrorMessage "Invalid first number."
executeOp x op Nothing = exitWithErrorMessage "Invalid second number."
executeOp x op y | getOp (op) == 5 
    = exitWithErrorMessage "Invalid operator."
executeOp x op y | doop x (getOp (op)) y /= Nothing 
    = print (removeJust(doop x (getOp (op)) y))
    | otherwise = exitWithErrorMessage "Division by 0"

main :: IO ()
main = do 
    x <- getArgs
    let arg1 = x !! 0
    let arg2 = x !! 1
    let arg3 = x !! 2
    executeOp (readInt arg1) arg2 (readInt arg3)