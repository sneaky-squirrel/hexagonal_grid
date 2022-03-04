#include "hexagon_grid_2d.h"
#include "core/variant.h"
#include "hexagon_math.h"
#include <cmath>
#include "hexagon_tile_2d.h"

using Grid = HexagonGrid2D;

HexagonGrid2D::HexagonGrid2D()
	: grid_size( 64 )
{
}

void Grid::_bind_methods()
{
	ClassDB::bind_method( D_METHOD( "set_grid_size", "Grid_Size" ), &Grid::set_grid_size);
	ClassDB::bind_method( D_METHOD( "get_grid_size" ), &Grid::get_grid_size);
	ADD_PROPERTY( PropertyInfo( Variant::INT, "Grid_Size", PROPERTY_HINT_RANGE, "64,1024,64", PROPERTY_USAGE_EDITOR | PROPERTY_USAGE_STORAGE ), "set_grid_size", "get_grid_size" );
}

void Grid::set_grid_size( int size )
{
	grid_size = size;
}

int Grid::get_grid_size( void ) const
{
	return grid_size;
}

void Grid::snap_tile( HexagonTile2D *tile )
{
	using namespace HexagonGrid;
	Vector2 v = tile->get_position();
	v.x = v.x < 0 ? v.x - grid_size * cos( M_PI / 6 ) : v.x + grid_size * cos( M_PI / 6 );
	v.y = v.y < 0 ? v.y - grid_size * 3 / 2  * sin( M_PI / 6 ) : v.y + grid_size * 3 / 2  * sin( M_PI / 6 );
	CubeCoordinates cubeCoor = cartesianToCube( CartesianCoordinates( v.x, v.y ), grid_size );
	tile->set_coordinates( Vector2( cubeCoor.x, cubeCoor.z ) );
	Vector2 p = tile->get_coordinates();
	CartesianCoordinates cartCoor = cubeToCartesian( CubeCoordinates( true, p.x, 0-p.x-p.y, p.y ), grid_size ) ;
	tile->set_position( Vector2( cartCoor.x, cartCoor.y) );
}
