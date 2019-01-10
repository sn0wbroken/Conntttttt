#pragma once

#include"DxLib.h"
#include"Rect.h"
#include"Bullet.h"
#include"Character.h"
#include"Enemy_Status.h"

#include<vector>
#include<unordered_map>

// �G�l�~�[�{�̂̃N���X
class Enemy : public Character {
public:
	// �R���X�g���N�^
	Enemy();
	// �R���X�g���N�^
	Enemy(Vector3D position,Vector3D set_playerpos);
	// �f�X�g���N�^
	~Enemy();

	// �G�l�~�[�̃X�e�[�^�X�֌W�̃N���X
	std::shared_ptr<Enemy_Status> enemy_status;

	// �킹���`(�����蔻��Ɏg�p) TODO:�L�[�ɓ�� ���ʁA�E�ʂł͍���Ȃ�
	std::unordered_map<std::string, Rect> rects;

	//TEST �����Ă���Set�̓v���C�x�[�g
	// �����蔻��p�̔��̒��S
	Vector3D collision_centor;
	void Set_Collision_Centor(std::unordered_map<std::string, Rect> rects);

	// ���W�A����ݒ�
	void Set_Radian(Vector3D set_playerpos);

	// �p�x���擾
	inline float Get_Degree();
	// ���W�A�����擾
	inline float Get_Radian();

private:
	// �p�x(�x���@)
	float degree;
	// �p�x(�ʓx�@)
	float radian;

	// �ł��o���e�̑��x
	int bullet_speed;
	// �G�l�~�[�̑O�����̓����蔻��̍��W(�v���C���[�̒ʏ�U���̓����蔻��Ɏg�p)
	Vector3D flont_face_position;
};
