#include <iostream>
#include <cmath>

using namespace std;



struct Vector2D
{
	float x, y;
};

struct Point
{
	float x, y;
};

Point MovePoint(Point position, Vector2D velocity)
{
	return { position.x + velocity.x, position.y + velocity.y };
}

Vector2D Add(Vector2D a, Vector2D b)
{
	return { a.x + b.x, a.y + b.y };
}

Vector2D Substract(Vector2D a, Vector2D b)
{
	return { a.x - b.x, a.y - b.y };
}

Vector2D Scale(Vector2D v, float scalar)
{
	return { v.x * scalar, v.y * scalar};
}

float Magnitude(Vector2D vec2D)
{
	return sqrt(vec2D.x * vec2D.x + vec2D.x * vec2D.y);
}
//int main()
//{
//	//for (int frame = 0; frame <= 5; frame++)
//	//{
//	//	cout << "Frame " << frame << " : (" << objectPos.x << " , " << objectPos.y << ")" << endl;
//	//	objectPos = MovePoint(objectPos, velocity);
//	//}
//	//Vector2D v1 = { 3.0f, 4.0f };
//	//Vector2D v2 = { 1.0f, 2.0f };
//
//	//Vector2D sum = Add( v1,v2 );
//	//Vector2D diff = Substract(v1, v2);
//	//Vector2D scaled = Scale(v1, 2.0f);
//
//	//cout << "v1: (" << v1.x << ", " << v1.y << ")" << endl;
//	//cout << "v2: (" << v2.x << ", " << v2.y << ")" << endl;
//
//	//cout << endl;
//
//	//cout << "Sum: (" << sum.x << ", " << sum.y << ")" << endl;
//	//cout << "Diff: (" << diff.x << ", " << diff.y << ")" << endl;
//	//cout << "Scale: (" << scaled.x << ", " << scaled.y << ") " << endl;
//
//
//	//Point objectPos = { 0.0f, 0.0f };
//	//Vector2D velocity = { 2.0f, 1.0f };
//
//	Vector2D v1 = { 3.0f, 4.0f };
//	Vector2D v2 = { 5.0f,12.0f };
//	Vector2D v3 = { 1.0f, 0.0f };
//	
//	cout << "Vector (" << v1.x << ", " << v1.y << " ) has magnitude: " << Magnitude(v1) << endl;
//	cout << "Vector (" << v2.x << ", " << v2.y << " ) has magnitude: " << Magnitude(v2) << endl;
//	cout << "Vector (" << v3.x << ", " << v3.y << " ) has magnitude: " << Magnitude(v3) << endl;
//
//	return 0;
//}