#pragma once

struct Point2D
{
	Point2D()
		: s_X(0)
		, s_Y(0)
	{
	}

	Point2D(float _X, float _Y)
		: s_X(_X)
		, s_Y(_Y)
	{
	}

	float s_X;
	float s_Y;
};

class CPolygon
{
	public:

		int m_Corners;

	public:

		virtual float GetArea() const = 0;

};

class CTriangle : CPolygon
{
	public:

		float GetArea() const;

	public:

		// -------------------------------
		// Should be set A, B, C
		// -------------------------------
		Point2D m_Points[];
		
};

class CRectangle : CPolygon
{
	public:

		float GetArea() const;

	public:

		// -------------------------------
		// Should be set A, B, C, D
		// -------------------------------
		Point2D m_PointA;
		Point2D m_PointB;
		Point2D m_PointC;
		Point2D m_PointD;

};