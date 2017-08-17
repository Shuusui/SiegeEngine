#pragma once
///internal includes
#pragma region Internal includes
#include "IComponent.h"
#include "Vector3.h"
#pragma endregion 

///
///
///A default Transform interface which is arose from a lesso. It's only a little step between the IComponent and the transform component
///
///

namespace SEngine
{
	class ITransform : public IComponent
	{
	public:
		///
		///translate the Component across the tranlation Vector
		///
		virtual void TranslateComponent(Vector3 translation) = 0; 
		///
		///rotate the component around the X Axis
		///
		virtual void RotateX(float scal) = 0;
		///
		///rotate the component around the Y Axis
		///
		virtual void RotateY(float scal) = 0; 
		///
		///rotate the component around the Z Axis
		///
		virtual void RotateZ(float scal) = 0; 
		///
		///scale the component with the scaling factor
		///
		virtual void Scale(Vector3 scale) = 0;		
	};
}