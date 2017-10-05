#include "include\EmptyGameObject.h"

//Default Constructor
SEngine::EmptyGameObject::EmptyGameObject(uint32 index)
	:m_Index(index)
	,m_ComponentIndex(0)
	,m_RemovedComponentIndex(0)
	,m_WorldPos(0,0,0,0)
	,m_WorldRot(0,0,0,0)
	,m_WorldScale(0,0,0,0)
	,IGameObject("EmptyGameObject "+ index)
{

}
//Constructor which sets the worldPos, worldRot, worldScale
SEngine::EmptyGameObject::EmptyGameObject(uint32 index, Vector3 worldPos, Vector4 worldRot, Vector3 worldScale)
	:m_Index(index)
	,m_ComponentIndex(0)
	,m_RemovedComponentIndex(0)
	,m_WorldPos(worldPos,1.0f)
	,m_WorldRot(worldRot)
	,m_WorldScale(worldScale, 1.0f)
	, IGameObject("EmptyGameObject "+ index)
{
}
//function to instantiate the empty gameobject
void SEngine::EmptyGameObject::Instantiate()
{
	IComponent* component = new TransformComponent(m_WorldPos, m_WorldRot, m_WorldScale);
	m_Components.push_back(component);
}
//function to update the empty gameobecjt
void SEngine::EmptyGameObject::Update()
{

}
//little function to get the index of the gameobject
__forceinline uint32 SEngine::EmptyGameObject::GetIndex()
{
	return m_Index; 
}

void SEngine::EmptyGameObject::AddComponent(IComponent* component)
{
	m_Components.push_back(component);
	component->SetIndex(m_ComponentIndex);
	m_ComponentIndex++;
}

void SEngine::EmptyGameObject::RemoveComponent(IComponent* component)
{
	m_Components[component->GetIndex()] = m_Components.back();
	m_Components.pop_back();
}

SEngine::IComponent* SEngine::EmptyGameObject::FindComponent(IComponent* component)
{

	if (std::binary_search(m_Components.begin(), m_Components.end(), component))
	{
		return component;
	}
	else
	{
		printf("component not found");
		return nullptr;
	}
	return nullptr;
}
//destroy the gameobject from the scene
void SEngine::EmptyGameObject::Destroy()
{

}
//default destructor
SEngine::EmptyGameObject::~EmptyGameObject()
{

}