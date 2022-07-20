#include "aufgabe4.h"
#include <cmath>

float CTriangle::GetArea() const
{
	// Implement actual area calculation
	return 3.0f;
}

float CRectangle::GetArea() const
{
	// Implement actual area calculation

	float Dx1 = m_PointD.s_X - m_PointA.s_X;
	float Dy1 = m_PointD.s_Y - m_PointA.s_Y;
	float Dx2 = m_PointB.s_X - m_PointA.s_X;
	float Dy2 = m_PointB.s_Y - m_PointA.s_Y;

	float Area = fabs(Dx1 * Dy2 - Dy2 * Dx2);
	return Area	;
}
