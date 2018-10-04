#pragma once

#include<memory>

// １つしか存在しないものを作る
template<class T>
class Unique_Component {
public:
	// インスタンスの生成
	static inline std::unique_ptr<T>& Get_Instance() {
		static std::unique_ptr<T> instance(new T());
		return instance;
	}

protected:
	// 外部からの生成を禁止
	Unique_Component() {};
	virtual ~Unique_Component() {};

private:
	// コピーの作成を禁止
	Unique_Component(const T& obj);
};
