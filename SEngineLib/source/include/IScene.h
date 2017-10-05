#pragma once
///internal includes
#pragma region Internal includes
#include "IWindow.h"
#include "IGameObject.h"
#pragma endregion
#pragma region External includes
#include <algorithm>
#include <string>
#pragma endregion
///
///
///interface for the scnene class
///
///

namespace SEngine
{
	class IScene
	{
	public:
		IScene(std::string name, uint32 index)
			: m_Name(name)
			, m_Index(index)
		{

		}
		///
		/// pure virtual function to initialize the scene
		///
		virtual void Init() = 0;
		/// 
		///pure virtual function to run the scene
		///
		virtual void Run() = 0;
		///
		///pure virtual function to change the scene
		///
		virtual void ChangeScene(IScene* otherScene) = 0;
		///
		///pure virtual function to create an object which can get add to the scene
		///
		virtual void CreateGameObject() = 0; 
		///
		///pure virtual function to add a gameobject to the scene
		///
		virtual void AddGameObjectToScene(IGameObject* gameObject) = 0;
		///
		///pure virtual function to remove a gameobject from the scene
		///
		virtual void RemoveGameObjectFromScene(IGameObject* gameObject) = 0;
		///
		///pure virtual fucntion to find a gameobject in the scene
		///
		virtual IGameObject* FindGameObjectInScene(IGameObject* gameObject) = 0;
		///
		///pure virtual function to get the index from the scene
		///
		uint32 GetSceneIndex() { return m_Index; };
		///
		///pure virtual function to shut down the scene
		///
		virtual void ShutDown() = 0;
		///
		///Getter function which returns the name of the Scene
		///
		std::string GetName() { return m_Name; }
		///
		///virtual Destructor
		///
		//virtual ~IScene() = 0; 
	private: 
		std::string m_Name; 
		uint32 m_Index;

	};
}