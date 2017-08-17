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
    matrix        g_mWorld                : packoffset( c4 );
};

//--------------------------------------------------------------------------------------
// Input / Output structures
//--------------------------------------------------------------------------------------
struct VS_INPUT
{
    	float3 vPosition    : POSITION;
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
VS_OUTPUT VSMain( VS_INPUT Input )
{
    VS_OUTPUT Output;
    
	Output.vPosition = float4(Input.vPosition,1);
	Output.vNormal = Input.vNormal;
    	Output.vTexcoord = Input.vTexcoord;
	Output.vColor = Input.vColor;
    
    return Output;
}