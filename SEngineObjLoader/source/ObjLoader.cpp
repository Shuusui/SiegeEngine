#include "include\ObjLoader.h"
//default constructor
SEngine::ObjLoader::ObjLoader()
	:m_SmoothGroups(0)
{
	m_ObjName = new char[256];
	m_GroupName = new char[256];
	m_UsedMtl = new char[256];
}
//Create the dll
SEngine::ILoader* SEngine::ObjLoader::CreateLoader()
{
	static SEngine::ILoader* loader = nullptr;
	loader = new ObjLoader();
	return loader;
}
//function which reads the obj file 
void SEngine::ObjLoader::LoadFile(const char* strFilename)
{
	//open the file  
	std::fstream file;
	file.open(strFilename, std::fstream::in);
	if (!file.good())
	{
		std::cerr << "Error! Can't read the file: " << strFilename << std::endl;
		file.clear();
		return;
	} 

	//get the length of the file 
	file.seekg(0, file.end);
	uint32 length = file.tellg();
	file.seekg(0, file.beg);
	uint32 lineCount = 0; 
	uint32 lineCountCheck = 0;
	//read out the objfile
	while (!file.eof())
	{
		char* buffer = new char[256];
		file.getline(buffer, 256);
		///pass the line whenver there is a #
		if (buffer[0] == '#')
		{
			continue;
		}
		///read out the Materiabl lib of the objfile
		else if (buffer[0] == 'm')
		{
			char* mtlLib = new char[256];
			for (uint8 i = 0; i < 256 - 1; i++)
			{
				if (buffer[i] != '\0')
				{
					mtlLib[i] = buffer[i + 7];
				}
				else
				{
					m_MtlLibs.push_back(mtlLib);
					break;
				}
			}
		}
		///read out the objName of the file
		else if (buffer[0] == 'o')
		{
			for (uint8 i = 0; i < 256 - 1; i++)
			{
				if (buffer[i] != '\0')
				{
					m_ObjName[i] = buffer[i + 2];
				}
				else
				{
					break;
				}
			}
		}
		///read out the vertices of the obj file
		else if (buffer[0] == 'v' && buffer[1] == ' ')
		{
			char* tempBuffer = new char[50];
			uint8 count = 2;
			uint8 counter = 0;
			Vector4 tempVec4(0, 0, 0, 0);
			float x = 0, y = 0, z = 0, w = 1;
			for (uint8 i = 2; i < 256 - 2; i++)
			{
				if (buffer[i] != ' ' && buffer[i] != '\0')
				{
					tempBuffer[i - count] = buffer[i];
				}
				else if (buffer[i] == ' ' && buffer[i] != '\0')
				{
					if (count == 2)
					{
						x = atof(tempBuffer);
						tempVec4.SetX((float)x);
						count = i + 1;
						counter++;
						
					}
					else if (counter == 1)
					{
						y = atof(tempBuffer);
						tempVec4.SetY((float)y);
						count = i + 1;
						counter++;
						
					}
					else if (counter == 2)
					{
						z = atof(tempBuffer);
						tempVec4.SetZ((float)z);
						
						count = i + 1;
						counter++;
					}

				}
				else
				{
					if (counter == 2)
					{
						z = atof(tempBuffer);
						tempVec4.SetZ((float)z);
					
					}
					else
					{
						w = atof(tempBuffer);
						tempVec4.SetW((float)w);
						
					}
					m_Vec4Vertices.push_back(tempVec4);
					break;
				}
			}
			delete[] tempBuffer;
		}
		///read out the normals of the objfile
		else if (buffer[0] == 'v' && buffer[1] == 'n')
		{
			char* tempBuffer = new char[50];
			uint8 count = 3;
			uint8 counter = 0;
			Vector3 tempVec3(0, 0, 0);
			float x = 0, y = 0, z = 0;
			for (uint8 i = 3; i < 256 - 3; i++)
			{
				if (buffer[i] != ' ' && buffer[i] != '\0')
				{
					tempBuffer[i - count] = buffer[i];
				}
				else if (buffer[i] == ' ' && buffer[i] != '\0')
				{
					if (counter == 0)
					{
						x = atof(tempBuffer);
						y = (float)tempBuffer[0];
						tempVec3.SetX((float)x);
						count = i + 1;
						counter++;
						
					}
					else if (counter == 1)
					{
						y = atof(tempBuffer);
						tempVec3.SetY((float)y);
						count = i + 1;
						counter++;						

					}
				}
				else
				{
					z = atof(tempBuffer);
					tempVec3.SetZ((float)z);					
					m_Normals.push_back(tempVec3);
					break;
				}
			}
			delete[] tempBuffer;
		}
		///read out the texcoords of the objfile
		else if (buffer[0] == 'v' && buffer[1] == 't')
		{
			char* tempBuffer = new char[50];
			uint8 count = 3;
			uint8 counter = 0;
			Vector2 tempVec2(0, 0);
			float x = 0, y = 0, z = 0;
			for (uint8 i = 3; i < 256 - 3; i++)
			{
				if (buffer[i] != ' ' && buffer[i] != '\0')
				{
					tempBuffer[i - count] = buffer[i];
				}
				else if (buffer[i] == ' ' && buffer[i] != '\0')
				{
					x = atof(tempBuffer);
					tempVec2.SetX((float)x);
					count = i + 1;
					counter++;
					
				}
				else 
				{
					y = atof(tempBuffer);
					tempVec2.SetY((float)y);
					count = i + 1;
					counter++;					
					m_TexCoords.push_back(tempVec2);
				break;
				}
			}
			delete[] tempBuffer;
		}
		///read out the groupname
		else if (buffer[0] == 'g')
		{		
			if (lineCountCheck != NULL)
			{
				FormGroup(); 
				m_Faces.clear();
				lineCountCheck = lineCount;
			}
			else
			{
				lineCountCheck = lineCount;
			}
			for (uint8 i = 0; i < 256; i++)
			{
				if (buffer[i] != '\0')
				{
					m_GroupName[i] = buffer[i + 2];
				}
				else
				{
					break;
				}
			}
		}
		///read out the used material of the objfile
		else if (buffer[0] == 'u')
		{
			for (uint8 i = 0; i < 256; i++)
			{
				if (buffer[i] != '\0')
				{
					m_UsedMtl[i] = buffer[i + 7];
				}
				else
				{
					break;
				}
			}
		}
		///read out the smoothgroups
		else if (buffer[0] == 's' && buffer[2] != 'o')
		{
			char* tempBuffer = new char[2];
			for (uint8 i = 0; i < 2; i++)
			{
				if (buffer[i + 2] != '\0')
				{
					tempBuffer[0] = buffer[i + 2];
				}
				else 
				{
					m_SmoothGroups = atoi(tempBuffer);
					break;
				}

			}
			delete[] tempBuffer;
		}
		else if (buffer[0] == 's' && buffer[2] == 'o')
		{
			m_SmoothGroups = 0;
		}
		///read the faces of the obj file
		else if (buffer[0] == 'f')
		{
			SEngine::Vector3 tempVec3(0,0,0);
			bool hasTexCoords = false; 
			char* tempBuffer = new char[15];
			uint8 count = 0;
			std::vector<Vector3> tempVertexData;
			for (uint8 i = 2; i < 256; i++)
			{
				if (buffer[i] != '/' && buffer[i] != ' ' && buffer[i] != '\0')
				{
					tempBuffer[count] = buffer[i];
					count++;
					continue;
				}
				else if (buffer[i] == '/' && buffer[i+1] != '/')					
				{
					if (tempVec3.GetX() == NULL)
					{
						tempVec3.SetX(atoi(tempBuffer));	
						tempBuffer = new char[15];
						count = 0;
					}
					else if (tempVec3.GetX() != NULL && tempVec3.GetY() == NULL)
					{
						tempVec3.SetY(atoi(tempBuffer));
						tempBuffer = new char[15];
						count = 0;
					}					
					continue;
				}
				else if (buffer[i] == '/' && buffer[i + 1] == '/')
				{
					hasTexCoords = true;
					tempVec3.SetX(atoi(tempBuffer));
					tempBuffer = new char[15];
					count = 0;
					continue;
				}
				else if (buffer[i] == ' ')
				{
					tempVec3.SetZ(atoi(tempBuffer));		
					tempVertexData.push_back(tempVec3);
					tempVec3.SetNull();
					tempBuffer = new char[15];
					count = 0;
					continue;
				}
				else if (buffer[i] == '\0')
				{
					m_Faces.push_back(tempVertexData);
					break;
				}
			}
			delete[] tempBuffer;
		}
		lineCount++;
		delete[] buffer;
	}
	// don't forget to close the file
	FormGroup();
	FormObject();
	file.close();
	
}
void SEngine::ObjLoader::FormGroup()
{
	GROUP currGroup;
	currGroup.Smooth = m_SmoothGroups; 
	currGroup.GroupName = m_GroupName;
	currGroup.UsedMtl = m_UsedMtl; 
	for (int i = 0; i < m_Faces.size(); i++)
	{
		std::vector<VERTEX> Vertices; 
		for (int j = 0; j < m_Faces[i].size(); j++)
		{
			VERTEX currVertex;
			currVertex.Vertex = m_Vec4Vertices[m_Faces[i][j].GetX()-1];
			currVertex.TexCoord = m_TexCoords[m_Faces[i][j].GetY()-1];
			currVertex.Normal = m_Normals[m_Faces[i][j].GetZ()-1]; 
			Vertices.push_back(currVertex); 
		}
		currGroup.VertexDatas.push_back(Vertices);
	}
	m_ObjGroups.push_back(currGroup);
}

void SEngine::ObjLoader::FormObject()
{
	m_ResultObject.MtlLibs = m_MtlLibs;
	m_ResultObject.ObjectName = m_ObjName;
	m_ResultObject.ObjGroups = m_ObjGroups;
}
SEngine::OBJECT SEngine::ObjLoader::GetObjectData()
{
	return m_ResultObject;
}

//default destructor
SEngine::ObjLoader::~ObjLoader()
{
	delete[] m_GroupName; 
	delete[] m_ObjName; 
	delete[] m_UsedMtl; 
}