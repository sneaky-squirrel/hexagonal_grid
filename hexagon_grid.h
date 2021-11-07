#ifndef HEXAGON_GRID_2D_H
#define HEXAGON_GRID_2D_H

#include "scene/main/node.h"

class HexagonGrid2D : public Node
{
	GDCLASS( HexagonGrid2D, Node );
protected:
	static void _bind_methods();

public:
	int foo();
	;

	HexagonGrid2D();
};

#endif
