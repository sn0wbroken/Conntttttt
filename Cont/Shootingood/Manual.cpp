#include "Manual.h"

// �R���X�g���N�^
Manual::Manual() {
	manual_graph[0] = LoadGraph("Picture/Manual/�X���C�h1.PNG");
	manual_graph[1] = LoadGraph("Picture/Manual/�X���C�h2.PNG");
	manual_graph[2] = LoadGraph("Picture/Manual/�X���C�h3.PNG");

	// �X�^�[�g��0�y�[�W����
	now_page_number = 0;
}

// �f�X�g���N�^
Manual::~Manual() {
}

// ���t���[���Ă΂�鏈��
void Manual::Update() {
	Page_Ejection();
}

// �`��
void Manual::Render() {
	DrawExtendGraph(0, 0, define_value.WINDOW_X, define_value.WINDOW_Y, manual_graph[now_page_number], TRUE);
}

// �}�j���A��������Ƃ��Ƀy�[�W���ŏ��ɖ߂�
void Manual::Set_Initialize_Page_Number(int intialize_page) {
	now_page_number = intialize_page;
}

// �L�[���͂Ńy�[�W���������
void Manual::Page_Ejection() {
	if (key_checker->key[KEY_INPUT_LEFT] == 1) {
		if (now_page_number <= 0) {
			return;
		}
		now_page_number--;
	}
	else if (key_checker->key[KEY_INPUT_RIGHT] == 1) {
		if (now_page_number >= define_value.MAX_PAGE_NUBER) {
			return;
		}
		now_page_number++;
	}
}