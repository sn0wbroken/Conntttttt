#include"Enemy.h"
#include"Scene_Manager.h"
#include <sstream>
// �R���X�g���N�^
Enemy::Enemy() {}

// �R�s�[�R���X�g���N�^
Enemy::Enemy(Vector3D position, Vector3D player_position) {
	// �v���C����X�e�[�W���擾
	std::unique_ptr<Scene_Manager>& scene_manager = Scene_Manager::Get_Instance();

	//���W��ݒ�
	vector3d.Set_Vector(position.x, position.y, position.z);
	OutputDebugString("AAA\n");
	// �傫����ݒ�
	size.Set_Size(define_value.ENEMY_WIDTH, define_value.ENEMY_HEIGHT, define_value.ENEMY_DEPTH);

	// �X�e�[�^�X���Z�b�g
	enemy_status = std::make_shared<Enemy_Status>(scene_manager->Get_Stage());

	// ���f����ݒ肷��
	Create_Actor("Resources/Enemy/Enemy.x");
	MV1SetPosition(model_handle, VGet(vector3d.x, vector3d.y, vector3d.z));
	MV1SetScale(model_handle, VGet(0.6f, 0.6f, 0.6f));
	auto hoge = VGet(0, radian, 0);
	MV1SetRotationXYZ(model_handle, VGet(0, radian, 0));

	// ��ƂȂ��(�V�䕔)�𐶐�
	rects["top_face"] = rect.Make_Top_Face(vector3d, size);
	// �����蔻��Ɏg�p�����`�𐶐�
	rects = rect.Make_3DBox(rects["top_face"], size, rects);
	//TEST	
	Set_Collision_Centor(rects);
	rect.Rotation_Rectangle(rects, radian);
}

// �f�X�g���N�^
Enemy::~Enemy() {}

void Enemy::Set_Collision_Centor(std::unordered_map<std::string, Rect> rects) {
	auto x_coordinates = rects.find("right_face")->second.top_right.x - size.width / 2;
	auto z_coordinates = rects.find("front_face")->second.top_right.z - size.depth / 2;

	collision_centor = vector3d.Get_Vector(x_coordinates, 0, z_coordinates);
}

//���W�A����ݒ�
void Enemy::Set_Radian(Vector3D set_playerpos) {
	radian = Vector3D::MoveOnAngleOfElevation(set_playerpos, vector3d);
	MV1SetRotationXYZ(model_handle, VGet(0, Vector3D::RotateOnAngleOfElevation(set_playerpos, vector3d), 0));
}

// �p�x���擾
inline float Enemy::Get_Degree() {
	return degree;
}
// ���W�A�����擾
inline float Enemy::Get_Radian() {
	return radian;
}
