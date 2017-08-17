#pragma once
///internal includes
#pragma region Internal includes
#include "EmptyGameObject.h"
#include "MakroDefines.h"
#pragma endregion
///external includes
#pragma region External includes
#include <vector>
#pragma endregion

///
///
///Default Camera object which inherist from EmptyGameObject and will render the project 
///
///
namespace SEngine
{

	class Camera :public EmptyGameObject
	{
	public:
		/// 
		///Constructor
		///
		Camera(Vector3 worldPos, Vector4 worldRot, Vector3 worldScale);
		/// 
		///Destructor
		///
		~Camera();
	private: 
		///Member variables
#pragma region Member variables
		uint32 m_Index; 
		uint32 m_ComponentIndex; 
		uint32 m_RemoveComponentIndex; 
		IComponent* m_CurrentComponent;
		Vector4 m_WorldPos; 
		Vector4 m_WorldRot; 
		Vector4 m_WorldScale;
		std::vector<IComponent*> m_Components; 
		const char* m_Name;
#pragma endregion
		};
}