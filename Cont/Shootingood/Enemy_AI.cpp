#include"Enum.h"
#include"Enemy_AI.h"
#include"Enemy_Manager.h"

//TODO::�ȉ��C���K�v
const Vector3D FrontVector(-1,0,0); 
const Vector3D UpVector(0.0f, 1.0f, 0.0f); // ������x�N�g��

// �R���X�g���N�^
//�K�v�Ȃ���
//�G�l�~�[�̃��f��ID
//�G�l�~�[�̍��W�A�h���X
//�v���C���[�̍��W���ǂ��ɂ�����B
Enemy_AI::Enemy_AI()
{
	//m_enemy = std::make_shared<Enemy>();
}

// �f�X�g���N�^
Enemy_AI::~Enemy_AI() {}

// ���t���[������
void Enemy_AI::Update() {
	
}

void Enemy_AI::MoveAI0()
{
	//Vector3D m_Forward;
	//float m_Rotation;
	////�v�Z��
	//m_Forward = Vector3D::VectorLength(m_enemy->vector3d);//TODO::�v���C���[���W�擾
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
	//enemy += m_Forward * 2.0f; //TODO::MAGICNUMBER  deltatime�̂悤�Ȃ��̂��|����
	//// �������ׂ��ʒu�ɒ�������ړ�����߂�
	//Vector3D length = VMath::VectorLength(enemy); //TODO::�v���C���[���W�擾
	//if (length.x <= (/*deltatime * */2.0f)) { //TODO::MagicNumber
	//return;
	//}
	
}
