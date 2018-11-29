#pragma once

#include"Enum.h"
#include"DxLib.h"
#include"Vector3D.h"
#include"Define_Value.h"
#include"Unique_Component.h"

#include<list>
#include<string>
#include<memory>

// �A�N�^�[�̊��N���X
class Actor : public Unique_Component<Actor> {
public:
	// �R���X�g���N�^
	Actor();
	// �f�X�g���N�^
	~Actor();

	// �A�N�^�[�̏�Ԃ�ݒ肷��
	eActor_Status actor_status;

	// �A�N�^�[�I�u�W�F�N�g�𐶐�����
	virtual void Create_Actor(TCHAR* model_path);
	// ���������s��
	virtual void Initialize();
	// �A�N�e�B�u�ȃA�N�^�[��`�悷��
	virtual void Render();
	// ���t���[������X�V����
	virtual void Update();

	// �q��ǉ�����B�C���X�^���X���������ꂽ�Ƃ��ɌĂ΂��
	void Add_Child(std::shared_ptr<Actor> const actor);

	// ���W�������N���X
	Vector3D vector3d;

protected:
	// �萔���܂Ƃ߂Ă����N���X
	Define_Value define_value;

	// �h���N���X���q�Ƃ��Ď����Ă���
	std::list<std::shared_ptr<Actor>> children;
};

