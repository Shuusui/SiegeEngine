#pragma once


namespace SEngine
{
	class PlayModes //TODO: Make the playmodes class work
	{
	public: 
		///
		///Constructor
		///
		PlayModes(); 
		///
		///Start all the Components depends on the Playmode which is active
		///
		bool StartComponents();
		/// 
		///Exit the Components and set all Components to the Start Point
		///
		void ExitComponents();
		///
		///Default Destructor of the Playmodes class
		///
		~PlayModes();
	};
}

