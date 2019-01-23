#pragma once

#include"Actor.h"
#include"Bullet.h"
#include"Weapon.h"
#include"Character.h"
#include"Collision.h"
#include"Enemy_Manager.h"
#include"Enemy_Controller.h"
#include"Player_Manager.h"
#include"Unique_Component.h"
#include"Scene_Manager.h"

#include<memory>

using std::shared_ptr;
using std::make_shared;
using std::unique_ptr;

// �Q�[���ɕK�v�ȃI�u�W�F�N�g�𐶐�����匳
class Object_Creater : public Unique_Component<Object_Creater> {
public:
	Object_Creater();
	
	~Object_Creater();

	void Create_Enemy();
	shared_ptr<Weapon> weapon;
	shared_ptr<Bullet> bullet;
	shared_ptr<Character> character;
	shared_ptr<Collision> collision;
	shared_ptr<Enemy_Controller> enemy_controller;
	
	// �����Ɏ��g���w�肵�����̂����ɐ�������邷
	friend class Unique_Component<Object_Creater>;
};

