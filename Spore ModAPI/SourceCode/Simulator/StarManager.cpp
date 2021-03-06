#ifndef MODAPI_DLL_EXPORT
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
#include <Spore\Simulator\SubSystem\StarManager.h>

namespace Simulator
{

	auto_METHOD(cSpaceTradeRouteManager, bool, HasTradeRoute, Args(StarIndex star, uint32_t empireID), Args(star, empireID));

	auto_STATIC_METHOD_(cStarManager, cStarManager*, Get);

	auto_METHOD(cStarManager, cPlanetRecord*, GetPlanetRecord, Args(PlanetIndex recordIndex), Args(recordIndex));

	cEmpire* cStarManager::GetEmpire(uint32_t politicalID)
	{
		auto it = mEmpiresMap.find(politicalID);
		if (it != mEmpiresMap.end())
		{
			return it->second.get();
		}
		else
		{
			return nullptr;
		}
	}

	cStarRecord* cStarManager::GetStarRecord(StarIndex id)
	{
		if (id == 0)
		{
			return field_14C.get();
		}
		else if (id == -1)
		{
			return nullptr;
		}
		else
		{
			return mStarRecords[id >> 12][id & 0xFFF].get();
		}
	}

	EmpiresMap& cStarManager::GetEmpires()
	{
		return mEmpiresMap;
	}


	auto_METHOD(cStarManager, uint32_t, NextPoliticalID, Args(bool arg), Args(arg));
	auto_METHOD(cStarManager, cEmpire*, GetEmpireForStar, Args(cStarRecord* arg), Args(arg));

	auto_METHOD_VOID(cStarManager, RecordToPlanet, Args(cPlanetRecord* record, intrusive_ptr<cPlanet>& dst),
		Args(record, dst));
}

auto_STATIC_METHOD_VOID(Simulator, SpaceTeleportTo, Args(cStarRecord* star), Args(star));
#endif
