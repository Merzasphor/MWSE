# Game Units

Each exterior cell is 8192 by 8192 game units or 385 by 385 feet (117 x 117m), according to the Construction Set help. Dividing the two we get 21.3 units per foot, or 70 units per meter. The various properties (e.g. `.position`), and functions in MWSE use these units.


## Cells and Their Sizes

There are two types of cells: interior cells and exterior cells. The exterior cells form a grid, where each is 8192 x 8192 units. Each interior cell is a separate space without the defined dimensions.

The water level in all the exterior cells is 0, while the interior cells have a custom water level, usually set in the Construction Set, or don't have water at all.

The landscape consists of verticies that can only be moved on z axis (up and down). The verticies are 128 units apart, so a "landscape tile" is 128 x 128 units. Each landscape texture covers 512 x 512 units or 4 by 4 tiles.


## Actor Height

Base height of an actor is 128 game units. It's further changed by racial height modifier.