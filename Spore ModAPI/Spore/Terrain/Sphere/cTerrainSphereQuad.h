/****************************************************************************
* Copyright (C) 2019 Eric Mor
*
* This file is part of Spore ModAPI.
*
* Spore ModAPI is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
****************************************************************************/

#pragma once

#include <d3d9types.h>
#include "..\RenderWare\IndexBuffer.h"
#include "..\RenderWare\VertexBuffer.h"

namespace Terrain
{
	struct TerrainTransform
	{
		/* 00h */	D3DMATRIX worldViewProjection;
		/* 40h */	
	};

	struct TerrainQuadMesh
	{
		/* 00h */	RenderWare::VertexBuffer* vertexBuffer;
		/* 04h */	RenderWare::IndexBuffer* indexBuffer;
		// anything else?
	};

	class cTerrainSphereQuad
	{
		// sub_FB53C0

	private:

		/* 94h */	TerrainQuadMesh* mesh;
		/* 98h */	int indicesCount;

		/* A4h */	TerrainTransform terrainTransform;
	};

	static_assert(sizeof(cTerrainSphereQuad) == 0x1B8, "sizeof(cTerrainSphereQuad) != 1B8h");
}