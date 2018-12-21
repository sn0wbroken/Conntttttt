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

	//TEST
	degree = set_degree;
	radian = degree * DX_PI_F / 180;

	// ���f����ݒ肷��
	Create_Actor("Resources/Enemy/Enemy.x");
	MV1SetPosition(model_handle, VGet(vector3d.x, vector3d.y, vector3d.z));
	MV1SetScale(model_handle, VGet(0.6f, 0.6f, 0.6f));
	MV1SetRotationXYZ(model_handle, VGet(0, radian, 0));

	// ��ƂȂ�ʂ𐶐��B�킹�锠�̓V��ɂ��������
	rect = rect.Make_Rectangle(vector3d, size); ///TODO:top_face�ɓ��ꂿ�Ⴆ�΂����̂ł́H///
	// �����蔻��Ɏg�p�����`�𐶐�
	Set_Rects();
}

// �f�X�g���N�^
Enemy::~Enemy() {}

// �����蔻��Ɏg�p�����`�𐶐�����
void Enemy::Set_Rects() {
	rects = rect.Make_3DBox(rect, size, rects);
}

//TEST
void Enemy::RENDER() {
	//�@�����蔻�����(�V�䕔�̂�)
	DrawLine3D(rect.top_right  , rect.top_left    , GetColor(0, 0, 0));
	DrawLine3D(rect.top_right  , rect.bottom_right, GetColor(0, 0, 0));
	DrawLine3D(rect.top_left   , rect.bottom_left , GetColor(0, 0, 0));
	DrawLine3D(rect.bottom_left, rect.bottom_right, GetColor(0, 0, 0));
}
