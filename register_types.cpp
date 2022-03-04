#include "register_types.h"

#include "core/class_db.h"
#include "hexagon_tile_2d.h"
#include "hexagon_grid_2d.h"

void register_hexagon_grid_types()
{
	ClassDB::register_class< HexagonTile2D >();
	ClassDB::register_class< HexagonGrid2D >();
	return;
}

void unregister_hexagon_grid_types()
{
	return;
}
