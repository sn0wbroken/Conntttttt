#include"Character.h"

// �R���X�g���N�^
Character::Character() {

}

// ���݂�x���W��Ԃ�
float Character::Get_X() {
	return vector3.x;
}
// x���W���Z�b�g����
void Character::Set_X(float set_x) {
	vector3.x = set_x;
}

// ���݂�y���W��Ԃ�
float Character::Get_Y() {
	return vector3.y;
}
// y���W��ݒ肷��
void Character::Set_Y(float set_y) {
	vector3.y = set_y;
}

// ���݂�z���W��Ԃ�
float Character::Get_Z() {
	return vector3.z;
}
// z���W��ݒ肷��
void Character::Set_Z(float set_z) {
	vector3.z = set_z;
}

// ����Ԃ�
int Character::Get_Width() {
	return width;
}
// ������Ԃ�
int Character::Get_Height() {
	return height;
}

// �o���ʒu��ݒ肷��
void Character::Set_Arrange_Poisition(float set_x, float set_y, float set_z) {
	vector3.Arrange(set_x, set_y, set_z);
}

// vector��ݒ肷��
void Character::Set_Vector3D(Vector3D Vec3) {
	vector3 = Vec3;
}

// �A�N�^�[�̉E�[�̍��W��Ԃ�
float Character::Get_Right_Edge() {
	return center_position.x - (width / 2);
}
// �A�N�^�[�̍��[�̍��W��Ԃ�
float Character::Get_Left_Edge() {
	return center_position.x + (width / 2);
}
// �A�N�^�[�̏�[�̍��W��Ԃ�
float Character::Get_Top_Edge() {
	return center_position.y - (height / 2);
}
// �A�N�^�[�̉��[�̍��W��Ԃ�
float Character::Get_Bottom_Edge() {
	return center_position.y + (height / 2);
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
	Actor::Render();
}