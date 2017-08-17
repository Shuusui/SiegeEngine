#pragma once

///
///
///Interface for the Input class
///
///

namespace SEngine
{
	class IInput
	{
	public: 
		///
		///pure virtual function to initialize the input
		///
		virtual void Init() = 0; 
		///
		///pure virtual function to run the input
		///
		virtual void Run() = 0; 
		///
		///pure virtual function to shut down the input
		///
		virtual void ShutDown() = 0; 
		///
		///virtual destructor
		///
		//virtual ~IInput() = 0;
	};
}