//#include "include\Camera.h"
//
//
////default Constructor 
//SEngine::Camera::Camera(uint32 index)
//	: m_Index(index)
//	, m_ComponentIndex(0)
//	, m_RemoveComponentIndex(0)
//	, m_CurrentComponent(nullptr)
//	, m_WorldPos(0, 0, 0, 0)
//	, m_WorldRot(0, 0, 0, 0)
//	, m_WorldScale(0, 0, 0, 0)
//	, IGameObject("Camera " + index)
//{
//}
//SEngine::Camera::Camera(uint32 index, Vector3 worldPos, Vector4 worldRot, Vector3 worldScale)
//	:m_Index(index)
//	,m_ComponentIndex(0)
//	,m_RemoveComponentIndex(0)
//	,m_CurrentComponent(nullptr)
//	,m_WorldPos(worldPos,1.0f)
//	,m_WorldRot(worldRot)
//	,m_WorldScale(worldScale,1.0f)
//	,IGameObject("Camera " + index)
//{
//}
//
//SEngine::Camera::~Camera()
//{
//	delete m_CurrentComponent;
//}