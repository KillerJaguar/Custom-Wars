#pragma once

#include "tile.h"
#include "serializable.h"

#include <string>
#include <unordered_map>
#include <memory>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/NonCopyable.hpp>

namespace cw
{
	class Map : public serial::Serializable, sf::NonCopyable
	{
	public:
		Map();

		void create( int width, int height );
		void resize( int width, int height );

		bool isInBounds( int x, int y ) const;

	public:
		int getNumPlayers() const { return m_players; }

		int getWidth() const { return m_width; }
		int getHeight() const { return m_height; }

		TileBase& getTile( int x, int y );
		const TileBase& getTile( int x, int y ) const;

		void setTile( std::unique_ptr< TileBase > tile );

	public:
		void read( serial::InputDatastream& );
		void write( serial::OutputDatastream& ) const;

	private:
		std::unique_ptr< TileBase >* getTilePtr( int x, int y );

	private:
		int m_width, m_height, m_players;
		std::unique_ptr< std::unique_ptr< TileBase >[] > m_tiles;
	};
}