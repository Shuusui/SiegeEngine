///include headerfile
#include "include\DirectX11.h"

//Default Constructor
SEngineGraphics::DirectX11::DirectX11()
	:m_SwapChain(nullptr)
	, m_Dev(nullptr)
	, m_DevCon(nullptr)
	, m_Hwnd(NULL)
	, m_PixelShader(nullptr)
	, m_VertexShader(nullptr)
	, m_VertexBuffer(nullptr)
	, m_InputLayout(nullptr)
{
}
//Constructor to initialize DX11 with Window handle
SEngineGraphics::DirectX11::DirectX11(HWND hWnd)
	:m_SwapChain(nullptr)
	, m_Dev(nullptr)
	, m_DevCon(nullptr)
	, m_Hwnd(hWnd)
	, m_PixelShader(nullptr)
	, m_VertexShader(nullptr)
	, m_VertexBuffer(nullptr)
	, m_InputLayout(nullptr)
{
}
//Saferelease Template to Release the Pointer in DX11 safely
template<typename T> void SafeRelease(T*& aPointer)
{
	if (aPointer != nullptr)
	{
		aPointer->Release();
		aPointer = nullptr;
	}
}
//function to check the HRESULT of some functions
bool Failed(HRESULT aResult)
{
	if (FAILED(aResult))
	{
		LPTSTR buffer;
		FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, nullptr, (DWORD)aResult, LANG_USER_DEFAULT, (LPTSTR)&buffer, 0, nullptr);

		MessageBox(0, buffer, TEXT("Fatal error"), MB_OK | MB_ICONERROR);
		LocalFree(buffer);
		return true;
	}
	return false;
}
//Set the window handle 
void SEngineGraphics::DirectX11::SetWindowHandle(HWND hwnd)
{
	m_Hwnd = hwnd;
}
//Initialize DirectX11
void SEngineGraphics::DirectX11::Init(uint16 wndWidth, uint16 wndHeight)
{

	//create a struct to hold information about the swap chain //{} clears out the struct
	DXGI_SWAP_CHAIN_DESC dxscDesc{};

	//fill out the swap chain description struct 
	dxscDesc.BufferCount = 1;
	dxscDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	dxscDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	dxscDesc.OutputWindow = DirectX11::m_Hwnd;
	dxscDesc.SampleDesc.Count = 4;
	dxscDesc.Windowed = true;
	dxscDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

	//HRESULT created to check the result of some functions
	HRESULT hr;
	//Create a device, device context and swapchain using the information int struct dxscDesc
	hr = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, NULL, D3D11_CREATE_DEVICE_DEBUG /*Show Errors in DebugLog*//*NULL*/, nullptr, NULL, D3D11_SDK_VERSION, &dxscDesc, &m_SwapChain, &m_Dev, nullptr, &m_DevCon);
	if (Failed(hr))
	{
		OutputDebugStringW(L"Failed to Create Device and Swap Chain");
		return;
	}
	//Get the address of the backbuffer
	ID3D11Texture2D *pBackBuffer = nullptr;
	hr = m_SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
	if (Failed(hr))
	{
		OutputDebugStringW(L"Failed to get the Buffer in SwapChain");
		return;
	}
	//use the backbuffer address to create the render target
	hr = m_Dev->CreateRenderTargetView(pBackBuffer, nullptr, &m_BackBuffer);
	if (Failed(hr))
	{
		OutputDebugStringW(L"Failed to create Render Target View");
		return;
	}
	//SafeRelease(pBackBuffer);
	pBackBuffer->Release();


	//Set the render target as the back buffer
	m_DevCon->OMSetRenderTargets(1, &m_BackBuffer, nullptr);

	//Set the viewport 
	D3D11_VIEWPORT viewPort{};

	viewPort.TopLeftX = 0;
	viewPort.TopLeftY = 0;
	viewPort.Width = wndWidth;
	viewPort.Height = wndHeight;

	m_DevCon->RSSetViewports(1, &viewPort);
	//use the 2 functions below 
	InitPipeline();
	InitGraphics();
}
//Initialize the pipeline
void SEngineGraphics::DirectX11::InitPipeline()
{
	//Create HRESULT to test the HRESULT with the Failed function
	HRESULT hr;
	//Load and compile the new Shaders
	ID3D10Blob *VertexShader = nullptr, *PixelShader = nullptr, *errorBlob = nullptr;
	hr = D3DCompileFromFile(L"TestV.Shader", nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE, "VSMain", "vs_4_0", 0, 0, &VertexShader, &errorBlob);
	if (Failed(hr))
	{
		OutputDebugStringA((char*)errorBlob->GetBufferPointer());
		OutputDebugStringW(L"Failed to Compile VS From File");
		SafeRelease(errorBlob);
		return;
	}
	hr = D3DCompileFromFile(L"TestP.Shader", nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE, "PSMain", "ps_4_0", 0, 0, &PixelShader, &errorBlob);
	if (Failed(hr))
	{
		OutputDebugStringA((char*)errorBlob->GetBufferPointer());
		OutputDebugStringW(L"Failed to Compile PS From File");
		SafeRelease(errorBlob);
		return;
	}
	hr = m_Dev->CreateVertexShader(VertexShader->GetBufferPointer(), VertexShader->GetBufferSize(), nullptr, &m_VertexShader);
	if (Failed(hr))
	{
		OutputDebugStringW(L"Failed to Create the Vertex Shader");
		return;
	}
	hr = m_Dev->CreatePixelShader(PixelShader->GetBufferPointer(), PixelShader->GetBufferSize(), nullptr, &m_PixelShader);
	if (Failed(hr))
	{
		OutputDebugStringW(L"Failed to Create the Pixel Shader");
		return;
	}
	m_DevCon->VSSetShader(m_VertexShader, nullptr, 0);
	m_DevCon->PSSetShader(m_PixelShader, nullptr, 0);

	//create an array of strucs for the input layout 
	D3D11_INPUT_ELEMENT_DESC inputElementDesc[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0},
		{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0},
		{ "NORMAL", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0},
		{ "TEXCOORD", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA,0},
	};
	//create the Input Layout
	hr = m_Dev->CreateInputLayout(inputElementDesc, ARRAYSIZE(inputElementDesc), VertexShader->GetBufferPointer(), VertexShader->GetBufferSize(), &m_InputLayout);
	if (Failed(hr))
	{
		OutputDebugStringW(L"Failed to create Input Layout");
		return;
	}
	m_DevCon->IASetInputLayout(m_InputLayout);
	SafeRelease(VertexShader);
	SafeRelease(PixelShader);
	SafeRelease(errorBlob);
}

//Initialize Graphics
void SEngineGraphics::DirectX11::InitGraphics()
{
	HMODULE objLoaderModule = LoadLibrary(L"module\\SEngineObjLoader.dll");
	CREATE_LOADER CreateLoader = nullptr;
	CreateLoader = (CREATE_LOADER)GetProcAddress(objLoaderModule, "CreateLoader");
	if (CreateLoader == nullptr)
	{
		OutputDebugStringW(L"Failed to load the ObjLoader.dll");
		return;
	}
	m_Loader = CreateLoader();
	m_Loader->LoadFile("..\\Models\\cube.obj");

	SEngine::OBJECT obj = m_Loader->GetObjectData();
	uint32 objSize = 0;
	for (int i = 0; i < obj.ObjGroups.size(); i++)
	{
		objSize += obj.ObjGroups[i].VertexDatas.size();
	}

	DX11VERTEX* NotATri = new DX11VERTEX[objSize];

	for (int i = 0; i < obj.ObjGroups.size(); i++)
	{
		for (int j = 0; j < obj.ObjGroups[i].VertexDatas.size(); j++)
		{
			for (int k = 0; k < obj.ObjGroups[i].VertexDatas[j].size(); k++)
			{
				NotATri[i + j].x = obj.ObjGroups[i].VertexDatas[j][k].Vertex.GetX();
				NotATri[i + j].y = obj.ObjGroups[i].VertexDatas[j][k].Vertex.GetY();
				NotATri[i + j].z = obj.ObjGroups[i].VertexDatas[j][k].Vertex.GetZ();
				//NotATri[i + j].w = obj.ObjGroups[i].VertexDatas[j][k].Vertex.GetW();
				NotATri[i + j].w = 1;
				NotATri[i + j].Color = D3DXCOLOR{ 1,0,0,1 };
			}
		}
	}

	//Create HRESULT to check some functions
	HRESULT hr;

	//int x = sizeof(DX11VERTEX);
	//int y = D3D11_REQ_CONSTANT_BUFFER_ELEMENT_COUNT;
	//x*= objSize; 

	//Create the Vertex Buffer
	D3D11_BUFFER_DESC DX11BufferDesc{};
	DX11BufferDesc.ByteWidth = sizeof(DX11VERTEX) * objSize;  //the size is the VERTEX * 3 as seen in Triangle[]
	DX11BufferDesc.Usage = D3D11_USAGE_DYNAMIC; //write access by CPU and GPU
	DX11BufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE; //Allow the CPU to write in the buffer
	DX11BufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER; // use the buffer as a Vertex Buffer

	//Create Subresource data
	D3D11_SUBRESOURCE_DATA subData{};
	subData.pSysMem = &m_VertexBuffer;

	hr = m_Dev->CreateBuffer(&DX11BufferDesc, /*&subData*/nullptr, &m_VertexBuffer); //Create Buffer
	if (Failed(hr))
	{
		OutputDebugStringW(L"Failed to Create VertexBuffer");
		return;
	}
	//Copy the vertices into the buffer
	D3D11_MAPPED_SUBRESOURCE mapSubRes{};
	hr = m_DevCon->Map(m_VertexBuffer, NULL, D3D11_MAP_WRITE_DISCARD, NULL, &mapSubRes);
	if (Failed(hr))
	{
		OutputDebugStringW(L"Failed to Map the vertex buffer");
		return;
	}

	memcpy(mapSubRes.pData, NotATri, objSize * 16);
	/*memcpy(mapSubRes.pData, Vertices, sizeof(Vertices));*/
	m_DevCon->Unmap(m_VertexBuffer, NULL);
	delete[] NotATri;
}

//run dx11
void SEngineGraphics::DirectX11::Run()
{
	//Create HRESULT to check some functions
	HRESULT hr;
	//clear the backbuffer
	m_DevCon->ClearRenderTargetView(m_BackBuffer, D3DXCOLOR(0.0f, 0.2f, 0.4f, 1.0f));
	//Select which vertex buffer to display
	UINT stride = sizeof(DX11VERTEX);
	UINT offset = 0;
	m_DevCon->IASetVertexBuffers(0, 1, &m_VertexBuffer, &stride, &offset);
	//Select which primitive type we are using 
	m_DevCon->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	//Draw the vertex buffer to the back buffer
	m_DevCon->Draw(3, 0);
	//switch the backbuffer and the front buffer
	hr = m_SwapChain->Present(0, 0);
	if (Failed(hr))
	{
		OutputDebugStringW(L"Failed to Present DirextX11");
		return;
	}
}
//Shutdown DX11
void SEngineGraphics::DirectX11::ShutDown()
{
	//Switch to Window Mode before ShutDown DX
	m_SwapChain->SetFullscreenState(FALSE, nullptr);

	//Close and Release all existing COM Objects
	SafeRelease(m_BackBuffer);
	SafeRelease(m_SwapChain);
	SafeRelease(m_Dev);
	SafeRelease(m_DevCon);
	SafeRelease(m_VertexShader);
	SafeRelease(m_PixelShader);
	SafeRelease(m_VertexBuffer);
	SafeRelease(m_InputLayout);
}
//Destructor for the DX11 class
SEngineGraphics::DirectX11::~DirectX11()
{
	//Release everything in destructor too, if there was an error before or forgot shutdown. //SafeRelease checks if it's already deleted
	SafeRelease(m_BackBuffer);
	SafeRelease(m_SwapChain);
	SafeRelease(m_Dev);
	SafeRelease(m_DevCon);
	SafeRelease(m_VertexShader);
	SafeRelease(m_PixelShader);
	SafeRelease(m_VertexBuffer);
	SafeRelease(m_InputLayout);
}
