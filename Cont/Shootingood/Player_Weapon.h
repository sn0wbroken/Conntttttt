#pragma once

#include"Enum.h"
#include"Bullet.h"
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
	void Update() override;

	// �v���C���[�̃V���b�g�^�C�v
	eBom_Type ebom_type;

private:
	std::shared_ptr<Player> player;
	std::unique_ptr<Key_Checker>& key_checker = Key_Checker::Get_Instance();

	// �������֐�
	void Initialize();

	// �L�[�̓��͂Œe�𔭎�
	void Fire();
	// �L�[�̓��͂ōU���̎�ނ�؂�ւ���B���t���[����t����
	void Change_Fire_Type();
	// ��Ԃɉ������V���b�g��ݒ肷��
	void Set_Shot_Pattern();

	// �e���̎��
	std::function<void()> bom_type;
	// �p�x
	float radian;
	// �e�����˂����ʒu
	double position_x;
	// sin�g����邽�߂ɉ��Z����l
	int counter;
	// �U�ꕝ
	double amplitude;
};