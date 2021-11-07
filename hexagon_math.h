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
		CubeCoordinates( const bool bIsValid, const int _x, const int _y, const int _z );
	};

	bool operator==( const CubeCoordinates& lhs, const CubeCoordinates& rhs );
	bool operator!=( const CubeCoordinates& lhs, const CubeCoordinates& rhs );
	CubeCoordinates operator+( const CubeCoordinates& lhs, const CubeCoordinates& rhs );
	CubeCoordinates operator-( const CubeCoordinates& lhs, const CubeCoordinates& rhs );
	CubeCoordinates operator*( const CubeCoordinates& vector, const int scale );
	CubeCoordinates rotate( const CubeCoordinates& vector, const bool bClockwise );
	CubeCoordinates rotate( const CubeCoordinates& target, const CubeCoordinates& pivot, const bool bClockwise );
	void print( const char* str, const CubeCoordinates& vector );
}

