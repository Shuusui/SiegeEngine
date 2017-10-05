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
#include <list>
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
		///Get the whole Object from the ObjFile
		///
		OBJECT GetObjectData();
		///
		///Default Destructor 
		///
		~ObjLoader();
	private:
		///
		///Form groups, which will be used by GetObjectData
		///
		void FormGroup();
		///
		///Fill the ObjectStruct with all of the Data
		///
		void FormObject(); 
		///
		///Member variables
		///
#pragma region Member variables
		char* m_ObjName;
		char* m_GroupName;
		char* m_UsedMtl;
		uint8  m_SmoothGroups;
		std::list<std::string> m_MtlLibs;
		std::vector<GROUP> m_ObjGroups;
		std::vector<Vector4> m_Vec4Vertices;
		std::vector<std::vector<Vector3>> m_Faces;
		std::vector<Vector3> m_Normals;
		std::vector<Vector2> m_TexCoords;
		OBJECT m_ResultObject;
#pragma endregion
	};
}