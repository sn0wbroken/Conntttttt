#pragma once

#include"Enemy.h"
#include"Player.h"

#include<memory>

// �t�@�N�g���[�N���X TODO:�Ƃ��Ă��ȒP�Ȏ����ɂȂ��Ă���̂Ŏ�̉����悤�͂�����ł�
template<class T>
class Factory {
public:
	static std::shared_ptr<T> Create_Actor() {
		return std::make_shared<T>();

		return nullptr;
	}
};
