#pragma once
///internal includes
#pragma region Internal includes
#include "IComponent.h"
#pragma endregion

///
///
///Interface for the GameObject class
///
///
namespace SEngine
{
	class IGameObject
	{
	public:
		///
		///pure virutal function for update 
		///
		virtual void Update() = 0; 
		/// 
		///pure virtual function to instantiate the GameObject
		/// 
		virtual void Instantiate(uint32 index)= 0; 
		/// 
		///pure virtual function to destroy the GameObject 
		///
		virtual void Destroy() = 0; 
		/// 
		///pure virtual funtion to add a component to the GameObject 
		///
		virtual void AddComponent(IComponent* component) = 0; 
		/// 
		///pure virtual function to remove a component from the GameObject 
		///
		virtual void RemoveComponent(IComponent* component) = 0; 
		/// 
		///pure virtual function to find a component from the GameObject 
		///
		virtual IComponent* FindComponent(IComponent* component) = 0;  
		/// 
		///pure virtual function to get the index of the GameObject
		///
		virtual uint32 GetIndex() = 0; 
		///
		///virtual Destructor
		///
		//virtual ~IGameObject() = 0; 
	};
}