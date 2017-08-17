#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include "EngineMakros.h"
#include "MakroDefines.h"
#include "IComponent.h"
#include <vector>

namespace SEngine
{
	class GameObject
	{
	public:
		GameObject();
		void Instantiate();
		void Update();
		void AddComponent(IComponent* component);
		void RemoveComponent(IComponent* component);
		void FindComponent(IComponent* component);
		void Destroy();
		~GameObject();
		const char* m_Name;
	private:
		std::vector<IComponent*> m_Components;
	};
}
#endif // _GAMEOBJECT_H_