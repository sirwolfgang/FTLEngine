//===============================================================
// File:	Shader.hlsl
// Purpose: Basic Test Color Shader
//===============================================================
cbuffer ConstantBuffer
{
    float3 g_Color;
}

struct VOut
{
	float4 Position : SV_POSITION;
	float4 Color	: COLOR;
};

//---------------------------------------------------------------
VOut VShader(float4 Position : POSITION, float4 Color : COLOR)
{
	VOut Output;

	Output.Position = Position;
	Output.Color	= float4(g_Color, 1.0f);

	return Output;
}

//---------------------------------------------------------------
float4 PShader(VOut In) : SV_TARGET
{
	return In.Color;
}