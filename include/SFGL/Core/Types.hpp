#pragma once

#include <bitset>

namespace SFGL
{
	/// Max Entity count
	using MAX_ENTITIES = 5000;
	/// Entity type definition
	using Entity = std::uint32_t;

	/// Max Component count
	using MAX_COMPONENTS = 32;
	/// Component type definition
	using ComponetType = std::uint8_t;

	/// Signature type definition
	using Signature = std::bitset<MAX_COMPONENTS>;
}