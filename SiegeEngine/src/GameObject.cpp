#include "include\GameObject.h"


SEngine::GameObject::GameObject()
{
}

void SEngine::GameObject::Instantiate()
{

}

void SEngine::GameObject::Update()
{

}

void SEngine::GameObject::AddComponent(IComponent* component)
{
	m_Components.push_back(component);
}

void SEngine::GameObject::RemoveComponent(IComponent* component)
{
	for (uint8 i = 0; i < m_Components.size(); i++)
	{
		if (m_Components[i] == component)
		{
			m_Components[i] = NULL;
		}
	}
}

void SEngine::GameObject::FindComponent(IComponent* component)
{

}

void SEngine::GameObject::Destroy()
{

}

SEngine::GameObject::~GameObject()
{

}