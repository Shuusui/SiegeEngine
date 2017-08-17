#include "include\TransformComponent.h"
//default Constructor
SEngine::TransformComponent::TransformComponent(SEngine::Vector4 transform, SEngine::Vector4 rotation, SEngine::Vector4 scaling)
	:m_LocalTransformMatrix(transform, rotation, scaling, SEngine::Vector4(0,0,0,1))
	,m_WorldTransformMatrix()
	,m_Position()
{
}
//function to set the index of the component, when it will be added to a gameobject
void SEngine::TransformComponent::SetIndex(uint32 index)
{
	m_Index = index;
}
//function to get the set index from the component
uint32 SEngine::TransformComponent::GetIndex()
{
	return m_Index;
}
//translate function which use the mathlib to translate the LocalTransformMatrix
void SEngine::TransformComponent::TranslateComponent(SEngine::Vector3 translation)
{
	m_LocalTransformMatrix.translate(translation);
}
//Rotation function which rotates the LocalTransfrom Matrix around the x Axis
void SEngine::TransformComponent::RotateX(float scal)
{
	m_LocalTransformMatrix.rotationX(scal);
}
//Rotation function which rotates the LocalTransfrom Matrix around the y Axis
void SEngine::TransformComponent::RotateY(float scal)
{
	m_LocalTransformMatrix.rotationY(scal);
}
//Rotation function which rotates the LocalTransfrom Matrix around the z Axis
void SEngine::TransformComponent::RotateZ(float scal)
{
	m_LocalTransformMatrix.rotationZ(scal);
}
//Scaling function which scales the transform Matrix with the scaling factor "scaling"
void SEngine::TransformComponent::Scale(SEngine::Vector3 scaling)
{
	m_LocalTransformMatrix.scaling(scaling);
}
//default Update function
void SEngine::TransformComponent::Update()
{
	m_WorldTransformMatrix = m_LocalTransformMatrix * m_Position;
}
//defaullt Destructor
SEngine::TransformComponent::~TransformComponent()
{

}
