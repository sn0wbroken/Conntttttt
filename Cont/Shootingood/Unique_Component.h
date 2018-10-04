#pragma once

#include<memory>

// �P�������݂��Ȃ����̂����
template<class T>
class Unique_Component {
public:
	// �C���X�^���X�̐���
	static inline std::unique_ptr<T>& Get_Instance() {
		static std::unique_ptr<T> instance(new T());
		return instance;
	}

protected:
	// �O������̐������֎~
	Unique_Component() {};
	virtual ~Unique_Component() {};

private:
	// �R�s�[�̍쐬���֎~
	Unique_Component(const T& obj);
};
