#pragma once

#include"Define_Value.h"
#include"Vector3D.h"
#include"Enemy.h"

// �G�l�~�[��AI���Ǘ�
class Enemy_AI {
public:
	// �R���X�g���N�^
	Enemy_AI();
	// �f�X�g���N�^
	~Enemy_AI();

	// ���t���[������
	void Update();

<<<<<<< Updated upstream
	void Move_AI0();

	std::shared_ptr<Enemy> enemy;
=======
	void MoveAI0();
>>>>>>> Stashed changes
private:
	// �萔���܂Ƃ߂Ă����N���X
	Define_Value define_value;
};
