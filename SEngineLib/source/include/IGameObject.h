#pragma once
///internal includes
#pragma region Internal includes
#include "IComponent.h"
#pragma endregion
///External includes
#pragma region External includes
#include <string>
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
		///Default Constructor
		///
		IGameObject(std::string name)
			: m_Name(name)
		{

		}
		///
		///pure virutal function for update 
		///
		virtual void Update() = 0; 
		/// 
		///pure virtual function to instantiate the GameObject
		/// 
		virtual void Instantiate()= 0; 
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
		///function to get the name of the gameObject
		///
		std::string GetName() { return m_Name; };
		///
		///virtual Destructor
		///
		~IGameObject() {};

	private: 
		std::string m_Name;
	};
}