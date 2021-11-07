#include "hexagon_math.h"
#include "stdio.h"

using direction = HexagonGrid::Direction;
namespace hex = HexagonGrid;
using cube = HexagonGrid::CubeCoordinates;

std::array< direction, 6 > DirectionList =
{
	direction::kSouthWest, direction::kWest,
	direction::kNorthWest, direction::kNorthEast,
	direction::kEast, direction::kSouthEast
};

cube::CubeCoordinates( const bool bIsValid, const int _x, const int _y, const int _z )
 :bValid( bIsValid ), x( _x ), y( _y ), z( _z )
{
}

bool hex::operator==( const cube& lhs, const cube& rhs )
{
	return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z; 
}

bool hex::operator!=( const cube& lhs, const cube& rhs )
{
	return lhs.x != rhs.x || lhs.y != rhs.y || lhs.z != rhs.z; 
}

cube hex::operator+( const cube& lhs, const cube& rhs )
{
	return cube( true, lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z ); 
}

cube hex::operator-( const cube& lhs, const cube& rhs )
{
	return cube( true, lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z ); 
}

cube hex::operator*( const cube& vector, const int scale )
{
	return cube( true, vector.x * scale, vector.y * scale, vector.z * scale ); 
}

cube hex::rotate( const cube& vector, const bool bClockwise )
{
	return bClockwise ?
			cube( true, 0 - vector.z, 0 - vector.x, 0 - vector.y ) :
			cube( true, 0 - vector.y, 0 - vector.z, 0 - vector.x );
}

cube hex::rotate( const cube& target, const cube& pivot, const bool bClockwise )
{
	cube difference = target - pivot;
	return pivot + rotate( difference, bClockwise );
}

void hex::print( const char* str, const cube& vector )
{
	printf( "Cube %s Coordinate:%4d,%4d,%4d | %s.\n",
			str,
			vector.x,
			vector.y,
			vector.z,
			vector.bValid ? "True" : "False"
		);
}
