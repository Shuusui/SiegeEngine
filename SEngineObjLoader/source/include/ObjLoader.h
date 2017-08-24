#pragma once
///Internal includes
#pragma region Internal includes
#include "Vector4.h"
#include "Vector3.h"
#include "Vector2.h"
#include "ILoader.h"
#pragma endregion
///External includes
#pragma region External includes
#include <iostream>
#include <vector>
#include <fstream>
#include <Shlwapi.h>
#pragma endregion

///
///
///Simple class to read out obj. files and return the values from the file
///
///


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
		std::vector<std::vector<Vector3>> GetFaces();
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
#pragma region Member variables
		char m_ObjName[256]{ 0 };
		char m_MtlLib[256]{ 0 };
		char m_GroupName[256]{ 0 };
		char m_UsedMtl[256]{ 0 };
		uint8  m_SmoothGroups;
		std::vector<Vector4> m_Vec4Vertices;
		std::vector<std::vector<Vector3>> m_Faces;
		std::vector<Vector3> m_VertexDataFaces;
		std::vector<Vector3> m_Normals;
		std::vector<Vector2> m_TexCoords;
#pragma endregion
	};
}