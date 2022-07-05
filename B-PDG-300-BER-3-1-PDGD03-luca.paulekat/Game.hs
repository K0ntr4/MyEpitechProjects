import System.Posix (Handler(Default))
data Item = Sword | Bow | MagicWand
data Mob = Mummy | Skeleton Item | Witch (Maybe Item) deriving Eq

class HasItem a where
    hasItem :: a -> Bool
    getItem :: a -> Maybe Item

    hasItem _ = False

instance HasItem Mob where
    getItem Mummy = Nothing
    getItem (Skeleton x) = Just x
    getItem (Witch (Just x)) = Just x
    getItem (Witch Nothing) = Nothing

    hasItem Mummy = False
    hasItem (Skeleton x)= True
    hasItem (Witch (Just x)) = True
    hasItem (Witch Nothing) = False

instance Eq Item where
    Sword == Sword = True
    Bow == Bow = True
    MagicWand == MagicWand = True
    _ == _ = False

instance Show Item where
    show Sword = "sword"
    show Bow = "bow"
    show MagicWand = "magic wand"

instance Show Mob where
    show Mummy = "mummy"
    show (Skeleton Bow) = "doomed archer"
    show (Skeleton Sword) = "dead knight"
    show (Skeleton x) = "skeleton holding a " <> show x
    show (Witch (Just MagicWand)) = "sorceress"
    show (Witch Nothing) = "witch"
    show (Witch (Just x)) = "witch holding a " <> show x

createMummy :: Mob
createMummy = Mummy

createArcher :: Mob
createArcher = Skeleton Bow

createKnight :: Mob
createKnight = Skeleton Sword

createWitch :: Mob
createWitch = Witch Nothing

createSorceress :: Mob
createSorceress = Witch (Just MagicWand)

create :: String -> Maybe Mob
create "mummy" = Just createMummy
create "doomed archer" = Just createArcher
create "dead knight" = Just createKnight
create "witch" = Just createWitch
create "sorceress" = Just createSorceress
create _ = Nothing

equip :: Item -> Mob -> Maybe Mob
equip _ Mummy = Nothing
equip i (Skeleton x) = Just (Skeleton i)
equip i (Witch x) = Just (Witch (Just i))