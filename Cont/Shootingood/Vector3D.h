#pragma once

#include"DxLib.h"

#include<numeric>
#include<cmath>

// ���W�֌W�������N���X
class Vector3D {
public:
	// �R���X�g���N�^
	Vector3D();
	// �R�s�[�R���X�g���N�^
	Vector3D(float x,float y,float z=0);
	// �R�s�[�R���X�g���N�^
	Vector3D(const Vector3D &vec);
	// �R�s�[�R���X�g���N�^
	Vector3D(const VECTOR &vec);
	// �f�X�g���N�^
	~Vector3D();

	// Dxlib��VECTOR���g��(Dxlib�̋@�\�ł��̌^���������̂������׍��킹��)
	VECTOR GetVECTOR();
	// �����̗v�f�������Vector3D�^�ɂ��ĕԂ�
	Vector3D Get_Vector(float set_x, float set_y, float set_z);
	// X���W��Ԃ�
	float Get_X();
	// Y���W��Ԃ�
	float Get_Y();
	// Z���W��Ԃ�
	float Get_Z();
	// �l���Z�b�g����
	void Set_Vector(float set_x = 0.0f, float set_y = 0.0f, float set_z = 0.0f);

	// �ړ�
	void Move(float set_x, float set_y, float set_z);

	// X���W�Ɉ����̒l�����Z����Vector��Ԃ�
	Vector3D Add_VectorX(float add_value);
	// Y���W�Ɉ����̒l�����Z����Vector��Ԃ�
	Vector3D Add_VectorY(float add_value);
	// Z���W�Ɉ����̒l�����Z����Vector��Ԃ�
	Vector3D Add_VectorZ(float add_value);
	// X���W�Ɉ����̒l�����Z����Vector��Ԃ�
	Vector3D Subtract_VectorX(float add_value);
	// Y���W�Ɉ����̒l�����Z����Vector��Ԃ�
	Vector3D Subtract_VectorY(float add_value);
	// Z���W�Ɉ����̒l�����Z����Vector��Ԃ�
	Vector3D Subtract_VectorZ(float add_value);
	
	// X���W�Ɉ����̒l�����Z�������l��Ԃ�
	float Add_X(float add_value);
	// Y���W�Ɉ����̒l�����Z�������l��Ԃ�
	float Add_Y(float add_value);
	// Z���W�Ɉ����̒l�����Z�������l��Ԃ�
	float Add_Z(float add_value);
	// X���W�Ɉ����̒l�����Z�������l��Ԃ�
	float Subtract_X(float add_value);
	// Y���W�Ɉ����̒l�����Z�������l��Ԃ�
	float Subtract_Y(float add_value);
	// Z���W�Ɉ����̒l�����Z�������l��Ԃ�
	float Subtract_Z(float add_value);

	// x���W
	float x;
	// y���W
	float y;
	// z���W
	float z;

#pragma region operator
	//�P�̉��Z�q
	inline const Vector3D operator+(const Vector3D& vec)const
	{
		Vector3D tmp;
		tmp.x = x + vec.x;
		tmp.y = y + vec.y;
		tmp.z = z + vec.z;
		return tmp;
	}

	inline const Vector3D operator-(const Vector3D& vec)const
	{
		Vector3D tmp;
		tmp.x = x - vec.x;
		tmp.y = y - vec.y;
		tmp.z = z - vec.z;
		return tmp;
	}

	inline const Vector3D operator*(const Vector3D& vec) const
	{
		Vector3D tmp;
		tmp.x = x * vec.x;
		tmp.y = y * vec.y;
		tmp.z = z * vec.z;
		return tmp;
	}

	inline const Vector3D operator*(const float& flt) const
	{
		Vector3D tmp;
		tmp.x = x * flt;
		tmp.y = y * flt;
		tmp.z = z * flt;
		return tmp;
	}

	inline const Vector3D operator/(const Vector3D& vec)const
	{
		Vector3D tmp;
		tmp.x = x / vec.x;
		tmp.y = y / vec.y;
		tmp.z = z / vec.z;
		return tmp;
	}
	// ���Z�q+�C�R�[���n
	inline Vector3D operator+=(const Vector3D& vec)
	{
		x += vec.x;
		y += vec.y;
		z += vec.z;
		return *this;
	}
	// DxLib��Vector�ϊ�
	inline operator DxLib::VECTOR() const
	{
		return DxLib::VGet(x, y, z);
	}
#pragma endregion

#pragma region Math
	// �x�N�g�������O�X
	static Vector3D VectorLength(Vector3D vector) {
		Vector3D tmp;

		tmp.x = vector.x * vector.x;
		tmp.y = vector.y * vector.y;
		tmp.z = vector.z * vector.z;

		return tmp;
	}
<<<<<<< Updated upstream
	// �x�N�g���̒�����Ԃ�
	static float Norm(float x, float y) {
		return sqrt(pow(x, 2) + pow(y , 2) + pow(x, 2));
=======
	// �m������Ԃ�
	static float Norm(float x, float y, float z = 0) {
		return sqrt(pow(x, 2) + pow(y , 2) + pow(z, 2));
>>>>>>> Stashed changes
	}

	// 2�_����x�N�g���𐶐� point1�����Z���邽�߁@point1 > point2�ɂȂ�悤��
	static Vector3D Make_Vector(Vector3D point1, Vector3D point2) {
		return point1.operator-(point2);
	}

	// 2�_�Ԃ̋��������߂�(3�����p)
	static float Norm_3D(float x1, float y1, float z1, float x2, float y2, float z2) {
		return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2) + pow((z2 - z1), 2));
	}

	// �������v�Z�i�o�r���j�A�l���\�b�h�j
	static float sqrt(float s) {
		float tmp_x = s / 2.0f; // Is there any better way to determine initial value?
		float last_x = 0.0; // the value one before the last step

		while (tmp_x != last_x) // until the difference is not significant
		{ // apply Babylonian method step
			last_x = tmp_x;
			tmp_x = static_cast<float>((tmp_x + s / tmp_x) / 2.0);
		}

		return tmp_x;
	}
	// �x�N�g���̃m�[�}���C�Y
	static Vector3D normalize(Vector3D vector) {
		float mag = 1 / Norm(vector.x, vector.y);
		float _x = vector.x * mag;
		float _y = vector.y * mag;

		return Vector3D(VGet(_x, _y, 0));
	}
<<<<<<< Updated upstream
	// ���όv�Z
	static float dot(Vector3D vector,Vector3D vector2) {
		float a[] = { vector.x,vector.y,vector.z };
		float b[] = { vector2.x,vector2.y,vector2.z };
		// �X�^���_�[�h���C�u�����̓��όv�Z
		float result = static_cast<float>(std::inner_product(a, a + sizeof(a) / sizeof(a[0]), b, 0));
=======
	//���όv�Z
	static float dot(Vector3D vector,Vector3D vector2)
	{
		//DX���C�u�����̓��όv�Z
		float result = DxLib::VDot(vector, vector2);
>>>>>>> Stashed changes

		return result;
	}
	// �N���X�όv�Z
	static Vector3D cross(Vector3D vector,Vector3D vector2) {
		Vector3D TempVector;
		TempVector.x = vector.y * vector2.z - vector.z * vector2.y;
		TempVector.y = vector.x * vector2.z - vector.z * vector2.x;
		TempVector.z = vector.x * vector2.y - vector.y * vector2.x;

		return TempVector;
	}
	// ���W�A���v�Z (�i�s�����v�Z�p)
	static float MoveOnAngleOfElevation(Vector3D vector,Vector3D vector2) {
		const double px = static_cast<double> (vector.x - vector2.x);
		const double pz = static_cast<double> (vector.z - vector2.z);
		//atan2 �� ������y x�̂��� pz,px�̏��ő}������
		return static_cast<float> (std::atan2(pz, px));
	}
	// ���W�A���v�Z(���f����])
	static float RotateOnAngleOfElevation(Vector3D vector, Vector3D vector2) {
		const double px = static_cast<double> (vector.x - vector2.x);
		const double pz = static_cast<double> (vector.z - vector2.z);
		//atan2 �� ������y x�����A�Ȃ�����]�����������Ȃ�̂�x z�ő}������
		return static_cast<float> (std::atan2(px, pz));
	}
#pragma endregion
};
