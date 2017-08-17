#pragma once
///internal includes
#pragma region Internal includes
#include "IComponent.h"
#pragma endregion

///
///
///A default Script interface which is arose from a lesson. It describes the behavior of a script.
///
///

namespace SEngine
{
	class IScript : IComponent
	{
		///Start function which can be overridden from the script
		virtual void Start() = 0; 
		///Fixed Update function which is equivalent to the fixedUpdate in Unity which updates in time.deltaTime
		virtual void FixedUpdate() = 0; 
		///Awake function which starts in front of the Start function and can be overridden from the script
		virtual void Awake() = 0; 
	};
}