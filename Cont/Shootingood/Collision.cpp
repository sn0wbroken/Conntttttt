#include"Collision.h"

#include"Object_Creater.h"

Collision::Collision() {

}

// ���t���[���Ă΂��X�V����
void Collision::Update() {
	std::unique_ptr<Enemy_Manager>& enemy_manager = Enemy_Manager::Get_Instance();
	auto enemys = enemy_manager->active_enemies;
	
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	auto player_weapon = player_manager->player_weapon;

	for (auto enemy : enemys) {
		// �v���C���[�ƃG�l�~�[�̓����蔻��
		if (Player_To_Enemy(player_manager->player, enemy)) {
			// �������Ă�����_���[�W
			player_manager->player_status->Damage();
			// ���������G�͎��S�B��ԂɂԂ���񂾂��瓖����܂�����Ȃ�
			enemy->enemy_status->Dead();
		}

		// �ʏ�U���Ƃ̓����蔻����s��
		if (!player_weapon->Get_Is_Shooting()) {
			continue;
		}
		else if (Nomal_Attack_To_Enemy(enemy)) {
			enemy->enemy_status->Dead();
		}
	}
	// �ʏ�U���͓G���ђʂ���̂Ńt���O��߂��͍̂Ō�
	player_weapon->Initialize_Is_Shooting();
}

// ������2�_�Ԃ̋��������߂ĕԂ�
float Collision::Get_Distance(Vector3D coordinates_1, Vector3D coordinates_2) {
	return calculator.Norm_3D(coordinates_1.x, coordinates_1.y, coordinates_1.z, coordinates_2.x, coordinates_2.y, coordinates_2.z);
}

// �ʏ�U�����s�����Ƃ��ɃG�l�~�[�Ƀq�b�g�������𒲂ׂ�
bool Collision::Nomal_Attack_To_Enemy(std::shared_ptr<Enemy> enemy) {
	// �����ƕ��ʂ̓����蔻����s��
	std::unique_ptr<Player_Manager>& player_manager = Player_Manager::Get_Instance();
	auto muzzule_position = player_manager->player_weapon->Get_Position();
	auto limit_fire_range = player_manager->player_weapon->Get_Limit_Range();
	auto front_face = enemy->rects["front_face"];
	auto normal_vector = front_face.normal_vector;

	// �ʂ̓_����n�_
	auto vector1 = calculator.Make_Vector(front_face.Get_Centor_Position(), muzzule_position);
	// �ʂ̓_����I�_
	auto vector2 = calculator.Make_Vector(front_face.Get_Centor_Position(), limit_fire_range);	
	// �ʂ̓_����n�_�̓���
	auto dot1 = calculator.Dot(vector1, normal_vector);
	// �ʂ̓_����n�_�̓���
	auto dot2 = calculator.Dot(vector2, normal_vector);
	DrawLine3D(vector1, vector2, GetColor(0, 255, 0));
	// ���������ʂ��т��Ă��邩
	if (dot1 * dot2 <= 0) {
		// ��_�����߂�
		Vector3D intersection = Get_Intersection(vector1, vector2, limit_fire_range, muzzule_position, front_face);
		DrawLine3D(vector1,vector2, GetColor(0,0,255));
		// ��_�������̖ʂɐڂ��Ă��邩�𒲂ׂ�
		if (Point_To_Rectangle(intersection, muzzule_position, limit_fire_range, normal_vector, front_face)) {
			OutputDebugString("Bell");
			DrawLine3D(vector1,vector2,GetColor(255,0,0));
			return true;
		}
	}

	return false;
}

// �_����`�ɓ��ڂ��Ă��邩�𒲂ׂ� ���ꕽ�ʏ�ɂ��邱�Ƃ��O��
bool Collision::Point_To_Rectangle(Vector3D intersection, Vector3D start_point, Vector3D end_point, Vector3D normal_vector, Rect face) {
	// �n�_��p,�I�_��q�Ƃ���
	auto p = start_point;
	auto q = end_point;
	// ���ׂ�ʂ̊e���_�𔽎��v����abcd�Ƃ���
	auto a = face.top_left;
	auto b = face.bottom_left;
	auto c = face.bottom_right;
	auto d = face.top_right;

	// ���ׂ����
	auto pq = calculator.Make_Vector(end_point, start_point);

	auto pa = calculator.Make_Vector(a, p);
	auto pb = calculator.Make_Vector(b, p);
	auto pc = calculator.Make_Vector(c, p);

	auto m = calculator.Cross(pc, pq);
	auto v = calculator.Dot(pa, m);

	if (v <= 0.0f) {
		float u = -calculator.Dot(pb, m);
		if (u < 0.0f) return false;

		float w = calculator.Dot(calculator.Cross(pq, pb), pa);
		if (w < 0.0f) return false;
	}
	else {
		auto pd = d - p;

		float u = calculator.Dot(pd, m);
		if (u < 0.0f) return false;
		
		float w = calculator.Dot(calculator.Cross(pq, pa), pd);
		if (w < 0.0f) return false;
	}

	return true;
}

// �����Ō��铖���蔻��B����������̒l���Z���Ɠ������Ă���
bool Collision::Distance_Collition(float distance, float judge_value) {
	return distance < judge_value;
}

// �v���C���[�ƃG�l�~�[�̓����蔻��B�����ōs��
bool Collision::Player_To_Enemy(std::shared_ptr<Player> player, std::shared_ptr<Enemy> enemy) {
	// �v���C���[�A�G�l�~�[�Ԃ̋���
	auto distance = Get_Distance(player->Get_Position(), enemy->Get_Position());
	// ���݂��̕��𑫂�������
	auto judge_value = player->Get_Size().depth + enemy->Get_Size().height;

	return Distance_Collition(distance, judge_value);
}

// �����ƕ��ʂ̌�_�����߂�
Vector3D Collision::Get_Intersection(Vector3D vector1, Vector3D vector2, Vector3D start_point, Vector3D end_point, Rect face) {
	auto dot1 = calculator.Dot(vector1, face.Get_Centor_Position());
	auto dot2 = calculator.Dot(vector2, face.Get_Centor_Position());

	// �x�N�g��
	auto vector = calculator.Make_Vector(end_point, start_point);
	// ��_����A�n�_�̋��� : �I�_�̋����̔䗦
	auto ratio = std::abs(dot1) / (std::abs(dot1) + std::abs(dot2));

	// ��_���i�[
	Vector3D result;
	result.x = start_point.x + (vector.x + ratio);
	result.y = start_point.y + (vector.y + ratio);
	result.z = start_point.z + (vector.z + ratio);
	
	return result;
}
