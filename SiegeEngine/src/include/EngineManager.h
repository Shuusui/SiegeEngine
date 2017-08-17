#pragma once
///internal includes
#pragma region Internal includes
#include "IScene.h"
#include "IWindow.h"
#pragma endregion

///
///
///The Engine Manager, which will manage the whole Engine and will connect all pieces together
///
///

namespace SEngine
{
	class EngineManager
	{
	private: 
		///
		///Constructor
		///
		EngineManager();
		///
		///Instantiate the Scene
		///
		void InstantiateScene(); 
		///
		///ChangeTheScene
		///
		void ChangeScene(); 
		///
		///Instantiate a Window
		///
		void InstantiateWindow();
		///
		/// Change the window
		///
		void ChangeWindow();
		///
		///Instantiate the Graphics API
		///
		void InstantiateGraphicAPI(); 
		///
		///Change the Graphic API
		///
		void ChangeGraphicAPI(); 
		/// 
		///Instantiate the Physics API
		///
		void InstantiatePhysics(); 
		/// 
		///Instantiate the Audio
		///
		void InstantiateAudio(); 
		/// 
		///Instantiate the Input Settings
		///
		void InstantiateInputSettings();
		/// 
		///Change the Input Settings
		///
		void ChangeInputSettings();
		/// 
		///Shut down the Engine
		///
		void ShutDownEngine(); 
		///
		///Default Destructor of the engine
		///
		~EngineManager();
	private: 
		///Member Variables
#pragma region Member variables
		IScene* m_CurrentScene; 
		IWindow* m_CurrentWindow;
#pragma endregion
	};
}