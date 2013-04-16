//===============================================================
// File:	Primitive.h
// Purpose: To Handle Primitive Data
//===============================================================
#pragma once

namespace Graphics
{
	namespace Primitive
	{
		enum eTOPOLOGY
		{
			eTOPOLOGY_UNDEFINED,
			eTOPOLOGY_POINTLIST,
			eTOPOLOGY_LINELIST,
			eTOPOLOGY_LINESTRIP,
			eTOPOLOGY_TRIANGLELIST,
			eTOPOLOGY_TRIANGLESTRIP,
			eTOPOLOGY_LINELIST_ADJ,
			eTOPOLOGY_LINESTRIP_ADJ,
			eTOPOLOGY_TRIANGLELIST_ADJ,
			eTOPOLOGY_TRIANGLESTRIP_ADJ,
			eTOPOLOGY_QUANTITY,
		};
	}
}

