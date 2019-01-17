#pragma once

#include"Actor.h"
#include"Enemy_Manager.h"
#include"Player_Manager.h"

#include<cmath>

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

private:
	// �����ƕ��ʂ̌�_�����߂�
	Vector3D Get_Intersection(Vector3D vector1, Vector3D vector2, Vector3D start_point, Vector3D end_point, Rect face);

	// �����ƕ��ʂ̓����蔻��
	bool Line_To_Face(std::shared_ptr<Enemy> enemy);
	// �_���ʂɓ��ڂ��Ă��邩�𒲂ׂ�B���ꕽ�ʏ�ɂ��邱�Ƃ��O��
	bool Point_To_Rectangle(Vector3D intersection, Vector3D start_point, Vector3D end_position, Vector3D normal_vector, Rect face);

	// �����Ō��铖���蔻��
	bool Distance_Collition();
};
