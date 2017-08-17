#pragma once
///internal includes
#pragma region Internal includes
#include "IScene.h"
#include "IGameObject.h"
#include "MakroDefines.h"
#pragma endregion
///external includes
#pragma region External includes
#include <vector>
#pragma endregion

///
///
///Default Scene inherits from IScene interface. Maybe there will be some more kinds of scenes later
///
///

namespace SEngine
{
	class DefaultScene : public IScene
	{
	public:
		///
		///Default Constructor
		///
		DefaultScene(); 
		///
		///Initialize the default Scene
		///
		void Init(uint32 index) override;
		///
		///Run the default Scene
		///
		void Run() override;  
		///
		///change the scene
		///
		void ChangeScene(IScene* otherScene) override;
		///
		///Add a GameObject to the Scene
		///
		void AddGameObjectToScene(IGameObject* gameObject) override; 
		///
		///Remove a Gameobject from the Scene
		///
		void RemoveGameObjectFromScene(IGameObject* gameObject) override; 
		///
		///Find a GameObject in the scene
		///
		IGameObject* FindGameObjectInScene(IGameObject* gameObject) override; 
		///
		///Get the Scene Index, set in the Init function
		///
		uint32 GetSceneIndex() override; 
		///
		///Shut Down the scene
		///
		void ShutDown();
		///
		///Default Destructor
		///
		//~DefaultScene(); 
	private: 
		///Member variables
#pragma region Member variables
		uint32 m_Index; 
		uint32 m_GameObjectIndex; 
		uint32 m_RemovedGameObjectIndex;
		std::vector<IGameObject*> m_GameObjects;
#pragma endregion

	};
}