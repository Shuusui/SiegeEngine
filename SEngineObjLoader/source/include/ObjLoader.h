#pragma once
#include "Vector4.h"
#include <fstream>
#include "Vector3.h"
#include "Vector2.h"
#include "ILoader.h"
#include <iostream>
#include <vector>

namespace SEngine
{
	class ObjLoader : public ILoader
	{
	public:
		///
		///Constructor
		///
		ObjLoader();
		///
		///Function to load the file
		///
		void LoadFile(const char* strFilename) override;
		///
		///Create the DLL for the ObjLoader
		///
		ILoader* CreateLoader(); // TODO: change the location of this function 
		/// 
		///Get the vertices read out of the obj file
		///
		std::vector<Vector4> GetVertices() override;
		///
		/// Get the faces read out of the obj file
		///
		std::vector<Vector3> GetFaces();
		/// 
		///Get the normals read out of the obj file
		///
		std::vector<Vector3> GetNormals()override;
		///
		///Get the Texture Coordinates read out of the file
		///
		std::vector<Vector2> GetTexCoords()override;
		///
		///Default Destructor 
		///
		~ObjLoader();
	private:
		///
		///Member variables
		///
		char m_ObjName[256]{ 0 };
		char m_MtlLib[256]{ 0 };
		char m_GroupName[256]{ 0 };
		char m_UsedMtl[256]{ 0 };
		uint8  m_SmoothGroups;
		std::vector<Vector4> m_Vec4Vertices;
		std::vector<Vector3> m_Faces;
		std::vector<Vector3> m_Normals;
		std::vector<Vector2> m_TexCoords;
	};
}