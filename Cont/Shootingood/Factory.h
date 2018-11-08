#pragma once

#include"Enemy.h"
#include"Player.h"

#include<memory>

// ファクトリークラス TODO:とっても簡単な実装になっているので手の加えようはいくらでも
template<class T>
class Factory {
public:
	static std::shared_ptr<T> Create_Actor() {
		return std::make_shared<T>();

		return nullptr;
	}
};
