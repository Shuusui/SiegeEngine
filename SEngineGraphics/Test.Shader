
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
	float4 vColor :COLOR;
};

struct VS_OUTPUT
{
    float3 vNormal        : NORMAL;
    float2 vTexcoord    : TEXCOORD0;
    float4 vPosition    : SV_POSITION;
	float4 vColor :COLOR;
};

//--------------------------------------------------------------------------------------
// Vertex Shader
//--------------------------------------------------------------------------------------
VS_OUTPUT VSMain( VS_INPUT Input )
{
    VS_OUTPUT Output;
    
	Output.vPosition = /*mul( Input.vPosition, g_mWorldViewProjection );*/ Input.vPosition;
	Output.vNormal = /*mul( Input.vNormal, (float3x3)g_mWorld );*/ Input.vNormal;
    Output.vTexcoord = Input.vTexcoord;
	Output.vColor = Input.vColor;
    
    return Output;
}

//--------------------------------------------------------------------------------------
// File: BasicHLSL11_PS.hlsl
//
// The pixel shader file for the BasicHLSL11 sample.  
// 
// Copyright (c) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------
// Globals
//--------------------------------------------------------------------------------------
cbuffer cbPerObject : register( b0 )
{
    float4        g_vObjectColor            : packoffset( c0 );
};

cbuffer cbPerFrame : register( b1 )
{
    float3        g_vLightDir                : packoffset( c0 );
    float        g_fAmbient                : packoffset( c0.w );
};

//--------------------------------------------------------------------------------------
// Textures and Samplers
//--------------------------------------------------------------------------------------
Texture2D    g_txDiffuse : register( t0 );
SamplerState g_samLinear : register( s0 );

//--------------------------------------------------------------------------------------
// Input / Output structures
//--------------------------------------------------------------------------------------
struct PS_INPUT
{
    float3 vNormal        : NORMAL;
    float2 vTexcoord    : TEXCOORD0;
	float4 vColor :  COLOR;
};

//--------------------------------------------------------------------------------------
// Pixel Shader
//--------------------------------------------------------------------------------------
float4 PSMain( PS_INPUT Input ) : SV_TARGET0
{
    float4 vDiffuse = /*g_txDiffuse.Sample( g_samLinear, Input.vTexcoord ) + */Input.vColor;
    
    float fLighting = saturate( dot( g_vLightDir, Input.vNormal ) );
    fLighting = max( fLighting, g_fAmbient );
    
    return vDiffuse /** fLighting*/;
}