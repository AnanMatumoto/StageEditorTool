#pragma once


//２次元ヘルパー関数群
struct t_Float2 {

	float x, y;

	t_Float2() {};

	t_Float2(float x_, float y_) {
		this->x = x_;
		this->y = y_;
	}

	t_Float2 operator + (const t_Float2& r) {
		return { this->x + r.x, this->y + r.y };
	}

	t_Float2 operator - (const t_Float2& r) {
		return { this->x - r.x, this->y - r.y };
	}

	t_Float2 operator * (const t_Float2& r) {
		return { this->x * r.x, this->y * r.y };
	}

	t_Float2 operator * (float r)const {
		return { this->x * r, this->y * r };
	}

	t_Float2 operator / (const t_Float2& r) {
		return { this->x / r.x, this->y / r.y };
	}

	t_Float2 operator / (float r) const {
		return { this->x / r, this->y / r };
	}

	~t_Float2() {}
};

//t_Float2を点として再定義
typedef t_Float2 Point2D;

//2Dベクトル構造体（点にも使える）
struct Vec2 : public t_Float2 {

	Vec2() {}
	Vec2(float x_, float y_) :t_Float2(x_, y_) {}
	//コピーコンストラクタ
	Vec2(const t_Float2& r) :t_Float2(r) {}

	//点（ポイント）を持つベクトルを作りたいとき
	Vec2 operator = (const t_Float2& r) {
		Vec2 vec2;
		vec2.x = r.x;
		vec2.y = r.y;

		return vec2;
	}

	//垂直判定
	bool IsVertical(const Vec2& r) const {

		float t = (x * r.y) + (y*r.x);
		if (t <= 0.0001) {
			return true;
		}
		return false;

	}
	//ベクトルが平行であるか（線上に点があるか）
	bool IsHorizontal(const Vec2& r) const {

		float t = (x*r.x) - (r.x*y);

		if (t <= 0.0001) {
			//ほぼ０に近いとみなす（floatの為）
			return true;
		}
		return false;
	}

};

typedef Vec2 Size;

//３次元ヘルパー関数群
struct t_Float3
{
	float x, y, z;

	t_Float3()
	{
	}

	t_Float3(const t_Float3 & r) {
		this->x = r.x;
		this->y = r.y;
		this->z = r.z;
	}

	t_Float3(float x_, float y_, float z_)
		: x(x_),
		y(y_),
		z(z_)
	{
	}

	t_Float3 operator+(const t_Float3 & r) {
		return{ this->x + r.x, this->y + r.y, this->z + r.z };
	}

	t_Float3 operator-(const t_Float3 & r) {
		return { this->x - r.x, this->y - r.y, this->z - r.z };
	}

	t_Float3  operator*(const t_Float3 &r) {
		return { this->x * r.x, this->y * r.y, this->z * r.z };
	}

	t_Float3 operator*(float f) const {
		return { this->x*f, this->y * f, this->z *f };
	}

	t_Float3 operator/(const t_Float3 & r) {
		return { this->x / r.x, this->y / r.y, this->z / r.z };
	}

	t_Float3 operator/(float f)const {
		return { this->x / f, this->y / f, this->z / f };
	}

	~t_Float3() {}
};

//3次元ベクトル構造体
struct Vec3 : public t_Float3 {

	Vec3() {}
	Vec3(float x_, float y_, float z_) {
		this->x = x_;
		this->y = y_;
		this->z = z_;
	}
	Vec3(const Vec3& v) {
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
	}
};

