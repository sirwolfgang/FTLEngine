//===============================================================
// File:	Shader.hlsl
// Purpose: Basic Test Color Shader
//===============================================================
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
	Output.Color	= Color;

	return Output;
}

//---------------------------------------------------------------
float4 PShader(float4 Position : SV_POSITION, float4 Color : COLOR) : SV_TARGET
{
	return Color;
}