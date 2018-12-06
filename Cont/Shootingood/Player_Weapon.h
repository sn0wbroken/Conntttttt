#pragma once

#include"Enum.h"
#include"Bullet.h"
#include"Weapon.h"
#include"Player.h"
#include"Vector3D.h"
#include"Key_Checker.h"

#include<memory>
#include<functional>

// �v���C���[����������(�U��)�̃N���X
class Player_Weapon : public Weapon {
public:
	// �R���X�g���N�^
	Player_Weapon();
	// �f�X�g���N�^
	~Player_Weapon();

	// �X�V����
	void Update() override;
	// �`��
	void Render() override;

	// �v���C���[�̃V���b�g�^�C�v
	eBom_Type ebom_type;

private:
	std::shared_ptr<Player> player;
	std::unique_ptr<Key_Checker>& key_checker = Key_Checker::Get_Instance();

	// �������֐�
	void Initialize() override;

	// �L�[�̓��͂Œe�𔭎�
	void Fire();
	// ��Ԃɉ������V���b�g��ݒ肷��
	void Set_Shot_Pattern();
	// �e���̈ʒu��ς���
	void Rotation();

	// �e���̎��
	std::function<void()> bom_type;
	// ��]�̒��S(�v���C���[�̒��S�ɓ���)
	Vector3D center_position;
	// �x���@
	float degree;
	// �ʓx�@
	float radian;
	// ���a(���S����e���܂ł�)
	float radius;

	// �S���ʂɒe���΂��{��
	void Fullrange_Shot(std::list<Bullet*> magazine);
};
