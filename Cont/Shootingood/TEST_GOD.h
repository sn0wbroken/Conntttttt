#pragma once

#include"Actor.h"
#include"Bullet.h"
#include"Weapon.h"
#include"Character.h"
#include"Enemy_Manager.h"
#include"Player_Manager.h"
#include"Unique_Component.h"

#include<memory>

using std::shared_ptr;
using std::make_shared;
using std::unique_ptr;

// ƒeƒXƒg
class TEST_GOD : public Unique_Component<TEST_GOD> {
public:
	TEST_GOD();
	
	~TEST_GOD();

	shared_ptr<Actor> actor;
	shared_ptr<Weapon> weapon;
	shared_ptr<Bullet> bullet;
	shared_ptr<Character> character;
	
};

