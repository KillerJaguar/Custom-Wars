#pragma once

namespace cw
{
	namespace util
	{
		template< typename T >
		class Reference
		{
		public:
			Reference() : m_ref( nullptr ) {}
			Reference( T& t ) : m_ref( &t ) {}
			Reference( T&& t ); // Undefined
			Reference( const Reference< T >& cpy ) : m_ref( cpy.m_ref ) {}
			Reference& operator=( const Reference< T >& cpy ) { m_ref = &cpy.get(); return *this; }			

			T& get() const { return *m_ref; }
			operator T&() const { return get(); }

			void clear() { m_ref = nullptr; }
			bool isValid() const { return m_ref != nullptr; }

			operator bool() const { return isValid(); }

		private:
			T* m_ref;
		};

		template< typename T >
		Reference< T > make_ref( T& t ) { return Reference< T >( t ); }

		template< typename T >
		Reference< const T > make_cref( const T& t ) { return Reference< const T >( T ); }
	}
}