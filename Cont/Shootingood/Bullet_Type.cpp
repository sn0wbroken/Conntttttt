#include "Bullet_Type.h"

#include"Player_Manager.h"

// �R���X�g���N�^
Bullet_Type::Bullet_Type() {}

// �f�X�g���N�^
Bullet_Type::~Bullet_Type() {}

void Bullet_Type::Fire_Straight() {
	Player_Manager& player_manager = Player_Manager::Get_Instance();

	player = player_manager.player;

	//TODO:�}�W�b�N�i���o�[
	player->player_bullet.emplace_back(player->Get_X(), player->Get_Y(), 0, -define_value);
}
void Bullet_Type::Fire_Wave() {

}
