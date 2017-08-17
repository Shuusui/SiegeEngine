#pragma once
///internal includes
#pragma region Internal includes
#include "IWindow.h"
#include "IGameObject.h"
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
		///
		/// pure virtual function to initialize the scene
		///
		virtual void Init(uint32 index) = 0;
		/// 
		///pure virtual function to run the scene
		///
		virtual void Run() = 0;
		///
		///pure virtual function to change the scene
		///
		virtual void ChangeScene(IScene* otherScene) = 0;
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
		virtual uint32 GetSceneIndex() = 0;
		///
		///pure virtual function to shut down the scene
		///
		virtual void ShutDown() = 0;
		///
		///virtual Destructor
		///
		//virtual ~IScene() = 0; 
	};
}