/****************************************************************************
* Copyright (C) 2018 Eric Mor
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

#include <Spore\RenderWare\IndexBuffer.h>
#include <Spore\RenderWare\VertexBuffer.h>
#include <Spore\RenderWare\VertexDescription.h>
#include <Spore\RenderWare\Mesh.h>
#include <Spore\RenderWare\Raster.h>
#include <Spore\Graphics\Renderer.h>

namespace RenderWare
{
	void IndexBuffer::ReleaseDirectX()
	{
		if (pDXBuffer != nullptr)
		{
			pDXBuffer->Release();
			pDXBuffer = nullptr;
		}
	}

	IndexBuffer::IndexBuffer()
		: pDXBuffer(nullptr)
		, startIndex(0)
		, primitiveType(D3DPT_TRIANGLELIST)
		, usage(D3DUSAGE_WRITEONLY)
		, format(D3DFORMAT::D3DFMT_INDEX16)
		, indicesCount(0)
		, pIndexData(nullptr)
	{
	}

	void IndexBuffer::CreateDirectX() {
		auto device = Graphics::Renderer::GetDevice();
		int size = (format == D3DFMT_INDEX16 ? 2 : 4) * indicesCount;
		device->CreateIndexBuffer(size, D3DUSAGE_DYNAMIC | D3DUSAGE_WRITEONLY, format, D3DPOOL_DEFAULT,
			&this->pDXBuffer, NULL);
	}

	void IndexBuffer::LockDirectXData() {
		int size = (format == D3DFMT_INDEX16 ? 2 : 4) * indicesCount;
		void* data;
		pDXBuffer->Lock(0, size, &data, D3DLOCK_NOOVERWRITE);
		memcpy_s(data, size, pIndexData, size);
		pDXBuffer->Unlock();
	}


	void VertexBuffer::ReleaseDirectX()
	{
		if (this->pDXBuffer != nullptr)
		{
			this->pDXBuffer->Release();
			this->pDXBuffer = nullptr;
		}
	}

	void VertexBuffer::CreateDirectX() {
		auto device = Graphics::Renderer::GetDevice();
		device->CreateVertexBuffer(vertexCount*stride, D3DUSAGE_DYNAMIC | D3DUSAGE_WRITEONLY, NULL, D3DPOOL_DEFAULT, 
			&this->pDXBuffer, NULL);
	}

	void VertexBuffer::LockDirectXData() {
		int size = vertexCount*stride;
		void* data;
		pDXBuffer->Lock(0, size, &data, D3DLOCK_NOOVERWRITE);
		memcpy_s(data, size, pVertexData, size);
		pDXBuffer->Unlock();
	}

	VertexBuffer::VertexBuffer()
		: pVertexDescription(nullptr)
		, pDXBuffer(nullptr)
		, baseVertexIndex(0)
		, vertexCount(0)
		, field_10(0)
		, stride(0)
		, pVertexData(nullptr)
	{
	}


	VertexElement::VertexElement()
		: stream(0)
		, offset(0)
		, type(0)
		, method(0)
		, usage(0)
		, usageIndex(0)
		, rwDecl()
	{
	}

	VertexElement::VertexElement(uint16_t stream_, uint16_t offset_, char type_, char method_,
		char usage_, char usageIndex_, int typeCode_)

		: stream(stream_)
		, offset(offset_)
		, type(type_)
		, method(method_)
		, usage(usage_)
		, usageIndex(usageIndex_)
		, rwDecl(typeCode_)
	{

	}


}
