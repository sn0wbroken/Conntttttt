#include"Enum.h"
#include"Enemy_AI.h"
#include"Enemy_Manager.h"

#include<cmath>

// �R���X�g���N�^
Enemy_AI::Enemy_AI()
{
	//m_enemy = std::make_shared<Enemy>();
}

// �f�X�g���N�^
Enemy_AI::~Enemy_AI() {}

// ���t���[������
void Enemy_AI::Update() {
	std::unique_ptr<Enemy_Manager>& enemy_manager = Enemy_Manager::Get_Instance();
	auto enemies = enemy_manager->active_enemies;
	for (auto enemy : enemies) {
		//TODO:�e�X�g�̒l�B���܂莟��Define_Value�Œ�`���Ďg��
		auto speed = 1.0f;
		enemy->vector3d.Move(speed * std::cosf(enemy->Get_Radian()), 0.0f, speed * std::sinf(enemy->Get_Radian()));
		enemy->Animation_Controller();

		// �����蔻����ꏏ�ɓ�����
		for (auto iterator = begin(enemy->rects); iterator != end(enemy->rects); ++iterator) {
			iterator->second.Move(speed, enemy->Get_Radian());   //speed * cosf(enemy->Get_Radian()), 0.0f, speed * sinf(enemy->Get_Radian()));
			iterator->second.Move(speed, enemy->Get_Radian());   //speed * cosf(enemy->Get_Radian()), 0.0f, speed * sinf(enemy->Get_Radian()));
			iterator->second.Move(speed, enemy->Get_Radian());   //speed * cosf(enemy->Get_Radian()), 0.0f, speed * sinf(enemy->Get_Radian()));
			iterator->second.Move(speed, enemy->Get_Radian());   //speed * cosf(enemy->Get_Radian()), 0.0f, speed * sinf(enemy->Get_Radian()));

			//TODO: ���X�G���H
			if (iterator == enemy->rects.find("front_face")) {
				iterator->second.center_position.Move(speed * cosf(enemy->Get_Radian()), 0.0f, speed * sinf(enemy->Get_Radian()));
			}
		}
	}
}

void Enemy_AI::Move_AI0() {
	//Vector3D m_Forward;
	//float m_Rotation;
	////�v�Z��
	//m_Forward = Vector3D::VectorLength(m_enemy->vector3d);//TODO:�v���C���[���W�擾
	////// �x�N�g������p�x���v�Z
	//Vector3D cos = Vector3D::dot(FrontVector, m_Forward) / (Vector3D::VectorLength(FrontVector) * Vector3D::VectorLength(m_Forward));
	//m_Rotation = acosf(cos.x);
	////���όv�Z
	//Vector3D dot = Vector3D::dot(UpVector, Vector3D::cross(FrontVector, m_Forward));
	//if (dot.x < 0) {
	//	m_Rotation = -m_Rotation;
	//}
	////�ړ���
	//// �ړ��x�N�g���ɑ��x�C�o�ߎ��Ԃ���Z���āC�ړ��ʂ����߂�
	//enemy += m_Forward * 2.0f; //TODO::MAGICNUMBER deltatime�̂悤�Ȃ��̂��|����
	//// �������ׂ��ʒu�ɒ�������ړ�����߂�
	//Vector3D length = VMath::VectorLength(enemy); //TODO:�v���C���[���W�擾
	//if (length.x <= (/*deltatime * */2.0f)) { //TODO:MagicNumber
	//return;
	//}
}
