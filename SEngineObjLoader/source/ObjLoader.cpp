#include "include\ObjLoader.h"
//default constructor
SEngine::ObjLoader::ObjLoader()
	:m_SmoothGroups(0)
	, m_ResultObject(nullptr)
{
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
			for (uint8 i = 0; i < 256 - 1; i++)
			{
				if (buffer[i] != '\0')
				{
					m_MtlLib[i] = buffer[i + 7];
				}
				else
				{
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
			for (uint8 i = 2; i < sizeof(buffer) - 2; i++)
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
			for (uint8 i = 3; i < sizeof(buffer) - 3; i++)
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
			for (uint8 i = 3; i < sizeof(buffer) - 3; i++)
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
		///read the faces of the obj file
		else if (buffer[0] == 'f')
		{
			SEngine::Vector3 tempVec3(0,0,0);
			bool hasTexCoords = false; 
			char* tempBuffer = new char[15];
			uint8 count = 0;
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
						count = 0;
					}
					else if (tempVec3.GetX() != NULL && tempVec3.GetY() == NULL)
					{
						tempVec3.SetY(atoi(tempBuffer));
						count = 0;
					}					
					continue;
				}
				else if (buffer[i] == '/' && buffer[i + 1] == '/')
				{
					hasTexCoords = true;
					tempVec3.SetX(atoi(tempBuffer));
					count = 0;
					continue;
				}
				else if (buffer[i] == ' ')
				{
					tempVec3.SetZ(atoi(tempBuffer));		
					m_VertexDataFaces.push_back(tempVec3);		
					tempVec3.SetNull();
					count = 0;
					continue;
				}
				else if (buffer[i] == '\0')
				{
					m_Faces.push_back(m_VertexDataFaces);
					break;
				}
			}
			delete[] tempBuffer;
		}
		delete[] buffer;
	}
	// don't forget to close the file
	file.close();
	FillStruct();
}
void SEngine::ObjLoader::FillStruct()
{

}
SEngine::OBJECT SEngine::ObjLoader::GetObjectData()
{
	return OBJECT{};
}

//default destructor
SEngine::ObjLoader::~ObjLoader()
{
	delete[] m_GroupName; 
	delete[] m_ObjName; 
	delete[] m_MtlLib; 
	delete[] m_UsedMtl; 
}