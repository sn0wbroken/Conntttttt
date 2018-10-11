#pragma once

#include"Enemy.h"
#include"Enemy_AI.h"
#include"Enemy_Status.h"
#include"Define_Value.h"
#include"Unique_Component.h"

#include<memory>
#include<vector>

// �G�l�~�[�̃}�l�[�W���[�N���X
class Enemy_Manager : public  Unique_Component<Enemy_Manager> {
public:
	// �G�l�~�[�̃X�e�[�^�X�֌W�������N���X
	std::shared_ptr<Enemy_Status> enemy_status = std::make_shared<Enemy_Status>();
	// �G�l�~�[��AI���Ǘ�
	std::shared_ptr<Enemy_AI> enemy_AI = std::make_shared<Enemy_AI>();

	// ������
	void Initialize();

	// ���t���[���Ă΂��
	void Update();
	// �`��
	void Render();

	// �G�l�~�[��z�u
	void Enemy_Arrange();
	// �G�l�~�[�����̈ʒu�ɔz�u���Ȃ���
	void Reset_Enemy();

	// ��ʏ�œ����G
	std::vector<Enemy> enemies;

	// �G�l�~�[�����e
	std::vector<Bullet> enemy_bullet;

	// �f�X�g���N�^
	~Enemy_Manager() {}

private:
	// �R���X�g���N�^
	Enemy_Manager();

	// x���W
	int x;
	// y ���W
	int y;

	// �o������G��z�u
	void Arrange(int set_x, int set_y);

	// �萔���܂Ƃ߂Ă����\����
	Define_Value define_value;

	// �����Ɏ��g���w�肵�����̂����ɐ�������邷
	friend class Unique_Component<Enemy_Manager>;
};