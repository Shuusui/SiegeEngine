//--------------------------------------------------------------------------------------
// File: BasicHLSL11_VS.hlsl
//
// The vertex shader file for the BasicHLSL11 sample.  
// 
// Copyright (c) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------
// Globals
//--------------------------------------------------------------------------------------
cbuffer cbPerObject : register( b0 )
{
    matrix        g_mWorldViewProjection    : packoffset( c0 );
    matrix        g_mWorld					: packoffset( c4 );
};

//--------------------------------------------------------------------------------------
// Input / Output structures
//--------------------------------------------------------------------------------------
struct VS_INPUT
{
    float4 vPosition    : POSITION;
	float4 vColor : COLOR; 
    float3 vNormal        : NORMAL;
    float2 vTexcoord    : TEXCOORD0;

};

struct VS_OUTPUT
{
	float4 vPosition    : SV_POSITION;
	float4 vColor: COLOR;
    	float3 vNormal        : NORMAL;
    	float2 vTexcoord    : TEXCOORD0;

};

//--------------------------------------------------------------------------------------
// Vertex Shader
//--------------------------------------------------------------------------------------
VS_OUTPUT VSMain(VS_INPUT Input)
{
	VS_OUTPUT Output;

	float4x4 worldMatrix = {	1.0f, 0.0f, 0.0f,	2.0f,
								0.0f, 1.0f, 0.0f,	1.f,
								0.0f, 0.0f, 1,		3.0f,
								0.0f, 0.0f, 0.0f,	1.0f };

	float4x4 rotationX = {		1.0f, 0,		 0,		 0,
								0, cos(45), -sin(45), 0,
								0, sin(45), cos(45), 0,
								0,	0,			0,	1 };
	float4x4 rotationY = {		cos(30), 0 , sin(30), 0 ,
								0, 1, 0, 0,
								-sin(30), 0, cos(30), 0,
								0, 0, 0, 1 };

	float4x4 rotationZ = {		cos(30), -sin(30), 0, 0,
								sin(30), cos(30), 0, 0,
								0,0,1, 0,
								0,0,0,1 };

	float4x4 identity = { 1, 0, 0 , 0,
							0, 1, 0, 0,
							0, 0, 1, 0,
							0, 0, 0, 1 };

	Output.vPosition = mul(Input.vPosition, mul(mul(worldMatrix, rotationZ), identity));
	//Output.vPosition = Input.vPosition;
	Output.vNormal = Input.vNormal;
    Output.vTexcoord = Input.vTexcoord;
	Output.vColor = Input.vColor;
    
    return Output;
}
