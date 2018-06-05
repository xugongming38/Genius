#ifndef __VEC2_H__
#define __VEC2_H__

// 1.Vec2����
//ctrl+h �滻
class Vec2
{
private:
	int x,y;
public:
	Vec2(int x=0,int y=0){this->x=x;this->y=y;}
	void setX(int x){this->x=x;}
	void setY(int y){this->y=y;}
	void setXY(int x,int y){this->x=x;this->y=y;}
	int getX()const{return x;}
	int getY()const{return y;}
	Vec2 getPosition(){ return *this;}

	//��������
	Vec2& operator=(Vec2 &p);//��ֵ
	Vec2& operator=(int xy);//��ֵ
	bool operator==(Vec2 &p);//�Ƚ�
	friend Vec2 operator+(const Vec2 &l,const Vec2 &r);//�ӷ�
	friend Vec2 operator-(const Vec2 &l,const Vec2 &r);//����
	friend Vec2 operator*(const Vec2 &p,const double &scale);//�˷�(ʹ��double����)
	friend Vec2 operator*(const double &scale,const Vec2 &p);//�˷�(ʹ��double����)
	friend Vec2 operator/(const Vec2 &p,const double &scale);//�˷�(ʹ��double����)
};

//����������ľ����ƽ��
int PointDistance(Vec2 v1,Vec2 v2);
#endif