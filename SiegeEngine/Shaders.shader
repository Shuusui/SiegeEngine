struct VS_INPUT
{
	float3 position : POSITION;
	float4 color : COLOR;
};
struct VS_OUTPUT
{
	float3 position : SV_POSITION;
	float4 color : COLOR;
};
VS_OUTPUT VShader(VS_INPUT input)
{
	VS_Output output;

	output.position = input.position;
	output.color = input.	color;

	return output;
}


float4 PShader(float4 position : SV_POSITION, float4 color : COLOR) : SV_TARGET
{
	return color;
}