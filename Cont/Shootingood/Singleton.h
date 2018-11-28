#pragma once
// シングルトン化テンプレートクラス(パブリック継承して使う)
//
// このクラスは下記の書籍の36ページ、下記のサイトを参考にしました。
// GAME PROGRAMMING GEMS Mark DeLoura 著 川西裕幸監訳 狩野智英翻訳 ボーンデジタル　
//http://www9.plala.or.jp/herm/Pages/DevTips/Designing/Singleton.html
template<class T> class Singleton
{
public:
	// 唯一のインスタンスを取得するメソッド
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
	// デフォルト・コンストラクタ
	explicit inline Singleton()
	{
		if (singleton != nullptr) {
			throw std::exception("multicreation exception");
		}
		// ここで行っていることは親のポインタを子のポインタとして保存しているだけである
		// 親と子のクラスがどの順に配置されるかでoffsetの値が変化する
		//多重継承を使用しない限り、Offset は 0 です。
		const int offset = reinterpret_cast<int> (reinterpret_cast<T *> (1)) - reinterpret_cast<int> (reinterpret_cast<const Singleton <T> *> (reinterpret_cast<T *> (1)));
		singleton = reinterpret_cast<T *> (reinterpret_cast<int> (this) + offset);
	}

	// コピー・コンストラクタ
	inline Singleton(const Singleton & /*right*/)
	{
		throw std::exception("multicreation exception");
	}

	// デストラクタ
	virtual inline ~Singleton() noexcept
	{
		singleton = nullptr;
	}

private:
	// 唯一のインスタンスを保存する変数(多重作成を拒絶するためのフラグ)
	static T * singleton;
};

template<class T> T * Singleton<T>::singleton = nullptr;