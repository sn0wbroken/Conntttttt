#include "Actor.h"

// �R���X�g���N�^
Actor::Actor() {

}

// �f�X�g���N�^
Actor::~Actor() {
	
}

// �A�N�^�[�I�u�W�F�N�g�𐶐�����
void Actor::Create_Actor(TCHAR*model_path) {
	for (auto iterator = children.begin(); iterator != children.end(); ++iterator) {
		if (iterator->second->actor_state != eActor_State::Break) {
			++iterator;
			iterator->second->Create_Actor(model_path);
		}
	}
}

// ���������s��
void Actor::Initialize() {
	for (auto iterator = children.begin(); iterator != children.end(); ++iterator) {
		if (iterator->second->actor_state != eActor_State::Break) {
			iterator->second->Initialize();
		}
	}
}

// ���t���[������X�V����
void Actor::Update() {
	for (auto iterator = children.begin(); iterator != children.end(); ++iterator) {
		if (iterator->second->actor_state != eActor_State::Break) {
			iterator->second->Update();
		}
	}
}

// �A�N�e�B�u�ȃA�N�^�[��`�悷��
void Actor::Render() {
	for (auto iterator = children.begin(); iterator != children.end(); ++iterator) {
		if (iterator->second->actor_state != eActor_State::Break) {
			iterator->second->Render();
		}
	}
}

// �q��ǉ�����
void Actor::Add_Child(std::string name, std::shared_ptr<Actor> const actor) {
	children[name] = actor;
}
