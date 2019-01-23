#include"Character.h"

// �R���X�g���N�^
Character::Character() {

}

// ���݂�x���W��Ԃ�
float Character::Get_X() {
	return vector3d.x;
}
// x���W���Z�b�g����
void Character::Set_X(float set_x) {
	vector3d.x = set_x;
}

// ���݂�y���W��Ԃ�
float Character::Get_Y() {
	return vector3d.y;
}
// y���W��ݒ肷��
void Character::Set_Y(float set_y) {
	vector3d.y = set_y;
}

// ���݂�z���W��Ԃ�
float Character::Get_Z() {
	return vector3d.z;
}
// z���W��ݒ肷��
void Character::Set_Z(float set_z) {
	vector3d.z = set_z;
}

// �o���ʒu��ݒ肷��
void Character::Set_Arrange_Poisition(float set_x, float set_y, float set_z) {
	vector3d.Set_Vector(set_x, set_y, set_z);
}

// vector��ݒ肷��
void Character::Set_Position(Vector3D set_vector3) {
	vector3d = set_vector3;
}

// ���W��Ԃ�
Vector3D Character::Get_Position() {
	return vector3d;
}

// �傫����Ԃ�
Object_Size Character::Get_Size() {
	return size;
}

// �A�N�^�[�̉E�[�̍��W��Ԃ�
float Character::Get_Right_Edge() {
	return center_position.x - (size.width / 2);
}
// �A�N�^�[�̍��[�̍��W��Ԃ�
float Character::Get_Left_Edge() {
	return center_position.x + (size.width / 2);
}
// �A�N�^�[�̏�[�̍��W��Ԃ�
float Character::Get_Top_Edge() {
	return center_position.y - (size.height / 2);
}
// �A�N�^�[�̉��[�̍��W��Ԃ�
float Character::Get_Bottom_Edge() {
	return center_position.y + (size.height / 2);
}

// �A�N�^�[�̃��f���n���h����Ԃ�
int &Character::Get_Model_Handle() {
	return model_handle;
}

// �A�N�^�[�I�u�W�F�N�g�𐶐�����
void Character::Create_Actor(TCHAR* model_path) {
	// �v���C���[�̃��f���n���h�����i�[
	model_handle = MV1LoadModel(model_path);
}

// �`����s��
void Character::Render() {
	MV1DrawModel(model_handle);
	MV1SetPosition(model_handle, vector3d);
}
