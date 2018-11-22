#pragma once
// �V���O���g�����e���v���[�g�N���X(�p�u���b�N�p�����Ďg��)
//
// ���̃N���X�͉��L�̏��Ђ�36�y�[�W�A���L�̃T�C�g���Q�l�ɂ��܂����B
// GAME PROGRAMMING GEMS Mark DeLoura �� �쐼�T�K�Ė� ���q�p�|�� �{�[���f�W�^���@
//http://www9.plala.or.jp/herm/Pages/DevTips/Designing/Singleton.html
template<class T> class Singleton
{
public:
	// �B��̃C���X�^���X���擾���郁�\�b�h
	static inline T & getInstance()
	{
		if (singleton == nullptr) {
			singleton = new T();
			if (singleton == nullptr) {
				std::exception("null pointer exception");
			}
		}
		return *singleton;
	}

protected:
	// �f�t�H���g�E�R���X�g���N�^
	explicit inline Singleton()
	{
		if (singleton != nullptr) {
			throw std::exception("multicreation exception");
		}
		// �����ōs���Ă��邱�Ƃ͐e�̃|�C���^���q�̃|�C���^�Ƃ��ĕۑ����Ă��邾���ł���
		// �e�Ǝq�̃N���X���ǂ̏��ɔz�u����邩��offset�̒l���ω�����
		//���d�p�����g�p���Ȃ�����AOffset �� 0 �ł��B
		const int offset = reinterpret_cast<int> (reinterpret_cast<T *> (1)) - reinterpret_cast<int> (reinterpret_cast<const Singleton <T> *> (reinterpret_cast<T *> (1)));
		singleton = reinterpret_cast<T *> (reinterpret_cast<int> (this) + offset);
	}

	// �R�s�[�E�R���X�g���N�^
	inline Singleton(const Singleton & /*right*/)
	{
		throw std::exception("multicreation exception");
	}

	// �f�X�g���N�^
	virtual inline ~Singleton() noexcept
	{
		singleton = nullptr;
	}

private:
	// �B��̃C���X�^���X��ۑ�����ϐ�(���d�쐬�����₷�邽�߂̃t���O)
	static T * singleton;
};

template<class T> T * Singleton<T>::singleton = nullptr;