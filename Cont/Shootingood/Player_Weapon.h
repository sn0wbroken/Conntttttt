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

	// �ʏ�U���̎˒���Ԃ�
	Vector3D Get_Limit_Range();

	// �v���C���[�̃V���b�g�^�C�v
	eBomb_Type bomb_type;

	// �v�[��������o�������̂�������ꕨ
	Bullet* bullet;
	// �v�[������擾���������o���e���܂Ƃ߂�
	std::list<Bullet*> bomb_bullets;

private:
	std::shared_ptr<Player> player;
	std::unique_ptr<Key_Checker>& key_checker = Key_Checker::Get_Instance();

	// �������֐�
	void Initialize() override;

	// �L�[���͂ōU�����s��
	void Fire();
	// ��Ԃɉ������{����ݒ肷��
	void Set_Bomb();
	// �e���̈ʒu��ς���
	void Rotation();

	// ��ʊO�ɏo���e���v�[���ւ��ǂ�
	void Return_Bullet_Pooling();

	// �{����I������
	void Chose_Bomb();
	// �S���ʂɒe���΂��{��
	void Fullrange_Shot();
	// �U�����~�炷
	void Rain();
	
	// ���Ԍo�߂Œe������
	void Time_Limit_Erase_Bullet();
	// ���W���݂Ēe������
	void Reference_Coordinates_Erase_Bullet(std::list<Bullet*>& bullets);

	// �{��
	std::function<void()> shoot_bomb;
	// �������e����������
	std::function<void()> bullet_erase;
	
	// ��]�̒��S(�v���C���[�̒��S�ɓ���)
	Vector3D center_position;
	// �e����ԍő�n�_
	Vector3D distance_limit;

	// ���ݍs���Ă���{���̃^�C�v
	eEnable_Bomb_Type enable_bomb_type;

	// �x���@
	float degree;
	// �ʓx�@
	float radian;
	// ���a(���S����e���܂ł�)
	float radius;

	// �{���U���̍Œ����ǂ���
	bool enable_bomb;
	// �A�˂ɂȂ�Ȃ��悤�ɉ�����Ă��邩���o����
	bool shot_button_flag;
	// �{���̍U�����p�����Ă��邩�ǂ����̃t���O
	bool living_bomb;

	// �e���������u�Ԃ���J�E���g�J�n
	int timer;
	// timer�����̐��l�ɒB�����猂�����e������
	int clear_count;

	//TEST
	const float fire_range = 300;
};
