#pragma once

#include"Actor.h"
#include"Enemy_Manager.h"
#include"Player_Manager.h"

// �����蔻����s��
class Collision : public Actor {
public:
	// �R���X�g���N�^
	Collision();
	// �f�X�g���N�^
	~Collision() {};

	// �v�Z���𗘗p����
	Vector3D calculator;

	// ���t���[���Ă΂��X�V����
	void Update() override;

	// ������2�_�Ԃ̋��������߂ĕԂ�
	float Get_Distance(Vector3D coordinates_1, Vector3D coordinates_2);

	// �����ƕ��ʂ̓����蔻��
	bool Line_To_Face(std::shared_ptr<Enemy> enemy);
};
