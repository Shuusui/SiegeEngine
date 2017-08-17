#pragma once
///internal includes
#pragma region Internal includes
#include "ITransform.h"
#include "Matrix.h"
#include "Vector4.h"
#pragma endregion

///
///
///Transform Component class which inherits from ITransform interface.
///
///

namespace SEngine
{
	class TransformComponent : public ITransform
	{
	public:
		/// 
		///Constructor
		///
		TransformComponent(SEngine::Vector4 transform, SEngine::Vector4 rotation, Vector4 scaling);
		///
		///Update Routine for the Transformcomponent not based on Physics
		///
		void Update() override;
		/// 
		///Translation for the GameObject 
		///
		void TranslateComponent(Vector3 translation) override; 
		/// 
		///Rotate the GameObject on the x axis
		///
		void RotateX(float scal) override; 
		/// 
		/// Rotate the GameObject on the y axis
		///
		void RotateY(float scal) override; 
		/// 
		/// Rotate the gameObject on the z axis
		/// 
		void RotateZ(float scal) override;
		/// 
		///Scale the GameObject 
		///
		void Scale(Vector3 scaling) override; 
		///
		/// Set The Index of Component while it will be added to the GameObject
		///
		void SetIndex(uint32 index) override;
		/// 
		///Get the index of the Component
		///
		uint32 GetIndex() override; 
		/// 
		///Default Destructor
		///
		~TransformComponent();
	private: 
		///Member variables
#pragma region Member variables
		Matrix m_LocalTransformMatrix;
		Matrix m_WorldTransformMatrix;
		Vector3 m_Position;
		uint32 m_Index; 
#pragma endregion
	};
}
