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
    float4 vPosition    : POSITION;
    float3 vNormal        : NORMAL;
    float2 vTexcoord    : TEXCOORD0;
	float4 vColor : COLOR; 
};

struct VS_OUTPUT
{
    float3 vNormal        : NORMAL;
    float2 vTexcoord    : TEXCOORD0;
    float4 vPosition    : SV_POSITION;
	float4 vColor: COLOR;
};

//--------------------------------------------------------------------------------------
// Vertex Shader
//--------------------------------------------------------------------------------------
VS_OUTPUT VSMain( VS_INPUT Input )
{
    VS_OUTPUT Output;
    
	Output.vPosition = Input.vPosition;
	Output.vNormal = Input.vNormal;
    Output.vTexcoord = Input.vTexcoord;
	Output.vColor = Input.vColor;
    
    return Output;
}
