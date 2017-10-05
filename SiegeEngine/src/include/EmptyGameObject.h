#pragma once
//internal includes
#pragma region Internal includes
#include "EngineMakros.h"
#include "MakroDefines.h"
#include "IComponent.h"
#include "IGameObject.h"
#include "TransformComponent.h"
#include "Vector3.h"
#include "Vector4.h"
#pragma endregion
//external includes
#pragma region External includes
#include <vector>
#include <algorithm>
#pragma endregion

///
///
///Default Gameobject, inherits from IGameObject interface to get a gameobject in the engine
///
///

namespace SEngine 
{
	class EmptyGameObject : public IGameObject
	{
	public:
		///
		///Constructors
		///
		EmptyGameObject(uint32 index);
		EmptyGameObject(uint32 index, Vector3 worldPos, Vector4 worldRot, Vector3 worldScale);
		///
		///Instantiate the EmptyGameObject
		///
		void Instantiate() override;
		///
		///Update function 
		///
		//TODO: Set the Update function for the Gameobject in the EngineManager
		void Update() override;
		/// 
		///Function to get the Index, which is set in the Instantiate function 
		///
		__forceinline uint32 GetIndex() override;
		/// 
		/// add a component to the GameObject
		///
		void AddComponent(IComponent* component) override;
		///
		/// Remove a component from a Gameobject
		///
		void RemoveComponent(IComponent* component) override;
		/// 
		///Find a component from a GameObject
		///
		IComponent* FindComponent(IComponent* component) override;
		/// 
		///Destroy the GameObject
		///
		void Destroy() override;
		///
		///Default Destructor
		///
		~EmptyGameObject();
	private: 
		///
		///Member Variables
		///
#pragma region Member Variables
		std::vector<IComponent*> m_Components;
		uint32 m_Index; 
		uint32 m_ComponentIndex;
		uint32 m_RemovedComponentIndex;
		Vector4 m_WorldPos;
		Vector4 m_WorldRot;
		Vector4 m_WorldScale;
#pragma endregion
	};
}
