#include "include\EmptyGameObject.h"

//Default Constructor
SEngine::EmptyGameObject::EmptyGameObject()
	:m_Index(0)
	,m_ComponentIndex(0)
	,m_RemovedComponentIndex(0)
	,m_WorldPos(0,0,0,0)
	,m_WorldRot(0,0,0,0)
	,m_WorldScale(0,0,0,0)
	,m_Name(nullptr)
{
	
}
//Constructor which sets the worldPos, worldRot, worldScale
SEngine::EmptyGameObject::EmptyGameObject(Vector3 worldPos, Vector4 worldRot, Vector3 worldScale)
	:m_Index(0)
	,m_ComponentIndex(0)
	,m_RemovedComponentIndex(0)
	,m_WorldPos(worldPos.GetX(), worldPos.GetY(), worldPos.GetZ(),1.0f)
	,m_WorldRot(worldRot.GetX(), worldRot.GetY(),worldRot.GetZ(), worldRot.GetW())
	, m_WorldScale(worldScale.GetX(), worldScale.GetY(), worldScale.GetZ(), 1.0f)
{
}
//function to instantiate the empty gameobject
void SEngine::EmptyGameObject::Instantiate(uint32 index)
{
	m_Index = index;
	m_Name = "EmptyGameObject" + m_Index;
	IComponent* component = new TransformComponent(m_WorldPos, m_WorldRot, m_WorldScale);
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

	/*for (uint32 i = 0; i < m_Components.size(); i++)
	{
		if (m_Components[i]->GetIndex() == component->GetIndex())
		{
			return m_Components[i];
		}
	}*/
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