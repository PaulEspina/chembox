#pragma once
class Vec2
{
public:
	Vec2() = default;
	Vec2(float x, float y)
		:
		Vec2()
	{
		this->x = x;
		this->y = y;
	}
	Vec2 operator+(const Vec2& rhs) const
	{
		return Vec2(x + rhs.x, y + rhs.y);
	}
	Vec2& operator+=(const Vec2& rhs)
	{
		return *this = *this + rhs;
	}
	Vec2 operator*(float rhs) const
	{
		return Vec2(x * rhs, y * rhs);
	}
	Vec2& operator*=(float rhs)
	{
		return *this = *this * rhs;
	}
	Vec2 operator-(const Vec2& rhs) const
	{
		return Vec2(x - rhs.x, y - rhs.y);
	}
	Vec2& operator-=(const Vec2& rhs)
	{
		return *this = *this - rhs;
	}
	bool operator==(const Vec2& rhs)
	{
		if(x == rhs.x && y == rhs.y)
			return true;
		return false;
	}
	bool operator!=(const Vec2& rhs)
	{
		if(x != rhs.x && y != rhs.y)
			return false;
		return true;
	}
	float GetLength() const
	{
		return std::sqrt(GetLengthSq());
	}
	float GetLengthSq() const
	{
		return x * x + y * y;
	}
	Vec2& Normalize()
	{
		return *this = GetNormalized();
	}
	Vec2 GetNormalized() const
	{
		const float len = GetLength();
		if(len != 0.0f)
		{
			return *this * (1.0f / len);
		}
		return *this;
	}
public:
	float x, y;
};

