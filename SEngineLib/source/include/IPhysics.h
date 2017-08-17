#pragma once


///
///
///interface for the physics class
///
///

namespace SEngine
{
	class IPhysics
	{
	public:
		///
		///pure virtual function to initialize phyiscs
		///
		virtual void Init() = 0; 
		///
		///pure virtual function to run  physics
		///
		virtual void Run() = 0; 
		///
		///pure virtual function to shut down physics
		///
		virtual void ShutDown() = 0; 
		///
		///virtual Destructor
		///
		//virtual ~IPhysics() = 0;
	};
}