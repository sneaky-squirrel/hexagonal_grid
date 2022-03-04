#ifndef HEXAGON_MATH_H
#define HEXAGON_MATH_H

#include <array>

namespace HexagonGrid
{
	// forward declarations
	enum class Direction;

	// global variables
	extern std::array< Direction, 6 > DirectionList;

	enum class Direction
	{
		kInvalid,
		kNorthWest, kNorthEast,
		kWest, kEast,
		kSouthWest, kSouthEast
	};

	struct CubeCoordinates
	{
		bool bValid;
		int x;
		int y;
		int z;
		CubeCoordinates( bool bIsValid, int _x, int _y, int _z );
	};

	struct CartesianCoordinates
	{
		double x;
		double y;
		CartesianCoordinates( double _x, double _y );
	};

	bool operator==( const CubeCoordinates &lhs, const CubeCoordinates &rhs );
	bool operator!=( const CubeCoordinates &lhs, const CubeCoordinates &rhs );
	CubeCoordinates operator+( const CubeCoordinates &lhs, const CubeCoordinates &rhs );
	CubeCoordinates operator-( const CubeCoordinates &lhs, const CubeCoordinates &rhs );
	CubeCoordinates operator*( const CubeCoordinates &vector, int scale );
	CubeCoordinates rotate( const CubeCoordinates &vector, bool bClockwise );
	CubeCoordinates rotate( const CubeCoordinates &target, const CubeCoordinates &pivot, bool bClockwise );
	void print( const char* str, const CubeCoordinates &vector );
	CartesianCoordinates cubeToCartesian( const CubeCoordinates &coordinates, int grid_size );
	CubeCoordinates cartesianToCube( const CartesianCoordinates &coordinates, int grid_size );
}

#endif
