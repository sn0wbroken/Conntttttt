#include"Enemy.h"
#include"Scene_Manager.h"

// �R���X�g���N�^
Enemy::Enemy() {}

// �R�s�[�R���X�g���N�^
Enemy::Enemy(Vector3D position, float set_degree) {
	// �v���C����X�e�[�W���擾
	std::unique_ptr<Scene_Manager>& scene_manager = Scene_Manager::Get_Instance();

	//���W��ݒ�
	vector3d.Set_Vector(position.x, position.y, position.z);

	// �G�l�~�[�̕�
	width = define_value.ENEMY_WIDTH;
	// �G�l�~�[�̍���
	height = define_value.ENEMY_HEIGHT;

	// �X�e�[�^�X���Z�b�g
	enemy_status = std::make_shared<Enemy_Status>(scene_manager->Get_Stage());

	// TODO:�摜�̗p�ӂ��܂��Ȃ̂�
	Create_Actor("Resources/Enemy/Enemy.x");
	MV1SetPosition(model_handle, VGet(vector3d.x, vector3d.y, vector3d.z));

	//TEST
	degree = set_degree;
	radian = degree * (DX_PI_F / 180);
	MV1SetRotationXYZ(model_handle, VGet(0, radian, 0)); // �G�l�~�[�̕\���p�x�𒲐�
	// �����蔻��Ɏg�p�����`�𐶐�
	Set_Rects();
}

// �f�X�g���N�^
Enemy::~Enemy() {}

// �����蔻��Ɏg�p�����`�𐶐�����
void Enemy::Set_Rects() {
	Rect rect;
	rects["front_face"] = rect.Make_3DBox(shared_from_this());

	���f�������邾�낤������
}

//TEST
void Enemy::RENDER() {
	DrawSphere3D(vector3d.GetVECTOR(), 2, 5, GetColor(255, 0, 255), GetColor(0, 0, 0), TRUE);
	
	//DrawTriangle3D(
	//	VGet(vector3d.x - (10 + cos(radian)), vector3d.y + (80 + sin(radian)), vector3d.z),
	//	VGet(vector3d.x - (10 + cos(radian)), vector3d.y                     , vector3d.z - (20 + sin(radian))),
	//	VGet(vector3d.x - (10 + cos(radian)), vector3d.y                     , vector3d.z + (20 + sin(radian))),
	//	GetColor(0, 0, 0), FALSE);

	//DrawTriangle3D(
	//	VGet(vector3d.x                     , vector3d.y + (80 + sin(radian)), vector3d.z),
	//	VGet(vector3d.x - (15 + cos(radian)), vector3d.y                     , vector3d.z - (10 + sin(radian))),
	//	VGet(vector3d.x + (15 + cos(radian)), vector3d.y                     , vector3d.z - (10 + sin(radian))),
	//	GetColor(0, 0, 0), FALSE);
}
