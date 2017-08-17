#pragma once

#include "include\DefaultScene.h"

//Default Constructor
SEngine::DefaultScene::DefaultScene()
	:m_Index(0)
	,m_RemovedGameObjectIndex(0)
{

}
//Initialize the default Scene and set the index of the scene
void SEngine::DefaultScene::Init(uint32 index)
{
	m_Index = index; 
}
//Run the DefaultScene 
void SEngine::DefaultScene::Run()
{

}
//Change the Scenes
void SEngine::DefaultScene::ChangeScene(IScene* otherScene)
{
	ShutDown(); 
	otherScene->Init(otherScene->GetSceneIndex());
}
//Add a Gameobject to the scene
void SEngine::DefaultScene::AddGameObjectToScene(IGameObject* gameObject)
{	
	m_GameObjects.push_back(gameObject);
	gameObject->Instantiate(m_GameObjectIndex);
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
		if (m_GameObjects[i]->GetIndex() == gameObject->GetIndex())
		{
			return gameObject;
		}
	}
	return nullptr;
}
//Get the index of the scene
uint32 SEngine::DefaultScene::GetSceneIndex()
{
	return m_Index;
}
//Shut down the default scene
void SEngine::DefaultScene::ShutDown()
{

}
