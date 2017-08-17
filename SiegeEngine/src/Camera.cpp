#include "include\Camera.h"


//default Constructor 
SEngine::Camera::Camera(Vector3 worldPos, Vector4 worldRot, Vector3 worldScale)
	:m_Index(0)
	,m_ComponentIndex(0)
	,m_RemoveComponentIndex(0)
	,m_CurrentComponent(nullptr)
	,m_WorldPos(worldPos,1.0f)
	,m_WorldRot(worldRot)
	,m_WorldScale(worldScale,1.0f)
{
	m_Name = "CameraObject" + m_Index;
}
//void SEngine::Camera::Update()
//{
//
//}
//void SEngine::Camera::Instantiate(uint32 index)
//{
//
//}
//void SEngine::Camera::AddComponent(IComponent* component)
//{
//
//}
//void SEngine::Camera::RemoveComponent(IComponent* component)
//{
//
//}
//
//SEngine::IComponent* SEngine::Camera::FindComponent(IComponent* component)
//{
//
//	return component;
//}
//
//uint32 SEngine::Camera::GetIndex()
//{
//
//}
//void SEngine::Camera::Destroy()
//{
//
//}

SEngine::Camera::~Camera()
{
	delete m_CurrentComponent;
	delete m_Name;  
}