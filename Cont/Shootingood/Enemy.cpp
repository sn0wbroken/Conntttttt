#include"Enemy.h"
#include"Scene_Manager.h"
#include <sstream>
// �R���X�g���N�^
Enemy::Enemy() {}

// �R�s�[�R���X�g���N�^
Enemy::Enemy(Vector3D position, Vector3D set_playerpos) {
	// �v���C����X�e�[�W���擾
	std::unique_ptr<Scene_Manager>& scene_manager = Scene_Manager::Get_Instance();

	//���W��ݒ�
	vector3d.Set_Vector(position.x, position.y, position.z);
	OutputDebugString("AAA\n");
	// �傫����ݒ�
	size.Set_Size(define_value.ENEMY_WIDTH, define_value.ENEMY_HEIGHT, define_value.ENEMY_DEPTH);

	// �X�e�[�^�X���Z�b�g
	enemy_status = std::make_shared<Enemy_Status>(scene_manager->Get_Stage());

	//TEST
	//���W�A���v�Z
	radian = Vector3D::MoveOnAngleOfElevation(set_playerpos,position);
	degree = radian * 180 * 3.14f;

	// ���f����ݒ肷��
	Create_Actor("Resources/Enemy/Enemy.x");
	MV1SetPosition(model_handle, VGet(vector3d.x, vector3d.y, vector3d.z));
	MV1SetScale(model_handle, VGet(0.6f, 0.6f, 0.6f));
	MV1SetRotationXYZ(model_handle, VGet(0, Vector3D::RotateOnAngleOfElevation(set_playerpos, position), 0));

	// ��ƂȂ��(�V�䕔)�𐶐�
	rects["top_face"] = rect.Make_Top_Face(vector3d, size);
	// �����蔻��Ɏg�p�����`�𐶐�
	Set_Rects();
}

// �f�X�g���N�^
Enemy::~Enemy() {}

// �����蔻��Ɏg�p�����`�𐶐�����
void Enemy::Set_Rects() {
	rects = rect.Make_3DBox(rects["top_face"], size, rects);
}

//TEST
void Enemy::RENDER() {
	//�@�����蔻�����(�V�䕔�̂�)
	DrawLine3D(rects["top_face"].max_vertex  , rects["top_face"].top_left    , GetColor(0, 0, 0));
	DrawLine3D(rects["top_face"].max_vertex  , rects["top_face"].bottom_right, GetColor(0, 0, 0));
	DrawLine3D(rects["top_face"].top_left   , rects["top_face"].bottom_left , GetColor(0, 0, 0));
	DrawLine3D(rects["top_face"].bottom_left, rects["top_face"].bottom_right, GetColor(0, 0, 0));
}
