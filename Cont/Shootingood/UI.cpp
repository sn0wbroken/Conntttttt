#include "UI.h"
#include"Game_Manager.h"

std::unique_ptr<Game_Manager>& game_manager = Game_Manager::Get_Instance();


// �R���X�g���N�^
UI::UI() {
	UI_background_graph = LoadGraph("Picture/UI/UI_Background.png");
}

// �`��
void UI::Render() {
	DrawExtendGraph(define_value.MAX_SCREEN_X, define_value.MIN_WINDOW_Y, 
					define_value.WINDOW_X, define_value.MAX_WINDOW_Y, UI_background_graph, TRUE);
	Now_Stage();
	Enemy_Number();
	Player_Shot_Type();
	Player_Life();
}

// ���݃v���C���Ă���X�e�[�W��\��
void UI::Now_Stage() {
	std::ostringstream now_stage;
	// enum�̒l�ɑ����ā{1
	now_stage << "Stage " << static_cast<int>(game_manager->Get_Stage()) + 1;
	DrawString(define_value.UI_X + (define_value.ADJUSTMENT_VALUE * 30), define_value.UI_BASE_Y, now_stage.str().c_str(), GetColor(0, 0, 0));
}

// �G�l�~�[�̐���\��
void UI::Enemy_Number() {
	std::ostringstream enemy_number;
	enemy_number << "�c��G�l�~�[ : " << enemy_manager->enemies.size();
	DrawString(define_value.UI_X, define_value.UI_BASE_Y + define_value.FELLOW_UI_SPACE, enemy_number.str().c_str() , GetColor(0, 0, 0));
}

// �v���C���[�̍U���^�C�v��\��
void UI::Player_Shot_Type() {
	std::string player_shot;
	switch (static_cast<int>(player_manager->player_action->shot_type)) {
		case 0:
			player_shot = "Straight";
			break;
		case 1:
			player_shot = "Wave";
			break;
	}

	std::ostringstream player_shot_type;
	player_shot_type << "�V���b�g�^�C�v\n   " << player_shot;
	DrawString(define_value.UI_X,
			   define_value.UI_BASE_Y + (define_value.FELLOW_UI_SPACE * 2), player_shot_type.str().c_str(), GetColor(0, 0, 0));
}

// �v���C���[�̎c�@��\��
void UI::Player_Life() {
	DrawString(define_value.UI_X, define_value.UI_BASE_Y + (define_value.FELLOW_UI_SPACE * 4), "Life", GetColor(0, 0, 0));

	switch (player_manager->player_status->Get_Life()) {
		case 2:
			DrawCircle(define_value.UI_X + (define_value.ADJUSTMENT_VALUE * 50), 
					   define_value.UI_BASE_Y + (define_value.FELLOW_UI_SPACE * 4) + (define_value.ADJUSTMENT_VALUE * 7.5), 5,
					   GetColor(150, 150, 255), TRUE);
			break;
		case 3:
			DrawCircle(define_value.UI_X + (define_value.ADJUSTMENT_VALUE * 50),
					   define_value.UI_BASE_Y + (define_value.FELLOW_UI_SPACE * 4) + (define_value.ADJUSTMENT_VALUE * 7.5), 5,
					   GetColor(150, 150, 255), TRUE);
			DrawCircle(define_value.UI_X + (define_value.ADJUSTMENT_VALUE * 65),
					   define_value.UI_BASE_Y + (define_value.FELLOW_UI_SPACE * 4) + (define_value.ADJUSTMENT_VALUE * 7.5), 5,
					   GetColor(150, 150, 255), TRUE);
			break;
	}
}


