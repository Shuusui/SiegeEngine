#pragma once
///
/// 
///
///Interface for the Audio Class
///
///
///

namespace SEngine
{
	class IAudio
	{
	public:
		/// 
		///Initialize the Audio  
		///
		virtual void Init() = 0;
		/// 
		///Run the Audio 
		///
		virtual void Run() = 0; 
		/// 
		///Shutdown the Audio
		///
		virtual void ShutDown() = 0; 
		///
		///virtual Destructor
		///
		/*virtual ~IAudio() = 0;*/
	};
}