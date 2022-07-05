data Tree a = Empty | Node (Tree a) a (Tree a) deriving Show

instance Functor Tree where
    fmap f Empty = Empty
    fmap f (Node x y z) = Node (fmap f x) (f y) (fmap f z)

instance Foldable Tree where
    foldr f x Empty = x
    foldr f x (Node Empty v Empty) = f v x
    foldr f x (Node l v r) = foldr f (f v (foldr f x r)) l

addInTree :: Ord a => a -> Tree a -> Tree a
addInTree x Empty = Node Empty x Empty
addInTree v (Node x y z) | v < y = Node (addInTree v x) y z
    | v >= y = Node x y (addInTree v z)
    | otherwise = Empty

listToTree :: Ord a => [a] -> Tree a
listToTree = foldr addInTree Empty

treeToList :: Tree a -> [a]
treeToList Empty = []
treeToList (Node x y z) = treeToList x <> (y : treeToList z)

treeSort :: Ord a => [a] -> [a]
treeSort a = treeToList (listToTree a)