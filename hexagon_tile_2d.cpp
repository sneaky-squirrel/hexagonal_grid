#include "hexagon_tile_2d.h"
#include "hexagon_math.h"

using Tile = HexagonTile2D;

Tile::HexagonTile2D()
	:coordinates( false, 0, 0, 0 )
{
}

void Tile::_bind_methods()
{
	ClassDB::bind_method( D_METHOD( "add_to_grid" ), &Tile::add_to_grid );
	ClassDB::bind_method( D_METHOD( "remove_from_grid" ), &Tile::remove_from_grid );
	ClassDB::bind_method( D_METHOD( "set_coordinates", "Coordinates" ), &Tile::set_coordinates );
	ClassDB::bind_method( D_METHOD( "get_coordinates" ), &Tile::get_coordinates );
	ADD_PROPERTY( PropertyInfo( Variant::VECTOR2, "Coordinates", PROPERTY_HINT_RANGE, "-4096,4096,1", PROPERTY_USAGE_EDITOR | PROPERTY_USAGE_STORAGE ), "set_coordinates", "get_coordinates" );
}

bool Tile::add_to_grid( void )
{
	SceneTree* tree = get_tree();
	Node *root = nullptr;
	Node *grid = nullptr;
	if( !tree )
	{
		printf( "HexagonTile2D::add_to_grid( void ): Cannot find SceneTree.\n" );
		return false;
	}
	root = tree->get_edited_scene_root();
	if( !root )
	{
		printf( "HexagonTile2D::add_to_grid( void ): Cannot find Root of SceneTree.\n" );
		return false;
	}
	grid = root->find_node( "/main/Grid" );
	return true;
}

void Tile::remove_from_grid( void )
{
	return;
}

void Tile::set_coordinates( const Vector2 &v )
{
	coordinates.x = v.x;
	coordinates.z = v.y;
	coordinates.y = 0 - v.x - v.y;
}

Vector2 Tile::get_coordinates( void ) const
{
	return Vector2( coordinates.x, coordinates.z );
}

int Tile::get_y( void ) const
{
	return coordinates.y;
}
