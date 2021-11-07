#include "register_types.h"

#include "core/class_db.h"
#include "hexagon_grid.h"

void register_hexagon_grid_types()
{
	ClassDB::register_class< HexagonGrid2D >();
	return;
}

void unregister_hexagon_grid_types()
{
	return;
}
