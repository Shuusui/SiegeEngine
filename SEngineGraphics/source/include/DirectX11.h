#pragma once
///internal includes
#pragma region Internal includes
#include "MakroDefines.h"
#include "IGraphics.h"
#include "ILoader.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Vector2.h"
#include "StructContainer.h"
#pragma endregion
///external includes
#pragma region External includes
#include <d3d11.h>
#include <D3DX11.h>
#include <D3DX10.h>
#include <D3Dcompiler.h>
#include <vector>
#include <fstream>
#pragma endregion


///
///
///Header file for the directX11 class. It'S the default GraphicsAPI for this engine
///
///
namespace SEngineGraphics
{

	///creates a struct for a single Vertex in DX11
	struct DX11VERTEX
	{
		float x = 0, y = 0, z = 0, w = 0;
		D3DXCOLOR Color{ 0,0,0,0 };
	};
	class DirectX11 /*: public SEngine::IGraphics*/
	{
	public: 
		///
		///Constructors
		///
		DirectX11();
		DirectX11(HWND hWnd);
		///
		///override the Init function to initialize DX11
		///
		void Init(uint16 wndWidth, uint16 wndHeight) ;
		///
		///override the Run function to run DX11
		///
		void Run(); 
		///
		///override the ShutDown function to shut down DX11
		///
		void ShutDown();
		///
		///override the SetWindowHandle function to set the window for DX11
		///
		void SetWindowHandle(HWND hwnd); 
		///
		///Destructor
		///
		~DirectX11();
	private: 
		///
		///private function to initialize the pipeline of DX11
		///
		void InitPipeline();
		///
		///private function to initialize the grahphics of DX11
		///
		void InitGraphics();
		///Member variables of the DX11 class
#pragma region Member variables
		IDXGISwapChain* m_SwapChain;
		ID3D11Device* m_Dev;
		ID3D11DeviceContext* m_DevCon;
		HWND m_Hwnd;
		ID3D11RenderTargetView* m_BackBuffer;
		ID3D11VertexShader* m_VertexShader; 
		ID3D11PixelShader* m_PixelShader; 
		ID3D11Buffer* m_VertexBuffer; 
		ID3D11InputLayout* m_InputLayout;
		SEngine::ILoader* m_Loader;
#pragma endregion
	};
}
typedef SEngine::ILoader* (*CREATE_LOADER)();
