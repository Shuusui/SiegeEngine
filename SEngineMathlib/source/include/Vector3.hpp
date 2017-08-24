#ifndef _VECTOR3_H_
#error Do not include this file directly! 
#elif !defined _VECTOR3_HPP_
#define _VECTOR3_HPP_




__forceinline float SEngine::Vector3::GetX() const
{
	return Vector3::X;
}
__forceinline float SEngine::Vector3::GetY() const
{
	return Vector3::Y;

}
__forceinline float SEngine::Vector3::GetZ() const
{
	return Vector3::Z;
}
__forceinline void SEngine::Vector3::SetX(float x)
{
	Vector3::X = x;
}
__forceinline void SEngine::Vector3::SetY(float y)
{
	Vector3::Y = y;
}
__forceinline void SEngine::Vector3::SetZ(float z)
{
	Vector3::Z = z;
}

__forceinline void SEngine::Vector3::SetX(int8 x)
{
	Vector3::X = static_cast<float>(x);
}
__forceinline void SEngine::Vector3::SetY(int8 y)
{
	Vector3::Y = static_cast<float>(y);
}
__forceinline void SEngine::Vector3::SetZ(int8 z)
{
	Vector3::Z = static_cast<float>(z);
}
__forceinline void SEngine::Vector3::SetX(int16 x)
{
	Vector3::X = static_cast<float>(x);
}
__forceinline void SEngine::Vector3::SetY(int16 y)
{
	Vector3::Y = static_cast<float>(y);
}
__forceinline void SEngine::Vector3::SetZ(int16 z)
{
	Vector3::Z = static_cast<float>(z);
}
__forceinline void SEngine::Vector3::SetX(int32 x)
{
	Vector3::X = static_cast<float>(x);
}
__forceinline void SEngine::Vector3::SetY(int32 y)
{
	Vector3::Y = static_cast<float>(y);
}
__forceinline void SEngine::Vector3::SetZ(int32 z)
{
	Vector3::Z = static_cast<float>(z);
}
__forceinline void SEngine::Vector3::SetVector(Vector3& vec0)
{
	Vector3::X = vec0.X;
	Vector3::Y = vec0.Y;
	Vector3::Z = vec0.Z;
}
//Setter function which sets all of the variables of the Vector3 to null
__forceinline void SEngine::Vector3::SetNull()
{
	Vector3::X = 0; 
	Vector3::Y = 0; 
	Vector3::Z = 0;
}
__forceinline float SEngine::Vector3::Length()
{
	float length = sqrt(pow(Vector3::X, 2) + pow(Vector3::Y, 2) + pow(Vector3::Z, 2));
	return length;
}


__forceinline void SEngine::Vector3::Normalize()
{
	float length = SEngine::Vector3::Length(); 
	Vector3::X /= length; 
	Vector3::Y /= length; 
	Vector3::Z /= length; 
}

__forceinline SEngine::Vector3 SEngine::Vector3::CrossProduct(const SEngine::Vector3& vec0, const SEngine::Vector3& vec1)
{
	SEngine::Vector3 cross; 
	cross.X = (vec0.Y * vec1.Z) - (vec0.Z*vec1.Y); 
	cross.Y = (vec0.Z*vec1.X) - (vec0.X*vec1.Z);
	cross.Z = (vec0.X*vec1.Y) - (vec0.Y*vec1.X);
	return cross; 
}

__forceinline float SEngine::Vector3::DotProduct(const SEngine::Vector3& vec0, const SEngine::Vector3& vec1)
{
	float dot = (vec0.X*vec1.X) + (vec0.Y*vec1.Y) + (vec0.Z*vec1.Z); 
	return dot; 
}


__forceinline SEngine::Vector3 SEngine::Vector3::operator*(const SEngine::Vector3& vec0) const
{
	SEngine::Vector3 product(SEngine::Vector3::X*vec0.X, SEngine::Vector3::Y*vec0.Y, SEngine::Vector3::Z*vec0.Z);
	return product;
}
__forceinline SEngine::Vector3 SEngine::Vector3::operator+(const SEngine::Vector3& vec0) const
{
	SEngine::Vector3 sum(SEngine::Vector3::X + vec0.X, SEngine::Vector3::Y + vec0.Y, SEngine::Vector3::Z + vec0.Z); 
	return sum; 
}
__forceinline SEngine::Vector3 SEngine::Vector3::operator-(const SEngine::Vector3& vec0)const
{
	SEngine::Vector3 difference(SEngine::Vector3::X - vec0.X, SEngine::Vector3::Y - vec0.Y, SEngine::Vector3::Z - vec0.Z); 
	return difference;
}
__forceinline SEngine::Vector3 SEngine::Vector3::operator/(const SEngine::Vector3& vec0) const
{
	SEngine::Vector3 quotient(SEngine::Vector3::X / vec0.X, SEngine::Vector3::Y / vec0.Y, SEngine::Vector3::Z / vec0.Z);
	return quotient;
}

__forceinline void SEngine::Vector3::operator*=(const SEngine::Vector3& vec0)
{
	SEngine::Vector3::X *= vec0.X;
	SEngine::Vector3::Y *= vec0.Y; 
	SEngine::Vector3::Z *= vec0.Z; 
	
}
__forceinline void SEngine::Vector3::operator+=(const SEngine::Vector3& vec0)
{
	SEngine::Vector3::X += vec0.X;
	SEngine::Vector3::Y += vec0.Y;
	SEngine::Vector3::Z += vec0.Z; 
	
}
__forceinline void SEngine::Vector3::operator-=(const SEngine::Vector3& vec0)
{
	SEngine::Vector3::X -= vec0.X;
	SEngine::Vector3::Y -= vec0.Y;
	SEngine::Vector3::Z -= vec0.Z;
	
}
__forceinline void SEngine::Vector3::operator/=(const SEngine::Vector3& vec0)
{
	SEngine::Vector3::X /= vec0.X; 
	SEngine::Vector3::Y /= vec0.Y; 
	SEngine::Vector3::Z /= vec0.Z; 
	
}
__forceinline void SEngine::Vector3::operator=(const SEngine::Vector3& vec0)
{
	SEngine::Vector3::X = vec0.X;
	SEngine::Vector3::Y = vec0.Y;
	SEngine::Vector3::Z = vec0.Z;
}
__forceinline bool SEngine::Vector3::operator==(const SEngine::Vector3& vec0)const
{
	if (SEngine::Vector3::X == vec0.X && SEngine::Vector3::Y == vec0.Y && SEngine::Vector3::Z == vec0.Z)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
__forceinline bool SEngine::Vector3::operator!=(const SEngine::Vector3& vec0)const
{
	if (SEngine::Vector3::X != vec0.X && SEngine::Vector3::Y != vec0.Y && SEngine::Vector3::Z != vec0.Z)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



__forceinline SEngine::Vector3 SEngine::Vector3::operator*(const float& scal) const
{
	SEngine::Vector3 product(SEngine::Vector3::X*scal, SEngine::Vector3::Y*scal, SEngine::Vector3::Z*scal);
	return product;
}
__forceinline SEngine::Vector3 SEngine::Vector3::operator+(const float& scal) const
{
	SEngine::Vector3 sum(SEngine::Vector3::X + scal, SEngine::Vector3::Y + scal, SEngine::Vector3::Z + scal); 
	return sum; 
}
__forceinline SEngine::Vector3 SEngine::Vector3::operator-(const float& scal) const
{
	SEngine::Vector3 difference(SEngine::Vector3::X + scal, SEngine::Vector3::Y + scal, SEngine::Vector3::Z + scal); 
	return difference;
}
__forceinline SEngine::Vector3 SEngine::Vector3::operator/(const float& scal) const
{
	SEngine::Vector3 quotient(SEngine::Vector3::X / scal, SEngine::Vector3::Y / scal, SEngine::Vector3::Z / scal);
	return quotient; 
}
__forceinline void SEngine::Vector3::operator*=(const float& scal)
{
	SEngine::Vector3::X *= scal;
	SEngine::Vector3::Y *= scal;
	SEngine::Vector3::Y *= scal;
	
}
__forceinline void SEngine::Vector3::operator+=(const float& scal)
{
	SEngine::Vector3::X += scal;
	SEngine::Vector3::Y += scal;
	SEngine::Vector3::Z += scal;
	
}
__forceinline void SEngine::Vector3::operator-=(const float& scal)
{
	SEngine::Vector3::X -= scal;
	SEngine::Vector3::Y -= scal;
	SEngine::Vector3::Z -= scal;
	
}
__forceinline void SEngine::Vector3::operator/=(const float& scal)
{
	SEngine::Vector3::X /= scal; 
	SEngine::Vector3::Y /= scal; 
	SEngine::Vector3::Z /= scal; 
}




#endif //_VECTOR3_HPP_