#pragma once
///Internal include files
#pragma region Internal includes
#include "MakroDefines.h"
#pragma endregion
///External include files

///
/// 
///
///Interface for the Component Class
///
///
///
namespace SEngine
{
	class IComponent		
	{
	public: 
		///
		///pure virtual function to update the Component
		///
		virtual void Update() = 0;
		///
		///pure virtual function to set the index of the component
		///
		virtual void SetIndex(uint32 index) = 0;
		///
		///pure virtual function to get the index of the component
		///
		virtual uint32 GetIndex() = 0; 
		///
		///virtual Destructor
		///
		//virtual ~IComponent() = 0; 
	};
}


