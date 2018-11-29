#include"Title_Scene.h"
#include"Scene_Manager.h"

// �R���X�g���N�^
Title_Scene::Title_Scene() {
	manual = std::make_shared<Manual>();

	// ���W�ɂ͏����ʒu����
	icon_position_x = Define_Value::INITIALIZE_POSITION_X;
	icon_position_y = Define_Value::INITIALIZE_POSITION_Y;

	icon_width = Define_Value::DECIDE_ICON_WIDTH;
	icon_height = Define_Value::DECIDE_ICON_HEIGHT;

	// �I������܂ł͌��Ȃ�
	is_watch_manual = false;

	const CSVData & Data(CSVData::getInstance());
	CSVData::M_SoundFiles Sound = Data.sounds.at(114514);
	DxLib::PlaySoundMem(Sound.SHandle,1);

	// �����ʒu��Start����
	select_command = eSelect_Command::Start;
}

// ���t���[������
void Title_Scene::Update() {
	// �Q�[���̐i�s���Ǘ�����N���X
	std::unique_ptr<Scene_Manager> &game_manager = Scene_Manager::Get_Instance();

	// �G�X�P�[�v�L�[�Ń}�j���A���̉{�����I��
	if (key_checker->key[KEY_INPUT_ESCAPE] == 1) {
		is_watch_manual = false;
		// ����̂Ńy�[�W��0�ɖ߂�
		manual->Set_Initialize_Page_Number(0);
	}

	if (!is_watch_manual) {
		// �I���A�C�R���̑���
		Icon_Move();

		if (key_checker->key[KEY_INPUT_RETURN] == 1) {
			switch (select_command) {
			case eSelect_Command::Start:
				game_manager->Change_Scene(Scene_Manager::Main);
				break;
			case eSelect_Command::Manual:
				// �������UI�\��
				is_watch_manual = true;
				break;
			case eSelect_Command::Exit:
				// �Q�[���I��
				DxLib_End();
				break;
			}
		}
		return;
	}
	// �}�j���A���{�����Ȃ�A�}�j���A���̑������t
	else{
		manual->Update();
}
}


// �`��
void Title_Scene::Render() {
	DrawExtendGraph(0, 0, define_value.WINDOW_X, define_value.WINDOW_Y, background_graph, TRUE);
	DrawTriangle(icon_position_x, icon_position_y,
		icon_position_x, icon_position_y + icon_height,
	icon_position_x + icon_width, icon_position_y + (icon_height / 2),
		GetColor(0, 0, 0), TRUE);

	// �}�j���A���{�����Ȃ�A�}�j���A����\��
	if (is_watch_manual) {
		manual->Render();
	}
}

// �I���A�C�R���𓮂���
void Title_Scene::Icon_Move() {
	// �X�^�[�g�ȏ�͂Ȃ��̂ŕԂ�
	if (key_checker->key[KEY_INPUT_UP] == 1) {
		if (select_command == eSelect_Command::Start) {
			return;
		}

		// �����ꂽ�L�[���擾����
		auto input_key = KEY_INPUT_UP;
		icon_position_y -= Define_Value::ICON_MOVE_VALUE;
		// �I�����Ă�����̂�ς���
		Change_Decide(select_command, input_key);
	}
	// �G�O�W�b�g�ȉ��͂Ȃ��̂ŕԂ�
	if (key_checker->key[KEY_INPUT_DOWN] == 1) {
		if (select_command == eSelect_Command::Exit) {
			return;
		}

		// �����ꂽ�L�[���擾����
		auto input_key = KEY_INPUT_DOWN;
		icon_position_y += Define_Value::ICON_MOVE_VALUE;
		// �I�����Ă�����̂�ς���
		Change_Decide(select_command, input_key);
	}
}

// ����ɉ����đI�����Ă�����̂�ς���
void Title_Scene::Change_Decide(eSelect_Command now_select, int which_key) {
	// �����ꂽ�L�[�ɂ���ď�����ς���
	switch (which_key) {
		// ��L�[��������Ă����ꍇ
	case KEY_INPUT_UP:
		switch (now_select) {
		case eSelect_Command::Manual:
			select_command = eSelect_Command::Start;
			break;
		case eSelect_Command::Exit:
			select_command = eSelect_Command::Manual;
			break;
		}
		break;
		// ���L�[��������Ă����ꍇ
	case KEY_INPUT_DOWN:
		switch (now_select) {
		case eSelect_Command::Start:
			select_command = eSelect_Command::Manual;
			break;
		case eSelect_Command::Manual:
			select_command = eSelect_Command::Exit;
			break;
		}
		break;
	}
}