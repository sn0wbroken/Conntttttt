#pragma once

#include"Define_Value.h"
#include"Vector3D.h"
#include"Math.h"

// �G�l�~�[��AI���Ǘ�
class Enemy_AI {
public:
	// �R���X�g���N�^
	Enemy_AI(int Enemy_Model,Vector3D *EnemyPosition);
	// �f�X�g���N�^
	~Enemy_AI();

	// ���t���[������
	void Update();


	void MoveAI0(Vector3D enemy,Vector3D player);
private:
	// �萔���܂Ƃ߂Ă����N���X
	Define_Value define_value;
	Vector3D * m_EPosition; //TODO::�v�C��
	int m_EnemyModel;
};
