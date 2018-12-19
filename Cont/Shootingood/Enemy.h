#pragma once

#include"DxLib.h"
#include"Rect.h"
#include"Bullet.h"
#include"Character.h"
#include"Enemy_Status.h"

#include<map>
#include<vector>

// �G�l�~�[�{�̂̃N���X
class Enemy : public Character {
public:
	// �R���X�g���N�^
	Enemy();
	// �R�s�[�R���X�g���N�^
	Enemy(Vector3D position, float set_degree);
	// �f�X�g���N�^
	~Enemy();

	// �G�l�~�[�̃X�e�[�^�X�֌W�̃N���X
	std::shared_ptr<Enemy_Status> enemy_status;

	//TEST
	void RENDER();

private:
	// �p�x(�x���@)
	float degree;
	// �p�x(�ʓx�@)
	float radian;

	// �ł��o���e�̑��x
	int bullet_speed;
	// �G�l�~�[�̑O�����̓����蔻��̍��W(�v���C���[�̒ʏ�U���̓����蔻��Ɏg�p)
	Vector3D flont_face_position;
	// �킹����(�����蔻��Ɏg�p)
	std::map<std::string, Rect*> rects;

	//TEST
	// ���f���̌��_����L�����N�^�[�̌�������ɍ��[�܂ł̕�
	float width_1;
	// ���f���̌��_����L�����N�^�[�̌�������ɉE�[�܂ł̕�
	float width_2;
	// ���f���̌��_����L�����N�^�[�̌�������ɏ�[�܂ł̍���
	float height_1;
	// ���f���̌��_����L�����N�^�[�̌�������ɉ��̒[�܂ł̉��s
	float depth_1;
	// ���f���̌��_����L�����N�^�[�̌�������Ɏ�O�̒[�܂ł̉��s
	float depth_2;
};
