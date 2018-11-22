#pragma once

#include"Enemy.h"
#include"Player.h"

#include<memory>

// ファクトリークラス TODO:templateだとわかりやすいが汎用性がないので修正
template<class T>
class Factory {
public:
	static std::shared_ptr<T> Create_Actor() {
		return std::make_shared<T>();

		return nullptr;
	}
};
