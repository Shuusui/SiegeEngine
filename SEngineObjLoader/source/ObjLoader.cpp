#include "include\ObjLoader.h"

SEngine::ObjLoader::ObjLoader()
	:m_SmoothGroups(0)
{
}

SEngine::ILoader* SEngine::ObjLoader::CreateLoader()
{
	static SEngine::ILoader* loader = nullptr;
	loader = new ObjLoader();
	return loader;
}

void SEngine::ObjLoader::LoadFile(const char* strFilename)
{
	//open the file  
	std::fstream file;
	file.open(strFilename, std::fstream::in);
	if (!file.good())
	{
		std::cerr << "Fehler beim lesen der datei: " << strFilename << std::endl;
		file.clear();
		return;
	}
	//get the length of the file 
	file.seekg(0, file.end);
	uint32 length = file.tellg();
	file.seekg(0, file.beg);
	while (!file.eof())
	{
		char buffer[256];
		file.getline(buffer, 256);
		if (buffer[0] == '#')
		{
			continue;
		}
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
		else if (buffer[0] == 'v' && buffer[1] == ' ')
		{
			char tempBuffer[50];
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
		}
		else if (buffer[0] == 'v' && buffer[1] == 'n')
		{
			char tempBuffer[50];
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
		}
		else if (buffer[0] == 'v' && buffer[1] == 't')
		{
			char tempBuffer[50];
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
		}
		
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
		else if (buffer[0] == 's' && buffer[2] != 'o')
		{
			char tempBuffer[2];
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
		}
	}
	file.close();
}


std::vector<SEngine::Vector4> SEngine::ObjLoader::GetVertices()
{
	return m_Vec4Vertices;
}
std::vector<SEngine::Vector3> SEngine::ObjLoader::GetNormals()
{
	return m_Normals;
}
std::vector<SEngine::Vector2> SEngine::ObjLoader::GetTexCoords()
{
	return m_TexCoords;
}

SEngine::ObjLoader::~ObjLoader()
{

}