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

	// �傫����ݒ�
	size.Set_Size(define_value.ENEMY_WIDTH, define_value.ENEMY_HEIGHT, define_value.ENEMY_DEPTH);

	// �X�e�[�^�X���Z�b�g
	enemy_status = std::make_shared<Enemy_Status>(scene_manager->Get_Stage());

	// ���f����ݒ肷��
	Create_Actor("Resources/Enemy/Enemy.x");
	MV1SetPosition(model_handle, VGet(vector3d.x, vector3d.y, vector3d.z));
	MV1SetScale(model_handle, VGet(0.6f, 0.6f, 0.6f));
	MV1SetRotationXYZ(model_handle, VGet(0, radian, 0)); // �G�l�~�[�̕\���p�x�𒲐�

	// ��ƂȂ�ʂ��쐬�B�킹�锠�̓V��ɂ��������
	rect = rect.Make_Enemy_Rectangle(vector3d, size.width, size.height, size.depth);
	// �����蔻��Ɏg�p�����`�𐶐�
	Set_Rects();
	
	//TEST
	degree = set_degree;
	radian = degree * DX_PI_F / 180;
}

// �f�X�g���N�^
Enemy::~Enemy() {}

// �����蔻��Ɏg�p�����`�𐶐�����
void Enemy::Set_Rects() {
	rects = rect.Make_3DBox(rects);
}

//TEST
void Enemy::RENDER() {
	//VECTOR pos = VGet(vector3d.x + half_depth * cos(radian), vector3d.y, vector3d.z + half_width * cos(radian));
	VECTOR pos = VGet(vector3d.x + size.Get_Helf_Depth(), vector3d.y, vector3d.z + size.Get_Helf_Width());

	DrawSphere3D(pos, 2, 5, GetColor(255, 0, 255), GetColor(0, 0, 0), TRUE);
	
	//DrawTriangle3D(
	//	VGet(vector3d.x - (half_width * cos(radian)), vector3d.y + (80 + sin(radian)), vector3d.z),
	//	VGet(vector3d.x - (half_width * cos(radian)), vector3d.y                     , vector3d.z - (half_depth * sin(radian))),
	//	VGet(vector3d.x - (half_width * cos(radian)), vector3d.y                     , vector3d.z + (half_depth * sin(radian))),
	//	GetColor(0, 0, 0), FALSE);
	//DrawTriangle3D(
	//	VGet(vector3d.x + (half_width * cos(radian)), vector3d.y + (80 + sin(radian)), vector3d.z),
	//	VGet(vector3d.x + (half_width * cos(radian)), vector3d.y,                      vector3d.z - (half_depth * sin(radian))),
	//	VGet(vector3d.x + (half_width * cos(radian)), vector3d.y,                      vector3d.z + (half_depth * sin(radian))),
	//	GetColor(0, 0, 0), FALSE);
}
