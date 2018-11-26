#include "Actor.h"

// �R���X�g���N�^
Actor::Actor() {

}

// �f�X�g���N�^
Actor::~Actor() {
	
}

// �A�N�^�[�I�u�W�F�N�g�𐶐�����
void Actor::Create_Actor(TCHAR*model_path) {
	std::list<std::shared_ptr<Actor>>::iterator iterator = children.begin();
	while (iterator != children.end()) {
		if ((*iterator)->actor_status != eActor_Status::Break) {
			++iterator;
			(*iterator)->Create_Actor(model_path);
		}
	}
}

// �A�N�e�B�u�ȃA�N�^�[��`�悷��
void Actor::Render() {
	std::list<std::shared_ptr<Actor>>::iterator iterator = children.begin();
	while (iterator != children.end()) {
		if ((*iterator)->actor_status != eActor_Status::Break) {
			(*iterator)->Render();
			++iterator;
		}
	}
}

// ���t���[������X�V����
void Actor::Update() {
	std::list<std::shared_ptr<Actor>>::iterator iterator = children.begin(); // Player_Weapon�̑���Ŏ��s
	while (iterator != children.end()) {
		if ((*iterator)->actor_status != eActor_Status::Break) {
 			(*iterator)->Update();
			++iterator;
		}
	}
}

// �q��ǉ�����
void Actor::Add_Child(std::shared_ptr<Actor> const actor) {
	children.push_back(actor);
}
