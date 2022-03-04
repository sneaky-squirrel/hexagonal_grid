#ifndef HEXAGON_TILE_2D_H
#define HEXAGON_TILE_2D_H

#include "scene/2d/sprite.h"
#include "hexagon_math.h"

class HexagonTile2D : public Sprite
{
	GDCLASS( HexagonTile2D, Sprite );
protected:
	static void _bind_methods();

public:
	HexagonTile2D();

	bool add_to_grid( void );
	void remove_from_grid( void );

	void set_coordinates( const Vector2 &v );
	Vector2 get_coordinates( void ) const;
	int get_y( void ) const;
private:
	HexagonGrid::CubeCoordinates coordinates;
};

#endif
