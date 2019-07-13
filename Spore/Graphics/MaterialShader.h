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

#include <Spore\Internal.h>
#include <Spore\IO\IStream.h>
#include <EASTL\intrusive_ptr.h>
#include <Spore\RenderWare\Mesh.h>

using namespace eastl;

namespace Graphics
{

	class MaterialShader
	{
	public:
		/// This type of function is called when rendering a mesh, before the \c DrawIndexedPrimitives is called.
		/// This function is responsible of loading the shaders into DirectX.
		typedef BOOL(*PrepareRender_t)(RenderWare::Mesh<>*);

		int AddRef();

		inline PrepareRender_t GetPrepareRenderFunction() const {
			return mpCallback;
		}

		inline void SetPrepareRenderFunction(PrepareRender_t function) {
			mpCallback = function;
		}

	protected:
		/* 00h */	int field_0;
		/* 04h */	int field_4;
		/* 08h */	int field_8;
		/* 0Ch */	int16_t mVertexShaderVersion;
		/* 0Eh */	int16_t mVertexShaderVersion_;
		/* 10h */	int16_t mPixelShaderVersion;
		/* 12h */	int16_t mPixelShaderVersion_;
		/* 14h */	PrepareRender_t mpCallback;
		/* 18h */	int field_18;
		/* 1Ch */	int field_1C;
		/* 20h */	int field_20;
		/* 24h */	int field_24;
		/* 28h */	int field_28;
		/* 2Ch */	int field_2C;
		/* 30h */	int field_30;
		/* 34h */	int field_34;
		/* 38h */	uint32_t shaderID;
		/* 3Ch */	int mnRefCount;
		/* 40h */	int field_40;  // intrusive_list_node?
		/* 44h */	int field_44;


	public:
		static MaterialShader* Initialize(MaterialShader* dst, uint32_t shaderID, int arg_8, int arg_C, int arg_10,
			int vertexShaderVersion, int vertexShaderVersion_, int pixelShaderVersion, int pixelShaderVersion_);

		static MaterialShader* GetMaterialShader(uint32_t shaderID);

	};

	static_assert(sizeof(MaterialShader) == 0x48, "sizeof(MaterialShader) != 0x48");
	
	namespace Addresses(MaterialShader) {
		DeclareAddress(Reset, SelectAddress(0x6E62F0,, 0x6E5C40));
		DeclareAddress(Initialize, SelectAddress(0x11F6B90, 0x11F4470, 0x11F4470));
		DeclareAddress(GetMaterialShader, SelectAddress(0x11FC770, 0x11FA030, 0x11FA030));
	}
}