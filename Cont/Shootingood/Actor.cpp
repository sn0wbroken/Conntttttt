#include "Actor.h"

// 現在のx座標を返す
int Actor::Get_X() {
	return vector3->x;
}
// x座標をセットする
void Actor::Set_X(int set_x) {
	vector3->x = set_x;
}

// 現在のy座標を返す
int Actor::Get_Y() {
	return vector3->y;
}
// y座標を設定する
void Actor::Set_Y(int set_y) {
	vector3->y = set_y;
}
// 幅を返す
int Actor::Get_Width() {
	return width;
}
// 高さを返す
int Actor::Get_Height() {
	return height;
}
