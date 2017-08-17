#ifndef _SCRIPTBEHAVIOR_H_
#define _SCRIPTBEHAVIOR_H_

#include "IComponent.h"
#include "IScript.h"

namespace SEngine
{
	class ScriptBehavior : public IScript
	{
		ScriptBehavior();
		void Update() override; 
		void Start() override; 
		void FixedUpdate() override; 
		void Awake() override; 
		~ScriptBehavior();
	};
}
#endif // _SCRIPTBEHAVIOR_H_