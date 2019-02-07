#pragma once

#include"Enemy_Controller.h"
#include"Enemy.h"
#include"Enemy_AI.h"
#include"Enemy_Status.h"
#include"Define_Value.h"
#include"Unique_Component.h"

#include<memory>
#include<vector>

class Effect_Info
{
public:
	Effect_Info(Vector3D t_pos, int sec)
	{
		pos = t_pos;
		effect_sec = sec;
	}

	bool operator==(const Effect_Info& Ei)
	{
		if (pos == Ei.pos)
		{
			if (Ei.effect_sec == effect_sec)
			{
				return true;
			}
		}
		return false;
	}

	Vector3D pos;
	int		 effect_sec;
};

// �G�l�~�[�̃}�l�[�W���[�N���X(�G�l�~�[�̏��(�e�N���X)��m���Ă���)
class Enemy_Manager : public Unique_Component<Enemy_Manager> {
public:
	//�G�l�~�[�̃R���g���[���[ �������瓮���𐧌䂷��
	std::shared_ptr<Enemy_Controller> enemy_controller;
	std::list<std::shared_ptr<Enemy>> active_enemies;
	std::list<std::shared_ptr<Enemy>> inactive_enemies;

	// ���t���[���Ă΂��
	void Update();

	// �G�l�~�[���S�ł������ǂ���
	bool Is_Enemy_All_Dead();

	// �f�X�g���N�^
	~Enemy_Manager() {}

	// ���W
	Vector3D position;

	void PlayEffect();

private:
	// �R���X�g���N�^
	Enemy_Manager();

	int e_explosionhandle[7];

	// �萔���܂Ƃ߂Ă����N���X
	Define_Value define_value;

	// �����Ɏ��g���w�肵�����̂����ɐ�������邷
	friend class Unique_Component<Enemy_Manager>;

	std::list<Effect_Info> active_effectList;
};
