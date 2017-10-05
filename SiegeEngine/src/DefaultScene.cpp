#include "include\DefaultScene.h"


//Initialize the default Scene and set the index of the scene
void SEngine::DefaultScene::Init()
{
}
//Run the DefaultScene 
void SEngine::DefaultScene::Run()
{

}
//Change the Scenes
void SEngine::DefaultScene::ChangeScene(IScene* otherScene)
{
	ShutDown(); 
}
//Add a Gameobject to the scene
void SEngine::DefaultScene::AddGameObjectToScene(IGameObject* gameObject)
{	
	m_GameObjects.push_back(gameObject);
	gameObject->Instantiate();
	m_GameObjectIndex++;
}
//Remove a Gameobject from the scene
void SEngine::DefaultScene::RemoveGameObjectFromScene(IGameObject* gameObject)
{
	for (uint32 i = 0; i < m_GameObjects.size(); i++)
	{
		if (gameObject->GetIndex() == m_GameObjects[i]->GetIndex())
		{
			m_GameObjects.erase(m_GameObjects.begin() + i);
			m_RemovedGameObjectIndex = i;
		}
	}
}
//Find a Gameobject in the scene
SEngine::IGameObject* SEngine::DefaultScene::FindGameObjectInScene(IGameObject* gameObject)
{
	for (uint32 i = 0; i < m_GameObjects.size(); i++)
	{
		if (std::binary_search(m_GameObjects.begin(), m_GameObjects.end(), gameObject))
		{
			return gameObject;
		}
		else
		{
			printf("Game Object \s not found", gameObject->GetName().c_str());
		}
	}
	return nullptr;
}
//Shut down the default scene
void SEngine::DefaultScene::ShutDown()
{

}
//The default destructor of the DefaultScene
SEngine::DefaultScene::~DefaultScene()
{

}
