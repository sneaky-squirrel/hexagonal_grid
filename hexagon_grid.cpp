#include "hexagon_grid.h"

int HexagonGrid2D::foo()
{
	return 17;
}

HexagonGrid2D::HexagonGrid2D()
{
}

void HexagonGrid2D::_bind_methods()
{
	ClassDB::bind_method( D_METHOD( "foo" ), &HexagonGrid2D::foo );
}
