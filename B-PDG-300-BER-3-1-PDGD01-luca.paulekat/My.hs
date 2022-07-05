mySucc :: Int -> Int
mySucc x = x + 1

myIsNeg :: Int -> Bool
myIsNeg x = x < 0

myAbs :: Int -> Int
myAbs x | x < 0 = x * (-1)
    | otherwise = x

myMin :: Int -> Int -> Int
myMin x y | x < y = x
    | otherwise = y

myMax :: Int -> Int -> Int
myMax x y | x < y = y
    | otherwise = x

myTuple :: a -> b -> (a, b)
myTuple a b = (a, b)

myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a, b, c)

myFst :: (a, b) -> a
myFst (a, b) = a

mySnd :: (a, b) -> b
mySnd (a, b) = b

mySwap :: (a, b) -> (b, a)
mySwap (a, b) = (b, a)

myHead :: [a] -> a
myHead (a:_) = a
myHead [] = error "empty list"

myTail :: [a] -> [a]
myTail (_:a) = a
myTail [] = error "empty list"

myLength :: [a] -> Int
myLength [] = 0
myLength (_:a) = 1 + myLength a

myNth :: [a] -> Int -> a
myNth [] x = error "end of list"
myNth (a:_) x | myIsNeg x = error "index can't be negative"
myNth (a:b) x | x <= 0 = a
    |otherwise = myNth b (x-1)

myTake :: Int -> [a] -> [a]
myTake 1 (a:_) = [a]
myTake x [] = error "empty list"
myTake x a | myLength a < x = a
myTake x (a:_) | myIsNeg x = error "index can't be negative"
myTake x (a:b) = a:myTake (x-1) b

myDrop :: Int -> [a] -> [a]
myDrop x [] = error "empty list"
myDrop x a | myLength a < x = []
myDrop x (a:_) | myIsNeg x = error "index can't be negative"
myDrop 1 (a:b) = b
myDrop x (a:b) = myDrop (x-1) b

myAppend :: [a] -> [a] -> [a]
myAppend [] b = b
myAppend a [] = a
myAppend (a:b) c = a:myAppend b c

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (x:y) = myAppend (myReverse y) [x]

myInit :: [a] -> [a]
myInit [] = error "empty list"
myInit (a:b) | myLength b > 0 = a:myInit b
    | otherwise = []

myLast :: [a] -> a
myLast [] = error "empty list"
myLast (a:b) | myLength b == 0 = a
    | otherwise = myLast b

myZip :: [a] -> [b] -> [(a, b)]
myZip [] b = []
myZip a [] = []
myZip (a:b) (x:y)| myLength b > 0 || myLength y > 0 = (a, x):myZip b y
    | otherwise = []

myUnzip :: [(a,b)] -> ([a], [b])
myUnzip [] = ([], [])
myUnzip ((a, b):c) = (a:myFst (myUnzip c), b:mySnd (myUnzip c))

myMap :: (a -> b) -> [a] -> [b]
myMap funct [] = [] 
myMap funct (a:b) = funct a:myMap funct b

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter funct [] = [] 
myFilter funct (a:b) | funct a = a:myFilter funct b
    | otherwise = myFilter funct b

myFilterr :: (a -> Bool) -> [a] -> [a]
myFilterr funct [] = [] 
myFilterr funct (a:b) | funct a == False = a:myFilterr funct b
    | otherwise = myFilterr funct b

myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldl funct x [] = x
myFoldl funct x (a:b) = myFoldl funct (funct x a) b

myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr funct x [] = x
myFoldr funct x a = myFoldr funct (funct (myLast a) x) (myInit a)

myPartition :: (a -> Bool) -> [a] -> ([a], [a])
myPartition funct [] = ([], [])
myPartition funct a = (myFilter funct a, myFilterr funct a)

myQuickSort :: (a -> a -> Bool) -> [a] -> [a]
myQuickSort funct [] = []
myQuickSort funct a = 
    myAppend (myAppend (myQuickSort funct 
        (myFilterrQ funct (myTail a) (myHead a)))
        [myHead a]) 
        (myQuickSort funct (myFilterQ funct (myTail a) (myHead a)))

myFilterQ :: (a -> a -> Bool) -> [a] -> a -> [a]
myFilterQ funct [] x = [] 
myFilterQ funct (a:b) x | funct x a = a:myFilterQ funct b x
    | otherwise = myFilterQ funct b x

myFilterrQ :: (a -> a -> Bool) -> [a] -> a -> [a]
myFilterrQ funct [] x = [] 
myFilterrQ funct (a:b) x | funct x a == False = a:myFilterrQ funct b x
    | otherwise = myFilterrQ funct b x