#pragma once

#include <tuple>
#include <SFML/Network/IpAddress.hpp>
#include <SFML/Network/TcpSocket.hpp>

namespace cw
{
	namespace serial
	{
		class Packetstream;
	}

	namespace net
	{
		class Client
		{
		public:
			Client();
			virtual ~Client() {}
			void updateClient();

			void connect( sf::IpAddress&, unsigned short port = 8888 );
			void sendToHost( serial::Packetstream& );
			void disconnectClient();

			bool isConnected() const;
			bool isConnecting() const;

		private:
			virtual void onClientConnect( serial::Packetstream& ) = 0;
			virtual void onClientRecieve( serial::Packetstream& ) = 0;
			virtual void onClientDisconnect() = 0;

		private:
			sf::TcpSocket m_socket;
			int m_state;
		};
	}
}