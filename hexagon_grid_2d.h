#ifndef HEXAGON_GRID_2D_H
#define HEXAGON_GRID_2D_H

#include "scene/main/node.h"
#include "core/variant.h"

class HexagonTile2D;

class HexagonGrid2D : public Node
{
	GDCLASS( HexagonGrid2D, Node );
protected:
	static void _bind_methods();

public:
	HexagonGrid2D();
	void set_grid_size( int size );
	int get_grid_size( void ) const;
	void snap_tile( HexagonTile2D *tile );
private:
	int grid_size;
};

#endif
