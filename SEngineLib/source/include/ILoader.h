#pragma once
///internal includes
#include "Vector4.h"
#include "StructContainer.h"
///external includes
#include <vector>
#include <list>
#include <string>

///
///
///interface for the Loader class to add different 3d loader to the engine
///
///
namespace SEngine
{
	
	class ILoader
	{
	public: 
		///
		/// pure virtual function to load the file you will read from 
		///
		virtual void LoadFile(const char* strFileName) = 0; 
		///
		///pure virtual function to get the Object from the file 
		///
		virtual OBJECT GetObjectData() = 0; 


		/*///
		///pure virtual function to Get the vertices out of the file
		///
		virtual std::vector<SEngine::Vector4> GetVertices() = 0;
		///
		///pure virtual function to get the normals out of the file
		///
		virtual std::vector<Vector3> GetNormals() = 0;
		///
		///pure virtual function to get the texture coordinates out of the file
		///
		virtual std::vector<Vector2> GetTexCoords() = 0; 
		///
		///virtual Destructor
		///*/
		//virtual ~ILoader() = 0;
	};
}