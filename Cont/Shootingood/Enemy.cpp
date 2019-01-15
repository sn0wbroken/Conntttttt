#include"Enemy.h"
#include"Scene_Manager.h"
#include <sstream>
// �R���X�g���N�^
Enemy::Enemy() {}

// �R�s�[�R���X�g���N�^
Enemy::Enemy(Vector3D position, Vector3D player_position) {
	// �v���C����X�e�[�W���擾
	std::unique_ptr<Scene_Manager>& scene_manager = Scene_Manager::Get_Instance();
	unique_ptr<Enemy_Manager>& enemy_manager = Enemy_Manager::Get_Instance();

	//���W��ݒ�
	vector3d.Set_Vector(position.x, position.y, position.z);
	// �傫����ݒ�
	size.Set_Size(define_value.ENEMY_WIDTH, define_value.ENEMY_HEIGHT, define_value.ENEMY_DEPTH);
	// �p�x���v���C���[�̕����ɐݒ�
	radian = Vector3D::AngleOfElevation(player_position, position);

	// �X�e�[�^�X���Z�b�g
	enemy_status = std::make_shared<Enemy_Status>(scene_manager->Get_Stage());

	// ���f����ݒ肷��
	if (enemy_manager->enemies.size() < 1)
	{
		//enemymanager�̔z��ɉ��������Ă��Ȃ������ꍇ�͍쐬����B
		Create_Actor("Resources/Enemy/Enemy.x");
	}
	else
	{
		//������x���f����ǂݍ��ނ�肱����̕����኱����
		model_handle = MV1DuplicateModel(enemy_manager->enemies.front()->Get_Model_Handle());
	}
	MV1SetPosition(model_handle, VGet(vector3d.x, vector3d.y, vector3d.z));
	MV1SetScale(model_handle, VGet(0.6f, 0.6f, 0.6f));
	MV1SetRotationXYZ(model_handle, VGet(0, radian, 0));
	//���s���[�V�����̃n���h�����擾����B
	anim_handle = MV1AttachAnim(model_handle, 0);
	Anim_CurrentFrame = 0;

	// ��ƂȂ��(�V�䕔)�𐶐�
	rects["top_face"] = rect.Make_Top_Face(vector3d, size);
	// �����蔻��Ɏg�p�����`�𐶐�
	rects = rect.Make_3DBox(rects["top_face"], size, rects);
	// �����蔻��̒��S�̍��W��ݒ肷��
	Set_Collision_Centor(rects);
	// �����蔻��p�̔����L�����N�^�[�̌����ɍ��킹�ĉ�]������
	rect.Rotation_Rectangle(rects, collision_centor, radian);
}

// �f�X�g���N�^
Enemy::~Enemy() {}

// �����蔻��p�̔��̒��S���W��ݒ肷��
void Enemy::Set_Collision_Centor(std::unordered_map<std::string, Rect> set_rects) {
	auto z_coordinates = set_rects.find("front_face")->second.top_right.z - size.depth / 2;
	auto x_coordinates = set_rects.find("right_face")->second.top_right.x - size.width / 2;

	collision_centor= vector3d.Get_Vector(x_coordinates, 0, z_coordinates);
}

//���W�A����ݒ�
void Enemy::Set_Radian(Vector3D set_playerpos) {
	radian = Vector3D::AngleOfElevation(set_playerpos, vector3d);
	MV1SetRotationXYZ(model_handle, VGet(0, Vector3D::AngleOfElevation(set_playerpos, vector3d), 0));
}

// �p�x���擾
float Enemy::Get_Degree() {
	return degree;
}
// ���W�A�����擾
float Enemy::Get_Radian() {
	return radian;
}

void Enemy::Add_AnimIndex() {
	Anim_CurrentFrame++;
	if (Anim_CurrentFrame >= MV1GetAttachAnimTotalTime(model_handle, anim_handle)){
		Anim_CurrentFrame = 0; //���Ԃ����Z�b�g����B
	}
	//���݂̃A�j���[�V�����̃^�C����ݒ肷��B
	MV1SetAttachAnimTime(model_handle, anim_handle, Anim_CurrentFrame);
}
