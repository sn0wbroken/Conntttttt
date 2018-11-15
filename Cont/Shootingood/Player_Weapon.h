#pragma once

#include"Enum.h"
#include"Weapon.h"
#include"Player.h"
#include"Vector3D.h"
#include"Key_Checker.h"

#include<memory>
#include<functional>

// �v���C���[����������(�U��)�̃N���X TODO:�v���C���[�̎d�l���ł܂��ĂȂ��̂łЂƂ܂����ۓI�Ȗ��O��
class Player_Weapon : public Weapon {
public:
	// �R���X�g���N�^
	Player_Weapon();
	// �R�s�[�R���X�g���N�^
	Player_Weapon(std::shared_ptr<Player> set_player);
	// �f�X�g���N�^
	~Player_Weapon();

	// �X�V����
	void Update();

	// �v���C���[�̃V���b�g�^�C�v
	ePlayer_Shot_Type shot_type;

private:
	// �萔���܂Ƃ߂Ă����N���X
	Define_Value define_value;
	// ���W�֌W�̃N���X�B�e���̍��W�Ƃ��Ĉ���
	Vector3D vector3;

	std::shared_ptr<Player> player;
	std::unique_ptr<Key_Checker>& key_checker = Key_Checker::Get_Instance();

	// �L�[�̓��͂Œe�𔭎�
	void Fire();
	// �L�[�̓��͂ōU���̎�ނ�؂�ւ���B���t���[����t����
	void Change_Fire_Type();
	// ��Ԃɉ������V���b�g��ݒ肷��
	void Set_Shot_Pattern();

	// �ł��o�����e�ۂ���ʊO�֏o�Ă��邩�𔻒f����
	bool Check_Off_Screen(Bullet& player_Bullet);
	// �ł��o�����e�ۂ���ʊO�ɏo�Ă��������
	void Bullet_Off_Screen_Erase();

	// �e���̎��
	std::function<void()> fire_type;
	// �p�x
	float rad;
	// �e�����˂����ʒu
	double position_x;
	// sin�g����邽�߂ɉ��Z����l
	int counter;
	// �U�ꕝ
	double amplitude;
};
